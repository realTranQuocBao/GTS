// TQB13 - Tran Quoc Bao
/*
Bài 5. 	Nhap du lieu cho mang chuoi A gom n sinh viên (n<=50).
a, Xuat các chuoi trong A ra màn hình
b, Tìm xem trong A có bao nhiêu nguoi có ho là “Nguyen”
c, Dua vào ho hãy sep xep A tang dan (a -> z).
d, Xuat ra màn hình tên cua các sinh viên duoi dang chu in hoa
*/

#include <iostream>
#include <string.h>
using namespace std;

void nhapTenSV(char SinhVien[][27], int n);
void inTenSV(char SinhVien[][27], int n);
int demSVtheoHo(char SinhVien[][27], char hoSV[], int n);
void sapXepTheoHo(char SinhVien[][27], int n);
void inHoaSV(char SinhVien[][27], int n);

int main(){
	
	// khai bao bien
	int m,n;
	do{
		cout<<"Nhap so luong sinh vien (max 50): ";
		cin>>n;
		cin.ignore(); //xóa '\n' cua cin
	} while (n<1 || n>50);
	char SinhVien[n][27];
	
	//MAIN
	nhapTenSV(SinhVien,n);
	
	//cau A.
	cout<<"\nDanh sach sinh vien vua nhap la:\n";
	inTenSV(SinhVien,n);
	cout<<endl;

	//cau B.
	char hoSV[]="Nguyen";
	cout<<"Co "<<demSVtheoHo(SinhVien,hoSV,n)<<" sinh vien ho "<<hoSV<<endl;
	
	//cau C.
	sapXepTheoHo(SinhVien,n);
	cout<<"\nDanh sach sinh vien vua sap xep xong la:\n";
	inTenSV(SinhVien,n);
	
	//cau D.
	inHoaSV(SinhVien,n);
	cout<<"\nDanh sach sinh vien vua chuyen thanh CHU IN HOA:\n";
	inTenSV(SinhVien,n);	

	return 0;
}

void nhapTenSV(char SinhVien[][27], int n){
	for(int i=0; i<n; i++) {
		cout<<"Nhap vao ho va ten sinh vien thu " <<i+1<<" : \n";
		cin.getline(SinhVien[i],26);
	}
}
void inTenSV(char SinhVien[][27], int n){
	for(int i=0; i<n; i++){
		cout<<"Sinh vien thu "<<i+1<<": "<<SinhVien[i]<<"\n";	
	}
}
int demSVtheoHo(char SinhVien[][27], char hoSV[], int n){
	int dem=0;
	for(int i=0; i<n; i++){
		if (strncmp(SinhVien[i],hoSV,strlen(hoSV))==0) {
			dem++;
		}	
	}
	return dem;
}
void sapXepTheoHo(char SinhVien[][27], int n){
	char temp[27];
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(strcmp(SinhVien[i],SinhVien[j])>0) {
				strcpy(temp,SinhVien[i]);
				strcpy(SinhVien[i],SinhVien[j]);
				strcpy(SinhVien[j],temp);
			}
		}
	}
}
void inHoaSV(char SinhVien[][27], int n){
	for(int i=0; i<n; i++){
		strupr(SinhVien[i]);
	}
}

