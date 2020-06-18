// TQB13 - Tran Quoc Bao
// Di chuyen vi tri Thu Hoi Bo Nho
//Cap nhat ham tim kiem

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
struct READER{
	char idOfReader[6];		//ID doc gia gom 5 ky tu
	char lastName[30];		//Ho hoac Ho+Ten Lot
	char firstName[30];		//Ten
	char idCard[13];		//So CMND gom 9 hoac 12 ky tu so
	DATE dayOfBirth;		//Ngay sinh
	int gender;				//Gioi tinh, 0 = Nu, 1 = Nam
	char phoneNumber[12];	//SoDT gom 10 hoac 11 so
	char email[60];			//Hop thu dien tu
	char address[256];		//dia chi trong demo de tinh thoi cho gon gang
	DATE cardIssuing;		//Ngay phat hanh the , Khi gia han se cap the moi cung ID
	DATE cardExpiry;		//Ngay het han the khoi tao = Ngay lam the + tròn 1 nam.
	//Gia han = cap nhat +1 nam vao Thoi han the
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
struct BORROW_RETURN{		//Phieu Muon/Tra
	int numberOrdinalTicket;//So thu tu cua phieu muon
	char idOfReader[6];		//ID doc gia gom 5 ky tu
	int numberBooksToBorrow;//So luong sach muon Muon (1-5)
	char idOfBook[5][10];	//danh sach toi da 5 sach duoc muon.
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
	cout<<"\n\t||    CMND  : 9 hoac 12 ky tu So  ||  Ma HP   :     0101124001      ||";
	cout<<"\n\t||        MSSV: 195 112 0086      || Nhom HP  :         02          ||";
	cout<<"\n\t||    03. Nguyen Thi Tra My       ||   GV     :   Nguyen Van Huy    ||";
	cout<<"\n\t||        MSSV: 195 112 0111      ||                                ||";
	cout<<"\n\t||                                ||                                ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||             Lop CN19B - Khoa CNTT - DH GTVT Tp.HCM               ||";
	cout<<"\n\t||==================================================================||";
	cout<<"\n\t||        Thank you for all       ||           ;  TQB13  ;          ||";
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

READER enterAReader(){
	READER aReader;
	cout<<"Ma Doc Gia              : "; cin.getline(aReader.idOfReader,6);
	cout<<"Ho & Ten Lot            : "; cin.getline(aReader.lastName,30);	
	cout<<"Ten                     : "; cin.getline(aReader.firstName,30);		
	cout<<"So CMND                 : "; cin.getline(aReader.idCard,13);	
	cout<<"Ngay sinh               : "; aReader.dayOfBirth=enterDate();			
	cout<<"Gioi tinh (1:Nam, 0:Nu) : "; cin>>aReader.gender;
	cin.ignore();		
	cout<<"So dien thoai           : "; cin.getline(aReader.phoneNumber,12);		
	cout<<"Email                   : "; cin.getline(aReader.email,60);	
	cout<<"Dia chi                 : "; cin.getline(aReader.address,256);	
	cout<<"Ngay lap the            : "; aReader.cardIssuing = enterDate();			
	cout<<"Ngay het han            : "; aReader.cardExpiry = enterDate();
	cin.ignore();
	return aReader;
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
BORROW_RETURN enterABorrowRecord(int &totalBorrowReturnRecord){
	BORROW_RETURN aBorrowRecord;
	aBorrowRecord.numberOrdinalTicket = totalBorrowReturnRecord+1;
	cout<<"\nSo thu tu phieu muon    : "<<aBorrowRecord.numberOrdinalTicket<<endl;	//He thong tu danh so
	cin.ignore();
	cout<<"Ma Doc Gia              : "; cin.getline(aBorrowRecord.idOfReader,6);
	cout<<"So cuon Sach muon [1-5] : "; cin>>aBorrowRecord.numberBooksToBorrow;
	cin.ignore();
	for(int i=0; i<aBorrowRecord.numberBooksToBorrow; i++){
		cout<<"      Ma Sach thu   "<<i+1<<"   : "; cin.getline(aBorrowRecord.idOfBook[i],11);
	}
	cout<<"Ngay Muon Sach          : "; aBorrowRecord.borrowDate = enterDate();
	aBorrowRecord.status = 0; //Muon
	cin.ignore();
	return aBorrowRecord;
}

void enterListReader(READER *listReader, int &totalReader){
	int n;
	cout<<"\nBan muon them bao nhieu Doc Gia?  "; cin>>n;
	cin.ignore();
	int j = 1;
	for(int i=totalReader; i<totalReader+n; i++){
		cout<<"\nMoi ban nhap Thong Tin Doc Gia thu "<<j++<<":\n";
		listReader[i] = enterAReader();
		cout<<"Thanh Cong!!!\n";
	}
	totalReader += n;
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
void enterListBorrowRecord(BORROW_RETURN *listBorrowReturnRecord, int &totalBorrowReturnRecord){
	cout<<"\nMoi ban nhap Thong Tin Phieu Muon:\n";
	listBorrowReturnRecord[totalBorrowReturnRecord] = enterABorrowRecord(totalBorrowReturnRecord);
	cout<<"\n         Thanh Cong!!!\n";
	totalBorrowReturnRecord+=1;
}

void printAReader(READER aReader){
	cout<<"\nMa Doc Gia              : "<<aReader.idOfReader;
	cout<<"\nHo & Ten                : "<<aReader.lastName<<" "<<aReader.firstName;		
	cout<<"\nSo CMND                 : "<<aReader.idCard;	
	cout<<"\nNgay sinh               : "; printDay(aReader.dayOfBirth);			
	cout<<"\nGioi tinh (1:Nam, 0:Nu) : "; printGender(aReader.gender);
	cout<<"\nSo dien thoai           : "<<aReader.phoneNumber;		
	cout<<"\nEmail                   : "<<aReader.email;	
	cout<<"\nDia chi                 : "<<aReader.address;	
	cout<<"\nNgay lap the            : "; printDay(aReader.cardIssuing);			
	cout<<"\nNgay het han            : "; printDay(aReader.cardExpiry);
	cout<<"\nTrang thai the          : "; ( statusCard(aReader.cardExpiry) )?( cout<<"Dang Hoat Dong" ):( cout<<"HET HAN Hoat Dong" );
}
void printListReader(READER *listReader, int totalReader){
	//cout<<"\nDanh sach Thong tin Doc Gia:\n";
	for(int i=0; i<totalReader; i++){
		cout<<"\n\n       Doc Gia thu "<<i+1<<" : ";
		printAReader(listReader[i]);
	}
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
	cout<<"\nDanh sach Thong tin Sach:\n";
	for(int i=0; i<totalBook; i++){
		cout<<"\n\n        Doc Gia thu "<<i+1<<" : ";
		printABook(listBook[i]);
	}
}

void sortReaderByIdOfReader(READER *listReader, int totalReader){
	READER temp;
	for(int i=0; i<totalReader-1; i++){
		for(int j=i+1; j<totalReader; j++){
			if(strcmp(listReader[i].idOfReader, listReader[j].idOfReader)>0){
				temp = listReader[i];
				listReader[i] = listReader[j];
				listReader[j] = temp;
			}
		}
	}
}
void sortReaderByFirstName(READER *listReader, int totalReader){
	READER temp;
	for(int i=0; i<totalReader-1; i++){
		for(int j=i+1; j<totalReader; j++){
			if(strcmp(listReader[i].firstName, listReader[j].firstName)>0){
				temp = listReader[i];
				listReader[i] = listReader[j];
				listReader[j] = temp;
			}
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

int searchIdOfReader(READER *listReader, int totalReader, READER *searchReader, int n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can tra cuu: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			searchReader[n++] = listReader[i];
		}
	}
	return n;
}

void saveReaderToFile(READER *listReader, int totalReader){
	ofstream file("READERS.bin", ios::binary|ios::trunc);
	for(int i=0; i<totalReader; i++){
		file.write(reinterpret_cast<char *> (&listReader[i]),sizeof(READER));
	}
	cout<<"\n               Luu Doc Gia thanh cong!!!";
	file.close();
}
void readReaderFromFile(READER *listReader, int totalReader){
	ifstream file("READERS.bin", ios::binary);
	for(int i=0; i<totalReader; i++){
		file.read(reinterpret_cast<char *> (&listReader[i]),sizeof(READER)*(totalReader+1));
	}
	file.close();
}
void saveBookToFile(BOOK *listBook, int totalBook){
	ofstream file("BOOKS.bin", ios::binary|ios::trunc);
	file.write(reinterpret_cast<char *> (&listBook),sizeof(BOOK)*(totalBook+1));
	cout<<"\n               Luu   Sach  thanh cong!!!";
	file.close();
}
void readBookFromFile(BOOK *listBook, int totalBook){
	ifstream file("BOOKS.bin", ios::binary);
	file.read(reinterpret_cast<char *> (&listBook),sizeof(BOOK)*(totalBook+1));
	file.close();
}
void saveBorrowReturnRecordToFile(BORROW_RETURN *listBorrowReturnRecord, int totalBorrowReturnRecord){
	ofstream file("BORROW_RETURN_RECORDS.bin", ios::binary|ios::trunc);
	file.write(reinterpret_cast<char *> (&listBorrowReturnRecord),sizeof(BORROW_RETURN)*(totalBorrowReturnRecord+1));
	cout<<"\n               Luu   Sach  thanh cong!!!";
	file.close();
}
void readBorrowReturnRecordFromFile(BORROW_RETURN *listBorrowReturnRecord, int totalBorrowReturnRecord){
	ifstream file("BORROW_RETURN_RECORDS.bin", ios::binary);
	file.read(reinterpret_cast<char *> (&listBorrowReturnRecord),sizeof(BORROW_RETURN)*(totalBorrowReturnRecord+1));
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
	
	READER *readers = new READER[100];								//Khoi tao mang 1000 doc gia
	BORROW_RETURN *borrowReturnRecords = new BORROW_RETURN[200];	//Khoi tao So ghi Phieu muon tra, 10000 record
	BOOK *books = new BOOK[100];									//Khoi tao mang 10000 ddaauf sachs, sao cho nay bi tran Data :(
	
	readCookieFromFile(totalReader, totalBook, totalBorrowReturnRecord);
	readReaderFromFile(readers, totalReader);
	readBookFromFile(books, totalBook);
	readBorrowReturnRecordFromFile(borrowReturnRecords, totalBorrowReturnRecord);
	
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
		//Quan ly Doc Gia
		case 11 :{
			system("cls");
			enterListReader(readers,totalReader);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 12 :
		case 13 :
		case 14 :{
			system("cls");
			cout<<"\n      Danh sach Thong tin Doc Gia,";
			cout<<"\n        chua duoc sap xep (Goc):    ";
			printListReader(readers, totalReader);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 141:{
			system("cls");
			sortReaderByIdOfReader(readers,totalReader);
			cout<<"\n      Danh sach Thong tin Doc Gia,";
			cout<<"\n     duoc sap xep theo Ma Doc Gia:";
			printListReader(readers, totalReader);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 142:{
			system("cls");
			cout<<"\n     Danh sach Thong tin Doc Gia,";
			cout<<"\n        duoc sap xep theo Ten:   ";
			sortReaderByFirstName(readers, totalReader);
			printListReader(readers, totalReader);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 151:{
			system("cls");
			READER *searchReader = new READER[1000];
			int n=0;
			if(searchIdOfReader(readers, totalReader, searchReader, n)){
				printListReader(searchReader, n);
			} else{
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			delete[] searchReader;
			break;
		}
		case 152:
		case 16:
		//Quan ly Sach
		case 21 :{
			system("cls");
			enterListBook(books,totalReader);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 22 :
		case 23 :
		case 24 :{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach,";
			cout<<"\n       chua duoc sap xep (Goc):";
			printListBook(books, totalBook);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 241:{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach, ";
			cout<<"\n     duoc sap xep theo Ma Sach:";
			sortBookByIdOfBook(books, totalBook);
			printListBook(books, totalBook);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 242:{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach, ";
			cout<<"\n     duoc sap xep theo Ten Sach:";
			sortBookByTitleOfBook(books, totalBook);
			printListBook(books, totalBook);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 243:{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach, ";
			cout<<"\n     duoc sap xep theo The Loai:";
			sortBookByGenreOfBook(books,totalBook);
			printListBook(books, totalBook);
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 251:
		case 252:
		case 253:
		//Muon & Tra sach
		case 31 :{
			system("cls");
			enterListBorrowRecord(borrowReturnRecords, totalBorrowReturnRecord);
			cout<<"\n      Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 32 :
		//Thong ke
		case 41 :
		case 42 :
		case 51 :
		case 52 :
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
			saveReaderToFile(readers, totalReader);
			saveBookToFile(books, totalBook);
			saveBorrowReturnRecordToFile(borrowReturnRecords, totalBorrowReturnRecord);
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
			saveReaderToFile(readers, totalReader);
			saveBookToFile(books, totalBook);
			saveBorrowReturnRecordToFile(borrowReturnRecords, totalBorrowReturnRecord);
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
	delete[] readers;
	delete[] books;
	delete[] borrowReturnRecords;
	getch();
	return 0;
}


