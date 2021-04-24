#pragma once
#include <iostream>
#include "myString.h"
#include "myVector.h"

class Terminal
{
private:
	myString command;
	myString input;
	myVector<myString> arguments;
public:
	void expectCommand();

	void setCommand(const myString& cmd);

	myString getCommand() const;

	myVector<myString> getArguments() const;

	myString getInput() const;
};

void Terminal::setCommand(const myString& cmd)
{
	this->command = cmd;
}

inline myVector<myString> Terminal::getArguments() const
{
	return this->arguments;
}

inline myString Terminal::getInput() const
{
	return this->input;
}

myString Terminal::getCommand() const
{
	return this->command;
}

void Terminal::expectCommand()
{
	std::cout << "Type your command: ";
	std::cin >> this->input;
	this->arguments = this->input.splitBy(' ');
	this->setCommand(this->arguments[0]);
}

void startUp()
{
	std::cout << "Welcome to Ticket center!" << std::endl;

	Terminal t;

	while (true)
	{
		t.expectCommand();
		myString command{ t.getCommand() };

		if (command == "addevent")
		{

		}
		else if (command == "addhall")
		{

		}
		else if (command == "freeseats")
		{

		}
		else if (command == "book")
		{

		}
		else if (command == "unbook")
		{

		}
		else if (command == "buy")
		{

		}
		else if (command == "bookings")
		{

		}
		else if (command == "check")
		{

		}
		else if (command == "report")
		{

		}
		else
		{
			std::cout << "Command is invalid! Please try again" << std::endl;
		}
	}
}
