// TQB13 - Tran Quoc Bao
// Di chuyen vi tri Thu Hoi Bo Nho
// Cap nhat ham tim kiem
// Xoa 1 dong read du o Main
// Chinh sua ham doc-ghi file
// Da fix ham nhap; xuat; doc; ghi Doc Gia
// Da code xong ham search Doc Gia
// Da code xong sua dg
// Da code xong xoa DG
// Da code xong ham gia han the
// Cap nhat ham doc phieu muon o main
// Cap nhat hàm editAReader; deleteAReader
// Cap nhat menu QL Sach
// Cap nhat ham nhap 1/list sach
// cap nhat ham in 1/list sach
// Cap nhat ham doc/ghi file sach 
// cap nhat cac ham sap xep Sach
// cap nhat ham tim kiem sach

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
struct BORROW_RETURN{		//Phieu Muon/Tra
	int numberOrdinalTicket;//So thu tu cua phieu muon
	char idOfReader[6];		//ID doc gia gom 5 ky tu
	int numberBooksToBorrow;//So luong sach muon Muon (1-5)
	char idOfBook[5][11];	//danh sach toi da 5 sach duoc muon.
	DATE borrowDate;		//Ngay muon sach, toi da 7 ngay
	DATE returnDate;		//Ngay tra sach, tre 5k/ngày
	int status;				//Trang thai phieu, 1=Da Tra, 0=Chua Tra
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
	cout<<"\n\t|| 14  : Xuat DANH SACH Doc Gia   || 24  : Xuat MUC LUC  Sach       ||";
	cout<<"\n\t|| 141 :        theo ma Doc Gia   || 241 :      theo ma  Sach       ||";
	cout<<"\n\t|| 142 :       theo ten Doc Gia   || 242 :      theo ten Sach       ||";
	cout<<"\n\t||                                || 243 : theo the loai Sach       ||";
	cout<<"\n\t|| 15x : Tim kiem  Doc Gia        || 25x : Tim kiem Sach            ||";
	cout<<"\n\t|| 151 :  theo Ma  Doc Gia        || 251 :       theo  ma Sach      ||";
	cout<<"\n\t|| 152 :  theo Ten Doc Gia        || 252 :       theo ten Sach      ||";
	cout<<"\n\t||                                || 253 :  theo the loai Sach      ||";
	cout<<"\n\t|| 16  : Gia han the              ||                                ||";
	cout<<"\n\t||===========================MUON_TRA_SACH==========================||";
	cout<<"\n\t|| 31  : Muon Sach                || 34  : Xuat TAT CA phieu muon   ||";
	cout<<"\n\t|| 32  : Tra  Sach                || 35  : Quen Ma Phieu?           ||";
	cout<<"\n\t|| 33  : In thong tin phieu muon  || 36  : Luu phieu muon vao CSDL  ||";
	cout<<"\n\t||=============================THONG_KE=============================||";
	cout<<"\n\t|| 41  : Doc Gia dang muon Sach   || 51  : 10 Sach muon nhieu nhat  ||";
	cout<<"\n\t|| 42  : Doc gia dang tre han tra || 52  : Cac Sach dang duoc muon  ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t|| 0   : THOAT                    || 1   : Xem Thong Tin            ||";
	cout<<"\n\t \\\\=================================================================//";
	if(selectFalse){
		cout<<"\n\t     [THONG BAO]: Chuong trinh khong nhan ra Chuc Nang ban da chon.";
		selectFalse = 0;
	}
	cout<<"\n\n\t\t Moi ban nhap So tuong ung voi cac Chuc Nang: ";
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
	cout<<"\n\n\t               [THONG BAO]: Bam Enter de tro lai Menu               ";
	getch();
	int selectFalse=0;
	showMenu(selectFalse);
}
void thankYou(){
	system("cls");
	cout<<"\n\n\t||\t                                   \t||";
	cout<<"\n\t||\tChuc ban mot ngay lam viec vui ve !  \t||";
	cout<<"\n\t||\t      Cam On va Hen Gap Lai !        \t||";
	cout<<"\n\t||\t                                     \t||";
	cout<<"\n\t||\t            .::CN19B::.              \t||";
	cout<<"\n\t||\t      \"Mua Ha, nam Covi thu I\"       \t||";
	cout<<"\n\t||\t                                     \t||";
}
void rule(){
	system("cls");
	cout<<"\n\t //==========================RULE==QUY=TAC===========================\\\\ ";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||        [ve DOC GIA]            ||            [ve SACH]           ||";
	cout<<"\n\t||    Ma DG :  5 ky tu So         ||    Ma Sach : 10 ky tu So       ||";
	cout<<"\n\t||    Ten   : Go dung chinh ta    ||    Ten   : Go dung chinh ta    ||";
	cout<<"\n\t||    CMND  : 9 hoac 12 ky tu So  ||                                ||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t \\\\=================================================================//";
	cout<<"\n";
}

