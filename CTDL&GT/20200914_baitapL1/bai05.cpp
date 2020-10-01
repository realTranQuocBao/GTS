// TQB13 - Tran Quoc Bao

//Bài 5: Tính tam giác: Nh?p vào ba s? a,b,c b?t kì.
//Ki?m tra xem nó có th?  là d? dài ba c?nh hay không,
//n?u  không  thì in  ra màn  hình  ' Khong la ba  canh cua mot tam  giac'. 
//Ngu?c l?i, thì in di?n tích, chu vi c?a tam giác ra màn hình.

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

