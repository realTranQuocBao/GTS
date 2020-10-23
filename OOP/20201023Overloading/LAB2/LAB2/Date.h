#pragma once
class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day = 1, int month = 1, int year = 1990);
	void print(void);
	int maxDay(int, int);
	bool check(int day, int month, int year);
	~Date(void);
	int getDay(void) const;
	int getMonth(void) const;
	int getYear(void) const;
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	friend bool operator>(const Date&, const Date&);
	friend bool operator<(const Date&, const Date&);
	friend bool operator==(const Date&, const Date&);
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator<<(ostream& in, const Date& d);
	Date operator++(void);	//prefix
	//Date operator++(int);	//	
};