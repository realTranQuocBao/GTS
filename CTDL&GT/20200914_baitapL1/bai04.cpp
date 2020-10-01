// TQB13 - Tran Quoc Bao

//Nh?p 3 lo?i ti?n và s? ti?n c?n d?i.
//Hãy tìm t?t c? các t? h?p có du?c c?a 3 lo?i ti?n trên cho s? ti?n v?a nh?p.

#include <iostream>
#include <iomanip>
using namespace std;

void nhapMenhGia(int tienVN[], int &soTien){
	cout<<"Don vi: 000VND\n";
	for(int i=0; i<3; i++){
		cout<<"Nhap menh gia "<<i+1<<" : ";
		cin>>tienVN[i];
	}
	cout<<"Nhap so tien: ";
	cin>>soTien;
}
void xepTien(int tienVN[]){
	for(int i=0; i<3-1; i++){
		for(int j=i+1; j<3; j++){
			if(tienVN[i]<tienVN[j]){
				int temp = tienVN[i];
				tienVN[i] = tienVN[j];
				tienVN[j] = temp;
			}
		}
	}
}
void find(int tienVN[], int soTien){
	int a = (soTien/tienVN[0]);
	int b = (soTien/tienVN[1]);
	int c = (soTien/tienVN[2]);
	for(int i=0; i<= a; i++){
		for(int j=0; j<= b; j++){
			for(int k=0; k<= c; k++){
				if( (tienVN[0]*i+tienVN[1]*j+tienVN[2]*k)==soTien ){
					cout<<setw(5)<<i<<setw(5)<<j<<setw(5)<<k<<" (to).\n";
				}
			}
		}
	}
}
int main(){
	int tienVN[3], soTien;
	nhapMenhGia(tienVN, soTien);
	xepTien(tienVN);
	cout<<"\nCac to hop co the xay ra la:\n";
	cout<<setw(5)<<tienVN[0]<<setw(5)<<tienVN[1]<<setw(5)<<tienVN[2]<<" (menh gia).\n";
	find(tienVN, soTien);
	return 0;
}

