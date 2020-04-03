// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tinh gan dung e^x theo cong thuc xap xi (Khai trien Taylor)\n";
	
	//Khai bao
	double x,s,i,nGT;
	
	//Nhap du lieu
	cout<<"Nhap x = ";
	cin>>x;
	
	//tinh toan
	s = 0;
	for (i = 0; i<32000 ; i++) {
		nGT = 1;
		for(int j=0; j<=i; j++) {
			if (j==0) nGT=1;
			else nGT *= j;
		}
		s += pow(x,i)/(nGT);
		if (fabs(pow(x,i)/(nGT)) < pow(10,-6)) break;
	}
	
	//in ket qua
	cout<<"Xap xi e^"<<x<<" = "<<s;
	
	return 0;
	
}

