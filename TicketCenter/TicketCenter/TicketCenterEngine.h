#pragma once
#include <iostream>
#include "myVector.h"
#include "Hall.h"
#include "Event.h"

class TicketCenter
{
private:
	myString name;
	myVector<Hall> halls;
	myVector<Event> events;
public:

	TicketCenter(const myString& _name);

	void startUp();

	bool existHall(const myString& hallName) const;

	int getHall(const myString& hallName) const;

	bool existEvent(const Date& date, const myString& eventName, int& indexOfEvent) const;

	bool hallIsFree(const myString& hallName, const Date& date) const;

	void writeOnFile(const myString& fileName);

	void readFormFile(const myString& fileName);

	void printTotalInfo();
};