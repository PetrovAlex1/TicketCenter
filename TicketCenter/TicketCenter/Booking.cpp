#include "Booking.h"

Booking::Booking()
{
	row = 0;
	seat = 0;
}

Booking::Booking(const myString& _note, const int& _row, const int& _seat)
{
	setNote(_note);
	setRow(_row);
	setSeat(_seat);
}

void Booking::setNote(const myString& _note)
{
	note = _note;
}

void Booking::setRow(const int& _row)
{
	row = _row;
}

void Booking::setSeat(const int& _seat)
{
	seat = _seat;
}

const myString& Booking::getNote() const
{
	return note;
}

int Booking::getRow() const
{
	return row;
}

int Booking::getSeat() const
{
	return seat;
}

std::ostream& operator<<(std::ostream& out, const Booking booking)
{
	out << booking.getNote() << " for seat on row " << booking.getRow() << " and seat " << booking.getSeat();
	out << std::endl;

	return out;
}
