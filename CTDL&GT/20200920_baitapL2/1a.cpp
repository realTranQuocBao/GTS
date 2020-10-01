// TQB13 - Tran Quoc Bao

#include <iostream>
#include <math.h>
using namespace std;

// 1. Khai b�o cau truc du lieu so nguyen
struct NODE{
	int Data;
	NODE *pNext;
};

struct LIST{
	NODE *pHead;
	NODE *pTail;
};

// 2. Khoi tao dslkd
void init(LIST &l){
	l.pHead = l.pTail = NULL;
}

// 3. Tao NODE trong danh s�ch
NODE *getNode(int x){
	NODE *p = new NODE;
	
	if(p == NULL){
		return NULL;
	} else{
		p->Data = x;
		p->pNext = NULL;
	}	
	return p;
}

// 4. Add node (dau/cuoi/tuychon)

//Them node p v�o d�u list
void addHead(LIST &l, NODE *p){
	if(l.pHead == NULL){ //neu list r�ng
		l.pHead = l.pTail = p;
	} else{
		p->pNext = l.pHead; // p dua lk cho head
		l.pHead = p; // p tro thanh head
	}
}
//Them node p v�o cuoi list
void addTail(LIST &l, NODE *p){
	if(l.pHead == NULL){ //neu list r�ng
		l.pHead = l.pTail = p;
	} else{
		l.pTail->pNext = p; // pTail dua lk cho p
		l.pTail = p; // p tro thanh tail
	}
}

// 5. Nhap /xuat du lieu cho list
void inputList(LIST &l){
	int n;
	cout<<"Nhap muon nhap So Node = ";
	cin>>n;
	init(l);
	for(int i=1; i<=n; i++){
		int x;
		cout<<"Nhap du lieu = ";
		cin>>x;
		NODE *p = getNode(x); // dua data vao con tro node p
	//	addHead(l,p); // Them dau : 54321
		addTail(l,p); // Them cu�i : 12345
	}
}

void outputList(LIST &l){
	cout<<endl;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){   //p != NULL <=> p
		cout<<p->Data<<'\t';
	}
	cout<<endl;
}

// 6. Xu ly blabla

//dem SNT
int checkSNT(int x){
	for(int i=2; i<=sqrt(x); i++){
		if(x%i == 0) return 0;
	}
	return 1;
}
int demSNT(LIST l){
	int k=0;
	for(NODE *tmp = l.pHead; tmp != NULL; tmp = tmp->pNext){
		if(checkSNT(tmp->Data)) k++;
	}
	return k;
}

// dem so phan tu trong list
int len(LIST l){
	int k=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		k++;
	}
	return k;
}

// Them node p v�o vi tri q
void addNodeTok(LIST &l, NODE *q, int k){
	if(k==0){
		addHead(l,q);
		return; //ket thuc
	}
	int i=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		i++;
		if(i+1 == k){
			NODE *t = p->pNext;
			p->pNext = q;
			q->pNext = t;
			return; //ket thuc
		}
	}
}

// 7. Giai Phong
void giaiPhong(LIST &l){
	NODE *p;
	while (l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		delete p;
	}
}

int main(){
	LIST l;
	cout<<"NHAP DS";
	inputList(l);
	cout<<"\nXUAT DS";
	outputList(l);

	cout<<"\nDanh sach tren co "<<demSNT(l)<<" So Nguyen To.\n";
	
	giaiPhong(l);
	return 0;
}

