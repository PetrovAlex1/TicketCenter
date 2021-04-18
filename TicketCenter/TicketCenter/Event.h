#pragma once
#include <iostream>
#include "myString.h"
#include "Hall.h"

class Event
{
private:
	myString eventName;
	Hall hall;
	//TODO Date class
	int freeseats;
public:

	Event();

	void initialize(const myString& eventName, const Hall& hall /*Date date*/);

	//void buyTicket(const int& row, const int& seat, /*date*/  )

	void setEventName(const myString& eventName);

	void setHall(const Hall& hall);

	myString getEventName() const;

	Hall getHall() const;

	int getFreeSeats() const;

};