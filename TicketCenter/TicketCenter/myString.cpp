#include <exception>
#include <cstring>
#include "myString.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

int countParts(const myString& str, const char& symbol)
{
	int countWS = 0;
	int i = 0;

	while (i != str.length())
	{
		if (str[i] == symbol)
		{
			countWS++;
		}

		i++;
	}

	return countWS;
}

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

myVector<myString> myString::splitBy(const char& symbol)
{
	int i = 0;
	int countWS = countParts(*this, symbol);//count whitespaces

	myVector<myString> vect;
	int j = 0;

	for (i = 0; i < countWS + 1; i++)
	{
		myString currentString;

		while (this->data[j] != symbol && this->data[j] != '\0')
		{
			currentString.append(this->data[j]);
			j++;
		}

		vect.add(currentString);
		j++;
	}


	return vect;
}

unsigned int myString::toInt()
{
	int result = 0;
	bool flag = false;

	for (int i = 0; i < size && (data[i] >= '0' && data[i] <= '9'); i++)
	{
		flag = true;
		int currentDigit = data[i] - '0';
		result = currentDigit + result * 10;
	}

	if (flag)
	{
		return result;
	}

	return -1;
}

bool myString::isFormLetters() const
{
	for (int i = 0; i < size; i++)
	{
		if (!(data[i] >= 'a' && data[i] <= 'z') && !(data[i] >= 'A' && data[i] <= 'Z'))
		{
			return false;
		}
	}

	return true;
}

void myString::fromInt(unsigned int& number)
{
	int counter = 0;
	char digits[8];

	while (number != 0)
	{
		int currentDigit = number % 10;
		number /= 10;
		digits[counter] = currentDigit;
		counter++;
	}

	for (int i = counter - 1; i >= 0; --i)
	{
		switch (digits[i])
		{
		case 0:
			append('0');
			break;
		case 1:
			append('1');
			break;
		case 2:
			append('2');
			break;
		case 3:
			append('3');
			break;
		case 4:
			append('4');
			break;
		case 5:
			append('5');
			break;
		case 6:
			append('6');
			break;
		case 7:
			append('7');
			break;
		case 8:
			append('8');
			break;
		case 9:
			append('9');
			break;
		default:
			break;
		}
	}
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
	try
	{
		if (index < 0 || index > this->size)
		{
			throw std::out_of_range("Out of range exception: Index out of range!");
		}
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	return this->data[index];
}

char myString::operator[](const int index)
{
	try
	{
		if (index < 0 || index > this->size)
		{
		 	throw std::out_of_range ("Out of range exception: Index out of range!");
		}
	}
	catch (const std::out_of_range& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
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

bool myString::operator==(const myString& other) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] != other.data[i])
		{
			return false;
		}
	}

	return true;
}

bool myString::operator==(const char* other) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->data[i] != other[i])
		{
			return false;
		}
	}

	return true;
}

std::ostream& operator<<(std::ostream& out, const myString& str)
{
	int size = str.length();

	for (int i = 0; i < size; i++)
	{
		out << str.data[i];
	}

	return out;
}

std::istream& operator>>(std::istream& in, myString& str)
{
	char data[128];
	in.getline(data, 128);

	str.setString(data);

	return in;
}

