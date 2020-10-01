//File "Fraction.h"
#include <iostream>
using namespace std;
#ifndef _FRACTION_H
#define _FRACTION_H

class Fraction{
	private:
		int numerator;
		int denominator;
	public:
		void input();
		void print();
		Fraction compact(); //rut gon phan so
		Fraction add(Fraction &); //phep cong
};

#endif
