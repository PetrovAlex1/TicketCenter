#include <iostream>
#include "Hall.h"
#include "myVector.h"
#include "myString.h"


int main()
{
	myString str;
	str.setString("addevent 22.10.2021 Omega Triviat");
	myVector<myString> arguments;
	arguments.split(str);
	arguments.print();
	return 0;
}