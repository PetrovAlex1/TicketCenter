#include <stdexcept>
#include "Date.h"
#include "myVector.h"
#include "myString.h"

bool Date::validateDate() const
{
	bool result = false;

	if (month == Month::January || //For months with 31 days
		month == Month::March ||
		month == Month::May ||
		month == Month::July ||
		month == Month::August ||
		month == Month::October ||
		month == Month::December)
	{
		if (this->day > 0 && this->day <= 31)
		{
			return true;
		}
	}
	else if (this->month == Month::April || //For months with 30 days
		month == Month::June ||
		month == Month::September ||
		month == Month::November)
	{
		if (day > 0 && day <= 30)
		{
			return true;
		}
	}
	else
	{
		if (checkYearLeap())
		{
			if (day > 0 && day <= 29)
			{
				return true;
			}
		}
		else //For February
		{
			if (day > 0 && day <= 28)
			{
				return true;
			}
		}
	}

	return result;
}

bool Date::checkYearLeap() const
{
	int thirdDigit = (this->year % 100) / 10;
	int fourthDigit = this->year % 10;

	if (thirdDigit == 0 && fourthDigit == 0)
	{
		if (this->year % 400 == 0)
		{
			return true;
		}
	}
	else if (year % 4 == 0)
	{
		return true;
	}

	return false;
}

Date::Date()
{
	day = 1;
	month = Month::January;
	year = 0;
}

Date::Date(const unsigned int& day, const unsigned int& month, const unsigned int& year)
{
	setDay(day);
	setMonth(month);
	setYear(year);

	try
	{
		if (!validateDate())
		{
			throw std::invalid_argument("Invalid argument exception: Date is invalid!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}
}

void Date::setDate(myString& date)
{
	myVector<myString> arguments;

	arguments = date.splitBy('-');

	//check input 
	try
	{
		for (int i = 0; i < 3; i++)
		{
			myString currentNumber = arguments[i];
			int count = i > 0 ? 2 : 4;

			for (int j = 0; j < count; j++)
			{
				if (currentNumber[j] < '0' || currentNumber[j] > '9')
				{
					throw std::invalid_argument("Invalid argument exception: Input date is invalid!");
				}

				break;
			}
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	setDay(arguments[2].toInt());
	setMonth(arguments[1].toInt());
	setYear(arguments[0].toInt());

	try
	{
		if (!validateDate())
		{
			throw std::invalid_argument("Date is invalid!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
	}
}

void const Date::showDate() const
{
	if (validateDate())
	{
		std::cout << year << "-" << (int)month + 1 << "-" << day << std::endl;
	}
}

void Date::setDay(const unsigned int& day)
{
	try
	{
		if (day > 31)
		{
			throw std::invalid_argument("Day is invalid!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	this->day = day;
}

void Date::setMonth(const unsigned int& _month)
{
	try
	{
		if (_month == 1)
		{
			month = Month::January;
		}
		else if (_month == 2)
		{
			month = Month::February;
		}
		else if (_month == 3)
		{
			month = Month::March;
		}
		else if (_month == 4)
		{
			month = Month::April;
		}
		else if (_month == 5)
		{
			month = Month::May;
		}
		else if (_month == 6)
		{
			month = Month::June;
		}
		else if (_month == 7)
		{
			month = Month::July;
		}
		else if (_month == 8)
		{
			month = Month::August;
		}
		else if (_month == 9)
		{
			month = Month::September;
		}
		else if (_month == 10)
		{
			month = Month::October;
		}
		else if (_month == 11)
		{
			month = Month::November;
		}
		else if (_month == 12)
		{
			month = Month::December;
		}
		else
		{
			throw std::invalid_argument("Month is invalid!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}
}

void Date::setYear(const unsigned int& year)
{
	try
	{
		if (year > 3000)
		{
			throw std::invalid_argument("Year is invalid!");
		}
	}
	catch (const std::invalid_argument& err)
	{
		std::cerr << err.what() << std::endl;
		exit(2);
	}

	this->year = year;
}

unsigned int Date::getDay() const
{
	return day;
}

unsigned int Date::getMonth() const
{
	return (int)month + 1;
}

unsigned int Date::getYear() const
{
	return year;
}

bool Date::operator==(const Date& otherDate) const
{
	if (day == otherDate.day
		&& month == otherDate.month
		&& year == otherDate.year)
	{
		return true;
	}

	return false;
}

bool Date::operator<=(const Date& otherDate) const
{
	if (year == otherDate.getYear())
	{
		if (((int)month + 1) == otherDate.getMonth())
		{
			if (day == otherDate.getDay())
			{
				return true;
			}
			else if (day < otherDate.getDay())
			{
				return true;
			}
		}
		else if (((int)month + 1) < otherDate.getMonth())
		{
			return true;
		}
	}
	else if (year < otherDate.getYear())
	{
		return true;
	}

	return false;
}

bool Date::operator>=(const Date& otherDate) const
{
	if (year == otherDate.getYear())
	{
		if (((int)month + 1) == otherDate.getMonth())
		{
			if (day == otherDate.getDay())
			{
				return true;
			}
			else if (day > otherDate.getDay())
			{
				return true;
			}
		}
		else if (((int)month + 1) > otherDate.getMonth())
		{
			return true;
		}
	}
	else if (year > otherDate.getYear())
	{
		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.getYear() << "-" << date.getMonth() << "-" << date.getDay();

	return out;
}
