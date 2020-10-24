#include <bits/stdc++.h> 
#include <iostream>
#include <fstream>
using namespace std;

void writeF(int *&csc, int &n){
	ifstream fi("SERIES.INP");
	//int n;
	fi>>n;
	int i = 0;
	csc = new int[n];
	while(fi>>*(csc+i)){
		cout<<*(csc+i)<<endl;
		i += sizeof(int);
	}
	fi.close();
}
void sort(int *csc, int &n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if( *(csc+i*4) > *(csc+j*4)){
				int temp= *(csc+i*4);
				*(csc+i*4) = *(csc+j*4);
				*(csc+j*4) = temp;
			}
		}
	}
}
int checkCSC(int *csc, int n){
	if(n==1) return 0;
	int k = *(csc+4) - *csc;
	for(int j=0; j<n-1; j++){
		if( (*(csc+4*j+4) - *(csc+4*j))!=k ) return 0;
	}
	return 1;
}
void readF(int *csc, int n){
	ofstream fo("SERIES.OUP", ios::trunc);
	if(!checkCSC(csc,n)){
		fo<<-1;
	} else{
		for(int i=0; i<n; i++){
			fo<<*(csc + i*sizeof(int))<<endl;
		}
	}
	if(csc != NULL) delete[] csc;
	fo.close();
}
int main(){
	int n;
	int *csc;
	writeF(csc, n);
	sort(csc, n);
	readF(csc, n);
	return 0;
}
