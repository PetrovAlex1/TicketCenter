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

	void Print();

	void Initialize(const myString& hallName, const int totalSeats, const int rows, const int seatsOnRows);

	void CreateMatrix(); 

	void SetHallName(const myString& hallName);

	void SetTotalSeats(const int totalSets);

	void SetRows(const int rows);

	void SetSeatsOnRow(const int seatsOnRow);

	myString GetHallName() const;

	int GetTotalSeats() const;

	int GetRows() const;

	int GetSeatsOnRow() const;

	Hall& operator=(const Hall& other);

	friend std::ostream& operator<<(std::ostream& out, const Hall& hall);
};