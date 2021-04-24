#pragma once
#include <iostream>
#include "myString.h"

class Hall
{
private:
	myString hallName;
	int totalSeats;
	int rows;
	int seatsOnRow;
	int** matrixHall;

public:

	Hall();

	~Hall();

	void print();

	void initialize(const myString& hallName, const int totalSeats, const int rows, const int seatsOnRows);

	void createMatrix(); 

	void setHallName(const myString& hallName);

	void setTotalSeats(const int totalSets);

	void setRows(const int rows);

	void setSeatsOnRow(const int seatsOnRow);

	myString getHallName() const;

	int getTotalSeats() const;

	int getRows() const;

	int getSeatsOnRow() const;

	Hall& operator=(const Hall& other);

	friend std::ostream& operator<<(std::ostream& out, const Hall& hall);
};