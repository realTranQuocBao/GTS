#include "Date.h"
#include <iostream>
using namespace std;

//Date::Date(void) {
//	day = 1;
//	month = 1;
//	year = 1900;
//}
Date::Date(int day, int month, int year) {
	if (check(day, month, year)) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else {
		cout << "invalid";
		this->day = 1;
		this->month = 1;
		this->year = 1900;
	}
}
void Date::print() {
	cout << day << "/" << month << "/" << year;
}
int Date::maxDay(int m, int y) {
	switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: return 31;
		case 4:
		case 6:
		case 9:
		case 11: return 30;
		case 2: {
			if ((y % 4 == 0 && y != 100) || y % 400 == 0) return 29;
			else return 28;
		}
		default: return -1;
	}
}
bool Date::check(int day, int month, int year) {
	if (year < 1900) return false;
	if (month < 1 || month>12) return false;
	if (day<1 || day>maxDay(month, year)) return false;
	return true;
}
Date::~Date(void) {

}

int Date::getDay(void) const {
	return this->day;
}
int Date::getMonth(void) const {
	return this->month;
}
int Date::getYear(void) const {
	return this->year;
}
void Date::setDay(int day) {
	if (check(day, month, year)) {
		this->day = day;
	}
	else {
		cout << "Invalid Day\n";
	}
}
void Date::setMonth(int month) {
	if (check(day, month, year)) {
		this->month = month;
	}
	else {
		cout << "Invalid Month\n";
	}
}
void Date::setYear(int year) {
	if (check(day, month, year)) {
		this->year = year;
	}
	else {
		cout << "Invalid Year\n";
	}
}
bool operator>(const Date& d1, const Date& d2) {
	if (d1.year > d2.year) return true;
	if (d1.year < d2.year) return false;
	if (d1.month > d2.month) return true;
	if (d1.month < d2.month) return false;
	if (d1.day > d2.day) return true;
	return false;
}
bool operator<(const Date& d1, const Date& d2) {
	if (d1.year < d2.year) return true;
	if (d1.year > d2.year) return false;
	if (d1.month < d2.month) return true;
	if (d1.month > d2.month) return false;
	if (d1.day < d2.day) return true;
	return false;
}
bool operator==(const Date& d1, const Date& d2) {
	if (d1.year != d2.year) return false;
	if (d1.month != d2.month) return false;
	if (d1.day != d2.day) return true;
	return false;
}

Date Date::operator++(void) {	//prefix
	day++;
	if (day > maxDay(month, year)) {
		day = 1;
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
	return *this;
}
//Date Date::operator++(int);	//	
