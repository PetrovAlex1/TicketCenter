#pragma once
#include <iostream>

class Device
{
private:
	void copy(const Device& device);
protected:
	char* manufacture;
public:
	Device();

	Device(const Device& device);

	~Device();

	Device& operator=(const Device& device);

	virtual void print() const = 0;

	virtual size_t get_pref() = 0;

	virtual Device* clone() = 0;
};