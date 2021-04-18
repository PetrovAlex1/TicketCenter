#include "Date.h"

Date::Date()
{
	this->day = 1;
	this->month = Month::January;
	this->year = 2021;
}

Date::Date(const int& day, const int& month, const int& year)
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);
}

void Date::setDate(const char* date)
{
	int j = 0;

	for (int i = 0; i < 3; i++)
	{
		char currentData[2];

		while (date[j] != '.')
		{

		}
	}
}

void Date::setDay(const int& day)
{
	if (day < 1 || day > 31)
	{
		std::cout << "Day is invalid!" << std::endl;
		return;
	}

	this->day = day;
}

void Date::setMonth(const int& month)
{
	if (month == 1)
	{
		this->month = Month::January;
	}
	else if (month == 2)
	{
		this->month = Month::February;
	}
	else if (month == 3)
	{
		this->month = Month::March;
	}
	else if (month == 4)
	{
		this->month = Month::April;
	}
	else if (month == 5)
	{
		this->month = Month::May;
	}
	else if (month == 6)
	{
		this->month = Month::June;
	}
	else if (month == 7)
	{
		this->month = Month::July;
	}
	else if (month == 8)
	{
		this->month = Month::August;
	}
	else if (month == 9)
	{
		this->month = Month::September;
	}
	else if (month == 10)
	{
		this->month = Month::October;
	}
	else if (month == 11)
	{
		this->month = Month::November;
	}
	else if (month == 12)
	{
		this->month = Month::December;
	}
	else
	{
		std::cout << "Invalid month!" << std::endl;
		return;
	}
}

void Date::setYear(const int& year)
{
	if (year < 2021)
	{
		std::cout << "Year is invalid!" << std::endl;
		return;
	}

	this->year = year;
}




