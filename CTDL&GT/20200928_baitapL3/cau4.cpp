// TQB13 - Tran Quoc Bao

//Cau4 

#include <iostream>
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
	int x;
	do{
		cout<<"Nhap du lieu = ";
		cin>>x;
		if(x<=0) break; 
		NODE *p = getNode(x);
		addTail(l,p);
	} while(x>0);
}
void outputList(LIST &l){
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		cout<<p->data<<" ";
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
void swapData(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void sortUp(LIST &l){
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		for(NODE *q = p->pNext; q != NULL; q = q->pNext){
			if(p->data > q->data) swapData(p->data,q->data);
		}
	}	
}
void deleteDuplicate(LIST &l){
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		while( (p->data == (p->pNext)->data) && (p->pNext != NULL) ){
			NODE *trung = p->pNext;
			if(trung == l.pTail){
				l.pTail = p;
				l.pTail->pNext = NULL;
				delete trung;
			} else{
				p->pNext = trung->pNext; 
				delete trung;
			} 
		}
	}
}
int checkCSC(LIST l){
	int flat = ( (l.pHead->pNext)->data ) - l.pHead->data; 
	for(NODE *k = l.pHead; k != l.pTail; k = k->pNext){
		NODE *next = k->pNext; 
		if( (next->data - k->data)!=flat ) return 0; 
	}
	return 1; 
} 
void giaiPhong(LIST &l){
	NODE *p;
	while (l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

int main(){
	cout<<"*****yeu cau 1*****\n";
	LIST l;
	cout<<"===Nhap danh sach Data gom cac So Nguyen Duong===\n";
	inputList(l);
	cout<<"===Danh sach Data gom cac So Nguyen Duong vua nhap===\n";
	outputList(l);
	
	cout<<"\n*****yeu cau 2*****\n";
	sortUp(l); 
	cout<<"===Danh sach Data gom cac So Nguyen Duong sau khi sap xep===\n";
	outputList(l);
	deleteDuplicate(l); 
	cout<<"===Danh sach Data gom cac So Nguyen Duong sau khi Xoa Trung===\n";
	outputList(l);
	
	cout<<"\n*****yeu cau 3*****\n";
	if( checkCSC(l) ){
		cout<<"Danh sach da xu ly tren la mot CSC";
	} else{
		cout<<"Danh sach da xu ly tren Khong la mot CSC";
	}
	
	return 0;
}