DATE enterDate(){
	DATE date;
	cout<<"ngay  ";								cin>>date.day;
	cout<<"                          thang ";	cin>>date.month;
	cout<<"                          nam   ";	cin>>date.year;
	return date;
}
int thisIsMagic(DATE date){
    if (date.month < 3) {
        date.year--;
        date.month += 12;
	}
	//Công thuc nay Su dung Magic de bien 1 Ngay(date) thanh 1 con so(Number)
    return 365* date.year + date.year/4 - date.year/100 + date.year/400 + (153*date.month - 457)/5 + date.day - 306;
}
DATE today(){
	int h, min, s;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	h= ltm->tm_hour;
	min= ltm->tm_min;
	s= ltm->tm_sec;
	//L?y nam tháng ngày
	DATE today;
	today.year = 1900 + ltm->tm_year;
	today.month = 1 + ltm->tm_mon;
	today.day = ltm->tm_mday;
	return today;
}
int statusCard(DATE cardExpiry){
	int daysLeft;
	daysLeft = thisIsMagic(cardExpiry)-thisIsMagic(today());
	if(daysLeft<0) return 0;
	else return 1;
}
int overDeadlineReturnBook(DATE borrowDate){
	int numberDayOverDeadline;
	numberDayOverDeadline = thisIsMagic(today()) - thisIsMagic(borrowDate)-7;
	return numberDayOverDeadline;
}
int getNumberOrdinalTicket(int &orderNumber){
	orderNumber++;
	return orderNumber;
}
void printDay(DATE date){
	if(date.day<10) cout<<"0"<<date.day;
	else cout<<date.day;
	cout<<"/";
	if(date.month<10) cout<<"0"<<date.month;
	else cout<<date.month;
	cout<<"/"<<date.year;
}
void printGender(int gender){
	if(gender) cout<<"Nam";
	else if(!gender) cout<<"Nu";
}
void printNull(){
	cout<<"";
}

BORROW_RETURN enterABorrowTicket(int &totalBorrowReturnTicket){
	BORROW_RETURN aBorrowTicket;
	aBorrowTicket.numberOrdinalTicket = totalBorrowReturnTicket+1;
	cout<<"\nSo thu tu phieu muon    : "<<aBorrowTicket.numberOrdinalTicket<<endl;	//He thong tu danh so
	cin.ignore();
	cout<<"Ma Doc Gia              : "; cin.getline(aBorrowTicket.idOfReader,6);
	cout<<"So cuon Sach muon [1-5] : "; cin>>aBorrowTicket.numberBooksToBorrow;
	cin.ignore();
	for(int i=0; i<aBorrowTicket.numberBooksToBorrow; i++){
		cout<<"      Ma Sach thu   "<<i+1<<"   : "; cin.getline(aBorrowTicket.idOfBook[i],11);
	}
	cout<<"Ngay Muon Sach          : "; aBorrowTicket.borrowDate = enterDate();
	aBorrowTicket.status = 0; //Muon=0, tra thi sua lai = 1 + nhap ngay tra
	cin.ignore();
	return aBorrowTicket;
}


void enterListBorrowTicket(BORROW_RETURN *listBorrowReturnTicket, int &totalBorrowReturnTicket){
	cout<<"\nMoi ban nhap Thong Tin Phieu Muon:\n";
	listBorrowReturnTicket[totalBorrowReturnTicket] = enterABorrowTicket(totalBorrowReturnTicket);
	cout<<"\n         Thanh Cong!!!\n";
	totalBorrowReturnTicket+=1;
	//Doi voi BORROW_RETURN moi lan chi cho phep nhap 1 phieu
}

void prisntABorrowReturnTicket(BORROW_RETURN aBorrowTicket){
	cout<<"\nSo Phieu Muon           : "<<aBorrowTicket.numberOrdinalTicket;
	cout<<"\nMa Doc Gia              : "<<aBorrowTicket.idOfReader;
	cout<<"\nHo & Ten Doc Gia        : "<<"Ho van Ten";
	cout<<"\nDoc Gia da muon "<<aBorrowTicket.numberBooksToBorrow<<" quyen sach, gom:";	
	for(int i=0; i<aBorrowTicket.numberBooksToBorrow; i++){
		cout<<"\n          Sach thu  "<<i+1<<"  : "<<aBorrowTicket.idOfBook[i];
		cout<<"\n                        : TEN SACH";
	}			
	cout<<"\nNgay Muon Sach          : "; printDay(aBorrowTicket.borrowDate);			
	cout<<"\nNgay Tra  Sach          : "; (aBorrowTicket.status)?printDay(aBorrowTicket.returnDate):printNull();
	cout<<"\nTinh trang Phieu        : "; (aBorrowTicket.status)?cout<<"da tra. ":cout<<"dang muon. ";
	int overDeadline = overDeadlineReturnBook(aBorrowTicket.borrowDate);
	if(overDeadline>0 && aBorrowTicket.status==0){
		cout<<"DA QUA HAN "<<overDeadline<<" NGAY.";
		cout<<"\nSo tien phai Nop Phat   : "<<overDeadline*5000<<" VND";
	}
}

