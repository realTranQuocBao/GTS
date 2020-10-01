// TQB13 - Tran Quoc Bao

//Cho vector AB vector CD, tính tích vô hu?ng c?a 2 vector

#include <iostream>
#include <math.h>
using namespace std;
struct VECTOR{
	int x,y;
};
VECTOR nhapVector(){
	VECTOR BG;
	cout<<"\nNhap x: "; cin>>BG.x;
	cout<<"Nhap y: "; cin>>BG.y;
	return BG;
}
float tichVH(VECTOR AB, VECTOR CD){
	return sqrt(pow(AB.x,2)+pow(AB.y,2))*sqrt(pow(CD.x,2)+pow(CD.y,2))*(AB.x*CD.x+AB.y*CD.y)/(sqrt(pow(AB.x,2)+pow(AB.y,2))*sqrt(pow(CD.x,2)+pow(CD.y,2)));
}
int main(){
	VECTOR AB,CD;
	cout<<"Nhap vecto AB: ";
	AB = nhapVector();
	cout<<"Nhap vecto CD: ";
	CD = nhapVector();
	cout<<"Tich vo huong cua 2 vector AB va CD la "<<tichVH(AB,CD);
	return 0;
}

