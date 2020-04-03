// TQB13 - Tran Quoc Bao
/*
Bài 4.  Nhap du lieu cho xâu kí tu str[100]
a, Xu?t ra màn hình xâu str
b, Xâu str có bao nhiêu kí tu và trong dó bao nhiêu kí tu là so
c, Loai bo các kí tu không phai là chu hoac không phai khoang trong trong xâu str
d, Ðoi chu thuong trong xâu str thành chu in hoa
e, Chèn vào xâu str mot xâu str2 khác vào vi trí bat kì trong str.
*/

#include <iostream>
#include <string.h>
using namespace std;

int demKiSo(char str[100]);
void xoaGiuLaiChu(char str[100]);
void insStrIntoStr(char str1[100], char str2[100], int k);

int main(){
	
	// khai bao bien
	char str[100], str2[100];
	int k;
		
	//Virtual String to Test
	//char str[100] = "trano"; //{'b','a',' ','o','\0'};
	//char str2[100] = "baoquyen";
	
	//MAIN
	cout<<"\nNhap du lieu cho sau (max 99 ki tu) A: \n";
	cin.getline(str,99);
	
	//cau A.
	cout<<"\nXau ban vua nhap la: \n"<<str<<endl;
	
	//cau B.
	cout<<"\nXau ban vua nhap co So Ki Tu la: "<<strlen(str)<<endl;
	cout<<"Trong do, co "<<demKiSo(str)<<" ki tu la So."<<endl;
	
	//cau C.
	xoaGiuLaiChu(str);
	cout<<"\nXau da xoa cac Ky Tu Dac Biet va So:\n"<<str<<endl;
	
	//cau D.
	cout<<"\nXau da chuyen thanh CHU IN HOA:\n"<<strupr(str)<<endl;
	
	//cau E.
	cout<<"\nNhap xau can chen (max 99 ki tu):\n";
	cin.getline(str2,99);
	cout<<"Nhap vi tri can chen: \n";
	cin>>k;
	insStrIntoStr(str,str2,k);
	cout<<"Chuoi sau khi chen:\n"<<str<<endl;
	
	return 0;
}

int demKiSo(char str[100]){
	int dem = 0;
	for(int i=0 ; i < strlen(str) ; i++){
		if('0'<=str[i] && str[i]<='9') {
			dem++;
		}
	}
	return dem;
}
void xoaGiuLaiChu(char str[100]){
	int n=strlen(str);
	for(int i=0 ; i < n ; i++){
		if ( (str[i]!=' ' && str[i]<'A') || ('Z'<str[i] && str[i]<'a') || ('z'<str[i]) ) {
			for(int j=i ; j<n-1 ; j++){
				str[j]=str[j+1];
			}
			n--;
			i--;
		}
	}
	str[n]='\0';
}
void insStrIntoStr(char str1[100], char str2[100], int k){
	char tam[100];
	strcpy(tam,str1+k-1); //copy chuoi str1 tu vi tri k, va gan vao xau TAM.
	strcpy(str1+k-1,str2); //copy chuoi str2 và ghi dè lên str1 tu vi tri k
	strcat(str1,tam); //Concatenate, Noi tiep chuoi tam vào sau str1 (lay ca ki tu \null)
}

