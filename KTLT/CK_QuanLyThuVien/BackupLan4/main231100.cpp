// TQB13 - Tran Quoc Bao
//Da xong het roi, con muc 4.
#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <iomanip>
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
	char idOfBook[5][11];	//danh sach toi da 5 sach duoc muon.
	DATE borrowDate;		//Ngay muon sach, toi da 7 ngay
	DATE returnDate;		//Ngay tra sach, tre 5k/ngày
	int status;				//Trang thai phieu, 1=Da Tra, 0=Chua Tra
};

void showMainMenu(int &selectFalse){
	//Giao dien Main Menu
	system("cls");
	cout<<"\n\t //===============================MENU===============================\\\\ ";
	cout<<"\n\t||                    CHUONG TRINH QUAN LY THU VIEN                   ||";
	cout<<"\n\t||==========QuanLyDocGia=========================QuanLySach===========||";
	cout<<"\n\t||  11  : Them Doc Gia             ||  21  : Them Sach                ||";
	cout<<"\n\t||  12  : Sua thong tin Doc Gia    ||  22  : Sua thong tin Sach       ||";
	cout<<"\n\t||  13  : Xoa Doc Gia              ||  23  : Xoa Sach                 ||";
	cout<<"\n\t||  14  : Xuat DANH SACH Doc Gia   ||  24  : Xuat MUC LUC  Sach       ||";
	cout<<"\n\t||  141 :        theo ma Doc Gia   ||  241 :      theo ma  Sach       ||";
	cout<<"\n\t||  142 :       theo ten Doc Gia   ||  242 :      theo ten Sach       ||";
	cout<<"\n\t||                                 ||  243 : theo the loai Sach       ||";
	cout<<"\n\t||  15x : Tim kiem  Doc Gia        ||  25x : Tim kiem Sach            ||";
	cout<<"\n\t||  151 :  theo Ma  Doc Gia        ||  251 :       theo  ma Sach      ||";
	cout<<"\n\t||  152 :  theo Ten Doc Gia        ||  252 :       theo ten Sach      ||";
	cout<<"\n\t||                                 ||  253 :  theo the loai Sach      ||";
	cout<<"\n\t||  16  : Gia han the              ||                                 ||";
	cout<<"\n\t||===========================Muon&TraSach=============================||";
	cout<<"\n\t||  31  : Muon Sach                ||  34  : Xuat TAT CA phieu muon   ||";
	cout<<"\n\t||  32  : Tra  Sach                ||  35  : Quen Ma Phieu?           ||";
	cout<<"\n\t||  33  : In thong tin phieu muon  ||  36  : Bao Mat Sach             ||";
	cout<<"\n\t||==============================ThongKe===============================||";
	cout<<"\n\t||  41  : Doc Gia dang muon Sach   ||  43  : 10 Sach muon nhieu nhat  ||";
	cout<<"\n\t||  42  : Doc gia dang tre han tra ||  44  :                          ||";
	cout<<"\n\t||==============================XemThem===============================||";
	cout<<"\n\t||  000 : THOAT Chuong Trinh       ||  666 : QUY TAC Nhap Du Lieu     ||";
	cout<<"\n\t||  999 : LUU nhanh Du Lieu        ||  777 : THONG TIN Nhom Tac Gia   ||";
	cout<<"\n\t \\\\===================================================================//";
	if(selectFalse){
		cout<<"\n\t     [THONG BAO]: Chuong trinh khong nhan ra Chuc Nang ban da chon.";
		selectFalse = 0;
	}
	cout<<"\n\n\t\t Moi ban nhap So tuong ung voi cac Chuc Nang: ";
}
void showExitMenu(int &selectFalse){
	//Giao dien Exit Menu
	system("cls");
	cout<<"\n\t|| Ban da chon Ket Thuc Chuong Trinh.";
	cout<<"\n\t|| Ban co muon LUU du lieu lai khong?";
	cout<<"\n\t||\tnhap Y de  LUU va THOAT;";
	cout<<"\n\t||\tnhap N de  KHONG LUU va THOAT;";
	cout<<"\n\t||\tnhap M de  TRO LAI Menu;\n";
	if(selectFalse){
		cout<<"\n[THONG BAO] Chuong trinh khong nhan ra chuc nang ban vua nhap.";
		selectFalse = 0;
	}
	cout<<"\n            Moi ban nhap ky tu tuong ung: ";
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
	showMainMenu(selectFalse);
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
	cout<<"\n\t //==============================RULE==QUY=TAC===============================\\\\";
	cout<<"\n\t||        [ve DOC GIA]                 ||            [ve SACH]                ||";
	cout<<"\n\t|| - Ma DG    :        05 ky tu        || - Ma Sach     :    10 ky tu         ||";
	cout<<"\n\t|| - Ho & Ten Lot, Ten:                || - Ten Sach, Nha Xuat Ban, Tac Gia:  ||";
	cout<<"\n\t||              toi da 30 ky tu        ||             toi da 60 ky tu         ||";
	cout<<"\n\t|| - CMND     : 9 hoac 12 ky tu So     || - Nam xuat ban: chi nhap nam        ||";
	cout<<"\n\t|| - Email    : toi da 60 ky tu        || - The loai    : doi da 30 ky tu     ||";
	cout<<"\n\t|| - GioiTinh : Nhap 0 hoac 1          || - Gia tien    : don vi (nghin VND)  ||";
	cout<<"\n\t|| - DiaChi   : chi nhap Tinh/Huyen/Xa ||=====================================||";
	cout<<"\n\t|| - Kieu Ngay: Nhap Ngay, enter, Nhap Thang, enter, Nhap Nam, enter .        ||";
	cout<<"\n\t||============================================================================||";
	cout<<"\n\t||     ==>>    HO TRO TRUC TUYEN       ::    fb.com/realTranQuocBao   <<==    ||";
	cout<<"\n\t||============================================================================||";
	cout<<"\n\t||                                     ||                                     ||";
	cout<<"\n\t \\\\==========================================================================//";
	cout<<"\n\n\t               [THONG BAO]: Bam Enter de tro lai Menu               ";
	getch();
	int selectFalse=0;
	showMainMenu(selectFalse);
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
void printDate(DATE date){
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
int checkBookToBorrow(char idOfBook[], BOOK *listBook, int totalBook, int &locationOfBook){
	for(int i=0; i<totalBook; i++){
		if(strcmp(idOfBook,listBook[i].idOfBook)==0){
			if(listBook[i].remain>0 && listBook[i].total>0){
				locationOfBook = i;
				return 1;	
			} else {
				locationOfBook = -2; // het sach
				return 0;
			}
		}
	}
	locationOfBook = -1; //khong co Ma sach nay
	return 0;
}
int checkBookToReturn(char idOfBook[], BOOK *listBook, int totalBook){
	for(int i=0; i<totalBook; i++){
		if(strcmp(idOfBook,listBook[i].idOfBook)==0){
			return i;
		}
	}
}
int checkReader(char idOfReader[], READER *listReader, int totalReader, int &locationOfReader){
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			if( thisIsMagic(listReader[i].cardExpiry) >= thisIsMagic(today())+7 ){
				locationOfReader = i; // tra ve vitri de in ten
				return 1;	
			} else {
				locationOfReader = -2; // Doc gia da het han The
				return 1;
			}
		}
	}
	locationOfReader = -1; //khong co doc gia nay
	return 0;
}
int checkLeapYear(int year){
	if( (year%4==0 && year%100!=0) || year%400==0 ) return 1; //Nham Nhuan
	else return 0;	//Khong phai nam nhuan
}
int checkDate(DATE date){
	if(date.year<1900 || date.year>2100) return 0;
	switch(date.month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:{
			if(date.day<1 || date.day>31) return 0;
			break;
		}
		case 4:
		case 6:
		case 9:
		case 11:{
			if(date.day<1 || date.day>30) return 0;
			break;
		}
		case 2:{
			if(checkLeapYear(date.year)){
				if(date.day<1 || date.day>29) return 0;
			} else{
				if(date.day<1 || date.day>28) return 0;	
			}
			break;
		}
		default:{
			return 0;
			break;
		}		
	}
	return 1;
}
int checkReturnBook(char idOfReader[], BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket){
	for(int i=0; i<totalBorrowReturnTicket; i++){
		if(strcmp(idOfReader, listBorrowReturnTicket[i].idOfReader)==0){
			if(!listBorrowReturnTicket[i].status) return 0; //chua tra
		}
	}
	return 1; //Doc gia chua tung muon sach HOAC da tra day du
}

