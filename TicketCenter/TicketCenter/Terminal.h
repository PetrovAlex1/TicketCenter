#pragma once
#include <iostream>
#include "myString.h"
#include "myVector.h"

class Terminal
{
private:
	myString command;
	myVector<myString> arguments;
public:
	void expectCommand();

	void setCommand(const myString& cmd);

	myString getCommand() const;
};

void Terminal::setCommand(const myString& cmd)
{
	this->command = cmd;
}

myString Terminal::getCommand() const
{
	return this->command;
}

void Terminal::expectCommand()
{
	std::cout << "Type your command: ";
	myString cmd;
	std::cin >> cmd;
	this->setCommand(cmd);
}

void startUp()
{
	std::cout << "Welcome to Ticket center!" << std::endl;

	Terminal t;

	while (true)
	{
		t.expectCommand();

	}
}
