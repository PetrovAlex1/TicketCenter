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

	void Initialize(const myString& eventName, const Hall& hall /*Date date*/);

	void SetEventName(const myString& eventName);

	void SetHall(const Hall& hall);

	myString GetEventName() const;

	Hall GetHall() const;

	int GetFreeSeats() const;

};