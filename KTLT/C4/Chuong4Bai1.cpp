// TQB13 - Tran Quoc Bao
/*
Bài 1. Hãy khai báo bien kí tu ch và con tro kieu kí tu pc tro vào bien ch. Viet ra các cách gán giá tri ‘A’ cho bien ch. 
*/

#include <iostream>
using namespace std;
int main(){
	
	char ch; //khai bao bien kitu
	char *pc; //khai bao con tro ki tu
	pc = &ch; //tro con tro pc vào bién ch
	
	ch = 'A'; //Cách 1
	*pc='A'; //Cách 2
	ch = 65; //Cách 3	
	*pc=65; //Cách 4
	ch = 1000001; //Cách 5
	*pc = 1000001; //Cách 6
	ch = 0x41; //Cách 7
	*pc = 0x41; //Cách 8

//	còn hê co sô 8 và 10 nua, ma em ko biet gh :(
	
	cout<<ch; //test
	
	return 0;
}

