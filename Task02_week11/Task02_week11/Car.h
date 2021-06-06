#pragma once
#include <iostream>
#include "Device.h"

class Car : public Device
{
private:
	size_t hp;
	size_t volume;

	void copy(const Car& car);
public:

	Car();

	Car(const char* manufacture, const size_t& hp, const size_t& volume);

	Car(const Car& car);


	void print() const override;

	size_t get_pref() override;

	Device* clone() override;
};