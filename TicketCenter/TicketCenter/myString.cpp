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

void myString::Append(const char symbol)
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

void myString::Append(const char* data)
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

void myString::Append(const myString& other)
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

void myString::SetString(const char* data)
{
	int otherSize = strlen(data);
	this->data = new char[otherSize + 1];

	strcpy(this->data, data);

	this->SetSize(otherSize);
	this->SetCapacity(otherSize);
}

void myString::SetSize(const size_t size)
{
	this->size = size;
}

void myString::SetCapacity(const size_t size)
{
	if (this->capacity < size)
	{
		this->resize(size);
	}
}

char* myString::GetData() const
{
	return this->data;
}

const size_t myString::Length() const
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
	int size = str.Length();

	for (int i = 0; i < size; i++)
	{
		out << str.data[i];
	}

	out << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, myString& str)
{
	char data[64];
	in.getline(data, 64);

	str.SetString(data);

	return in;
}

