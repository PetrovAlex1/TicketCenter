#include "Hall.h"

Hall::Hall()
{
	totalSeats = 4;
	rows = 2;
	seatsOnRow = 2;
	createMatrix();
}

Hall::Hall(const myString& hallName, const unsigned int totalSeats, const unsigned int rows, const unsigned int seatsOnRows)
{
	setHallName(hallName);
	setTotalSeats(totalSeats);
	setRows(rows);
	setSeatsOnRow(seatsOnRows);
	createMatrix();
}

Hall::~Hall()
{
	for (int i = 0; i < this->rows; i++)
	{
		delete[] matrixHall[i];
	}

	delete[] matrixHall;
}

void Hall::print()
{
	std::cout << getHallName() << " with " << getTotalSeats() << " with rows " << getRows() << " with seats on a rows " << getSeatsOnRow() << std::endl;
}

void Hall::createMatrix() //private
{
	matrixHall = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		matrixHall[i] = new int[seatsOnRow];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < seatsOnRow; j++)
		{
			matrixHall[i][j] = 0;
		}
	}
}

void Hall::copyMatrix(int** otherMatrix)
{
	this->~Hall();
	createMatrix();

	int rows = getRows();
	int cols = getSeatsOnRow();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrixHall[i][j] = otherMatrix[i][j];
		}
	}
}

void Hall::setHallName(const myString& hallName)
{
	this->hallName = hallName;
}

void Hall::setTotalSeats(const unsigned int totalSeats)
{
	this->totalSeats = totalSeats;
}

void Hall::setRows(const unsigned int rows)
{
	this->rows = rows;
}

void Hall::setSeatsOnRow(const unsigned int seatsOnRow)
{
	this->seatsOnRow = seatsOnRow;
}

void Hall::showMatrix()
{
	int rows = getRows();
	int cols = getSeatsOnRow();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << matrixHall[i][j] << " ";
		}

		std::cout << std::endl;
	}
}

void Hall::changeSeatBehavior(const unsigned int& row, const unsigned int& seat, const unsigned int& code)
{
	if (row > rows || seat > seatsOnRow)
	{
		std::cout << "Invalid seat!" << std::endl;
	}
	if (code < 0 || code > 2)
	{
		std::cout << "Code is invalid!" << std::endl;
	}

	matrixHall[row][seat] = code;
}

const myString& Hall::getHallName() const
{
	return hallName;
}

unsigned int Hall::getTotalSeats() const
{
	return totalSeats;
}

unsigned int Hall::getRows() const
{
	return rows;
}

unsigned int Hall::getSeatsOnRow() const
{
	return seatsOnRow;
}

int** Hall::getMatrixHall() const
{
	return matrixHall;
}

Hall& Hall::operator=(const Hall& other)
{
	if (this != &other)
	{
		setHallName(other.getHallName());
		setTotalSeats(other.getTotalSeats());
		setRows(other.getRows());
		setSeatsOnRow(other.getSeatsOnRow());
		copyMatrix(other.getMatrixHall());
	}

	return *this;
}

