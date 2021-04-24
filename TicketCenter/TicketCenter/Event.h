#pragma once
#include <iostream>
#include "myString.h"
#include "Hall.h"
#include "Date.h"

class Event
{
private:
	myString eventName;
	Hall hall;
	Date date;
	int freeseats;
public:

	Event();

	void initialize(const myString& eventName, const Hall& hall, const Date& date);

	//void buyTicket(const int& row, const int& seat, const Date& date);

	//void bookTicket(const in& row, const int& seat, const Date& date, const myString& name, const myString& note);

	//void unbookTicket(const in& row, const int& seat, const Date& date, const myString& name);

	void setEventName(const myString& eventName);

	void setHall(const Hall& hall);

	void setDate(const Date& date);

	myString getEventName() const;

	Hall getHall() const;

	int getFreeSeats() const;

};