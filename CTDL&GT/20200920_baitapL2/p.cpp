#include <iostream>
#include <math.h>
using namespace std;

struct dssn {
    int data;
    struct dssn * next;
};
typedef struct dssn DSSN;
struct list{
	DSSN *head;
	DSSN *tail;
};
typedef struct list LIST;

void KhoiTao(LIST &a) {
    a.head = NULL;
    a.tail = NULL;
}
DSSN* KhoiTaoDSSN(int x) {
    DSSN *p = new DSSN;
    if (p == NULL) {
        cout << "Khong du bo nho de cap phat!" << endl;
        return NULL;
    }
    p -> data = x;
    p -> next = NULL;
    return p;
}
void ThemVaoCuoi(LIST & a, DSSN * p) {
    if (a.tail == NULL) {
        a.head = a.tail = p;
    } else {
        a.tail -> next = p;
        a.tail = p;
    }
}
void TaoDS(LIST &a, int x) {
     KhoiTao(a);
   	cout<<"Nhap cac co so (x^0 -=> x^n): "<<endl;
	for (int i=0; i<=x;i++) {
		int data;
		cout<<"Co so cua x^"<<i<<'\t';
		cin>>data;
		DSSN *p;
		p = KhoiTaoDSSN(data);
		ThemVaoCuoi(a,p);	
	}
}
int TinhFx( LIST a){
	int sum=0;
	int i=0, x;
	cout<<"Nhap gia tri x ";
	cin>>x;
	for(DSSN *k = a.head; k != NULL; k = k -> next) {
	sum= sum + (k->data)*pow(x,i);
	i++;	
	}
	cout<<"Gia tri cua f(x)= "<<sum;
}
int main() {
	LIST a;
	KhoiTao(a);
	int n;
	cout<<"Nhap bac cua ham so ";
	cin>>n;
	TaoDS(a, n);
	TinhFx(a);
}
