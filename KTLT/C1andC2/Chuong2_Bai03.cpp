// 1951120086 - Tran Quoc Bao

#include <iostream>
using namespace std;

int main(){
	
	//info program
	cout<<"Phien am 0->9\n";
	
	//Khai bao
	int c;
	
	//Nhap du lieu
	cout<<"Nhap vao so 0->9: ";
	cin>>c;
	
	//Xu ly du lieu & In KQ
	switch (c) {
		case 0: {
			cout<<"KHOONG";
			break;
		}
		case 1: {
			cout<<"MOOTJ";
			break;
		}
		case 2: {
			cout<<"HAI";
			break;
		}
		case 3: {
			cout<<"BA";
			break;
		}
		case 4: {
			cout<<"BOONS";
			break;
		}
		case 5: {
			cout<<"NAWM";
			break;
		}
		case 6: {
			cout<<"SAUS";
			break;
		}
		case 7: {
			cout<<"BAYR";
			break;
		}
		case 8: {
			cout<<"TAMS";
			break;
		}
		case 9: {
			cout<<"CHINS";
			break;
		}
		default: cout<<"Toi yeu cau nhap 0->9 ma ?!";
	} 
	
	cout<<endl;
	return 0;
	
}

