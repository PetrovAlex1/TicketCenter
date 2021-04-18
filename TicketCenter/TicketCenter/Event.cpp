#include "Event.h"

void Event::Initialize(const myString& eventName, const Hall& hall)
{
	this->SetEventName(eventName);
	this->SetHall(hall);
}

Event::Event()
{
	this->freeseats = 0;
}

void Event::SetEventName(const myString& eventName)
{
	this->eventName = eventName;
}

void Event::SetHall(const Hall& hall)
{
	this->hall = hall;
}

myString Event::GetEventName() const
{
	return this->eventName;
}

Hall Event::GetHall() const
{
	return this->hall;
}

int Event::GetFreeSeats() const
{
	return this->freeseats;
}