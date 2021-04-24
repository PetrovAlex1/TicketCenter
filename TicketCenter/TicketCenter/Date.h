#pragma once
#include <iostream>

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
	int day;
	Month month;
	int year;
	bool yearIsLeap;
	bool dateIsValid;

	bool validateDate();
	void checkYearLeap();

public:

	Date();

	Date(const int& day, const int& month, const int& year);

	void setDate(const char* date);

	void const showDate() const;

	void setDay(const int& day);

	void setMonth(const int& month);

	void setYear(const int& year);

	Date& operator=(const Date& other);
};