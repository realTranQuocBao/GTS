// TQB13 - Tran Quoc Bao

//Vi?t chuong tr�nh t�m s? d?o c?a m?t s? nguy�n duong. 

#include <iostream>
using namespace std;

long long int daoNguoc(long long int a){
	long long int KQ=0;
	while(a>0){
		int temp = a%10;
		KQ = KQ*10 + temp;
		a/=10;
	}
	return KQ;
}

int main(){
	long long int a;
	cout<<"Nhap so nguyen duong: ";
	cin>>a;
	cout<<daoNguoc(a);
	return 0;
}

