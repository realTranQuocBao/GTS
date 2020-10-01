// TQB13 - Tran Quoc Bao

//s? d?ng struct, cài d?t s? ph?c.
//Vi?t hàm th?c hi?n các phép toán trên s? ph?c(C?ng, tr?, nhân..)

#include <iostream>
using namespace std;
struct SOPHUC{
	int a,b;
};
void inSP(SOPHUC i){
	cout<<i.a<<"i+"<<i.b;
}
SOPHUC nhapSP(){
	SOPHUC i;
	cout<<"\nPhan thuc = "; cin>>i.a;
	cout<<"Phan  ao  = "; cin>>i.b;
	return i;
}
SOPHUC tongz(SOPHUC z1, SOPHUC z2){
	SOPHUC kq;
	kq.a=z1.a+z2.a;
	kq.b=z1.b+z2.b;
	return kq;
}
SOPHUC hieuz(SOPHUC z1, SOPHUC z2){
	SOPHUC kq;
	kq.a=z1.a-z2.a;
	kq.b=z1.b-z2.b;
	return kq;
}
SOPHUC tichz(SOPHUC z1, SOPHUC z2){
	SOPHUC kq;
	kq.a=z1.a*z2.a-z1.b*z2.b;
	kq.b=z1.a*z2.a+z1.b*z2.b;
	return kq;
}
SOPHUC thuongz(SOPHUC z1, SOPHUC z2){
	SOPHUC kq;
	z2.b*=-1;
	kq=tichz(z1,z2);
	kq.a/=(z2.a*z2.a+z2.b*z2.b);
	kq.b/=(z2.a*z2.a+z2.b*z2.b);
	return kq;
}
int main(){
	SOPHUC z1,z2,tong,hieu,tich,thuong;
	
	cout<<"Nhap so phuc z1:";
	z1=nhapSP();
	cout<<"Nhap so phuc z2:";
	z2=nhapSP();
	
	cout<<"\nSo phuc z1 = "; inSP(z1);
	cout<<"\nSo phuc z2 = "; inSP(z2);
	
	tong = tongz(z1,z2);
	hieu = hieuz(z1,z2);
	tich = tichz(z1,z2);
	thuong = thuongz(z1,z2);
	
	cout<<"\nz1+z2 = "; inSP(tong);
	cout<<"\nz1-z2 = "; inSP(hieu);
	cout<<"\nz1*z2 = "; inSP(tich);
	cout<<"\nz1/z2 = "; inSP(thuong);
	
	return 0;
}

