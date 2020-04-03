// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tim cac so co dang abcd\nTrong do: (a+b) chan ; (c+d) le\n";
	
	//Khai bao
	int i;

	//Xu li & in KQ
	cout<<"cac so có 4 chu so phu hop yu cau la:";
	for (i = 1000; i<10000; i++) {
		if( (i/1000 + i/100)%2!=0 && (i/10 + i/1)%2==0) cout<<"\n"<<i;
	}

	cout<<endl;
	return 0;
	
}

