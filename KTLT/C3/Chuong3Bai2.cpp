// TQB13 - Tran Quoc Bao
/*
Bài 2. 	Nhap du lieu cho 2 ma tran so nguyên  A và B "deu" gom m hàng n cot.
a, Xuat tung ma tran và ma tran tong A+B
b, Tìm phan tu lon nhat trên tung ma tran và trên ca 2 ma tran
c, Tong các phan tu trên ma tran nào là lon hon
d, Sap xep ma tran A tang dan, ma tran B giam dan
*/

#include <iostream>
using namespace std;

void nhapMaTran(int mt[][277], int m, int n);
void xuatMaTran(int mt[][277], int m, int n);
void sumMatrix(int sum[][277], int mt1[][277], int mt2[][277], int m, int n);
int timMax1mt(int mt[][277], int m, int n);
int timMax2mt(int mt1[][277], int mt2[][277], int m, int n);
void tongPhanTu(int mt1[][277], int mt2[][277], int m, int n);
void sapXepTang(int mt[][277], int m, int n);
void sapXepGiam(int mt[][277], int m, int n);

int main(){
	
	// khai bao bien
	int m,n;
	do{
		cout<<"Nhap so dong: ";
		cin>>m;
		cout<<"Nhap so cot: ";
		cin>>n;
	} while (m<=0 && n<=0);
	
	//Virtual Matrix to Test
	//int ma_tran[4][3] = {{ 1, 2, 3 }, {2, 3, 4}, {3, 4, 5}, {4, 5, 6}};
	
	int A[277][277], B[277][277], C[277][277];
	
	//MAIN
	cout<<"\nNhap du lieu cho ma tran A:\n";
	nhapMaTran(A,m,n);
	cout<<"\nNhap du lieu cho ma tran B:\n";
	nhapMaTran(B,m,n);
	
	//cau A.
	cout<<"\nXuat ma tran A:\n";
	xuatMaTran(A,m,n);
	cout<<"\nXuat ma tran B:\n";
	xuatMaTran(B,m,n);
	cout<<"\nXuat ma tran [A+B]:\n";
	sumMatrix(C,A,B,m,n);
	xuatMaTran(C,m,n);
	
	//cau B.
	cout<<"\nMAX cua ma tran A la "<<timMax1mt(A,m,n);
	cout<<"\nMAX cua ma tran B la "<<timMax1mt(B,m,n);
	cout<<"\nMAX cua ma tran A&B la "<<timMax2mt(A,B,m,n);
	cout<<endl;
	
	//cau C.
	tongPhanTu(A,B,m,n);
	cout<<endl;
	
	//cau D.
	cout<<"\nXuat ma tran A (da sx tang dan):\n";
	sapXepTang(A,m,n);
	xuatMaTran(A,m,n);
	cout<<"\nXuat ma tran B (da sx giam dan):\n";
	sapXepGiam(B,m,n);
	xuatMaTran(B,m,n);
	
	return 0;
}

void nhapMaTran(int mt[][277], int m, int n){
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			cout<<"Gia tri ["<<i<<"]["<<j<<"] = ";
			cin>>mt[i][j];	
		}
	}
}
void xuatMaTran(int mt[][277], int m, int n){
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			cout<<mt[i][j]<<"\t";	
		}
		cout<<endl;
	}
}
void sumMatrix(int sum[][277], int mt1[][277], int mt2[][277], int m, int n){
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			sum[i][j] = mt1[i][j] + mt2[i][j];
		}
	}
}
int timMax1mt(int mt[][277], int m, int n){
	int max = mt[0][0];
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(mt[i][j] > max){
				max = mt[i][j];
			}
		}
	}
	return max;
}
int timMax2mt(int mt1[][277], int mt2[][277], int m, int n){
	int max = mt1[0][0];
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(mt1[i][j] > max){
				max = mt1[i][j];
			}
			if(mt2[i][j] > max){
				max = mt2[i][j];
			}
		}
	}
	return max;
}
void tongPhanTu(int mt1[][277], int mt2[][277], int m, int n){
	int sum1=0, sum2=0;
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			sum1 += mt1[i][j];
			sum2 += mt2[i][j];
		}
	}
	if(sum1 == sum2) cout<<"\nTong cac phan tu tren ma tran bang nhau";
	if(sum1 > sum2) cout<<"\nTong cac phan tu tren mt thu nhat("<<sum1<<") LON hon mt thu hai("<<sum2<<").";
	if(sum1 < sum2) cout<<"\nTong cac phan tu tren mt thu hai("<<sum2<<") LON hon mt thu nhat("<<sum1<<").";
}
void sapXepTang(int mt[][277], int m, int n){
	int k=0, tam[m*n], temp;
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			tam[k] = mt[i][j];
			k++;
		}
	}
	for(int i=0; i<m*n-1; i++){
		for(int j=i+1; j<m*n; j++){
			if(tam[i]>tam[j]) {
				temp = tam[i];
				tam[i] = tam[j];
				tam[j] = temp;
			}
		}
	}
	k=0;
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			mt[i][j] = tam[k];
			k++;
		}
	}
}
void sapXepGiam(int mt[][277], int m, int n){
	int k=0, tam[m*n], temp;
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			tam[k] = mt[i][j];
			k++;
		}
	}
	for(int i=0; i<m*n-1; i++){
		for(int j=i+1; j<m*n; j++){
			if(tam[i]<tam[j]) {
				temp = tam[i];
				tam[i] = tam[j];
				tam[j] = temp;
			}
		}
	}
	k=0;
	for(int i=0 ; i<m ; i++) {
		for(int j=0 ; j<n ; j++) {
			mt[i][j] = tam[k];
			k++;
		}
	}
}



