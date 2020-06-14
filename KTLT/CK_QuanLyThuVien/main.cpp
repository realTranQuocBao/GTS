// TQB13 - Tran Quoc Bao

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std;
struct DATE{
	int day;
	int month;
	int year;
};
struct READERS{
	char idOfReaders[5];	//ID doc gia gom 5 ky tu
	char lastName[30];		//Ho hoac Ho+Ten Lot
	char firstName[30];		//Ten
	char idCard[12];		//So CMND gom 9 hoac 12 ky tu so
	DATE dayOfBirth;		//Ngay sinh
	int gender;				//Gioi tinh, 0 = Nu, 1 = Nam
	char phoneNumber[11];	//SoDT gom 10 hoac 11 so
	char email[40];			//Hop thu dien tu
	char address[256];		//dia chi trong demo de tinh thoi cho gon gang
	DATE cardIssuing;		//Ngay phat hanh the , Khi gia han se cap the moi cung ID
	DATE cardExpiry;		//Ngay het han the khoi tao = Ngay lam the + tròn 1 nam.
	//Cân 1 ý tuong cho Gia Han The, Gia han cai gì? Ngay Phat Hanh (cap the moi) hay la cap nhat HSD.
};
struct BOOK{
	char idOfBook[10];		//10 ky tu
	char title[60];			//Ten sach
	char author[60];		//Ten tac gia
	char publisher[30];		//Nhà xuat ban
	int publicationYear;	//Nam xuat ban
	char genre[30];			//The loai
	int coverPrice;			//Giá bìa, mat sach phat 200% gia bia
	int totalNumber;		//Tong so sach ma TV có
	int totalRemaining;		//Tong so sach ma TV còn
};
struct BORROW_RETURN{		//Phieu Muon/Tra
	int numberOrdinalTicket;//So thu tu cua phieu muon
	char idOfReaders[5];	//ID doc gia gom 5 ky tu
	char idOfBook[5][10];	//danh sach toi da 5 sach duoc muon.
	DATE borrowDate;		//Ngay muon sach, toi da 7 ngay
	DATE returnDate;		//Ngay tra sach, tre 5k/ngày
	int status;				//Trang thai phieu, 1=Da Tra, 0=Chua Tra
};
void viewInfo();
void confirmExit();
void showMenu(int &selectFalse);

int main(){
	
	int selectFalse = 0;				//Còw Lêjnh, Bat thong bao khi chon menu sai
	READERS readers[1000];						//Khoi tao mang 1000 doc gia
	BORROW_RETURN borrowReturnRecord[10000];	//Khoi tao So ghi Phieu muon tra, 10000 record
	BOOK books[9500];							//Khoi tao mang 10000 ddaauf sachs, sao cho nay bi tran Data :(
	showMenu(selectFalse);

	return 0;
}

void viewInfo(){
	system("cls");
	cout<<"\n\t //=================================================================\\\\ ";
	cout<<"\n\t||                        Thong Tin De Tai                          ||";
	cout<<"\n\t||                  CHUONG TRINH QUAN LY THU VIEN                   ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||  [Thong tin Thanh vien Nhom]   ||      [Thong tin Mon hoc]       ||";
	cout<<"\n\t||    01. Phan Thi Ngoc Anh       ||                                ||";
	cout<<"\n\t||        MSSV: 195 112 0082      || Hoc Phan : Ky thuat lap trinh  ||";
	cout<<"\n\t||    02. Tran Quoc Bao           ||  Ma HP   :     0101124001      ||";
	cout<<"\n\t||        MSSV: 195 112 0086      || Nhom HP  :         02          ||";
	cout<<"\n\t||    03. Nguyen Thi Tra My       ||   GV     :   Nguyen Van Huy    ||";
	cout<<"\n\t||        MSSV: 195 112 0111      ||                                ||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||             Lop CN19B - Khoa CNTT - DH GTVT Tp.HCM               ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||        Thank you for all       ||           ;  TQB13  ;          ||";
	cout<<"\n\t \\\\=================================================================//";
	cout<<"\n\n\t               [THONG BAO]: Bam Enter de tro lai Menu             \n";
};
void confirmExit(){
	cout<<"hic :( ban muon thoat that a???";
};
void showMenu(int &selectFalse){
	//Giao dien Menu
	system("cls");
	cout<<"\n\t //==============================MENU==============================\\\\ ";
	cout<<"\n\t||                  CHUONG TRINH QUAN LY THU VIEN                   ||";
	cout<<"\n\t||=============================QUAN_LY==============================||";
	cout<<"\n\t|| 11  : Them Doc Gia             || 21  : Them Sach                ||";
	cout<<"\n\t|| 12  : Sua thong tin Doc Gia    || 22  : Sua thong tin Sach       ||";
	cout<<"\n\t|| 13  : Xoa Doc Gia              || 23  : Xoa Sach                 ||";
	cout<<"\n\t|| 14x : Xuat DANH SACH Doc Gia   || 24x : Xuat muc luc  Sach       ||";
	cout<<"\n\t|| 141 :        theo ma Doc Gia   || 241 :      theo ma  Sach       ||";
	cout<<"\n\t|| 142 :       theo ten Doc Gia   || 242 :      theo ten Sach       ||";
	cout<<"\n\t||                                || 243 : theo the loai Sach       ||";
	cout<<"\n\t|| 15x : Tim kiem  Doc Gia        || 25x : Tim kiem Sach            ||";
	cout<<"\n\t|| 151 :  theo Ma  Doc Gia        || 251 :        theo ma Sach      ||";
	cout<<"\n\t|| 152 :  theo Ten Doc Gia        || 252 :        theo ma Sach      ||";
	cout<<"\n\t||                                || 253 :  theo the loai Sach      ||";
	cout<<"\n\t|| 16  : Gia han the              ||                                ||";
	cout<<"\n\t||===========================MUON_TRA_SACH==========================||";
	cout<<"\n\t|| 31  : Muon Sach                || 32  : Tra Sach                 ||";
	cout<<"\n\t||=============================THONG_KE=============================||";
	cout<<"\n\t|| 41  : Doc Gia dang muon Sach   || 51 : 10 Sach muon nhieu nhat   ||";
	cout<<"\n\t|| 42  : Doc gia dang tre han tra || 52 : Cac Sach dang duoc muon   ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t|| 0   : THOAT                    || 1  : Xem Thong Tin             ||";
	cout<<"\n\t \\\\=================================================================//";
	if(selectFalse){
		cout<<"\n\t     [THONG BAO]: Chuong trinh khong nhan ra Chuc Nang ban da chon.";
		selectFalse = 0;
	}
	cout<<"\n\t\t Moi ban nhap So tuong ung voi cac Chuc Nang: ";
	//Xu ly Chon menu
	int select;
	cin>>select;
	switch(select){
		//Thong tin & Thoat
		case 0:{
			confirmExit();
			break;
		}
		case 1:{
			viewInfo();
			break;
		}
		//Quan ly Doc Gia
		case 11:
		case 12:
		case 13:
		case 141:
		case 142:
		case 151:
		case 152:
		case 16:
		//Quan ly Sach
		case 21:
		case 22:
		case 23:
		case 241:
		case 242:
		case 243:
		case 251:
		case 252:
		case 253:
		//Muon & Tra sach
		case 31:
		case 32:
		//Thong ke
		case 41:
		case 42:
		case 51:
		case 52:
		//Chon sai menu
		default:{
			selectFalse = 1;
			showMenu(selectFalse);
			break;
		}
	}
}
