#pragma once
#include <iostream>
#include "myString.h"

class Hall
{
private:
	myString hallName;
	unsigned int totalSeats;
	unsigned int rows;
	unsigned int seatsOnRow;
	int** matrixHall;

	void createMatrix();
	void copyMatrix(int** otherMatrix, const int& previousRows);
public:

	Hall();

	Hall(const myString& hallName, const unsigned int totalSeats, const unsigned int rows, const unsigned int seatsOnRows);

	~Hall();

	void print();

	void showMatrix() const;

	void changeSeatBehavior(const unsigned int& row, const unsigned int& seat, const unsigned int& code);

	void setHallName(const myString& hallName);

	void setTotalSeats(const unsigned int totalSets);

	void setRows(const unsigned int rows);

	void setSeatsOnRow(const unsigned int seatsOnRow);

	const myString& getHallName() const;

	unsigned int getTotalSeats() const;

	unsigned int getRows() const;

	unsigned int getSeatsOnRow() const;

	int** getMatrixHall() const;

	Hall& operator=(const Hall& other);

	friend std::ostream& operator<<(std::ostream& out, const Hall& hall);

	void writeOnfFile(const char* fileName);
};