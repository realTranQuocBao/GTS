// TQB13 - Tran Quoc Bao

//Cau1

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
	int n;
	cout<<"Ban muon nhap bao nhieu Node? ";
	cin>>n;
	init(l);
	for(int i=0; i<n; i++){
		int x;
		do{
			cout<<"Nhap du lieu = ";
			cin>>x;
		} while(x<=0);
		
		NODE *p = getNode(x);
		addTail(l,p);
	}
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
	for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
		for(NODE *q = p->pNext; q != NULL; q = q->pNext){
			if(p->data > q->data) swapData(p->data,q->data);
		}
	}	
}
void mergeTwoLists(LIST lA , LIST lB, LIST &lC){
	int a = len(lA);
	int b = len(lB);
	NODE *p = lA.pHead;
	while(p != NULL){
		addTail(lC, p);
		p = p->pNext;
	}
	p = lB.pHead;
	while(p != NULL){
		addTail(lC, p);
		p = p->pNext;
	}
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
	
	cout<<"\n*****yeu cau 2*****\n";
	cout<<"===Nhap danh sach Data gom cac So Nguyen Duong===\n";
	inputList(l);
	cout<<"===Danh sach Data gom cac So Nguyen Duong vua nhap===\n";
	outputList(l);
	giaiPhong(l);
	
	cout<<"\n*****yeu cau 3*****\n";
	LIST lA, lB, lC;
	cout<<"\n===Nhap danh sach Data A gom cac So Nguyen Duong===\n";
	inputList(lA);
	cout<<"\n===Nhap danh sach Data B gom cac So Nguyen Duong===\n";
	inputList(lB);
	cout<<"===Danh sach Data A gom cac So Nguyen Duong vua nhap===\n";
	outputList(lA);
	cout<<"===Danh sach Data B gom cac So Nguyen Duong vua nhap===\n";
	outputList(lB);
	//Tao Danh sach C
	init(lC);
	mergeTwoLists(lA , lB, lC);
	//Sap xep danh sach C
	sortUp(lC);
	//Xuat danh sach C
	cout<<"\n===Danh sach Data C da Sap Xep tu dsA va dsB===\n";
	outputList(lC);
	giaiPhong(lA);
	giaiPhong(lB);
	giaiPhong(lC);
	return 0;
}
