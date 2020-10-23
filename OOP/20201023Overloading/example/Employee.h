#include <string>
#include "Date.h"
using namespace std;
#pragma once
class Employee
{
	//date is part of employee
private:
	string lastname;
	string firstname;
	Date birthday;
	Date hiredate;
public:
	Employee(string lastname, string firstname, Date birthday, Date hiredate);
	void print(void);
	~Employee(void);
};

class Employee
{
};

