#include <iostream>
#include "Hall.h"
#include "myVector.h"

int main()
{
    Hall h1;
    h1.Initialize("Omega", 25, 5, 5);
    Hall h2;
    h2.Initialize("Beta", 36, 6, 6);
    Hall h3;
    h3.Initialize("Sigma", 49, 7, 7);
    
    myVector<Hall> halls;
    halls.Add(h1);
    halls.Add(h2);
    halls.Add(h3);
    halls.Print();

    return 0;
}