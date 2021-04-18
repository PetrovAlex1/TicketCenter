#include "Event.h"

void Event::initialize(const myString& eventName, const Hall& hall)
{
	this->setEventName(eventName);
	this->setHall(hall);
}

Event::Event()
{
	this->freeseats = 0;
}

void Event::setEventName(const myString& eventName)
{
	this->eventName = eventName;
}

void Event::setHall(const Hall& hall)
{
	this->hall = hall;
}

myString Event::getEventName() const
{
	return this->eventName;
}

Hall Event::getHall() const
{
	return this->hall;
}

int Event::getFreeSeats() const
{
	return this->freeseats;
}