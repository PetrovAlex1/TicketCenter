#include "Car.h"
#pragma warning(disable:4996)

void Car::copy(const Car& car)
{
	this->manufacture = new char[strlen(car.manufacture) + 1];
	strcpy(this->manufacture, car.manufacture);
	this->hp = car.hp;
	this->volume = car.volume;
}

Car::Car()
{
	this->hp = 0;
	this->volume = 0;
}

Car::Car(const char* manufacture, const size_t& hp, const size_t& volume)
{
	this->manufacture = new char[strlen(manufacture) + 1];
	strcpy(this->manufacture, manufacture);
	this->hp = hp;
	this->volume = volume;
}

Car::Car(const Car& car)
{
	copy(car);
}

void Car::print() const
{
	std::cout << "This car is " << this->manufacture << " with " << this->hp << " horse power and " << this->volume << " engine." << std::endl;
}

size_t Car::get_pref()
{
	return this->hp;
}

Device* Car::clone()
{
	return new Car(*this);
}
