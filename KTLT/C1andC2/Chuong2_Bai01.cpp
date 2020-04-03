// 1951120086 - Tran Quoc Bao

#include <iostream>
using namespace std;

int main(){

	//info program
	cout<<"Chu cai? Hoa/Thuong?"<<endl;
	
	//Khai bao
	char t ;
	
	//Nhap du lieu
	cout<<"Hay nhap vao 1 ky tu: ";
	cin>>t;
	
	//Xu ly du lieu & Xuat KQ
	if(t>='A'&&t<='Z') cout<<t<<" la Chu Cai IN HOA";
	else if(t>='a'&&t<='z') cout<<t<<" la Chu Cai THUONG";
	else cout<<t<<" KHONG PHAI Chu Cai";
	
	cout<<endl;
	return 0;
	
}

