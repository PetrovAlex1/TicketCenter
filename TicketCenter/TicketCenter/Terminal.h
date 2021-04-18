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
	void ExpectCommand();

	void SetCommand(const myString& cmd);

	myString GetCommand() const;
};

void Terminal::SetCommand(const myString& cmd)
{
	this->command = cmd;
}

myString Terminal::GetCommand() const
{
	return this->command;
}

void Terminal::ExpectCommand()
{
	std::cout << "Type your command: ";
	myString cmd;
	std::cin >> cmd;
	this->SetCommand(cmd);
}

void StartUp()
{
	std::cout << "Welcome to Ticket center!" << std::endl;
	
	Terminal t;

	while (true)
	{
		t.ExpectCommand();

	}
}
