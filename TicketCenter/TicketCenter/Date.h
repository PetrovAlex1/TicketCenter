#pragma once
#include <iostream>
#include "myString.h"

enum class Month
{
	January,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

class Date
{
private:
	unsigned int day;
	Month month;
	unsigned int year;

public:

	Date();

	Date(const unsigned int& day, 
		const unsigned int& month,
		const unsigned int& year);

	void setDate(myString& date);

	void const showDate() const;

	void setDay(const unsigned int& day);

	void setMonth(const unsigned int& month);

	void setYear(const unsigned int& year);

	unsigned int getDay() const;

	unsigned int getMonth() const;

	unsigned int getYear() const;

	bool checkYearLeap() const;

	bool validateDate() const;

	bool operator==(const Date& otherDate) const;

	bool operator<=(const Date& otherDate) const;

	bool operator>=(const Date& otherDate) const;

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};