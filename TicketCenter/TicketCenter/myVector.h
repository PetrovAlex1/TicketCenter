#pragma once
#include <iostream>

template <typename T>

class myVector
{
private:
	T* data;
	size_t size;
	size_t capacity;

	void copy(const myVector<T>& other)
	{
		this->data = new T[other.capacity];
		this->size = other.size;
		this->capacity = other.capacity;

		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = other.data[i];
		}
	}

	void resize()
	{
		this->capacity *= 2;

		T* newData = new T[capacity];

		for (int i = 0; i < this->size; i++)
		{
			newData[i] = this->data[i];
		}

		delete[] this->data;
		this->data = newData;
	}

	void destroy()
	{
		delete[] this->data;
		this->data = nullptr;
	}

public:

	myVector()
	{
		this->size = 0;
		this->capacity = 4;
		this->data = new T[capacity];
	}

	myVector(const myVector& other)
	{
		this->copy(other);
	}

	size_t Size()
	{
		return this->size;
	}

	int CountWhiteSpaces(const myString& str)
	{
		int countWS = 0;
		int i = 0;

		while (str[i] != '\0')
		{
			if (str[i] == ' ')
			{
				countWS++;
			}

			i++;
		}

		return countWS;
	}

	myVector& Split(myString& str)
	{
		int i = 0;
		int countWS = CountWhiteSpaces(str);//count whitespaces

		this->destroy();
		this->data = new myString[countWS + 1];
		int j = 0;

		for (i = 0; i < countWS + 1; i++)
		{
			myString currentString;

			while (str[j] != ' ' && str[j] != '\0')
			{
				currentString.Append(str[j]);
				j++;
			}

			this->Add(currentString);
			j++;
		}

		return *this;
	}

	void Add(const T& element)
	{
		if (this->size + 1 >= this->capacity)
		{
			this->resize();
		}

		this->data[this->size] = element;
		this->size++;
	}

	const T& operator[](const int index) const
	{
		return this->data[index];
	}

	T& operator[](const int index)
	{
		return this->data[index];
	}

	myVector operator=(const myVector& other)
	{
		if (this != &other)
		{
			this->destroy();
			this->copy(other);
		}

		return *this;
	}

	myVector& operator+=(const myVector& other)
	{
		int otherSize = other.size;

		for (int i = 0; i < otherSize; i++)
		{
			this->Add(other.data[i]);
		}

		return *this;
	}

	myVector operator+(const myVector& other)
	{
		myVector<T> result(*this);
		result += other;

		return result;
	}

	void Print()
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->data[i] << " ";
		}

		std::cout << std::endl;
	}

	~myVector()
	{
		this->destroy();
	}
};