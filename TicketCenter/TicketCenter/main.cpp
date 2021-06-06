#include <iostream>
#include "TicketCenterEngine.h"

int main()
{
	std::cout << "Enter name of ticket center: ";
	myString ticketCenterName;
	std::cin >> ticketCenterName;

	TicketCenter ticketCenter{ ticketCenterName };
	ticketCenter.startUp();

	return 0;
}