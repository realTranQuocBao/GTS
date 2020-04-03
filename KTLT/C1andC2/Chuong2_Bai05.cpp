// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tinh S = sqrt(1^2+2^2+3^2+...+N^2) \n";
	
	//Khai bao
	double S,N;
	
	//Nhap du lieu
	cout<<"Nhap N: ";
	cin>>N;
	
	//tinh toan
	S = sqrt(N*(N+1)*(2*N+1)/6);
	
	//in ket qua
	cout<<"S = "<<S;
	
	cout<<endl;
	return 0;
	
}

