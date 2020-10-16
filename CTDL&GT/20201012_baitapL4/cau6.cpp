// TQB13 - Tran Quoc Bao

//Stack
	//IsEmpty	: kiem tra stack co rong hay khong
	//Push		: them 1 doi tuong vao dau stack <theo co che LIPO>
	//Pop		: Lay phan tu dau stack va tra ve gia tri cua doi tuong dau stack
	//Top		: xem thong tin cua stack da danh sach và Khong huy no
	
#include <iostream>
using namespace std;

struct NODE{
	int data;
	NODE *pNext;
};
struct STACK{
	NODE *pTop;
};

void init(STACK s){
	s.pTop == NULL;
}
bool isEmpty(STACK s){
	if(s.pTop == NULL){
		return true;
	}
	return false;
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
bool push(STACK &s, NODE *p){
	if(p == NULL) return false;
	if(isEmpty(s)){
		s.pTop = p;
	} else{
		p->pNext = s.pTop;
		s.pTop = p;
	}
	return true;
}
int pop(STACK &s){
	if(isEmpty(s)){
		cout<<" !!!danh sach rong!!! ";
	} else{
		int x;
		NODE *p = s.pTop;
		x = p->data;
		s.pTop = s.pTop->pNext;
		delete p;
		return x;
	}
}
int top(STACK s){
	if(isEmpty(s)){
		cout<<" !!!danh sach rong!!! ";
	} else{
		int x;
		x = s.pTop->data;
		return true;
	}
}
void printStack(STACK s){
	if(isEmpty(s)) cout<<"\nDanh sach rong ne ban oi!!!";
	while(!isEmpty(s)){
		cout<<pop(s)<<"\t";
	}
}
void inputStack(STACK &s){
	int select;
	while(true){
		//system("cls");
		cout<<"\n\n\t\t========== ===== MENU ===== ==========";
		cout<<"\n\n\t\t1. Them phan thu vao stack";
		cout<<"\n\n\t\t2. Xuat danh sach stack ra man hinh";
		cout<<"\n\n\t\t0. Ket thuc";
		cout<<"\n\n\t\t========== ===== END  ===== ==========";
		
		cout<<"\nNhap lua chon: ";
		cin>>select;
		
		if(select == 1){
			int x;
			cout<<"Nhap phan tu can them: ";
			cin>>x;
			NODE *p = getNode(x);
			push(s, p);
		} else if(select == 2){
			printStack(s);
		} else break;
	}
}
void giaiPhong(STACK &s){
	NODE *p;
	while (s.pTop != NULL){
		p = s.pTop;
		s.pTop = s.pTop->pNext;
		if(p != NULL) delete p;
	}
}

int main(){
	STACK s;
	inputStack(s);
	
	//giaiPhong(s);
	return 0;
}
