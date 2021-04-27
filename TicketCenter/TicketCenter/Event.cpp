#include "Event.h"

Event::Event()
{
	this->freeseats = 0;
}

Event::Event(const myString& eventName, const Hall& hall, const Date& date)
{
	this->setEventName(eventName);
	this->setHall(hall);
	this->setDate(date);
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
	return this->hall;
}

unsigned int Event::getFreeSeats() const
{
	return this->freeseats;
}