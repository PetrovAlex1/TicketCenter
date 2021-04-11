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

	void resize(size_t newSize)
	{
		if (newSize < 0)
		{
			std::cout << "Invalid size!" << std::endl;
			return;
		}

		this->capacity *= 2;

		T* newData = new T[capacity];

		for (int i = 0; i < this->size; i++)
		{
			newData[i] = this->data[i];
		}

		this->size = newSize;
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

	size_t Length()
	{
		return this->size;
	}

	void Add(T element)
	{
		if (this->size + 1 >= this->capacity)
		{
			this->resize(this->size + 1);
		}

		this->data[this->size] = element;
		this->size++;
	}

	const T operator[](const int index) const
	{
		return this->data[index];
	}

	T operator[](const int index)
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