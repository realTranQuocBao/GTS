// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tinh gan dung sin theo cong thuc xap xi (Khai trien Taylor)\n";
	
	//Khai bao
	double x,s,i,nGT;
	
	//Nhap du lieu
	cout<<"Nhap x = ";
	cin>>x;
	
	//tinh toan
	s = 0;
	for (i = 0; i<32000 ; i++) {
		nGT = 1;
		for(int j=0; j<=2*i+1; j++) {
			if (j==0) nGT=1;
			else nGT *= j;
		}
		s += pow(-1,i)*pow(x,2*i+1)/(nGT);
		if (fabs(pow(x,2*i+1)/(nGT)) < pow(10,-6)) break;
	}
	
	//in ket qua
	cout<<"Xap xi sin("<<x<<") = "<<s;
	
	cout<<endl;
	return 0;
	
}

