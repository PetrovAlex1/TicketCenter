#pragma once
#include <iostream>
#include "myString.h"

class Booking
{
private:
	myString note;
	int row;
	int seat;
public:

	Booking();

	Booking(const myString& _note, const int& _row, const int& _seat);

	void setNote(const myString& _note);

	void setRow(const int& _row);

	void setSeat(const int& _seat);

	const myString& getNote() const;

	int getRow() const;

	int getSeat() const;

	friend std::ostream& operator<<(std::ostream& out, const Booking booking);
};