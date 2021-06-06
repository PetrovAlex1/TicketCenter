#include "Device.h"
#pragma warning(disable:4996)

void Device::copy(const Device& device)
{
	this->manufacture = new char[strlen(device.manufacture) + 1];
	strcpy(this->manufacture, device.manufacture);
}

Device::Device()
{
	this->manufacture = nullptr;
}

Device::Device(const Device& device)
{
	copy(device);
}

Device::~Device()
{
	delete[] this->manufacture;
	this->manufacture = nullptr;
}

Device& Device::operator=(const Device& device)
{
	if (this != &device)
	{
		delete[] this->manufacture;
		copy(device);
	}

	return *this;
}