void returnBook(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket, int &n){
	int numberOrdinalTicket;
	cout<<"Nhap So Phieu muon Tra: "; cin>>numberOrdinalTicket;
	for(int i=0; i<totalBorrowReturnTicket; i++){
		if(numberOrdinalTicket == listBorrowReturnTicket[i].numberOrdinalTicket){
			n = 1;
			cout<<"\nTra thanh cong!!!";
			int overDeadline = overDeadlineReturnBook(listBorrowReturnTicket[i].borrowDate);
			if(overDeadline>0 && listBorrowReturnTicket[i].status==0){
				cout<<"\n\nBan da Qua Han Tra "<<overDeadline<<" ngay.";
				cout<<"\nSo tien phai Nop Phat la : "<<overDeadline*5000<<" VND";
			}
			listBorrowReturnTicket[i].status = 1;
			listBorrowReturnTicket[i].returnDate = today();
			break;
		}
	}
}

int findABorrowReturnTicket(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket, int &n){
	int numberOrdinalTicket;
	cout<<"Nhap So Phieu can xem thong tin: "; cin>>numberOrdinalTicket;
	for(int i=0; i<totalBorrowReturnTicket; i++){
		if(numberOrdinalTicket == listBorrowReturnTicket[i].numberOrdinalTicket){
			n = 1;
			return i;
		}
	}
}

void printListBorrowReturnTicket(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnRecord){
	//cout<<"\nDanh sach Thong tin Phieu Muon:\n";
	for(int i=0; i<totalBorrowReturnRecord; i++){
		cout<<"\n\n====== Phieu Muon "<<i+1<<" =======";
		printABorrowReturnTicket(listBorrowReturnTicket[i]);
	}
}

void forgotNumberOrdinalTicket(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket, BORROW_RETURN *searchNumberOrdinalTicket, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia : "; cin.getline(idOfReader,6);
	for(int i=0; i<totalBorrowReturnTicket; i++){
		if(strcmp(idOfReader,listBorrowReturnTicket[i].idOfReader)==0){
			searchNumberOrdinalTicket[n++] = listBorrowReturnTicket[i];
		}
	}
}

void saveBorrowReturnTicketToFile(BORROW_RETURN *listBorrowReturnRecord, int totalBorrowReturnRecord){
	ofstream file("BORROW_RETURN_RECORDS.bin", ios::binary|ios::trunc);
	for(int i=0; i<totalBorrowReturnRecord; i++){
		file.write(reinterpret_cast<char *> (&listBorrowReturnRecord[i]),sizeof(BORROW_RETURN));
	}
	cout<<"\n               Luu Phieu Muon/Tra thanh cong!!!";
	file.close();
}
void readBorrowReturnTicketFromFile(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket){
	ifstream file("BORROW_RETURN_RECORDS.bin", ios::binary);
	for(int i=0; i<totalBorrowReturnTicket; i++){
		file.read(reinterpret_cast<char *> (&listBorrowReturnTicket[i]),sizeof(BORROW_RETURN));		
	}
	file.close();
}
void saveCookieToFile(int totalReader, int totalBook, int totalBorrowReturnTicket){
	ofstream file("COOKIE.tqb", ios::trunc);
	file<<totalReader<<endl;
	file<<totalBook<<endl;
	file<<totalBorrowReturnTicket<<endl;
	cout<<"\n               Luu  Cookie thanh cong!!!";
	file.close();
}
void readCookieFromFile(int &totalReader, int &totalBook, int &totalBorrowReturnRecord){
	ifstream file("COOKIE.tqb");
	file>>totalReader;
	file>>totalBook;
	file>>totalBorrowReturnRecord;
	file.close();
}


