#include "TicketCenter.h"

TicketCenter::TicketCenter(const myString& _name)
{
	name = _name;
}

void TicketCenter::startUp()
{
	std::cout << "Welcom to " << name << " ticket center!" << std::endl;

	while (true)
	{
	theBegining:
		std::cout << "Waiting for your command..." << std::endl;
		myString input;
		std::cin >> input;
		myVector<myString> arguments;
		arguments = input.splitBy(' ');
		myString command = arguments[0];

		if (command == "addhall")
		{
			unsigned int totalSeats = arguments[2].toInt();
			unsigned int rows = arguments[3].toInt();
			unsigned int seatsOnRow = arguments[4].toInt();
			myString hallName = arguments[1];

			Hall hall{ hallName, totalSeats, rows, seatsOnRow };
			halls.add(hall);

			std::cout << "Hall successfully added!" << std::endl;
		}
		else if (command == "addevent")
		{
			myString hallName{ arguments[2] };

			if (existHall(hallName))
			{
				myString eventName{ arguments[3] };
				Date date;
				date.setDate(arguments[1]);
				int hallIndex = getHall(hallName);

				if (hallIsFree(hallName, date))
				{
					Event event{ eventName, halls[hallIndex], date };
					events.add(event);

					std::cout << "Event successfully added!" << std::endl;
					continue;
				}

				std::cout << "Hall " << hallName << " is not free on date " << date << std::endl;
				continue;
			}

			std::cout << "No such hall!" << std::endl;
		}
		else if (command == "freeseats")
		{
			Date date;
			date.setDate(arguments[1]);
			myString eventName = arguments[2];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				std::cout << "On event " << eventName << " on date " << date << " there are " << events[indexOfEvent].getFreeSeats() << " free seats." << std::endl;
				continue;
			}

			std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
		}
		else if (command == "book")
		{
			unsigned int row = arguments[1].toInt();
			unsigned int seat = arguments[2].toInt();
			Date date;
			date.setDate(arguments[3]);
			myString eventName = arguments[4];
			myString note = arguments[5];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				events[indexOfEvent].bookTicket(row, seat, note);
				std::cout << "Ticket was booked successfully!" << std::endl;
				continue;
			}

			std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
		}
		else if (command == "unbook")
		{
			unsigned int row = arguments[1].toInt();
			unsigned int seat = arguments[2].toInt();
			Date date;
			date.setDate(arguments[3]);
			myString eventName = arguments[4];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				events[indexOfEvent].unbookTicket(row, seat);
				std::cout << "Ticket was unbooked successfully!" << std::endl;
				continue;
			}

			std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
		}
		else if (command == "buy")
		{
			unsigned int row = arguments[1].toInt();
			unsigned int seat = arguments[2].toInt();
			Date date;
			date.setDate(arguments[3]);
			myString eventName = arguments[4];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				events[indexOfEvent].buyTicket(row, seat);
				std::cout << "Ticket was bought successfully!" << std::endl;
				continue;
			}

			std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
		}
		else if (command == "bookings")
		{
			if (arguments.length() == 3)
			{
				Date date;
				date.setDate(arguments[1]);
				myString eventName = arguments[2];
				int indexOfEvent = 0;

				if (existEvent(date, eventName, indexOfEvent))
				{
					std::cout << events[indexOfEvent].getEventName() << std::endl;
					events[indexOfEvent].getBookings().print();
					continue;
				}

				std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
			}
			else
			{
				if (arguments.length() == 1)//if the input is only bookings then it prints information for all dates
				{
					int length = events.length();

					for (int i = 0; i < length; i++)
					{
						std::cout << events[i].getEventName() << std::endl;
						events[i].getBookings().print();
					}
				}
				else //if the input is bookings <date> then it prints all bookings on the exact <date> 
				{
					int length = events.length();
					bool dateExist = false;
					Date date;
					date.setDate(arguments[1]);

					for (int i = 0; i < length; i++)
					{
						if (events[i].getDate() == date)
						{
							std::cout << events[i].getEventName() << std::endl;
							events[i].getBookings().print();
							dateExist = true;
						}
					}

					if (!dateExist)//if in <date> there is no events
					{
						std::cout << "Events on date " << date << " does not exist!" << std::endl;
					}
				}
			}
		}
		else if (command == "check")
		{
			myString code = arguments[1];
			bool isFound = false;
			int eventsLength = events.length();

			for (int i = 0; i < eventsLength; i++)
			{
				int codesLength = events[i].getCodes().length();

				for (int j = 0; j < codesLength; j++)
				{
					if (events[i].getCodes()[j] == code)
					{
						std::cout << "The ticket is valid and it's seat is on row " << code[3] << " and seat " << code[4] << std::endl;
						goto theBegining;
					}
				}
			}

			std::cout << "There is no such purchased ticket with code " << code << std::endl;
		}
		else if (command == "report")
		{
			myString formStr = arguments[1];
			Date startDate;
			startDate.setDate(formStr);
			myString toStr = arguments[2];
			Date endDate;
			endDate.setDate(toStr);
			int countEvents = events.length();
			bool findEvent = false;

			if (arguments.length() == 4)// if the input is report <form> <to> <hall>
			{
				myString hallName = arguments[3];
				int countEvents = events.length();
				bool findEvent = false;

				for (int i = 0; i < countEvents; i++)
				{
					if (events[i].getHall().getHallName() == hallName)
					{
						if (events[i].getDate() >= startDate && events[i].getDate() <= endDate)
						{
							std::cout << "Event " << events[i].getEventName() << " - bought tickets: " << events[i].getCodes().length();
							findEvent = true;
							std::cout << std::endl;
						}
					}
				}
			}
			else//if the input is report <form> <to>
			{
				for (int i = 0; i < countEvents; i++)
				{
					if (events[i].getDate() >= startDate && events[i].getDate() <= endDate)
					{
						std::cout << "Event " << events[i].getEventName() << " - bought tickets: " << events[i].getCodes().length();
						findEvent = true;
						std::cout << std::endl;
					}
				}
			}

			if (!findEvent)
			{
				std::cout << "There are no events in periond " << startDate << " to " << endDate << std::endl;
			}
		}
		else if (command == "open")
		{

		}
		else if (command == "close")
		{

		}
		else if (command == "save")
		{

		}
		else if (command == "saveas")
		{

		}
		else if (command == "help")
		{
			std::cout << "This project supports the following commands:" << std::endl;
			std::cout << "addhall <hall name> <total seats> <rows> <seats on a rows>" << std::endl;
			std::cout << "addevent <date> <hall> <name>" << std::endl;
			std::cout << "freeseats <date> <name>" << std::endl;
			std::cout << "book <row> <seat> <date> <name> <note>" << std::endl;
			std::cout << "unbook <row> <seat> <date> <name>" << std::endl;
			std::cout << "buy <row> <seat> <date> <name>" << std::endl;
			std::cout << "bookings [<date>] [<name>]" << std::endl;
			std::cout << "check <code>" << std::endl;
			std::cout << "report <from> <to> [<hall>]" << std::endl;
			std::cout << "open <file name> - opens file <file name>" << std::endl;
			std::cout << "close - closes currently opened file" << std::endl;
			std::cout << "save - saves the currently open file" << std::endl;
			std::cout << "saveas <file name> - saves the currently opened file in <file>" << std::endl;
			std::cout << "exit - exits the program" << std::endl;
		}
		else if (command == "exit")
		{
			exit(0);
		}
		else if (command == "print")
		{
			if (halls.length() != 0 && events.length() != 0)
			{
				printTotalInfo();
				continue;
			}

			std::cout << "There are no an"
		}
		else
		{
			std::cout << "Command is invalid!" << std::endl;
		}
	}
}

