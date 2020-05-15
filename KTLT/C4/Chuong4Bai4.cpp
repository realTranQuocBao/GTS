// TQB13 - Tran Quoc Bao

#include <iostream>
using namespace std;

// 1. Khai báo cau truc du lieu so nguyen
struct NODE{
	int Data;
	struct NODE *pNext;
};

struct LIST{
	NODE *pHead;
	NODE *pTail;
};

// 2. Khoi tao dslkd
void init(LIST &l){
	l.pHead = l.pTail = NULL;
}

// 3. Tao NODE trong danh sách
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

//Them node p vào dàu list
void addHead(LIST &l, NODE *p){
	if(l.pHead == NULL){ //neu list rõng
		l.pHead = l.pTail = p;
	} else{
		p->pNext = l.pHead; // p dua lk cho head
		l.pHead = p; // p tro thanh head
	}
}
//Them node p vào cuoi list
void addTail(LIST &l, NODE *p){
	if(l.pHead == NULL){ //neu list rõng
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
		addTail(l,p); // Them cuói : 12345
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

// Hoan Vi
void hoanVi(int &a, int &b){
	int tam;
	tam = a;
	a = b;
	b = tam;
}
// sap xep Tang
void sortUp(LIST &l){
	for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
		for(NODE *q = p->pNext; q != NULL; q = q->pNext){
			if(p->Data > q->Data){
				hoanVi(p->Data,q->Data);
			}
		}
	}
}
// sap xep Giam
void sortDown(LIST &l){
	for(NODE *p = l.pHead; p != l.pTail; p = p->pNext){
		for(NODE *q = p->pNext; q != NULL; q = q->pNext){
			if(p->Data < q->Data){
				hoanVi(p->Data,q->Data);
			}
		}
	}
}

// dem so phan tu trong list
int len(LIST l){
	int k=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		k++;
	}
	return k;
}

// Them node p vào vi tri q
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

//Xóa node p dàu list
void deleteHead(LIST &l){
	NODE *t = l.pHead;
	l.pHead = l.pHead->pNext;
	delete t;
}
//Xóa node p cuói list
void deleteTail(LIST &l){
	if(len(l)==1){
		l.pHead=l.pTail=NULL;
		return;
	}
	NODE *g = l.pHead;
	NODE *t = l.pTail;
	while(g->pNext != l.pTail){
		g = g->pNext;
	}
	//if(g->pNext == l.pTail) cout<<"Bao dep trai";
	l.pTail = g;
	l.pTail->pNext = NULL;
	delete t;
}
//Xóa node p tai vitri k cua list
void deleteTail(LIST &l, int k){
	
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
	
	int Q, k;
	cout<<"\nNhap Q muon them: ";
	cin>>Q;
	NODE *q= getNode(Q);
	cout<<"Nhap vi tri k muon them: ";
	cin>>k;
	cout<<"DS sau khi them:";
	addNodeTok(l,q,k);
	outputList(l);
	
	cout<<"\nDS sau khi xoa dau:";
	deleteHead(l);
	outputList(l);
	cout<<"\nDS sau khi xoa cuoi:";
	deleteTail(l);
	outputList(l);
	
	cout<<"\nDS sau sap xep Tang:";
	sortUp(l);
	outputList(l);
	
	cout<<"\nDS sau sap xep Giam:";
	sortDown(l);
	outputList(l);
	
	cout<<"\nSo phan tu hien tai trong List la: "<<len(l)<<endl;
	
	giaiPhong(l);
	return 0;
}

