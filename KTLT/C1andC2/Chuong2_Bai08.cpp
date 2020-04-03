// 1951120086 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

int main(){
	
	//info program
	cout<<"Tim SoHoanChinh < N cho truoc.\n";
	
	//Khai bao
	unsigned long long int n,i,j,tong; //0  toi max = 18446744073709551615
	
	//Nhap du lieu
	cout<<"Nhap N: ";
	cin>>n;
	
	//Xu li du lieu & in KQ
	if (n < 6) cout<<"khong tim thay SoHoanChinh < "<<n;
	cout<<"Cac SoHoanChinh < "<<n<<" la: ";
	for (i = 6; i < n; i++) {
		tong = 0;
		for (j = 1; j <= i/2; j++) {
			if (i%j == 0) {
				tong += j;
			}
		}
		if (tong == i) cout<<i<<" ";
	}
	
	cout<<endl;
	return 0;
	
}

