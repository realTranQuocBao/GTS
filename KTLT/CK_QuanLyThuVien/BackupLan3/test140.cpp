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
struct BOOK{
	char idOfBook[11];		//10 ky tu
	char title[60];			//Ten sach
	char author[60];		//Ten tac gia
	char publisher[60];		//Nhà xuat ban
	int publicationYear;	//Nam xuat ban
	char genre[30];			//The loai
	int coverPrice;			//Giá bìa, mat sach phat 200% gia bia
	int total;				//Tong so sach ma TV có
	int remain;				//Tong so sach ma TV còn
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
	cout<<"\n\t|| 14  : Xuat DANH SACH Doc Gia   || 24  : Xuat muc luc  Sach       ||";
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


BOOK enterABook(){
	BOOK aBook;
	cout<<"Ma sach      : "; cin.getline(aBook.idOfBook,11);
	cout<<"Ten sach     : "; cin.getline(aBook.title,60);
	cout<<"Ten tac gia  : "; cin.getline(aBook.author,60);
	cout<<"Nha xuat ban : "; cin.getline(aBook.publisher,60);
	cout<<"Nam xuat ban : "; cin>>aBook.publicationYear;
	cin.ignore();
	cout<<"The loai     : "; cin.getline(aBook.genre,30);
	cout<<"Gia bia      : "; cin>>aBook.coverPrice;
	cout<<"SL sach co   : "; cin>>aBook.total;
	cout<<"SL sach con  : "; cin>>aBook.remain;	
	cin.ignore();
	return aBook;	
}

void enterListBook(BOOK *listBook, int &totalBook){
	int n;
	cout<<"\nBan muon them bao nhieu Sach?  "; cin>>n;
	cin.ignore();
	int j = 1;
	for(int i=totalBook; i<totalBook+n; i++){
		cout<<"\nMoi ban nhap Thong Tin Sach thu "<<j++<<":\n";
		listBook[i] = enterABook();
		cout<<"Thanh Cong!!!\n";
	}
	totalBook += n;
}


void printABook(BOOK aBook){
	cout<<"\nMa sach      : "<<aBook.idOfBook;
	cout<<"\nTen sach     : "<<aBook.title;
	cout<<"\nTen tac gia  : "<<aBook.author;
	cout<<"\nNha xuat ban : "<<aBook.publisher;
	cout<<"\nNam xuat ban : "<<aBook.publicationYear;
	cout<<"\nThe loai     : "<<aBook.genre;
	cout<<"\nGia bia      : "<<aBook.coverPrice;
	cout<<"\nSL sach co   : "<<aBook.total;
	cout<<"\nSL sach con  : "<<aBook.remain;
}
void printListBook(BOOK *listBook, int totalBook){
	//cout<<"\nDanh sach Thong tin Sach:\n";
	for(int i=0; i<totalBook; i++){
		cout<<"\n\n======= Sach thu "<<i+1<<" =======";
		printABook(listBook[i]);
	}
}


void editABook(BOOK *listBook, int &totalBook, int &n){
	char idOfBook[11];
	cout<<"Nhap Ma Sach can chinh sua: "; cin.getline(idOfBook,11);
	for(int i=0; i<totalBook; i++){
		if(strcmp(idOfBook,listBook[i].idOfBook)==0){
			cout<<"\n     Da tim thay Sach:";
			printABook(listBook[i]);
			cout<<"\n\nMoi ban nhap thong tin moi cho Doc Gia nay:\n";
			//cin.ignore();
			listBook[i] = enterABook();
			n=1;
			cout<<"Thanh Cong!!!\n";
		}
	}
}

void deleteABook(BOOK *listBook, int &totalBook, int &n){
	char idOfBook[11];
	cout<<"Nhap Ma Sach can xoa: "; cin.getline(idOfBook,11);
	for(int i=0; i<totalBook; i++){
		if(strcmp(idOfBook,listBook[i].idOfBook)==0){
			n=1;
			cout<<"\n     Da tim thay Sach:";
			printABook(listBook[i]);
			cout<<"\n\nBan co chac chan Xoa Sach nay?";
			int confirm;
			cout<<"\nNhap (1=co, 0=khong) : ";
			cin>>confirm;
			if(confirm){
				for(int j=i; j<totalBook-1; j++){
					listBook[j] = listBook[j+1];
				}
				totalBook--;
				cout<<"Xoa Sach Thanh Cong!!!\n";
			} else{
				cout<<"Khong Xoa Sach Nay!!!\n";
			}
			break;
		}
	}
}

void sortBookByIdOfBook(BOOK *listBook, int totalBook){
	BOOK temp;
	for(int i=0; i<totalBook-1; i++){
		for(int j=i+1; j<totalBook; j++){
			if(strcmp(listBook[i].idOfBook, listBook[j].idOfBook)>0){
				temp = listBook[i];
				listBook[i] = listBook[j];
				listBook[j] = temp;
			}
		}
	}
}
void sortBookByTitleOfBook(BOOK *listBook, int totalBook){
	BOOK temp;
	for(int i=0; i<totalBook-1; i++){
		for(int j=i+1; j<totalBook; j++){
			if(strcmp(listBook[i].title, listBook[j].title)>0){
				temp = listBook[i];
				listBook[i] = listBook[j];
				listBook[j] = temp;
			}
		}
	}
}
void sortBookByGenreOfBook(BOOK *listBook, int totalBook){
	BOOK temp;
	for(int i=0; i<totalBook-1; i++){
		for(int j=i+1; j<totalBook; j++){
			if(strcmp(listBook[i].genre, listBook[j].genre)>0){
				temp = listBook[i];
				listBook[i] = listBook[j];
				listBook[j] = temp;
			}
		}
	}
}

/////////////////////////////////////
void searchIdOfBook(BOOK *listBook, int totalBook, BOOK *searchBook, int &n){
	char idOfBook[11];
	cout<<"Nhap Ma Sach can tra cuu: "; cin.getline(idOfBook,11);
	for(int i=0; i<totalBook; i++){
		if(strcmp(idOfBook,listBook[i].idOfBook)==0){
			searchBook[n++] = listBook[i];
		}
	}
}
void searchTitle(BOOK *listBook, int totalBook, BOOK *searchBook, int &n){
	char title[60];
	cout<<"Nhap Ten Sach can tra cuu : "; cin.getline(title,60);
	for(int i=0; i<totalBook; i++){
		if(strcmp(title,listBook[i].title)==0){
			searchBook[n++] = listBook[i];
		}
	}
}
void searchGenre(BOOK *listBook, int totalBook, BOOK *searchBook, int &n){
	char genre[30];
	cout<<"Nhap Ten Sach can tra cuu : "; cin.getline(genre,30);
	for(int i=0; i<totalBook; i++){
		if(strcmp(genre,listBook[i].genre)==0){
			searchBook[n++] = listBook[i];
		}
	}
}
///////////////////////////////////


void saveBookToFile(BOOK *listBook, int totalBook){
	ofstream file("BOOKS.bin", ios::binary|ios::trunc);
	for(int i=0; i<totalBook; i++){
		file.write(reinterpret_cast<char *> (&listBook[i]),sizeof(BOOK));
	}
	cout<<"\n               Luu   Sach  thanh cong!!!";
	file.close();
}
void readBookFromFile(BOOK *listBook, int totalBook){
	ifstream file("BOOKS.bin", ios::binary);
	for(int i=0; i<totalBook; i++){
		file.read(reinterpret_cast<char *> (&listBook[i]),sizeof(BOOK));
	}
	file.close();
}

void saveCookieToFile(int totalReader, int totalBook, int totalBorrowReturnRecord){
	ofstream file("COOKIE.tqb", ios::trunc);
	file<<totalReader<<endl;
	file<<totalBook<<endl;
	file<<totalBorrowReturnRecord<<endl;
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
	
	int totalBook = 0;
	int totalReader = 0;
	int totalBorrowReturnRecord = 0;
	
	BOOK *books = new BOOK[100];									//Khoi tao mang 10000 ddaauf sachs, sao cho nay bi tran Data :(
	
	readCookieFromFile(totalReader, totalBook, totalBorrowReturnRecord);
	readBookFromFile(books, totalBook);
	
	int selectFalse = 0; //Còw Lêjnh, Bat thong bao khi chon menu sai
	
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
		//Quan ly Sach
		case 21 :{
			system("cls");
			enterListBook(books,totalBook);
			cout<<"\n\n    Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 22 :{
			system("cls");
			int n=0;
			cin.ignore();
			editABook(books, totalBook, n);
			if(!n){
				cout<<"\nKhong tim thay Sach nay!!!";
			}
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 23 :{
			system("cls");
			int n=0;
			cin.ignore();
			deleteABook(books, totalBook, n);
			if(!n){
				cout<<"\nKhong tim thay Sach nay!!!";
			}
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 24 :{
			system("cls");
			cout<<"\n Danh sach Thong tin Sach,";
			cout<<"\n  chua duoc sap xep (Goc):";
			printListBook(books, totalBook);
			cout<<"\n\n    Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 241:{
			system("cls");
			cout<<"\n Danh sach Thong tin Sach, ";
			cout<<"\nduoc sap xep theo Ma Sach:";
			sortBookByIdOfBook(books, totalBook);
			printListBook(books, totalBook);
			cout<<"\n\n    Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 242:{
			system("cls");
			cout<<"\n Danh sach Thong tin Sach, ";
			cout<<"\nduoc sap xep theo Ten Sach:";
			sortBookByTitleOfBook(books, totalBook);
			printListBook(books, totalBook);
			cout<<"\n\n    Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 243:{
			system("cls");
			cout<<"\n Danh sach Thong tin Sach, ";
			cout<<"\nduoc sap xep theo The Loai:";
			sortBookByGenreOfBook(books,totalBook);
			printListBook(books, totalBook);
			cout<<"\n\n    Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 251:{
			system("cls");
			BOOK *searchBook = new BOOK;
			int n=0;
			cin.ignore();
			searchIdOfBook(books, totalBook, searchBook, n);
			if(n){
				cout<<"\n     Da tim thay Sach:";
				printListBook(searchBook, n);
			} else{
				cout<<"\nKhong tim thay Sach co Ma nay!!!";
			}
			cout<<"\n\n       Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			delete searchBook;
			break;
		}
		case 252:{
			system("cls");
			BOOK *searchBook = new BOOK[100];
			int n=0;
			cin.ignore();
			searchTitle(books, totalBook, searchBook, n);
			if(n){
				cout<<"\n     Da tim thay Sach:";
				printListBook(searchBook, n);
			} else{
				cout<<"\nKhong tim thay Sach co Ten nay!!!";
			}
			cout<<"\n\n       Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			delete[] searchBook;
			break;
		}
		case 253:{
			system("cls");
			BOOK *searchBook = new BOOK[100];
			int n=0;
			cin.ignore();
			searchGenre(books, totalBook, searchBook, n);
			if(n){
				cout<<"\n     Da tim thay Sach:";
				printListBook(searchBook, n);
			} else{
				cout<<"\nKhong tim thay Sach thuoc The Loai nay!!!";
			}
			cout<<"\n\n       Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			delete[] searchBook;
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
			saveBookToFile(books, totalBook);
			saveCookieToFile(totalReader, totalBook, totalBorrowReturnRecord);
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
			saveBookToFile(books, totalBook);
			saveCookieToFile(totalReader, totalBook, totalBorrowReturnRecord);
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
	delete[] books;
	getch();
	return 0;
}