int main(){
	
	int totalReader = 0;
	int totalBook = 0;
	int totalBorrowReturnTicket = 0;
	int selectFalse = 0; //Còw Lêjnh dung chung cho menu chuc nang va menu exit, Bat thong bao khi chon menu sai
	
	BORROW_RETURN *borrowReturnTickets = new BORROW_RETURN[200];	//Khoi tao So ghi Phieu muon tra, 10000 record
	
	readCookieFromFile(totalReader, totalBook, totalBorrowReturnTicket);
	readBorrowReturnTicketFromFile(borrowReturnTickets, totalBorrowReturnTicket);
	
	
	//Hien thi & Xu ly Chon menu
	MenuProcessing:
	showMenu(selectFalse);
	int select;
	cin>>select;
	switch(select){
		//Thong tin & Thoat
		case 0  :{
			system("cls");
			goto confirmExit;
			break;
		}
		case 1  :{
			viewInfo();
			getch();
			goto MenuProcessing;
			break;
		}
		//Muon & Tra sach
		case 31 :{
			system("cls");
			enterListBorrowTicket(borrowReturnTickets, totalBorrowReturnTicket);
			cout<<"\n\n      Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 32 :{
			system("cls");
			int n=0;
			cin.ignore();
			returnBook(borrowReturnTickets, totalBorrowReturnTicket, n);
			if(!n){
				cout<<"Khong tim thay Phieu nay!!!";
			}
			cout<<"\n\n   Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 33 :{
			system("cls");
			int n = 0;
			int i = findABorrowReturnTicket(borrowReturnTickets, totalBorrowReturnTicket, n);
			if(n){
				cout<<"\n======= Thong tin Phieu =======";
				printABorrowReturnTicket(borrowReturnTickets[i]);
			} else{
				cout<<"\n   Khong tim thay Phieu nay!!!";
			}
			cout<<"\n\n     Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 34 :{
			system("cls");
			cout<<"\n    Danh sach Thong tin Phieu Muon,";
			cout<<"\n     duoc sap xep theo Ma Doc Gia:";
			printListBorrowReturnTicket(borrowReturnTickets, totalBorrowReturnTicket);
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 35 :{
			system("cls");
			BORROW_RETURN *searchTicket = new BORROW_RETURN[200];
			int n=0;
			cin.ignore();
			forgotNumberOrdinalTicket(borrowReturnTickets, totalBorrowReturnTicket, searchTicket, n);
			if(n){
				cout<<"\n     Da tim thay cac Phieu:";
				printListBorrowReturnTicket(searchTicket, n);
			} else{
				cout<<"\nKhong tim thay Phie nao tu Doc Gia nay!!!";
			}
			cout<<"\n\n       Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			delete[] searchTicket;
			break;
		}
		case 36 :{
			
			break;
		}
		//Chon sai menu
		default:{
			selectFalse = 1;
			goto MenuProcessing;
			break;
		}
	}
	
	//Xu ly Thoat chuong trinh
	confirmExit:
	system("cls");
	cout<<"\n\t|| Ban da chon Ket Thuc Chuong Trinh.";
	cout<<"\n\t|| Ban co muon LUU du lieu lai khong?";
	cout<<"\n\t||\tnhap Y de  LUU va THOAT;";
	cout<<"\n\t||\tnhap N de  KHONG LUU va THOAT;";
	cout<<"\n\t||\tnhap S de  LUU;";
	cout<<"\n\t||\tnhap M de  TRO LAI Menu;\n";
	if(selectFalse){
		cout<<"\n[THONG BAO] Chuong trinh khong nhan ra chuc nang ban vua nhap.";
		selectFalse = 0;
	}
	cout<<"\n            Moi ban nhap ky tu tuong ung: ";

	int selectExit = toupper(getch());
	switch(selectExit){
		case 'Y':{
			cout<<endl;
			system("cls");
			saveBorrowReturnTicketToFile(borrowReturnTickets, totalBorrowReturnTicket);
			saveCookieToFile(totalReader, totalBook, totalBorrowReturnTicket);
			thankYou();
			goto EndProgram;
			break;
		}
		case 'N':{
			thankYou();
			goto EndProgram;
			break;
		}
		case 'S':{
			cout<<endl;
			system("cls");
			saveBorrowReturnTicketToFile(borrowReturnTickets, totalBorrowReturnTicket);
			saveCookieToFile(totalReader, totalBook, totalBorrowReturnTicket);
			cout<<"\n\n            [THONG BAO] Ban da luu du lieu.";
			cout<<"\n                Nhan enter de tiep tuc!";
			getch();
			goto confirmExit;
			break;
		}
		case 'M':{
			selectFalse = 0;
			showMenu(selectFalse);
			goto MenuProcessing;
			break;
		}
		default: {
			selectFalse = 1;
			goto confirmExit;
			break;
		}
	}
	
EndProgram:
	delete[] borrowReturnTickets;
	getch();
	return 0;
}

