#include <stdexcept>
#include <fstream>
#include "Event.h"

myString Event::createCode(const myString& hallName, unsigned int& row, unsigned int& seat)
{
	myString code;
	code.append(eventName[0]);
	code.append(eventName[1]);
	code.append(eventName[2]);
	myString rowStr, seatStr;
	rowStr.fromInt(row);
	seatStr.fromInt(seat);
	code.append(rowStr);
	code.append(seatStr);

	return code;
}

Event::Event()
{
	this->freeseats = 0;
}

Event::Event(const myString& eventName, const Hall& hall, const Date& date)
{
	this->setEventName(eventName);
	this->setHall(hall);
	this->setDate(date);
	freeseats = hall.getTotalSeats();
}

void Event::buyTicket(unsigned int& row, unsigned int& seat)
{
	hall.changeSeatBehavior(row, seat, 2);
	myString code;
	code = createCode(hall.getHallName(), row, seat);

	std::cout << "Your tickes's code is: " << code << std::endl;

	codes.add(code);
	freeseats--;
}

void Event::bookTicket(const int& row, const int& seat, const myString& note)
{
	try
	{
		if (row > hall.getRows())
		{
			throw std::out_of_range("Out of range exception: Row is out of range or is invalid!");
		}
		else if (seat > hall.getSeatsOnRow())
		{
			throw std::out_of_range("Out of range exception: Seat is out of range or is invalid!");
		}
		else if (this->hall.getMatrixHall()[row][seat] != 0)
		{
			throw std::runtime_error("Ivalid operation exception: The seat is already reserved!");
		}
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	hall.changeSeatBehavior(row, seat, 1);
	Booking booking{ note, row, seat };
	bookings.add(booking);
	freeseats--;
}

void Event::unbookTicket(const int& row, const int& seat)
{
	try
	{
		if (freeseats == hall.getTotalSeats())
		{
			throw std::runtime_error("Invalid operation exception: Cannot unbook seat, which is not booked!");
		}
		else if (row > hall.getRows())
		{
			throw std::out_of_range("Out of range exception: Row is out of range or is invalid!");
		}
		else if (seat > hall.getSeatsOnRow())
		{
			throw std::out_of_range("Out of range exception: Seat is out of range or is invalid!");
		}
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}
	catch (const std::runtime_error& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	hall.changeSeatBehavior(row, seat, 0);
	freeseats++;
}

void Event::setEventName(const myString& eventName)
{
	this->eventName = eventName;
}

void Event::setHall(const Hall& hall)
{
	this->hall = hall;
	freeseats = hall.getTotalSeats();
}

void Event::setDate(const Date& date)
{
	this->date = date;
}

const myString& Event::getEventName() const
{
	return eventName;
}

const Hall& Event::getHall() const
{
	return hall;
}

const Date& Event::getDate() const
{
	return date;
}

const myVector<Booking>& Event::getBookings() const
{
	return bookings;
}

const myVector<myString>& Event::getCodes() const
{
	return codes;
}

unsigned int Event::getFreeSeats() const
{
	return this->freeseats;
}

void Event::writeOnFile(const char* fileName)
{
	std::ofstream myFile(fileName, std::ios::app);

	myFile << "Event" << std::endl;
	myFile << eventName << std::endl;
	myFile << hall.getHallName() << std::endl;
	myFile << date << std::endl;
	myFile << "bookings" << std::endl;

	int bookingsSize = bookings.length();

	for (int i = 0; i < bookingsSize; i++)
	{
		myFile << bookings[i].getNote() << " row: " << bookings[i].getRow() << " seat: " << bookings[i].getSeat() << std::endl;
	}

	myFile << "codes" << std::endl;
	int codesLength = codes.length();

	for (size_t i = 0; i < codesLength; i++)
	{
		myFile << codes[i] << std::endl;
	}

	myFile.close();
}

std::ostream& operator<<(std::ostream& out, const Event& event)
{
	out << event.getEventName() << std::endl;
	out << "In hall: " << event.getHall().getHallName() << std::endl;
	out << "On a date: " << event.getDate() << std::endl;
	out << "With free seats: " << event.getFreeSeats() << std::endl;

	return out;
}
