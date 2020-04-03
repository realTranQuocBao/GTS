// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	
	//info program
	cout<<"Tim GTLN trong a, b, c, d \n";
	
	//Khai bao
	float max,a,b,c,d;
	
	//Nhap du lieu
	cout<<"Nhap a,b,c,d: ";
	cin>>a>>b>>c>>d;
	
	//Xu ly du lieu
	max = a;
	if (max < b) max = b;
	if (max < c) max = c;
	if (max < d) max = d;
	
	//in ket qua
	cout<<"GTLN la "<<max;
	
	cout<<endl;
	return 0;
	
}

