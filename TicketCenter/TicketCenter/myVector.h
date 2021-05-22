#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>

class myVector
{
private:
	T* data;
	int size;
	int capacity;

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

	int length() const
	{
		return size;
	}

	void add(const T& element)
	{
		if (this->size + 1 >= this->capacity)
		{
			this->resize();
		}

		this->data[this->size++] = element;
	}

	const T& operator[](const int index) const
	{
		try
		{
			if (index > this->size)
			{
				throw std::out_of_range("Out of range exception: Index out of range exception!");
			}
		}
		catch (const std::out_of_range& err)
		{
			std::cerr << err.what() << std::endl;
			exit(2);
		}

		return this->data[index];
	}

	T& operator[](const int index)
	{
		try
		{
			if (index > this->size)
			{
				throw std::out_of_range("Out of range exception: Index out of range exception!");
			}
		}
		catch (const std::out_of_range& err)
		{
			std::cerr << err.what() << std::endl;
			exit(2);
		}

		return this->data[index];
	}

	myVector& operator=(const myVector& other)
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
			this->add(other.data[i]);
		}

		return *this;
	}

	myVector operator+(const myVector& other)
	{
		myVector<T> result(*this);
		result += other;

		return result;
	}

	void print() const
	{
		for (int i = 0; i < this->size; i++)
		{
			std::cout << this->data[i];
		}

		std::cout << std::endl;
	}

	~myVector()
	{
		this->destroy();
	}
};