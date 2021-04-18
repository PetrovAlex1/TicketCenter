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

void Hall::Print()
{
	std::cout << this->GetHallName() << " with " << this->GetTotalSeats() << " with rows " << this->GetRows() << " with seats on a rows " << this->GetSeatsOnRow() << std::endl;
}

void Hall::Initialize(const myString& hallName, const int totalSeats, const int rows, const int seatsOnRows)
{
	this->SetHallName(hallName);
	this->SetTotalSeats(totalSeats);
	this->SetRows(rows);
	this->SetSeatsOnRow(seatsOnRows);
	this->CreateMatrix();
}

void Hall::CreateMatrix()
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

void Hall::SetHallName(const myString& hallName)
{
	this->hallName = hallName;
}

void Hall::SetTotalSeats(const int totalSeats)
{
	this->totalSeats = totalSeats;
}

void Hall::SetRows(const int rows)
{
	this->rows = rows;
}

void Hall::SetSeatsOnRow(const int seatsOnRow)
{
	this->seatsOnRow = seatsOnRow;
}

myString Hall::GetHallName() const
{
	return this->hallName;
}

int Hall::GetTotalSeats() const
{
	return this->totalSeats;
}

int Hall::GetRows() const
{
	return this->rows;
}

int Hall::GetSeatsOnRow() const
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

	this->SetHallName(other.GetHallName());
	this->SetTotalSeats(other.GetTotalSeats());
	this->SetRows(other.GetRows());
	this->SetSeatsOnRow(other.GetSeatsOnRow());

	return *this;
}

std::ostream& operator<<(std::ostream& out, const Hall& hall)
{
	out << "Hall name " << hall.GetHallName();

	return out;
}