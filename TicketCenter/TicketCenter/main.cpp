#include <iostream>
#include "Hall.h"
#include "myVector.h"
#include "myString.h"


int main()
{
	myString str;
	str.SetString("addevent 22.10.2021 Omega Triviat");
	myVector<myString> arguments;
	arguments.Split(str);
	arguments.Print();
	return 0;
}