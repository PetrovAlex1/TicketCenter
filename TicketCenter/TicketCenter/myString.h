#pragma once
#include <iostream>
#include <string>
#include "myVector.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

class myString
{
private:
	char* data;
	int size;
	int capacity;

	void copy(const myString& other)
	{
		delete[] this->data;
		this->data = new char[other.capacity];
		this->size = other.size;
		this->capacity = other.capacity;

		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	void resize(int size)
	{
		while (this->capacity < size)
		{
			this->capacity += 7;
		}

		char* newData = new char[this->capacity + 1];
		strcpy(newData, this->data);

		this->destroy();
		data = newData;
	}

	void destroy()
	{
		delete[] this->data;
		this->data = nullptr;
	}
public:
	myString();

	myString(const myString& other);

	~myString();

	myVector<myString> splitBy(const char& symbol);

	void append(const char symbol);

	void append(const char* data);

	void append(const myString& other);

	void setString(const char* data);

	void setSize(const int size);

	void setCapacity(const int size);

	char* getData() const;

	const int length() const;

	const char operator[](const int index) const;

	char operator[](const int index);

	myString& operator=(const myString& other);

	bool operator==(const myString& other);

	bool operator==(const char* other);

	friend std::ostream& operator<<(std::ostream& out, const myString& str);

	friend std::istream& operator>>(std::istream& in, myString& str);
};

