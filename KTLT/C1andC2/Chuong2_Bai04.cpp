// 1951120086 - Tran Quoc Bao

#include <iostream>
using namespace std;

int main(){
	
	//info program
	cout<<"Ngay X cua T3/2020 là thu may?\n";
	
	//Khai bao
	int c;
	
	//Nhap du lieu
	cout<<"Nhap vao ngay 1->31: ";
	cin>>c;
	
	//Xu ly du lieu & In KQ
	if(c<1 || c>31) cout<<"Ban vua nhap 1 ngay khong thuoc Thang 3 nam 2020";
	switch (c) {
		case 2,9,16,23,30:{
			cout<<"Thu 2";
			break;
		}
		case 3: {
			cout<<"Thu 3";
			break;
		}
		case 4: {
			cout<<"Thu 4";
			break;
		}
		case 5: {
			cout<<"Thu 5";
			break;
		}
		case 6: {
			cout<<"Thu 6";
			break;
		}
		case 0: {
			cout<<"Thu 7";
			break;
		}
		case 1: {
			cout<<"Chua Nhat";
			break;
		}
		default: break;
	} 
	
	cout<<endl;
	return 0;
	
}

