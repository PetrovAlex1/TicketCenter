#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Hall.h"
#include "myVector.h"
#include "myString.h"
#include "Date.h"
#include "TicketCenter.h"
#include "Event.h"
#include "Booking.h"

TEST_CASE("myVector Testing")
{
	myVector<int> vect1;

	CHECK(vect1.length() == 0);
	//adding elements
	vect1.add(1);
	vect1.add(2);
	vect1.add(3);

	CHECK(vect1.length() == 3);
	//check operator [] to get the value
	CHECK(vect1[0] == 1);
	CHECK(vect1[1] == 2);

	vect1[2] = 5;
	//check operator [] for changing the value
	CHECK(vect1[2] == 5);

	myVector<int> vect2;
	vect2.add(7);
	vect2.add(8);
	vect2.add(9);
	vect2.add(12);

	vect1 = vect2;

	CHECK(vect1.length() == 4);
	CHECK(vect1[3] == 12);
}

TEST_CASE("myString Testing")
{
	myString str1;
	str1.setString("Alex");

	//check setString methoä
	//check operator ==
	CHECK(str1 == "Alex");

	str1.append(" Ivanov");
	myString familyName;
	familyName.setString(" Petrov");
	str1.append(familyName);

	//check append method and their overrideings
	CHECK(str1 == "Alex Ivanov Petrov");

	myString integer;
	integer.setString("1");

	//check toInt method
	CHECK(integer.toInt() == 1);

	unsigned int a = 23;

	integer.fromInt(a);

	//check fromInt method
	CHECK(integer.toInt() == 123);

	myVector<myString> arguments;
	arguments = str1.splitBy(' ');

	//check splitBy method
	CHECK(arguments[1] == "Ivanov");
	//check operator[] to get value
	CHECK(str1[0] == 'A');
	//check length method
	CHECK(arguments[0].length() == 4);
	//check isFromLetters method
	CHECK(arguments[0].isFormLetters());
}

TEST_CASE("Date Testing")
{
	unsigned int day1 = 23;
	unsigned int month1 = 3;
	unsigned int year1 = 2021;
	unsigned int day2 = 22;
	unsigned int month2 = 3;
	unsigned int year2 = 2021;

	Date date1{ day1, month1, year1 };
	Date date2{ day2, month2, year2 };
	Date date3;
	date3 = date1;
	CHECK(date1 >= date2);
	CHECK(date1 == date3);
}

TEST_CASE("Event Testing")
{
	myString eventName;
	myString hallName;
	hallName.setString("Omega");
	eventName.setString("Traviat");

	unsigned int totalSeats = 25;
	unsigned int rows = 5;
	unsigned int seatsOnRow = 5;
	Hall omega{ hallName, totalSeats, rows, seatsOnRow };

	unsigned int day = 23;
	unsigned int month = 3;
	unsigned int year = 2021;
	Date date{ day, month, year };

	Event traviat{ eventName, omega, date };

	unsigned int ticketRow = 1;
	unsigned int ticketSeat = 1;
	traviat.buyTicket(ticketRow, ticketSeat);

	//check buyTicket method
	CHECK(traviat.getCodes()[0] == "Tra11");
	CHECK(traviat.getHall().getMatrixHall()[1][1] == 2);

	unsigned int ticketRowBooking = 2;
	unsigned int ticketSeatBooking = 2;
	myString note;
	note.setString("expensiveBro");

	traviat.bookTicket(ticketRowBooking, ticketSeatBooking, note);

	//check bookTicket method
	CHECK(traviat.getBookings()[0].getNote() == "expensiveBro");
	CHECK(traviat.getHall().getMatrixHall()[2][2] == 1);

	//check unbookTicket method
	traviat.unbookTicket(ticketRowBooking, ticketSeatBooking);
	CHECK(traviat.getHall().getMatrixHall()[2][2] == 0);

	//check getFreeSeats method
	CHECK(traviat.getFreeSeats() == 24);
}

TEST_CASE("Hall Testing")
{
	myString hallName;
	hallName.setString("Omega");
	unsigned int totalSeats = 25;
	unsigned int rows = 5;
	unsigned int seatsOnRow = 5;

	Hall omega{ hallName, totalSeats, rows, seatsOnRow };

	unsigned int row = 1;
	unsigned int seat = 1;
	unsigned int code = 2;

	omega.changeSeatBehavior(row, seat, 2);//ticket was bought

	//check changeSeatBehavior method
	CHECK(omega.getMatrixHall()[1][1] == 2);
}