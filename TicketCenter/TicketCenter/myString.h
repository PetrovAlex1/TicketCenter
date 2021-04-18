#pragma once
#include <iostream>
#include <string>

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

class myString
{
private:
	char* data;
	size_t size;
	size_t capacity;

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

	void resize(size_t size)
	{
		while (this->capacity < size)
		{
			this->capacity *= 2;
		}
		
		int newCapcacity = this->capacity;
		char* newData = new char[newCapcacity + 1];

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

	void Append(const char symbol);

	void Append(const char* data);

	void Append(const myString& other);

	void SetString(const char* data);

	void SetSize(const size_t size);

	void SetCapacity(const size_t size);

	char* GetData() const;

	const size_t Length() const;

	const char operator[](const int index) const;

	char operator[](const int index);

	myString& operator=(const myString& other);

	friend std::ostream& operator<<(std::ostream& out, const myString& str);

	friend std::istream& operator>>(std::istream& in, myString& str);
};
