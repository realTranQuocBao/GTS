// TQB13 - Tran Quoc Bao
/*
Bài 1.  Nhap DL cho day so nguyen gom n phan tu (n<=50)
a, Xac dinh so phan tu la so chan ma lon hon 30 trong mang
b, Tìm giá tri nho nhat trong mang và so lan xuat hien cua no
c, Sap xep mang tang dan
d, Xaa tat ca cac phan tu có giá tri bang x o trong mang
e, Chen vao mang phan tu y sao cho mang van tang dan.
*/

#include <iostream>
using namespace std;

void nhapMang(int arr[], int n);
void xuatMang(int arr[], int n);
int demSoChan(int arr[], int n);
void inSoChan(int arr[], int n);
int timMinCuaMang(int arr[], int n);
int soLanXuatHien(int arr[], int n, int k);
void sapXepMangTang(int arr[], int n);
void xoaPhanTu(int arr[], int &n, int x);
void themPhanTu(int arr[], int &n, int y);

int main(){
	
	// khai bao bien
	int n,i,x,y;
	do{
		cout<<"Nhap so phan tu cua mang (toi da 50): ";
		cin>>n;
	} while (n>50 || n<0);
	int arr[n];

	//Virtual Arrays to Test
	//int arr[6] = {38,5,1,36,3,1};
	//n=6;
	
	//MAIN
	nhapMang(arr,n);
	
	//cau A.
	cout<<"\nSo phan tu la so CHAN & lon hon 30 la: "<<demSoChan(arr,n)<<" phan tu.";
	cout<<"\nDo la:";
	inSoChan(arr,n);
	cout<<endl;
	
	//cau B.
	cout<<"\nGTNN cua mang do la: "<<timMinCuaMang(arr,n);
	cout<<"\nSo lan xuat hien cua "<<timMinCuaMang(arr,n)<<" trong mang do la: "<<soLanXuatHien(arr,n,timMinCuaMang(arr,n));
	cout<<endl;
	
	//cau C.
	cout<<"\nSap xep mang tang dan: ";
	sapXepMangTang(arr,n);
	xuatMang(arr,n);
	cout<<endl;
	
	//cau D.
	cout<<"\nNhap gia tri can xoa: ";
	cin>>x;
	xoaPhanTu(arr,n,x);
	xuatMang(arr,n);
	cout<<endl;
	
	//cau E.
	cout<<"\nNhap gia tri can them: ";
	cin>>y;
	themPhanTu(arr,n,y);
	xuatMang(arr,n);
	cout<<endl;
	
	return 0;
}

void nhapMang(int arr[], int n){
	for(int i=0 ; i<n ; i++) {
		cout<<"Gia tri thu "<<i+1<<" = ";
		cin>>arr[i];
	}
}
void xuatMang(int arr[], int n){
	for(int i=0 ; i<n ; i++) {
		cout<<"\nGia tri thu "<<i+1<<" = "<<arr[i];
	}	
}
int demSoChan(int arr[], int n){
	int dem=0;
	for(int i=0 ; i<n ; i++) {
		if (arr[i]>30 && arr[i]%2==0) {
			dem++;	
		}
	}
	return dem;
}
void inSoChan(int arr[], int n){
	for(int i=0 ; i<n ; i++) {
		if (arr[i]>30 && arr[i]%2==0) {
			cout<<"\nGia tri thu "<<i+1<<" = "<<arr[i];		
		}
	}
}
int timMinCuaMang(int arr[], int n){
	int min = arr[0];
	for(int i=0 ; i<n ; i++) {
		if (arr[i]<min) {
			min=arr[i];
		}
	}
	return min;
}
int soLanXuatHien(int arr[], int n, int k){
	int dem=0;
	for(int i=0 ; i<n ; i++) {
		if (arr[i]==k) {
			dem++;
		}
	}
	return dem;
}
void sapXepMangTang(int arr[], int n){
	int i,j,temp;
	for(i=0 ; i<n-1 ; i++){
		for(j=i+1 ; j<n ; j++){
			if(arr[i]>arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void xoaPhanTu(int arr[], int &n, int x){
	for(int i=0 ; i<n ; i++){
		if(arr[i]==x) {
			for(int j=i ; j<n-1 ; j++){
				arr[j]=arr[j+1];
			}
			n--;
			i--;
		}
	}
}
void themPhanTu(int arr[], int &n, int y){
	if(y > arr[n-1]){
		n++;
		arr[n-1] = y;	
	}
	else if(y < arr[0]){
		n++;
		for(int j=n-1 ; j>0 ; j--){
			arr[j]=arr[j-1];
		}
		arr[0] = y;
	}
	else for(int i=0 ; i<n-1 ; i++){
		if(arr[i]<=y && arr[i+1]>=y) {
			n++;
			for(int j=n-1 ; j-1>i ; j--){
				arr[j]=arr[j-1];
			}
			arr[i+1] = y;
			break;
		}
	}
}

