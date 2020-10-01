// TQB13 - Tran Quoc Bao

// Bài 1: Nh?p vào tâm và bán kính c?a m?t du?ng tròn.
//Sau dó nh?p vào m?t di?m A(x, y) b?t kì và ki?m tra xem nó có thu?c du?ng tròn hay không?

#include <iostream>
#include <math.h>
using namespace std;
struct TOA_DO{
	int x,y;
};
TOA_DO nhapToaDo(){
	TOA_DO M;
	cout<<"\nNhap x: ";
	cin>>M.x;
	cout<<"Nhap y: ";
	cin>>M.y;
	return M;
}
float khoangCach(TOA_DO I, TOA_DO M){
	return sqrt(pow((M.x-I.x),2)+pow((M.y-I.y),2));
}
int main(){
	int R;
	TOA_DO I;
	//
	cout<<"Nhap toa do tam I:";
	I = nhapToaDo();
	cout<<"Nhap ban kinh R: ";
	cin>>R;
	//
	cout<<"Nhap toa do Diem muon kiem tra:";
	TOA_DO M = nhapToaDo();
	//
	((khoangCach(I,M)-R)==0)?cout<<"Diem M THUOC Duong Tron":cout<<"Diem M KHONG THUOC Duong Tron";
	return 0;
}

