#include "Student.h"
#include <iostream>
using namespace std;

void Student::input(){
	cout<<"Nhap ma so sinh vien: ";
	cin.getline(mssv,11);
	cout<<"Nhap Ten: ";
	cin.getline(name,31);
	cout<<"Nhap Diem Trung Binh: ";
	cin>>averMark;
}

void Student::print(){
	cout<<"\nMSSV    : "<<mssv;
	cout<<"\nTen     : "<<name;
	cout<<"\nDiem TB : "<<averMark;	
}
