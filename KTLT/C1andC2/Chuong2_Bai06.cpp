// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tinh S = sqrt(3+sqrt(3+sqrt(3+sqrt(3+...)))) \n";
	//n dau can -> S= (sqrt(13)+1)/2
	
	//Khai bao
	double S,n;
	
	//Nhap du lieu
	cout<<"Nhap so Dau Can: ";
	cin>>n;
	
	//tinh toan
	S = 0;
	for(int i=0; i<n; i++){
		S= sqrt(3+S);
	}
	
	//in ket qua
	cout<<"S = "<<S;
	
	cout<<endl;
	return 0;
	
}

