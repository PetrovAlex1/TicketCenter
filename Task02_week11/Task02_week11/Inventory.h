#pragma once

#include <iostream>
#include <vector>

#include "Device.h"

class Inventory
{
private:
	std::vector<Device*> devices;
public:

	void addItem(Device* device);

	void print() const;

	bool areIncrProductivity();
};