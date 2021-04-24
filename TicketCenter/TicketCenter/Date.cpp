#include "Date.h"
#include "myVector.h"
#include "myString.h"

int stringToInt(myString& str)
{
	int result = 0;
	int length = str.length();

	for (int i = 0; i < length; i++)
	{
		int currentDigit = str[i] - 48;
		result = currentDigit + result * 10;
	}

	return result;
}

bool Date::validateDate()
{
	bool result = false;

	if ((int)this->month == 0 || //For months with 31 days
		(int)this->month == 2 ||
		(int)this->month == 4 ||
		(int)this->month == 6 ||
		(int)this->month == 7 ||
		(int)this->month == 9 ||
		(int)this->month == 11)
	{
		if (this->day > 0 && this->day <= 31)
		{
			result = true;
		}
	}
	else if ((int)this->month == 3 || //For months with 30 days
		(int)this->month == 5 ||
		(int)this->month == 8 ||
		(int)this->month == 10)
	{
		if (this->day > 0 && this->day <= 30)
		{
			result = true;
		}
	}
	else
	{
		if (this->yearIsLeap)
		{
			if (this->day > 0 && this->day < 29)
			{
				result = true;
			}
		}
		else //For February
		{
			if (this->day > 0 && this->day < 28)
			{
				result = true;
			}
		}
	}

	return result;
}

void Date::checkYearLeap()
{
	this->yearIsLeap = false;

	int thirdDigit = (this->year % 100) / 10;
	int fourthDigit = this->year % 10;

	if (thirdDigit == 0 && fourthDigit == 0)
	{
		if (this->year % 400 == 0)
		{
			this->yearIsLeap = true;
		}
	}
	else if (year % 4 == 0)
	{
		this->yearIsLeap = true;
	}
}

Date::Date()
{
	this->day = 1;
	this->month = Month::January;
	this->year = 2021;
	this->yearIsLeap = false;
}

Date::Date(const int& day, const int& month, const int& year)
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);
	this->dateIsValid = this->validateDate();

	if (!this->dateIsValid)
	{
		std::cout << "Date is invalid!" << std::endl;
	}
}

void Date::setDate(const char* date)
{
	myString str;
	str.setString(date);
	myVector<myString> arguments;
	arguments = str.splitBy('.');

	this->setDay(stringToInt(arguments[0]));
	this->setMonth(stringToInt(arguments[1]));
	this->setYear(stringToInt(arguments[2]));
	this->dateIsValid = this->validateDate();

	if (!this->dateIsValid)
	{
		std::cout << "Date is invalid!" << std::endl;
	}
}

void const Date::showDate() const
{
	if (this->dateIsValid)
	{
		std::cout << this->day << "." << (int)this->month + 1 << "." << this->year;
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

Date& Date::operator=(const Date& other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
}





