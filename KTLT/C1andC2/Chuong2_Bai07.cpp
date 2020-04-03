// 1951120086 - Tran Quoc Bao

#include <iostream>
using namespace std;

int main(){

	//info program // ThapPhan to NhiPhan
	cout<<"Nhap N & Xuat N duoi dang Nhi Phan"<<endl;
	
	//Khai bao
	int n,np[250],i;
	
	//Nhap du lieu
	cout<<"Hay nhap so tu nhien N: ";
	cin>>n;
	
	//Xu ly du lieu
	for (i = 0; n > 0; i++) {
		np[i] = n % 2;
		n = n / 2;
	}
	
	//Xuat KQ
	cout<<"Dang so Nhi Phan la: ";
	for (i -= 1; i >= 0; i--) {
		cout<<np[i];	
	}
	
	cout<<endl;
	return 0;
	
}

