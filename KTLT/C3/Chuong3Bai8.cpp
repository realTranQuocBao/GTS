// TQB13 - Tran Quoc Bao
/*
Bài 8.
	Tinh S = sqrt(3+sqrt(3+sqrt(3+sqrt(3+...))))
	//n dau can -> S= (sqrt(13)+1)/2
*/

#include <iostream>
#include <math.h>
using namespace std;

float tong(int n){
	if(n==1) return sqrt(3);
	return sqrt(3+tong(n-1));
}

int main(){
	
	int n;
	cout<<"Tinh S = sqrt(3+sqrt(3+sqrt(3+sqrt(3+...)))) (voi n dau can) \n";
	//n dau can -> S= (sqrt(13)+1)/2
	do{
		cout<<"\nNhap n: ";
		cin>>n;
	} while (n<=0);
	
	cout<<"\nS = "<<tong(n);
	
	return 0;
}