bool TicketCenter::existHall(const myString& hallName) const
{
	int length = halls.length();

	for (int i = 0; i < length; i++)
	{
		if (halls[i].getHallName() == hallName)
		{
			return true;
		}
	}

	return false;
}

int TicketCenter::getHall(const myString& hallName) const
{
	int length = halls.length();

	for (int i = 0; i < length; i++)
	{
		if (halls[i].getHallName() == hallName)
		{
			return i;
		}
	}
}

bool TicketCenter::existEvent(const Date& date, const myString& eventName, int& indexOfEvent) const
{
	int length = events.length();

	for (int i = 0; i < length; i++)
	{
		if (events[i].getEventName() == eventName)
		{
			if (events[i].getDate() == date)
			{
				indexOfEvent = i;
				return true;
			}
		}
	}

	return false;
}

bool TicketCenter::hallIsFree(const myString& hallName, const Date& date) const
{
	int length = events.length();

	for (int i = 0; i < length; i++)
	{
		if (events[i].getDate() == date && events[i].getHall().getHallName() == hallName)
		{
			return false;
		}
	}

	return true;
}

void TicketCenter::printTotalInfo()
{
	std::cout << "Halls" << std::endl;
	halls.print();

	std::cout << "Events" << std::endl;
	events.print();
}
