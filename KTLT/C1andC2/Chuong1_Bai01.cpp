// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	
	//info program
	cout<<"Tinh Khoang Cach \ntu DIEM A(x,y,z) \nden MAT PHANG Ax+By+Cz+D=0\n";
	
	//Khai bao
	float khoangCach,x,y,z,A,B,C,D;
	
	//Nhap du lieu
	cout<<"\nNhap x,y,z,A,B,C,D: ";
	cin>>x>>y>>z>>A>>B>>C>>D;
	
	//tinh toan
	khoangCach = fabs(A*x+B*y+C*z+D) / sqrt(pow(A,2)+pow(B,2)+pow(C,2));
	
	//in ket qua
	cout<<"\nKhoang Cach = "<<fixed<<setprecision(3)<<khoangCach<<endl;
	
	return 0;
	
}

