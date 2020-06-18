// TQB13 - Tran Quoc Bao
// Di chuyen vi tri Thu Hoi Bo Nho
// Cap nhat ham tim kiem
// Chinh sua ham doc-ghi file

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
		cout<<"\n\n===== Doc Gia thu "<<i+1<<" ======";
		printAReader(listReader[i]);
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

void editAReader(READER *listReader, int totalReader, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can chinh sua: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			cout<<"\n     Da tim thay Doc Gia:";
			printAReader(listReader[i]);
			cout<<"\n\nMoi ban nhap thong tin moi cho Doc Gia nay:\n";
			//cin.ignore();
			listReader[i] = enterAReader();
			n=1;
			cout<<"Thanh Cong!!!\n";
		}
	}
}

void deleteAReader(READER *listReader, int &totalReader, int &n){
	char idOfReader[6];
	cout<<"Nhap Ma Doc Gia can xoa: "; cin.getline(idOfReader,6);
	for(int i=0; i<totalReader; i++){
		if(strcmp(idOfReader,listReader[i].idOfReader)==0){
			n=1;
			cout<<"\n     Da tim thay Doc Gia:";
			printAReader(listReader[i]);
			cout<<"\n\nBan co chac chan Xoa Doc gia nay?";
			int confirm;
			cout<<"\nNhap (1=co, 0=khong) : ";
			cin>>confirm;
			if(confirm){
				for(int j=i; j<totalReader-1; j++){
					listReader[j] = listReader[j+1];
					totalReader--;
				}
				cout<<"Xoa Doc Gia Thanh Cong!!!\n";
			} else{
				cout<<"Khong Xoa Doc Gia Nay!!!\n";
			}
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
			} else{
				cout<<"\nKhong Gia Han!!!\n";
			}
			break;
		}
	}
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
	
	readCookieFromFile(totalReader, totalBook, totalBorrowReturnRecord);
	readReaderFromFile(readers, totalReader);
		
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
		case 12 :{
			system("cls");
			int n=0;
			cin.ignore();
			editAReader(readers, totalReader, n);
			if(!n){
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 13 :{
			system("cls");
			int n=0;
			cin.ignore();
			deleteAReader(readers, totalReader, n);
			if(!n){
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		case 14 :{
			system("cls");
			cout<<"\n      Danh sach Thong tin Doc Gia,";
			cout<<"\n        chua duoc sap xep (Goc):    ";
			printListReader(readers, totalReader);
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
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
			READER *searchReader = new READER[5];
			int n=0;
			cin.ignore();
			searchIdOfReader(readers, totalReader, searchReader, n);
			if(n){
				cout<<"\n     Da tim thay Doc Gia:";
				printListReader(searchReader, n);
			} else{
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			cout<<"\n\n       Nhan enter de tiep tuc!   ";
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
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			cout<<"\n\n       Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			delete[] searchReader;
			break;
		}
		case 16:{
			system("cls");
			int n=0;
			cin.ignore();
			extendCard(readers, totalReader, n);
			if(!n){
				cout<<"Khong tin thay Doc Gia nao!!!";
			}
			cout<<"\n\n         Nhan enter de tiep tuc!   ";
			getch();
			goto MenuProcessing;
			break;
		}
		//Quan ly Sach
		case 21 :{
			system("cls");
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
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 241:{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach, ";
			cout<<"\n     duoc sap xep theo Ma Sach:";
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 242:{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach, ";
			cout<<"\n     duoc sap xep theo Ten Sach:";
			cout<<"\n\n                Nhan enter de tiep tuc!";
			getch();
			goto MenuProcessing;
			break;
		}
		case 243:{
			system("cls");
			cout<<"\n      Danh sach Thong tin Sach, ";
			cout<<"\n     duoc sap xep theo The Loai:";
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
	getch();
	return 0;
}
