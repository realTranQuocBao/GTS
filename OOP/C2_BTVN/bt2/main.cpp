#include "Fraction.h"

int main(){
	Fraction ba, gi, bg;
	cout<<"Nhap ps thu I:\n";
	ba.input();
	ba.compact();
	cout<<"Ps thu I = ";
	ba.print();
	
	cout<<"\nNhap ps thu II:\n";
	gi.input();
	gi.compact();
	cout<<"Ps thu II= ";
	gi.print();
	
	bg = ba.add(gi);
	bg.compact();
	cout<<"\nPs I+II = ";
	bg.print();
	
	return 0;
}
