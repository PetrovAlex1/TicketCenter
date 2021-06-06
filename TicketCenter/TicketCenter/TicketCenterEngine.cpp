#include <fstream>
#include <stdexcept>
#include "TicketCenterEngine.h"
#pragma warning(disable:4996)

TicketCenter::TicketCenter(const myString& _name)
{
	name = _name;
}

void TicketCenter::startUp()
{
	std::cout << "Welcom to " << name << " ticket center!" << std::endl;
	bool isOpened = false;
	myString fileToSave;

	while (true)
	{
		std::cout << "Waiting for your command..." << std::endl;
		myString input;
		std::cin >> input;
		myVector<myString> arguments;
		arguments = input.splitBy(' ');
		myString command = arguments[0];

		if (command == "addhall" && isOpened)
		{
			if (arguments.length() != 5)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			unsigned int totalSeats = arguments[2].toInt();
			unsigned int rows = arguments[3].toInt();
			unsigned int seatsOnRow = arguments[4].toInt();
			myString hallName = arguments[1];

			Hall hall{ hallName, totalSeats, rows, seatsOnRow };
			halls.add(hall);

			std::cout << "Hall successfully added!" << std::endl;
		}
		else if (command == "addevent" && isOpened)
		{
			if (arguments.length() != 4)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			myString hallName{ arguments[2] };

			if (existHall(hallName))
			{
				myString eventName{ arguments[3] };
				Date date;
				myString dateStr = arguments[1];
				date.setDate(dateStr);
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
		else if (command == "freeseats" && isOpened)
		{
			if (arguments.length() != 3)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			Date date;
			myString dateStr = arguments[1];
			date.setDate(dateStr);
			myString eventName = arguments[2];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				std::cout << "On event " << eventName << " on date " << date << " there are " << events[indexOfEvent].getFreeSeats() << " free seats." << std::endl;
				continue;
			}

			std::cout << "There is no such event on this date" << std::endl;
		}
		else if (command == "book" && isOpened)
		{
			if (arguments.length() != 3)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			Date date;
			myString dateStr = arguments[1];
			date.setDate(dateStr);
			myString eventName = arguments[2];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				events[indexOfEvent].getHall().showMatrix();
				std::cout << "Enter the number of row and seat, after that enter the note" << std::endl;
				myString bookInput;
				std::cin >> bookInput;
				myVector<myString> bookArguments;
				bookArguments = bookInput.splitBy(' ');

				if (bookArguments.length() != 4)
				{
					std::cout << "Too few arguments!" << std::endl;
					continue;
				}

				unsigned int row = bookArguments[1].toInt();
				unsigned int seat = bookArguments[2].toInt();
				myString note = bookArguments[3];
				events[indexOfEvent].bookTicket(row, seat, note);
				std::cout << "Ticket was booked successfully!" << std::endl;
				continue;
			}

			std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
		}
		else if (command == "unbook" && isOpened)
		{
			if (arguments.length() != 5)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			unsigned int row = arguments[1].toInt();
			unsigned int seat = arguments[2].toInt();
			Date date;
			myString dateStr = arguments[3];
			date.setDate(dateStr);
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
		else if (command == "buy" && isOpened)
		{
			if (arguments.length() != 3)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			Date date;
			myString dateStr = arguments[1];
			date.setDate(dateStr);
			myString eventName = arguments[2];
			int indexOfEvent = 0;

			if (existEvent(date, eventName, indexOfEvent))
			{
				events[indexOfEvent].getHall().showMatrix();
				std::cout << "Enter the number of row and seat" << std::endl;
				myString buyInput;
				std::cin >> buyInput;
				myVector<myString> buyArguments;
				buyArguments = buyInput.splitBy(' ');

				if (buyArguments.length() != 3)
				{
					std::cout << "Too few arguments!" << std::endl;
					continue;
				}

				unsigned int row = buyArguments[1].toInt();
				unsigned int seat = buyArguments[2].toInt();

				events[indexOfEvent].buyTicket(row, seat);
				std::cout << "Ticket was bought successfully!" << std::endl;
				continue;
			}

			std::cout << "There is no such event " << eventName << " on date " << date << std::endl;
		}
		else if (command == "bookings" && isOpened)
		{
			if (arguments.length() == 3)
			{
				Date date;
				myString dateStr = arguments[1];
				date.setDate(dateStr);
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
				if (arguments.length() == 1)//if the input is only "bookings" then it prints information for all dates
				{
					int length = events.length();

					for (int i = 0; i < length; i++)
					{
						std::cout << events[i].getEventName() << std::endl;
						events[i].getBookings().print();
					}
				}
				else //if the input is "bookings <date>" then it prints all bookings on the exact <date> 
				{
					int length = events.length();
					bool dateExist = false;
					Date date;
					myString dateStr = arguments[1];
					date.setDate(dateStr);

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
		else if (command == "check" && isOpened)
		{
			if (arguments.length() != 2)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			myString code = arguments[1];
			bool isFound = false;
			int eventsLength = events.length();
			bool flag = false;

			for (int i = 0; i < eventsLength; i++)
			{
				int codesLength = events[i].getCodes().length();

				for (int j = 0; j < codesLength; j++)
				{
					if (events[i].getCodes()[j] == code)
					{
						std::cout << "The ticket is valid and it's seat is on row " << code[3] << " and seat " << code[4] << std::endl;
						flag = true;
						break;
					}
				}

				if (flag)
				{
					break;
				}
			}

			if (!flag)
			{
				std::cout << "There is no such purchased ticket with code " << code << std::endl;
			}
		}
		else if (command == "report" && isOpened)
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
			else if (arguments.length() == 3)//if the input is report <form> <to>
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
			else
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			if (!findEvent)
			{
				std::cout << "There are no events in periond " << startDate << " to " << endDate << std::endl;
			}
		}
		else if (command == "open")
		{
			if (arguments.length() != 2)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			if (isOpened)
			{
				std::cout << "File is opened!" << std::endl;
				continue;
			}

			isOpened = true;
			fileToSave = arguments[1];//file.txt -> 8
			int nameSize = fileToSave.length();

			if (nameSize > 4
				&& fileToSave[nameSize - 4] == '.'
				&& fileToSave[nameSize - 3] == 't'
				&& fileToSave[nameSize - 2] == 'x'
				&& fileToSave[nameSize - 1] == 't')
			{
				readFormFile(fileToSave);
				std::cout << "File is opened!" << std::endl;
				continue;
			}

			std::cout << "File is invalid!" << std::endl;
		}
		else if (command == "close" && isOpened)
		{
			if (arguments.length() != 1)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			events.~myVector();
			halls.~myVector();
			myVector<Event> newEvents;
			myVector<Hall> newHalls;
			events = newEvents;
			halls = newHalls;
			fileToSave.~myString();
			isOpened = false;

			std::cout << "File is closed!" << std::endl;
		}
		else if (command == "save" && isOpened)
		{
			if (arguments.length() != 1)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			writeOnFile(fileToSave);
			std::cout << "File is saved!" << std::endl;
		}
		else if (command == "saveas" && isOpened)
		{
			if (arguments.length() != 2)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			myString directory = arguments[1];
			writeOnFile(directory);
			std::cout << "File is saved on " << directory << " directory!" << std::endl;
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
			std::cout << "statistics - display statistics for the most watched events" << std::endl;
			std::cout << "open <file name> - opens file <file name>" << std::endl;
			std::cout << "close - closes currently opened file" << std::endl;
			std::cout << "save - saves the currently open file" << std::endl;
			std::cout << "saveas <file name> - saves the currently opened file in <file>" << std::endl;
			std::cout << "exit - exits the program" << std::endl;
		}
		else if (command == "exit")
		{
			if (arguments.length() != 1)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			exit(0);
		}
		else if (command == "print")
		{
			if (arguments.length() != 1)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			if (halls.length() != 0 || events.length() != 0)
			{
				printTotalInfo();
				continue;
			}

			std::cout << "There are no events or halls yet!" << std::endl;
		}
		else if (command == "statistics" && isOpened)
		{
			if (arguments.length() != 1)
			{
				std::cout << "Too few arguments!" << std::endl;
				continue;
			}

			double totalViews = 0;
			int countEvents = events.length();
			int* positions = new int[countEvents + 1];//positions will keep the indexes from events from the most watched event to the event with fewest watches

			for (int i = 0; i < countEvents; i++)
			{
				totalViews += events[i].getCodes().length();
				positions[i] = i;
			}
			for (int i = 0; i < countEvents - 1; i++)//order the events with positions 
			{
				for (int j = 0; j < countEvents - 1; j++)
				{
					if (events[j].getCodes().length() > events[j + 1].getCodes().length())
					{
						int tempPosition = positions[j];
						positions[j] = positions[j + 1];
						positions[j] = tempPosition;
					}
				}
			}
			for (int i = 0; i < countEvents; i++)
			{
				double currentPercentage = (events[positions[i]].getCodes().length() / totalViews) * 100;
				std::cout << events[positions[i]].getEventName() << " - " << currentPercentage << std::endl;
			}
		}
		else if (isOpened)
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

void TicketCenter::writeOnFile(const myString& fileName)
{
	int newLength = fileName.length();
	char* fileNameCharArr = new char[newLength + 1];

	for (int i = 0; i < newLength; i++)
	{
		fileNameCharArr[i] = fileName[i];
	}

	fileNameCharArr[newLength] = '\0';

	std::ofstream myFile(fileNameCharArr, std::ios::out | std::ios::trunc);
	int hallsSize = halls.length();
	int eventsSize = events.length();

	for (int i = 0; i < hallsSize; i++)
	{
		halls[i].writeOnfFile(fileNameCharArr);
	}
	for (int i = 0; i < eventsSize; i++)
	{
		events[i].writeOnFile(fileNameCharArr);
	}

	myFile.close();
	delete[] fileNameCharArr;
}

void TicketCenter::readFormFile(const myString& fileName)
{
	std::ifstream myFile;
	bool fileExist = false;
	int newLength = fileName.length();
	char* fileNameCharArr = new char[newLength + 1];

	for (int i = 0; i < newLength; i++)
	{
		fileNameCharArr[i] = fileName[i];
	}

	fileNameCharArr[newLength] = '\0';

	myFile.open(fileNameCharArr);
	char buffer[64];

	while (myFile.getline(buffer, 64, '\n'))
	{
		fileExist = true;

		if (!strcmp(buffer, "Hall"))
		{
			int i = 0;
			myString hallName;
			unsigned int rows = 0, seatsOnRow = 0, totalSeats = 0;
			while (myFile.getline(buffer, 64, '\n'))
			{
				myString currentLine;
				currentLine.setString(buffer);

				if (i == 0)//hall name
				{
					hallName = currentLine;
					i++;
				}
				else if (i == 1) //total seats
				{
					totalSeats = currentLine.toInt();
					i++;
				}
				else if (i == 2) //rows
				{
					rows = currentLine.toInt();
					i++;
				}
				else if (i == 3) //seats on Row
				{
					seatsOnRow = currentLine.toInt();
					break;
				}
			}

			Hall hall{ hallName, totalSeats, rows, seatsOnRow };
			halls.add(hall);
		}
		else
		{
			Event event;
			bool flag = false;
			int i = 0;

			while (myFile.getline(buffer, 64, '\n'))
			{
				myString currentLine;
				currentLine.setString(buffer);

				if (i == 0)//event name
				{
					event.setEventName(currentLine);
					i++;
				}
				else if (i == 1)//hall name
				{
					int indexOfHall = getHall(currentLine);
					event.setHall(halls[indexOfHall]);
					i++;
				}
				else if (i == 2)//date
				{
					Date date;
					date.setDate(currentLine);
					event.setDate(date);
					i++;
				}
				else if (i == 3)//bookings
				{
					while (myFile.getline(buffer, 64, '\n'))
					{
						myString currentBooking;
						currentBooking.setString(buffer);
						myVector<myString> arguments = currentBooking.splitBy(' ');

						if (!strcmp(buffer, "codes"))
						{
							i++;
							break;
						}

						event.bookTicket(arguments[2].toInt(), arguments[4].toInt(), arguments[0]);
					}
				}
				else if (i == 4)//codes from bought tickets
				{
					unsigned int row = buffer[3] - '0';
					unsigned int seat = buffer[4] - '0';
					event.buyTicket(row, seat);

					while (myFile.getline(buffer, 64, '\n'))
					{
						if (!strcmp(buffer, "Event"))
						{

							break;
						}

						unsigned int row = buffer[3] - '0';
						unsigned int seat = buffer[4] - '0';
						event.buyTicket(row, seat);
					}

					flag = true;
				}

				if (flag)
				{
					i = 0;
					events.add(event);
					Event newEvent;
					event = newEvent;
					flag = false;
				}
			}
		}
	}

	myFile.close();
	delete[] fileNameCharArr;

	if (!fileExist)
	{
		writeOnFile(fileName);
	}
}

void TicketCenter::printTotalInfo()
{
	std::cout << "Halls" << std::endl;
	halls.print();

	std::cout << "Events" << std::endl;
	events.print();
}