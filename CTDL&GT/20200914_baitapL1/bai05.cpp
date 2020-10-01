// TQB13 - Tran Quoc Bao

//B�i 5: T�nh tam gi�c: Nh?p v�o ba s? a,b,c b?t k�.
//Ki?m tra xem n� c� th?  l� d? d�i ba c?nh hay kh�ng,
//n?u  kh�ng  th� in  ra m�n  h�nh  ' Khong la ba  canh cua mot tam  giac'. 
//Ngu?c l?i, th� in di?n t�ch, chu vi c?a tam gi�c ra m�n h�nh.

#include <iostream>
#include <math.h>
using namespace std;
int checkTG(int a, int b, int c){
	if( (a+b)!=c && (c+b)!=a && (a+c)!=b ) return 1;
	return 0;
}
float dtTG(int a, int b, int c){
	float s=(a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){
	int a,b,c;
	cout<<"Nhap do dai 3 canh: ";
	cin>>a>>b>>c;
	if(checkTG(a,b,c)){
		cout<<"Chu vi = "<<a+b+c<<"\nDien tich = "<<dtTG(a,b,c);
	} else{
		cout<<"Khong la ba  canh cua mot tam  giac";
	}
	return 0;
}

