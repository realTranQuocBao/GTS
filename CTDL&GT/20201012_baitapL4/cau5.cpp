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

void giaiPhong(LIST &l){
	NODE *p;
	while (l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		if(p != NULL) delete p;
	}
}

int main(){

	return 0;
}
