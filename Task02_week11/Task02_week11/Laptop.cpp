#include "Laptop.h"
#pragma warning(disable:4996)

Laptop::Laptop()
{
	this->speed = 0;
	this->manufacture = nullptr;
}

Laptop::Laptop(const char* manufacture, const size_t& speed)
{
	this->manufacture = new char[strlen(manufacture) + 1];
	strcpy(this->manufacture, manufacture);
	this->speed = speed;
}

Laptop::Laptop(const Laptop& laptop)
{
	this->manufacture = new char[strlen(laptop.manufacture) + 1];
	strcpy(this->manufacture, laptop.manufacture);
	this->speed = laptop.speed;
}

void Laptop::print() const
{
	std::cout << "This laptop is " << this->manufacture << " with speed " << this->speed << std::endl;
}

size_t Laptop::get_pref()
{
	return this->speed;
}

Device* Laptop::clone()
{
	return new Laptop(*this);
}




