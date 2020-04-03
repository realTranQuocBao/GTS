// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tim cac cap SoSinhDoi < 1000";
	
	//Khai bao
	int i,j,k,kiemTra,soNT[255];
	
	//Tim so nguyen to < 1000
	j=0;
	k=0;
	for (i=2; i<1000; i++) {
		kiemTra = 0;
		for(j=2 ; j<=sqrt(i) ; j++) {
			if (i%j == 0) kiemTra++;
		}
		if (kiemTra==0) {
			soNT[k] = i;
			k++;
		}
	}
	
	//Kiem tra So Sinh Doi & in ket qua
	cout<<"\nCac cap So Sinh Doi la:";
	for (i=0 ; i<k-1 ; i++) {
		if(soNT[i+1]-soNT[i] == 2){
			cout<<"\n("<<soNT[i]<<";"<<soNT[i+1]<<")";
		}
	}
		
	cout<<endl;
	return 0;
	
}

