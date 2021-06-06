#pragma once
#include <iostream>
#include "Device.h"

class Laptop : public Device
{
private:
	size_t speed;
public:

	Laptop();

	Laptop(const char* manufacture, const size_t& speed);

	Laptop(const Laptop& laptop);

	void print() const override;

	size_t get_pref() override;

	Device* clone() override;
};