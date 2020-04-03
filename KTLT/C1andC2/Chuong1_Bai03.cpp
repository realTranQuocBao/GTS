// 1951120086 - Tran Quoc Bao

#include <iostream>
#include<string>
using namespace std;

int main(){
	
	//info program
	cout<<"Nhap vao Ten_GioiTinh_Tuoi \nXuat ra Ten_GioiTinh_NamSinh \n\n---------------------------\n";
	
	//Khai bao
	string ten,gioiTinh;
	int tuoi,namSinh;
	
	//Nhap thong tin
	cout<<"\n!!!Nhap vao Thong Tin cua Ban!!!";
	cout<<"\nTen       : ";
	getline(cin,ten);
	cout<<"Gioi tinh : ";
	getline(cin,gioiTinh);
	cout<<"Tuoi      : ";
	cin>>tuoi;
	cout<<"\n---------------------------\n";
	
	//Xuat thong tin
	cout<<"\n!!!Day la Thong Tin cua Ban!!!";
	cout<<"\nTen       : "<<ten;
	cout<<"\nGioi tinh : "<<gioiTinh;
	cout<<"\nNam sinh  : "<<2020-tuoi;
	cout<<endl;
	
	return 0;

}

