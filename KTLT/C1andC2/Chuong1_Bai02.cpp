// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	
	//info program
	cout<<"Tinh Gia tri Trung Binh cua 3 so bat ky\n";
	
	//Khai bao
	float giaTriTrungBinh,x,y,z;

	//Nhap du lieu
	cout<<"\nNhap x,y,z: ";
	cin>>x>>y>>z;

	//tinh toan
	giaTriTrungBinh = (x+y+z)/3;

	//in ket qua
	cout<<"\nGia tri Trung Binh = "<<fixed<<setprecision(4)<<giaTriTrungBinh<<endl;
	
	return 0;
	
}


