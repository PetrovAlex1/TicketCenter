#include <iostream>

#include "Laptop.h" 
#include "Car.h" 
#include "Inventory.h" 


int main()
{
    Car c1{ "Volvo", 135, 2 };
    Car c2{ "BMW", 245, 3 };

    Laptop l1{ "Lenovo", 5 };
    Laptop l2{ "Asus", 3 };
    
    Inventory inv;

    inv.addItem(&l2);
    inv.addItem(&l1);
    inv.addItem(&c1);
    inv.addItem(&c2);

    inv.print();
    
    std::cout << std::boolalpha << inv.areIncrProductivity();
}