READER enterAReader(READER *listReader, int totalReader, int edit){
	READER aReader;
	int k = 0, check=0;
	if(!edit){
		do{
			cout<<"Ma Doc Gia              : "; cin.getline(aReader.idOfReader,6);
			check = checkReader(aReader.idOfReader, listReader, totalReader, k);
			if(k!=-1){
				cout<<"                        [Ma Doc Gia nay da ton tai.]\n";
			}
		} while(check);
	} else{
		*aReader.idOfReader = '\0';
		strcat(aReader.idOfReader,listReader[edit-1].idOfReader);
		cout<<"Ma Doc Gia              : "<<aReader.idOfReader<<endl;
	}
	cout<<"Ho & Ten Lot            : "; cin.getline(aReader.lastName,30);	
	cout<<"Ten                     : "; cin.getline(aReader.firstName,30);		
	cout<<"So CMND                 : "; cin.getline(aReader.idCard,13);	
	do{
		cout<<"Ngay sinh               : "; aReader.dayOfBirth=enterDate();
		if(!checkDate(aReader.dayOfBirth)) cout<<"                        [Vui long nhap 1 ngay hop le.]\n";		
	} while(!checkDate(aReader.dayOfBirth));			
	cout<<"Gioi tinh (1:Nam, 0:Nu) : "; cin>>aReader.gender;
	cin.ignore();		
	cout<<"So dien thoai           : "; cin.getline(aReader.phoneNumber,12);		
	cout<<"Email                   : "; cin.getline(aReader.email,60);	
	cout<<"Dia chi                 : "; cin.getline(aReader.address,256);
	do{
		cout<<"Ngay lap the            : "; aReader.cardIssuing = enterDate();	
		if(!checkDate(aReader.cardIssuing)) cout<<"                        [Vui long nhap 1 ngay hop le.]\n";		
	} while(!checkDate(aReader.cardIssuing));
	do{
		cout<<"Ngay het han            : "; aReader.cardExpiry = enterDate();
		if(!checkDate(aReader.cardExpiry)) cout<<"                        [Vui long nhap 1 ngay hop le.]\n";		
	} while(!checkDate(aReader.cardExpiry));
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
BORROW_RETURN enterABorrowTicket(BORROW_RETURN *listBorrowReturnTicket, int &totalBorrowReturnTicket, READER *listReader, int totalReader, BOOK *listBook, int &totalBook, int &check){
	BORROW_RETURN aBorrowTicket;
	int locationOfElement;
	aBorrowTicket.numberOrdinalTicket = totalBorrowReturnTicket+1;
	cout<<"\nSo thu tu phieu muon    : "<<setw(3)<<aBorrowTicket.numberOrdinalTicket<<endl;	//He thong tu danh so
	cin.ignore();
	do{
		cout<<"Ma Doc Gia              : "; cin.getline(aBorrowTicket.idOfReader,6);
		check = checkReader(aBorrowTicket.idOfReader, listReader, totalReader, locationOfElement);
		if(locationOfElement == -1) cout<<"                        [Ma Doc Gia nay khong ton tai.]\n";
		else if(locationOfElement == -2){
			cout<<"                        [The Da Het Han, Vui long gia han de muon sach.]\n";
			check = 0; //The het han
			goto EndFunction;
		} else if(!checkReturnBook(aBorrowTicket.idOfReader, listBorrowReturnTicket, totalBorrowReturnTicket)){
			cout<<"                        [Ban chua tra cac sach da muon, Vui long tra ngay.]\n";
			check = -1; //Chua tra sach
			goto EndFunction;
		}
	} while(!check);
	cout<<"                        ->"<<listReader[locationOfElement].lastName<<" "<<listReader[locationOfElement].firstName<<endl;
	do{
		cout<<"So cuon Sach muon [1-5] : "; cin>>aBorrowTicket.numberBooksToBorrow;
		check = (aBorrowTicket.numberBooksToBorrow<1 || aBorrowTicket.numberBooksToBorrow>5)?0:1;
		if(!check) cout<<"                        [Ban chi duoc phep muon tu 1 -> 5 cuon sach.]\n";
	} while(!check);
	cin.ignore();
	for(int i=0; i<aBorrowTicket.numberBooksToBorrow; i++){
		do{
			cout<<"      Ma Sach thu   "<<i+1<<"   : "; cin.getline(aBorrowTicket.idOfBook[i],11);
			check = checkBookToBorrow(aBorrowTicket.idOfBook[i], listBook, totalBook, locationOfElement);
			if(locationOfElement == -1) cout<<"                        [Khong tim thay Ma Sach nay.]\n";
			else if(locationOfElement == -2) cout<<"                        [Sach nay da duoc muon het.]\n";
			else cout<<"                        ->"<<listBook[locationOfElement].title<<endl;
		} while(!check);
		listBook[locationOfElement].remain--;
	}
	do{
		cout<<"Ngay Muon Sach          : "; aBorrowTicket.borrowDate = enterDate();
		check = ( thisIsMagic(aBorrowTicket.borrowDate) <= thisIsMagic(today()) );
		if(!checkDate(aBorrowTicket.borrowDate)) cout<<"                        [Ban vua nhap 1 ngay khong hop le.]\n";
		else if(!check) cout<<"                        [Khong the nhap 1 ngay trong tuong lai.]\n";
	} while(!(check && checkDate(aBorrowTicket.borrowDate)) );
	cin.ignore();
	aBorrowTicket.status = 0; //Muon=0, tra thi sua lai = 1 + nhap ngay tra
	EndFunction:
	return aBorrowTicket;
}
void enterListReader(READER *listReader, int &totalReader){
	int n;
	cout<<"\nBan muon them bao nhieu Doc Gia?  "; cin>>n;
	cin.ignore();
	int j = 1;
	for(int i=totalReader; i<totalReader+n; i++){
		cout<<"\nMoi ban nhap Thong Tin Doc Gia thu "<<j++<<":\n";
		listReader[i] = enterAReader(listReader, totalReader, 0);
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
void enterListBorrowTicket(BORROW_RETURN *listBorrowReturnTicket, int &totalBorrowReturnTicket, READER *listReader, int totalReader, BOOK *listBook, int &totalBook){
	cout<<"\nMoi ban nhap Thong Tin Phieu Muon:\n";
	int check;
	listBorrowReturnTicket[totalBorrowReturnTicket] = enterABorrowTicket(listBorrowReturnTicket, totalBorrowReturnTicket, listReader, totalReader, listBook, totalBook, check);
	if(check==0){
		cout<<"\n  Khong Thanh Cong do The Het Han!!!";
	} else if(check==-1){
		cout<<"\n  Khong Thanh Cong do Chua Tra sach da muon!!!";
	} else{
		cout<<"\n         Thanh Cong!!!";
		totalBorrowReturnTicket+=1;
	}
	//Doi voi BORROW_RETURN moi lan chi cho phep nhap 1 phieu
}

void printAReader(READER aReader){
	cout<<"\nMa Doc Gia              : "<<aReader.idOfReader;
	cout<<"\nHo & Ten                : "<<aReader.lastName<<" "<<aReader.firstName;		
	cout<<"\nSo CMND                 : "<<aReader.idCard;	
	cout<<"\nNgay sinh               : "; printDate(aReader.dayOfBirth);			
	cout<<"\nGioi tinh (1:Nam, 0:Nu) : "; printGender(aReader.gender);
	cout<<"\nSo dien thoai           : "<<aReader.phoneNumber;		
	cout<<"\nEmail                   : "<<aReader.email;	
	cout<<"\nDia chi                 : "<<aReader.address;	
	cout<<"\nNgay lap the            : "; printDate(aReader.cardIssuing);			
	cout<<"\nNgay het han            : "; printDate(aReader.cardExpiry);
	cout<<"\nTrang thai the          : "; ( statusCard(aReader.cardExpiry) )?( cout<<"Dang Hoat Dong" ):( cout<<"HET HAN Hoat Dong" );
}
void printListReader(READER *listReader, int totalReader){
	//cout<<"\nDanh sach Thong tin Doc Gia:\n";
	for(int i=0; i<totalReader; i++){
		cout<<"\n\n===== Doc Gia thu "<<i+1<<" ======";
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
	//cout<<"\nDanh sach Thong tin Sach:\n";
	for(int i=0; i<totalBook; i++){
		cout<<"\n\n======= Sach thu "<<i+1<<" =======";
		printABook(listBook[i]);
	}
}
void printABorrowReturnTicket(BORROW_RETURN aBorrowTicket, READER *listReader, int totalReader, BOOK *listBook, int totalBook){
	cout<<"\nSo Phieu Muon           : "<<setw(3)<<aBorrowTicket.numberOrdinalTicket;
	cout<<"\nMa Doc Gia              : "<<aBorrowTicket.idOfReader;
	cout<<"\nHo & Ten Doc Gia        : "<<"Ho van Ten";
	cout<<"\nDoc Gia da muon "<<aBorrowTicket.numberBooksToBorrow<<" quyen sach, gom:";	
	for(int i=0; i<aBorrowTicket.numberBooksToBorrow; i++){
		cout<<"\n          Sach thu   "<<i+1<<"  : ["<<aBorrowTicket.idOfBook[i]<<"] "<<listBook[checkBookToReturn(aBorrowTicket.idOfBook[i], listBook, totalBook)].title;
		//cout<<"\n                        : "<<;
	}			
	cout<<"\nNgay Muon Sach          : "; printDate(aBorrowTicket.borrowDate);			
	cout<<"\nNgay Tra  Sach          : "; (aBorrowTicket.status)?printDate(aBorrowTicket.returnDate):printNull();
	cout<<"\nTinh trang Phieu        : "; (aBorrowTicket.status)?cout<<"da tra. ":cout<<"dang muon. ";
	int overDeadline = overDeadlineReturnBook(aBorrowTicket.borrowDate);
	if(overDeadline>0 && aBorrowTicket.status==0){
		cout<<"DA QUA HAN "<<overDeadline<<" NGAY.";
		cout<<"\nSo tien phai Nop Phat   : "<<overDeadline*5*aBorrowTicket.numberBooksToBorrow<<"000 VND";
	}
}
void printListBorrowReturnTicket(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnRecord, READER *listReader, int totalReader, BOOK *listBook, int totalBook){
	//cout<<"\nDanh sach Thong tin Phieu Muon:\n";
	for(int i=0; i<totalBorrowReturnRecord; i++){
		cout<<"\n\n========= Phieu Muon "<<i+1<<" ==========";
		printABorrowReturnTicket(listBorrowReturnTicket[i], listReader, totalReader, listBook, totalBook);
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

void editAReader(READER *listReader, int totalReader, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can chinh sua: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			cout<<"\n     Da tim thay Doc Gia:";
			printAReader(listReader[i]);
			cout<<"\n\nMoi ban nhap thong tin moi cho Doc Gia nay:\n";
			//cin.ignore();
			listReader[i] = enterAReader(listReader, totalReader, i+1);
			n=1;
			cout<<"Thanh Cong!!!\n";
			break;
		}
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

void deleteAReader(READER *listReader, int &totalReader, BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can xoa: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			n=1;
			cout<<"\n     Da tim thay Doc Gia:";
			printAReader(listReader[i]);
			if( !checkReturnBook(idOfReader, listBorrowReturnTicket, totalBorrowReturnTicket) ){
				cout<<"\n\n\nKhong the Xoa, do Doc Gia nay Chua Tra sach!!!\n";
				goto EndFunction;
			}
			cout<<"\n\nBan co chac chan Xoa Doc gia nay?";
			int confirm;
			cout<<"\nNhap (1=co, 0=khong) : ";
			cin>>confirm;
			if(confirm){
				for(int j=i; j<totalReader-1; j++){
					listReader[j] = listReader[j+1];
				}
				totalReader--;
				cout<<"Xoa Doc Gia Thanh Cong!!!\n";
			} else{
				cout<<"Khong Xoa Doc Gia Nay!!!\n";
			}
			EndFunction:
			break;
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
			if( (listBook[i].total>listBook[i].remain) && (listBook[i].total>0) ){
				cout<<"\n\n\nKhong the Xoa, do Sach nay van con nguoi Muon!!!\n";
				goto EndFunction;
			}
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
			EndFunction:
			break;
		}
	}
}

void extendCard(READER *listReader, int totalReader, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can Gia Han: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			n=1;
			cout<<"\n     Da tim thay Doc Gia:";
			printAReader(listReader[i]);
			cout<<"\n\nBan co muon gia han 1 nam cho Doc Gia nay?";
			int confirm;
			cout<<"\nNhap (1=co, 0=khong) : ";
			cin>>confirm;
			if(confirm){
				if(statusCard(listReader[i].cardExpiry)==1){
					//The con Han SD thi ngay het han = nam+1
					listReader[i].cardExpiry.year += 1;
				} else{
					//The het Han SD thi ngay het han bang ngay gia han +1nam
					listReader[i].cardExpiry = today();
					listReader[i].cardExpiry.year += 1;
				}
				cout<<"\nGia Han Thanh Cong!!!\n";
				cout<<"Ngay het han the moi la: "; printDate(listReader[i].cardExpiry);
			} else{
				cout<<"\nKhong Gia Han!!!\n";
			}
			break;
		}
	}
}

void returnBook(BORROW_RETURN *listBorrowReturnTicket, int totalBorrowReturnTicket, int &n, BOOK *listBook, int &totalBook){
	//check = checkReaderToReturn(aBorrowTicket.idOfReader, listReader, totalReader, locationOfElement);
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
			for(int j=0; j<listBorrowReturnTicket[i].numberBooksToBorrow; j++){
				listBook[checkBookToReturn(listBorrowReturnTicket[i].idOfBook[j], listBook, totalBook)].remain++;
			}
			break;
		}
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

void reportLostBook(BOOK *listBook, int totalBook){
	int totalLostBook = 0;		//so sach bi mat
	int indemnification = 0;	//so tien boi thuong
	int locationOfElement = 0;	//vi tri phan tu
	int check = 0;				//luu gia tri ham logic
	cout<<"Ban da lam mat bao nhieu dau sach? "; cin>>totalLostBook;
	cin.ignore();
	for(int i=0; i<totalLostBook; i++){
		do{
			char idOfBook[11];
			cout<<"\n      Ma Sach thu   "<<i+1<<"   : "; cin.getline(idOfBook,11);
			check = checkBookToBorrow(idOfBook, listBook, totalBook, locationOfElement);
			if(locationOfElement == -1) cout<<"                        [Khong tim thay Ma Sach nay.]\n";
			else cout<<"                        ->"<<listBook[locationOfElement].title<<endl;
			if(check) cout<<"                Gia bia : "<<listBook[locationOfElement].coverPrice;
		} while(!check);
		listBook[locationOfElement].total--;
		listBook[locationOfElement].remain--;
		indemnification += 2*listBook[locationOfElement].coverPrice;
	}
	cout<<"\n\nSo tien ban phai nop phat la: "<<indemnification<<"000 VND";
}

void searchIdOfReader(READER *listReader, int totalReader, READER *searchReader, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can tra cuu: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			searchReader[n++] = listReader[i];
		}
	}
}
void searchFirstName(READER *listReader, int totalReader, READER *searchReader, int &n){
	char firstName[30];
	cout<<"Nhap TEN Doc Gia can tra cuu: "; cin.getline(firstName,30);
	for(int i=0; i<totalReader; i++){
		if(strcmp(firstName,listReader[i].firstName)==0){
			searchReader[n++] = listReader[i];
		}
	}
}
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
	cout<<"Nhap The Loai Sach can tra cuu : "; cin.getline(genre,30);
	for(int i=0; i<totalBook; i++){
		if(strcmp(genre,listBook[i].genre)==0){
			searchBook[n++] = listBook[i];
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

void saveReaderToFile(READER *listReader, int totalReader){
	ofstream file("READERS.bin", ios::binary|ios::trunc);
	for(int i=0; i<totalReader; i++){
		file.write(reinterpret_cast<char *> (&listReader[i]),sizeof(READER));
	}
	cout<<"\n               Luu    Doc  Gia    Thanh cong!!!";
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
	for(int i=0; i<totalBook; i++){
		file.write(reinterpret_cast<char *> (&listBook[i]),sizeof(BOOK));
	}
	cout<<"\n               Luu      Sach      thanh cong!!!";
	file.close();
}
void readBookFromFile(BOOK *listBook, int totalBook){
	ifstream file("BOOKS.bin", ios::binary);
	for(int i=0; i<totalBook; i++){
		file.read(reinterpret_cast<char *> (&listBook[i]),sizeof(BOOK));
	}
	file.close();
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
void saveCookieToFile(int totalReader, int totalBook, int totalBorrowReturnRecord){
	ofstream file("COOKIE.tqb", ios::trunc);
	file<<totalReader<<endl;
	file<<totalBook<<endl;
	file<<totalBorrowReturnRecord<<endl;
	cout<<"\n               Luu     Cookie     thanh cong!!!";
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
	
	READER *readers = new READER[100];								//Khoi tao mang 1000 doc gia
	BOOK *books = new BOOK[100];									//Khoi tao mang 10000 ddaauf sachs, sao cho nay bi tran Data :(
	BORROW_RETURN *borrowReturnTickets = new BORROW_RETURN[200];	//Khoi tao So ghi Phieu muon tra, 10000 record
	
	readCookieFromFile(totalReader, totalBook, totalBorrowReturnTicket);
	readReaderFromFile(readers, totalReader);
	readBookFromFile(books, totalBook);
	readBorrowReturnTicketFromFile(borrowReturnTickets, totalBorrowReturnTicket);	
	int dem=1;
	//Hien thi & Xu ly Chon menu
	MenuProcessing:
	showMainMenu(selectFalse);
	int select;
	cin>>select;
	switch(select){
		//Quan ly Doc Gia
		case 11 :{
			system("cls");
			enterListReader(readers,totalReader);
			cout<<"\n\n                Bam Enter de tro lai Menu!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 12 :{
			system("cls");
			int n=0;
			cin.ignore();
			editAReader(readers, totalReader, n);
			if(!n){
				cout<<"Khong tim thay Doc Gia nao!!!";
			}
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 13 :{
			system("cls");
			int n=0;
			cin.ignore();
			deleteAReader(readers, totalReader, borrowReturnTickets, totalBorrowReturnTicket, n);
			if(!n){
				cout<<"Khong tim thay Doc Gia nao!!!";
			}
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 14 :{
			system("cls");
			cout<<"\n      Danh sach Thong tin Doc Gia,";
			cout<<"\n        chua duoc sap xep (Goc):    ";
			printListReader(readers, totalReader);
			cout<<"\n\n                Bam Enter de tro lai Menu!";
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
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
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
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 151:{
			system("cls");
			READER *searchReader = new READER[1];
			int n=0;
			cin.ignore();
			searchIdOfReader(readers, totalReader, searchReader, n);
			if(n){
				cout<<"\n     Da tim thay Doc Gia:";
				printListReader(searchReader, n);
			} else{
				cout<<"Khong co Doc Gia nao!!!";
			}
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			delete[] searchReader;
			break;
		}
		case 152:{
			system("cls");
			READER *searchReader = new READER[100];
			int n=0;
			cin.ignore();
			searchFirstName(readers, totalReader, searchReader, n);
			if(n){
				cout<<"\n     Da tim thay Doc Gia:";
				printListReader(searchReader, n);
			} else{
				cout<<"Khong tim thay Doc Gia nao!!!";
			}
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			delete[] searchReader;
			break;
		}
		case 16 :{
			system("cls");
			int n=0;
			cin.ignore();
			extendCard(readers, totalReader, n);
			if(!n){
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		//Quan ly Sach
		case 21 :{
			system("cls");
			enterListBook(books,totalBook);
			cout<<"\n\n    Bam Enter de tro lai Menu!";
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
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
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
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 24 :{
			system("cls");
			cout<<"\n Danh sach Thong tin Sach,";
			cout<<"\n  chua duoc sap xep (Goc):";
			printListBook(books, totalBook);
			cout<<"\n\n    Bam Enter de tro lai Menu!";
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
			cout<<"\n\n    Bam Enter de tro lai Menu!";
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
			cout<<"\n\n    Bam Enter de tro lai Menu!";
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
			cout<<"\n\n    Bam Enter de tro lai Menu!";
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
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
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
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
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
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			delete[] searchBook;
			break;
		}
		//Muon & Tra sach
		case 31 :{
			system("cls");
			enterListBorrowTicket(borrowReturnTickets, totalBorrowReturnTicket, readers, totalReader, books, totalBook);
			cout<<"\n\n      Bam Enter de tro lai Menu!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 32 :{
			system("cls");
			int n=0;
			cin.ignore();
			returnBook(borrowReturnTickets, totalBorrowReturnTicket, n, books, totalBook);
			if(!n){
				cout<<"Khong tim thay Phieu nay!!!";
			}
			cout<<"\n\n   Bam Enter de tro lai Menu!";
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
				printABorrowReturnTicket(borrowReturnTickets[i], readers, totalReader, books, totalBook);
			} else{
				cout<<"\n   Khong tim thay Phieu nay!!!";
			}
			cout<<"\n\n     Bam Enter de tro lai Menu!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 34 :{
			system("cls");
			cout<<"\n    Danh sach Thong tin Phieu Muon,";
			cout<<"\n     duoc sap xep theo Ma Doc Gia:";
			printListBorrowReturnTicket(borrowReturnTickets, totalBorrowReturnTicket, readers, totalReader, books, totalBook);
			cout<<"\n\n         Bam Enter de tro lai Menu!   ";
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
				printListBorrowReturnTicket(searchTicket, n, readers, totalReader, books, totalBook);
			} else{
				cout<<"\nKhong tim thay Phieu nao tu Doc Gia nay!!!";
			}
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			delete[] searchTicket;
			break;
		}
		case 36 :{
			system("cls");
			reportLostBook(books, totalBook);
			cout<<"\n\n       Bam Enter de tro lai Menu!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		//Thong ke
		case 41 : //chua lam
		case 42 : //chua lam
		case 43 : //chua lam
		case 44 : {
			system("cls");
			cout<<"\nChuc nang nay team chua suy nghi ra,\nHay vao Xem Thong Tin de gop y nha <3\n";
			cout<<"\n\n      Bam Enter de tro lai Menu!";
			getch();
			goto MenuProcessing;
			break;
		}
		//Thong tin Chuong trinh & Huong dan & Luu nhanh & Thoat
		case 000:{
			cin.clear();
			cin.ignore(10000,'\n');
			system("cls");
			goto confirmExit;
			break;
		}
		case 666  :{
			rule();
			getch();
			goto MenuProcessing;
			break;
		}
		case 777  :{
			viewInfo();
			getch();
			goto MenuProcessing;
			break;
		}
		case 999  :{
			system("cls");
			saveReaderToFile(readers, totalReader);
			saveBookToFile(books, totalBook);
			saveBorrowReturnTicketToFile(borrowReturnTickets, totalBorrowReturnTicket);
			saveCookieToFile(totalReader, totalBook, totalBorrowReturnTicket);
			cout<<"\n\n               [THONG BAO] Du Lieu da duoc luu.";
			cout<<"\n                   Bam Enter de tro lai Menu!";
			getch();
			goto MenuProcessing;
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
	showExitMenu(selectFalse);
	int selectExit = toupper(getch());
	switch(selectExit){
		case 'Y':{
			system("cls");
			saveReaderToFile(readers, totalReader);
			saveBookToFile(books, totalBook);
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
		case 'M':{
			selectFalse = 0;
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
	delete[] borrowReturnTickets;
	getch();
	return 0;
}

