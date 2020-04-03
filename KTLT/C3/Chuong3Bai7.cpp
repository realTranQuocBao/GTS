// TQB13 - Tran Quoc Bao
/*
Bài 7.  Viêt hàm de qui tính so fibonaci thu n. 
a, Xuat ra n phan tu dau tiên cua dãy Fibonacci
b, Xuat ra màn hình k phan tu chan dau tiên cua dãy Fibonacci
c, Xuat ra phan tu le thu m cua dãy Fibonacci
a( Cho dãy Fibonacci: 0,1, 1, 2, 3, 5, 8, 13(5), 21,….)
*/

#include <iostream>
using namespace std;

unsigned long long fibo(int n);
void inNFiboDau(int n);
void inNFiboChan(int n);
int fiboLe(int n);

int main(){
	
	int n,k,m;
	
	//MAIN
	do{
		cout<<"\nNhap n: ";
		cin>>n;
	} while (n<=0);
	cout<<"So Fibonacci thu "<<n<<" la: "<<fibo(n-1)<<endl;
	
	//Cau A.
	cout<<"\nDay gom "<<n<<" so Fibonacci dau tien la:\n";
	inNFiboDau(n);
	cout<<endl;
	
	
	//Cau B.
	do{
		cout<<"\nNhap k: ";
		cin>>k;
	} while (k<0);
	cout<<"Day gom "<<k<<" so Fibonacci Chan dau tien la:\n";
	inNFiboChan(k);
	cout<<endl;
	
	//Cau C.
	do{
		cout<<"\nNhap m: ";
		cin>>m;
	} while (m<=0);
	cout<<"So Fibonacci Le thu "<<m<<" la: "<<fiboLe(m);
	cout<<endl;
	
	return 0;
}

unsigned long long fibo(int n){
	if(n==0||n==1) return n;
	return fibo(n-1)+fibo(n-2);
}
void inNFiboDau(int n){
	for(int i=0; i<n; i++){
		cout<<fibo(i)<<" ";
	}
}
void inNFiboChan(int n){
	if(n==0) cout<<endl;
	else{
		int dem=0,i=0;
		do{
			if(fibo(i)%2==0){
				cout<<fibo(i)<<" ";
				dem++;
			}
			i++;
		}while(dem<=n);
	}
}
int fiboLe(int n){
	int dem=0,i=0;
	do{
		if(fibo(i)%2!=0){
			dem++;
		}
		i++;
	} while(dem<n);
	return fibo(i-1);
}

