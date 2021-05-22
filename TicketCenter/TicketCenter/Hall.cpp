#include <fstream>
#include <stdexcept>
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
	setRows(rows);
	setSeatsOnRow(seatsOnRows);
	setTotalSeats(totalSeats);
	createMatrix();
}

Hall::~Hall()
{
	for (int i = 0; i < rows; i++)
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
	matrixHall = 0;
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

void Hall::copyMatrix(int** otherMatrix, const int& previousRows)
{
	for (int i = 0; i < previousRows; i++)
	{
		delete[] matrixHall[i];
	}

	delete[] matrixHall;

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
	try
	{
		if ((totalSeats == 0 || totalSeats > 2500) || (rows * seatsOnRow != totalSeats))
		{
			throw std::invalid_argument("Invalid argument exceptioin: Hall too large or invalid digit!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	this->totalSeats = totalSeats;
}

void Hall::setRows(const unsigned int rows)
{
	try
	{
		if (rows == 0 || rows > 50)
		{
			throw std::invalid_argument("Invalid argument exceptioin: Too much rows or invalid digit!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	this->rows = rows;
}

void Hall::setSeatsOnRow(const unsigned int seatsOnRow)
{
	try
	{
		if (seatsOnRow == 0 || seatsOnRow > 50)
		{
			throw std::invalid_argument("Invalid argument exceptioin: Too much seats on a row or invalid digit!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(0);
	}

	this->seatsOnRow = seatsOnRow;
}

void Hall::showMatrix() const
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

	std::cout << "Legend: " << std::endl;
	std::cout << "0 - free seat" << std::endl;
	std::cout << "1 - booked seat" << std::endl;
	std::cout << "2 - bought seat" << std::endl;
}

void Hall::changeSeatBehavior(const unsigned int& row, const unsigned int& seat, const unsigned int& code)
{
	try
	{
		if (row > rows || seat > seatsOnRow)
		{
			throw std::invalid_argument("Invalid argument exceptioin: Invalid seat!");
		}
		if (code < 0 || code > 2)
		{
			throw std::invalid_argument("Invalid argument exceptioin: Code is invalid!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
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
		int previousRows = rows;
		setHallName(other.getHallName());
		setRows(other.getRows());
		setSeatsOnRow(other.getSeatsOnRow());
		setTotalSeats(other.getTotalSeats());
		copyMatrix(other.getMatrixHall(), previousRows);
	}

	return *this;
}

void Hall::writeOnfFile(const char* fileName)
{
	std::ofstream myFile(fileName, std::ios::app);

	myFile << "Hall" << std::endl;
	myFile << hallName << std::endl;
	myFile << totalSeats << std::endl;
	myFile << rows << std::endl;
	myFile << seatsOnRow << std::endl;

	myFile.close();
}

std::ostream& operator<<(std::ostream& out, const Hall& hall)
{
	out << hall.getHallName() << std::endl;
	out << "Total seats: " << hall.getTotalSeats() << std::endl;
	out << "Rows: " << hall.getRows() << std::endl;
	out << "Seats on a row: " << hall.getSeatsOnRow() << std::endl;

	return out;
}
