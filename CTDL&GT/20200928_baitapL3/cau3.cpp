// TQB13 - Tran Quoc Bao

//Cau3

#include <iostream>
#include <math.h>
using namespace std;

struct NODE{
	int data;
	NODE *pNext;
};
struct LIST{
	NODE *pHead;
	NODE *pTail;
};

void init(LIST &l){
	l.pHead = l.pTail = NULL;
}
NODE *getNode(int x){
	NODE *p = new NODE;
	if(p==NULL){
		cout<<"Het bo nho roi ban eiii :(";
		return NULL;
	} else{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}
void addTail(LIST &l, NODE *p){
	if(l.pHead == NULL){ //=> List dang trong rong
		l.pHead = l.pTail = p;
	} else{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void inputList(LIST &l){
	init(l);
	int x, i=0;
	char c;
	do{
		cout<<"Nhap phan tu thu "<<++i<<" = ";
		cin>>c;
		x = toupper(c);
		if( !((x>='A'&&x<='F')||(x>='0'&&x<='9')) ) break;
		NODE *p = getNode(x);
		addTail(l,p);	
	} while(1);
}
void outputList(LIST &l){
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		switch(p->data){
			case '0':{
				cout<<"0";
				break;
			}
			case '1':{
				cout<<"1";
				break;
			}
			case '2':{
				cout<<"2";
				break;
			}
			case '3':{
				cout<<"3";
				break;
			}
			case '4':{
				cout<<"4";
				break;
			}
			case '5':{
				cout<<"5";
				break;
			}
			case '6':{
				cout<<"6";
				break;
			}
			case '7':{
				cout<<"7";
				break;
			}
			case '8':{
				cout<<"8";
				break;
			}
			case '9':{
				cout<<"9";
				break;
			}
			case 'A':{
				cout<<"A";
				break;
			}
			case 'B':{
				cout<<"B";
				break;
			}
			case 'C':{
				cout<<"C";
				break;
			}
			case 'D':{
				cout<<"D";
				break;
			}
			case 'E':{
				cout<<"E";
				break;
			}
			case 'F':{
				cout<<"F";
				break;
			}
		}
	}
	cout<<endl;
}
int len(LIST l){
	int k=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		k++;
	}
	return k;
}
void chuanHoa(LIST &hexA, int lenB){
	NODE *p;
	for(p = hexA.pHead; --lenB; p = p->pNext);
	hexA.pTail = p;
	p = p->pNext; 
	hexA.pTail->pNext = NULL;
	
	NODE *q;
	while (p != NULL){
		q = p;
		p = p->pNext;
		if(q != NULL) delete q;
	}
}
int getValOfEle(int x){
	switch(x){
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A': return 10;
		case 'B': return 11;
		case 'C': return 12;
		case 'D': return 13;
		case 'E': return 14;
		case 'F': return 15;
	}
}
int hexToOct(LIST hex){
	int oct=0;
	int i=0;
	for(NODE *p = hex.pHead; p != NULL; p = p->pNext){
		oct += pow(getValOfEle(p->data),i++);
	}
	return oct;
}
void soSanh(int a, int b){
	if(a==b) cout<<"=";
	else if(a>b) cout<<">";
	else cout<<"<";
}
void giaiPhong(LIST &l){
	NODE *p;
	while (l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		if(p != NULL) delete p;
	}
}

int main(){
	cout<<"*****yeu cau 1*****\n";
	LIST hexA, hexB;
	
	cout<<"\n*****yeu cau 2*****\n";
	cout<<"\n===Nhap so HEX A===\n";
	inputList(hexA);
	cout<<"\n===Nhap so HEX B===\n";
	inputList(hexB);
	cout<<"\nSo HEX A vua nhap = ";
	outputList(hexA);
	cout<<"\nSo HEX B vua nhap = ";
	outputList(hexB);
	//Chuan hoa so Hex (lam cho 2 chuoi co cung do dai)
	int lenA = len(hexA);
	int lenB = len(hexB);
	if(lenA>lenB) chuanHoa(hexA, lenB);
	else if(lenA<lenB) chuanHoa(hexB, lenA);
	cout<<"\nSo HEX A da chuan hoa = ";
	outputList(hexA);
	cout<<"\nSo HEX B da chuan hoa = ";
	outputList(hexB);
	
	cout<<"\n*****yeu cau 3*****\n";
	//So sanh
	cout<<"\nSo Oct A = "<<hexToOct(hexA);
	cout<<"\nSo Oct B = "<<hexToOct(hexB);
	//Tra KQ
	cout<<"\nVay A";
	soSanh(hexToOct(hexA),hexToOct(hexB));
	cout<<"B.\n";
	
	giaiPhong(hexA);
	giaiPhong(hexB);
	return 0;
}
