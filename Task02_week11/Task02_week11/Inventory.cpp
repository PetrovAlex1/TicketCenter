#include "Inventory.h"
#include "Inventory.h"

void Inventory::addItem(Device* device)
{
	if (devices.size() <= 100)
	{
		devices.emplace_back(device->clone());
	}
}

void Inventory::print() const
{
	for (Device* d : devices)
	{
		d->print();
	}
}

bool Inventory::areIncrProductivity()
{
	size_t previousProductivity = devices[0]->get_pref();
	int size = devices.size();

	for (int i = 1; i < size; i++)
	{
		if (devices[i]->get_pref() < previousProductivity)
		{
			return false;
		}
	}

	return true;
}
