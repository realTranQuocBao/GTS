#include "Employee.h"
#include <iostream>
using namespace std;
Employee::Employee(string lastname, string firstname, Date birthday, Date hiredate) {
	this->lastname = lastname;
	this->firstname = firstname;
	this->birthday = birthday;
	this->hiredate = hiredate;
} //Váy hoa nhí
void Employee::print(void) {
	cout << "\nLastname\t: " << lastname;
	cout << "\nFirstname\t: " << firstname;
	cout << "\nBirthday\t: "; birthday.print();
	cout << "\nHiredate\t: "; hiredate.print();
}
Employee::~Employee(void){

}