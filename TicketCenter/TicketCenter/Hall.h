#pragma once
#include <iostream>

class Hall
{
private:
	char* hallName;
	int totalSeats;
	int rows;
	int seatsOnRow;
public:

	Hall();

	~Hall();

	void Print();

	void Initialize(const char* hallName, const int totalSeats, const int rows, const int seatsOnRows);

	void setHallName(const char* hallName);

	void setTotalSeats(const int totalSets);

	void setRows(const int rows);

	void setSeatsOnRow(const int seatsOnRow);

	char* getHallName() const;

	int getTotalSeats() const;

	int getRows() const;

	int getSeatsOnRow() const;

	Hall& operator=(const Hall& other);

	friend std::ostream& operator<<(std::ostream& out, const Hall& hall);
};