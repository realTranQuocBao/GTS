#include <math.h>
#include "Fraction.h"

void Fraction::input(){
	cout<<"Tu so = ";
	cin>>this->numerator;
	cout<<"Mau so = ";
	cin>>this->denominator;
}

void Fraction::print(){
	cout<<this->numerator<<"/"<<this->denominator<<endl;
}

Fraction Fraction::compact(){
	int a = abs(this->numerator);
	int b = abs(this->denominator);
	while(a!=b){
		if(a>b) a-=b;
		else b-=a;
	}
	this->numerator /= a;
	this->denominator /= a;
	return *this;
}

Fraction Fraction::add(Fraction &gi){
	Fraction *sum;
	sum->numerator = this->numerator*gi.denominator + gi.numerator*this->denominator;
	sum->denominator = this->denominator * gi.denominator;
	return *sum;
}
