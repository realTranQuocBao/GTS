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
		cout<<"Khong du bo nho de khoi tao!";
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
// dem so phan tu trong list
int len(LIST l){
	int k=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){
		k++;
	}
	return k;
}

// 5. Nhap /xuat du lieu cho list
void inputList(LIST &l){
	int n;
	cout<<"\nBac cao nhat cua ham so = ";
	cin>>n;
	n++;
	init(l);
	for(int i=n; i>=1; i--){
		int x;
		cout<<"Nhap He So cua x^"<<i-1<<" = ";
		cin>>x;
		NODE *p = getNode(x); // dua data vao con tro node p
	//	addHead(l,p); // Them dau : 54321
		addTail(l,p); // Them cu�i : 12345
	}
}

void outputFunction(LIST &l){
	int k=len(l)-1;
	int sum=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){   //p != NULL <=> p
		sum+=(p->Data);
		if(p->Data==0) cout<<"";
		else if(p->Data==1 && k!=0) cout<<"x^"<<k;
		else if(k>1) cout<<p->Data<<"x^"<<k;
		else if(k==1) cout<<p->Data<<"x";
		else if(k==0) cout<<p->Data;
		k--;
		if( (p->pNext!=NULL)&&((p->pNext)->Data!=0) ) cout<<" + ";
	}
	if(!sum) cout<<"0";
	cout<<endl;
}

// 6. Xu ly blabla

long long f(LIST &l, int x){
	int k=len(l)-1;
	int sum=0;
	for(NODE *p = l.pHead; p != NULL; p = p->pNext){   //p != NULL <=> p
		sum+=( p->Data * pow(x,k--) );
	}
	return sum;
}

void congHaiHamSo(LIST fx, LIST gx, LIST &hx, int k){
	init(hx);
	
	NODE *f, *g;
	f=fx.pHead;
	g=gx.pHead;
	
	int lech=abs(len(fx)-len(gx));
	
	
	if( len(fx)>len(gx) ){
		
		for(int i=k;i>k-lech; i--){
			NODE *p = new NODE;
			p->Data = f->Data;
			addTail(hx,p);
			f = f->pNext;
			delete p;
		}
	} else{
		for(int i=k;i>k-lech; i--){
			NODE *p;
			p->Data = g->Data;
			addTail(hx,p);
			g = g->pNext;
		}
	}
	
	for(int i=k-lech; i>=1; i--){
		NODE *p;
		p->Data = f->Data + g->Data;
		addTail(hx,p);
		f = f->pNext;
		g = g->pNext;
	}
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
	LIST fx;
	cout<<"NHAP HE SO CHO HAM SO F(X)";
	inputList(fx);
	cout<<"\nXUAT HAM SO";
	cout<<"\nf(x) = "; outputFunction(fx);
	
	int x;
	cout<<"\nNhap x = ";
	cin>>x;
	cout<<"Ket qua f("<<x<<") = "<<f(fx,x);

	LIST gx;
	cout<<"\n\nNHAP HE SO CHO HAM SO G(X)";
	inputList(gx);
	cout<<"\nXUAT HAM SO";
	cout<<"\ng(x) = "; outputFunction(gx);
	
	LIST hx;
	congHaiHamSo(fx,gx,hx,(len(fx)>len(gx))?len(fx):len(gx));
	cout<<"\nHam so h(x) = f(x)+g(x) = "; outputFunction(hx);
	
	giaiPhong(fx);
	return 0;
}

