#pragma once
#include <iostream>
#include "myString.h"
#include "Hall.h"
#include "Date.h"
#include "Booking.h"

class Event
{
private:
	myString eventName;
	Hall hall;
	Date date;
	myVector<Booking> bookings;
	myVector<myString> codes;
	unsigned int freeseats;

	myString createCode(const myString& hallName, unsigned int& row, unsigned int& seat);
public:

	Event();

	Event(const myString& eventName, const Hall& hall, const Date& date);

	void buyTicket(unsigned int& row, unsigned int& seat);

	void bookTicket(const int& row, const int& seat, const myString& note);

	void unbookTicket(const int& row, const int& seat);

	void setEventName(const myString& eventName);

	void setHall(const Hall& hall);

	void setDate(const Date& date);

	const myString& getEventName() const;

	const Hall& getHall() const;

	const Date& getDate() const;

	const myVector<Booking>& getBookings() const;

	const myVector<myString>& getCodes() const;

	unsigned int getFreeSeats() const;

	friend std::ostream& operator<<(std::ostream& out, const Event& event);

	void writeOnFile(const char* fileName);
};