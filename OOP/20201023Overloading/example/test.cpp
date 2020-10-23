// Demonstrating composition--an object with member objects.
#include <iostream>
using std::cout;
using std::endl;
#include "Employee.h" // Employee class definition
#include "Date.h"
int main()
{
	Date birth(7, 24, 1949);
	Date hire(3, 12, 1988);
	Employee manager("Bob", "Blue", birth, hire);
	cout << endl;
	manager.print();
	cout << "\nTest Date constructor with invalid values: ";
	Date lastDayOff(14, 35, 1994); // invalid month and day
	cout << endl;
	return 0;
} // end main