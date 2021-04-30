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
	if (row > hall.getRows())
	{
		std::cout << "Row is out of range!" << std::endl;
		exit(0);
	}
	else if (seat > hall.getSeatsOnRow())
	{
		std::cout << "Seat is out of range!" << std::endl;
		exit(0);
	}

	hall.changeSeatBehavior(row, seat, 1);
	Booking booking{ note, row, seat };
	bookings.add(booking);
	freeseats--;
}

void Event::unbookTicket(const int& row, const int& seat)
{
	if (freeseats == hall.getTotalSeats())
	{
		std::cout << "Cannot unbook seat, which is not booked!" << std::endl;
		exit(0);
	}
	if (row > hall.getRows())
	{
		std::cout << "Row is out of range!" << std::endl;
		exit(0);
	}
	else if (seat > hall.getSeatsOnRow())
	{
		std::cout << "Seat is out of range!" << std::endl;
		exit(0);
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

std::ostream& operator<<(std::ostream& out, const Event& event)
{
	out << event.getEventName() << std::endl;
	out << "In hall: " << event.getHall().getHallName() << std::endl;
	out << "On a date: " << event.getDate() << std::endl;
	out << "With free seats: " << event.getFreeSeats() << std::endl;

	return out;
}
