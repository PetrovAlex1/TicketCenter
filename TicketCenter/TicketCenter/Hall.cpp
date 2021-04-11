#include "Hall.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma warning(disable:4996)

Hall::Hall()
{
	this->hallName = nullptr;
	this->totalSeats = 0;
	this->rows = 0;
	this->seatsOnRow = 0;
}

Hall::~Hall()
{
	delete[] this->hallName;
	hallName = nullptr;
}

void Hall::Print()
{
	std::cout << this->getHallName() << " with " << this->getTotalSeats() << " with rows " << this->getRows() << " with seats on a rows " << this->getSeatsOnRow() << std::endl;
}

void Hall::Initialize(const char* hallName, const int totalSeats, const int rows, const int seatsOnRows)
{
	this->setHallName(hallName);
	this->setTotalSeats(totalSeats);
	this->setRows(rows);
	this->setSeatsOnRow(seatsOnRows);
}

void Hall::setHallName(const char* hallName)
{
	delete[] this->hallName;
	this->hallName = new char[strlen(hallName) + 1];
	strcpy(this->hallName, hallName);
}

void Hall::setTotalSeats(const int totalSeats)
{
	this->totalSeats = totalSeats;
}

void Hall::setRows(const int rows)
{
	this->rows = rows;
}

void Hall::setSeatsOnRow(const int seatsOnRow)
{
	this->seatsOnRow = seatsOnRow;
}

char* Hall::getHallName() const
{
	return this->hallName;
}

int Hall::getTotalSeats() const
{
	return this->totalSeats;
}

int Hall::getRows() const
{
	return this->rows;
}

int Hall::getSeatsOnRow() const
{
	return this->seatsOnRow;
}

Hall& Hall::operator=(const Hall& other)
{
	if (this != &other)
	{
		delete[] this->hallName;
		this->rows = 0;
		this->seatsOnRow = 0;
		this->totalSeats = 0;
	}

	this->setHallName(other.getHallName());
	this->setTotalSeats(other.getTotalSeats());
	this->setRows(other.getRows());
	this->setSeatsOnRow(other.getSeatsOnRow());

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Hall& hall)
{
	out << "Hall name " << hall.getHallName();
	
	return out;
}