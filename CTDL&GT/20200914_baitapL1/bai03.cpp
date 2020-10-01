// TQB13 - Tran Quoc Bao

//Tìm t?t c? các ch? s? có ba ch? s?  abc
//sao cho t?ng các l?p phuong c?a các ch?
//s? thì b?ng chính s? dó (  abc  = a^3 + b^3 + c^3). 

#include <iostream>
#include <math.h>
using namespace std;

int check(int N){
	int a,b,c;
	a = N/100;
	b = (N-a*100)/10;
	c = N%10;
	if( (pow(a,3)+pow(b,3)+pow(c,3))==N ) return 1;
	return 0;
}

int main(){
	for(int i=100; i<1000; i++){
		if( check(i) ) cout<<i<<endl;
	}
	return 0;
}

