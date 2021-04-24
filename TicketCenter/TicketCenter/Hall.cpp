#include "Hall.h"

Hall::Hall()
{
	this->totalSeats = 0;
	this->rows = 0;
	this->seatsOnRow = 0;
}

Hall::~Hall()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] this->matrixHall[i];
	}

	delete[] this->matrixHall;
}

void Hall::print()
{
	std::cout << this->getHallName() << " with " << this->getTotalSeats() << " with rows " << this->getRows() << " with seats on a rows " << this->getSeatsOnRow() << std::endl;
}

void Hall::initialize(const myString& hallName, const int totalSeats, const int rows, const int seatsOnRows)
{
	this->setHallName(hallName);
	this->setTotalSeats(totalSeats);
	this->setRows(rows);
	this->setSeatsOnRow(seatsOnRows);
	this->createMatrix();
}

void Hall::createMatrix()
{
	this->matrixHall = new int* [this->rows];

	for (int i = 0; i < this->rows; i++)
	{
		this->matrixHall[i] = new int[this->seatsOnRow];
	}

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->seatsOnRow; j++)
		{
			this->matrixHall[i][j] = 0;
		}
	}
}

void Hall::setHallName(const myString& hallName)
{
	this->hallName = hallName;
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

myString Hall::getHallName() const
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