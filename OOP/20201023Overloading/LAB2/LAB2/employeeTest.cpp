// Demonstrating composition--an object with member objects.
#include <iostream>
using std::cout;
using std::endl;
#include "Employee.h" // Employee class definition
int main()
{
	//Date birth(7, 24, 1949);
	//Date hire(3, 12, 1988);
	//Employee manager("Bob", "Blue", birth, hire);
	//cout << endl;
	//manager.print();
	//cout << "\nTest Date constructor with invalid values: ";
	//Date lastDayOff(14, 35, 1994); // invalid month and day
	//cout << endl;

	Date test(25, 12, 1999);
	//test.print();
	//test.setDay(13);
	//test.setMonth(4);
	//test.setYear(2001);
	//test.print();

	test++ ;
	test.print();


	return 0;
} // end main