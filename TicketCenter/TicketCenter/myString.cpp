#include <iostream>
#include <cstring>
#include "myString.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

myString::myString()
{
	this->data = nullptr;
	this->size = 0;
	this->capacity = 8;
}

myString::myString(const myString& other)
{
	this->copy(other);
}

myString::~myString()
{
	this->destroy();
}

void myString::append(const char symbol)
{
	if (this->data == nullptr)
	{
		this->data = new char[8];
	}
	if (this->capacity <= this->size + 1)
	{
		this->resize(this->capacity * 2);
	}

	this->data[this->size] = symbol;
	this->size++;
}

void myString::append(const char* data)
{
	int oldSize = this->size;
	int otherSize = strlen(data);

	if (this->capacity <= otherSize + oldSize + 1)
	{
		this->resize(oldSize + otherSize + 1);
	}

	int j = 0;

	for (int i = oldSize; i < oldSize + otherSize + 1; i++)
	{
		this->data[i] = data[j];
		j++;
	}

	this->size += otherSize;
}

void myString::append(const myString& other)
{
	int oldSize = this->size;
	int otherSize = other.size;

	if (this->capacity <= otherSize + oldSize + 1)
	{
		this->resize(oldSize + otherSize + 1);
	}

	int j = 0;

	for (int i = oldSize; i < oldSize + otherSize + 1; i++)
	{
		this->data[i] = other.data[j];
		j++;
	}

	this->size += otherSize;
}

void myString::setString(const char* data)
{
	int otherSize = strlen(data);
	this->data = new char[otherSize + 1];

	strcpy(this->data, data);

	this->setSize(otherSize);
	this->setCapacity(otherSize);
}

void myString::setSize(const int size)
{
	this->size = size;
}

void myString::setCapacity(const int size)
{
	if (this->capacity < size)
	{
		this->resize(size);
	}
}

char* myString::getData() const
{
	return this->data;
}

const int myString::length() const
{
	return this->size;
}

const char myString::operator[](const int index) const
{
	if (index < 0 || index > this->size)
	{
		std::cout << "Index out of range exception!";
		return 0;
	}

	return this->data[index];
}

char myString::operator[](const int index)
{
	if (index < 0 || index > this->size)
	{
		std::cout << "Index out of range exception!";
		return 0;
	}

	return this->data[index];
}

myString& myString::operator=(const myString& other)
{
	if (this != &other)
	{
		this->destroy();
		this->copy(other);
	}

	return *this;
}

std::ostream& operator<<(std::ostream& out, const myString& str)
{
	int size = str.length();

	for (int i = 0; i < size; i++)
	{
		out << str.data[i];
	}

	out << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, myString& str)
{
	char data[128];
	in.getline(data, 128);

	str.setString(data);

	return in;
}

