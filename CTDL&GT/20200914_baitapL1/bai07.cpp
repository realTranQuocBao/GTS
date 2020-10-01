// TQB13 - Tran Quoc Bao

//Nh?p 1 sô t? nhiên, d?m sô t? nhiên có bao nhiêu ch? sô.

#include <iostream>
using namespace std;
int demChuSo(long long int n){
	int dem=0;
	while(n>0){
		n/=10;
		dem++;
	}
	return dem;
}
int main(){
	long long int N;
	cout<<"Nhap so tu nhien: ";
	cin>>N;
	cout<<"So vua nhap co "<<demChuSo(N)<<" chu so.";
	return 0;
}

