// TQB13 - Tran Quoc Bao

#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TIME{
	int d;
	int m;
	int y;
};
struct DOC_GIA{
	char maDocGia[6]; //6 ky tu
	char hoVaLot[30];
	char ten[10];
	char cmnd[13]; //9 hoac 12 ky tu so
	TIME birth;
	int gt;
	char sdt[12];
	char email[40];
	char diaChi[30];
	TIME lapThe;
	TIME hetHan;
	int statusThe;
};
struct SACH{
	char maSach[9]; //8 ky tu
	char tenSach[50];
	char nxb[30];
	int namXB;
	char theLoai[30];
	int giaBia;
	int soSachCo;
	int soSachCon;
};
struct PHIEU_MUONvTRA{
	int soTTPhieu;
	char maDocGia[7]; 	//6 ky tu
	TIME ngayMuon;		//Toi da 7 ngay cho moi cuon
	TIME ngayTra;		//Tre: 5k/ngay , Mat 200% gia bia
	int SLSachMuon;		//Toi da 5 cuon
	char dsMaSachMuon[5][9]; //maSach 8 ky tu
	int tra; //0 muon, 1 da tra
};
void getTime(TIME &x){
	cout<<"ngay  ";								cin>>x.d;
	cout<<"                          thang ";	cin>>x.m;
	cout<<"                          nam   ";	cin>>x.y;
}
int thisIsMagic(int year, int month, int day) {
    if (month < 3) {
        year--;
        month += 12;
	}
	//Công thuc nay Su dung Magic de bien 1 Ngay(date) thanh 1 con so(Number)
    return 365*year + year/4 - year/100 + year/400 + (153*month - 457)/5 + day - 306;
}
void ngayHienTai(TIME &x){
	int h, min, s;
	time_t now = time(0);
	tm *ltm = localtime(&now);
	h= ltm->tm_hour;
	min= ltm->tm_min;
	s= ltm->tm_sec;
	//L?y nam tháng ngày
	x.y = 1900 + ltm->tm_year;
	x.m = 1 + ltm->tm_mon;
	x.d = ltm->tm_mday;
}
int soNgayMuon(TIME dau){
	TIME cuoi;
	ngayHienTai(cuoi);
	return thisIsMagic(cuoi.y, cuoi.m, cuoi.d) - thisIsMagic(dau.y, dau.m, dau.d);
}
void getDocGia(DOC_GIA &x){
	cout<<"Ma Doc Gia              : "; cin.getline(x.maDocGia,7);
	cout<<"Ho & Ten Lot            : "; cin.getline(x.hoVaLot,30);	
	cout<<"Ten                     : "; cin.getline(x.ten,10);		
	cout<<"So CMND                 : "; cin.getline(x.cmnd,13);		
	cout<<"Ngay sinh               : "; getTime(x.birth);			
	cout<<"Gioi tinh (1:Nam, 0:Nu) : "; cin>>x.gt;
	cin.ignore();		
	cout<<"So dien thoai           : "; cin.getline(x.sdt,12);		
	cout<<"Email                   : "; cin.getline(x.email,40);	
	cout<<"Dia chi                 : "; cin.getline(x.diaChi,30);	
	cout<<"Ngay lap the            : "; getTime(x.lapThe);			
	cout<<"Ngay het han            : "; getTime(x.hetHan);			
	cout<<"T.T.H.D (1:HD, 0:Khoa)  : "; cin>>x.statusThe;	
	cin.ignore();			
}
void getSach(SACH &y){
	cout<<"Ma sach      : "; cin.getline(y.maSach,9);
	cout<<"Ten sach     : "; cin.getline(y.tenSach,50);
	cout<<"Nha xuat ban : "; cin.getline(y.nxb,30);
	cout<<"Nam xuat ban : "; cin>>y.namXB;
	cin.ignore();
	cout<<"The loai     : "; cin.getline(y.theLoai,30);
	cout<<"Gia bia      : "; cin>>y.giaBia;
	cout<<"SL sach co   : "; cin>>y.soSachCo;
	cout<<"SL sach con  : "; cin>>y.soSachCon;
}
void getPhieuMuonTra(PHIEU_MUONvTRA &x){
	x.tra=0;
	cout<<"Ma Doc Gia              : ";				cin.getline(x.maDocGia,7);
	cout<<"Ngay muon               : "; 			getTime(x.ngayMuon);
	cout<<"So sach muon Muon       : "; 			cin>>x.SLSachMuon;
	cin.ignore();
	for(int i=0; i<x.SLSachMuon; i++){ 
		cout<<"Nhap Ma Sach thu "<<i+1<<"      : "; cin.getline(x.dsMaSachMuon[i],9); //Toi da 5 cuon, maSach 8 ky tu
	}
	cout<<endl<<x.dsMaSachMuon[3];
}
void themDocGia(DOC_GIA *l){
	int n;
	cout<<"Ban muon them bao nhieu Doc Gia?  "; cin>>n;
	cin.ignore();
	for(int i=0; i<n; i++){
		cout<<"\nMoi ban nhap Thong Tin Doc Gia thu "<<i+1<<":\n";
		getDocGia(l[i]);
		cout<<"Thanh Cong!!!";
	}
}
int namNhuan(int x){
	if( (x%4==0&&x%100!=0) || x%400==0 ) return 1;
	else return 0;
}
void outputTime(TIME x){
	if(x.d<10) cout<<"0"<<x.d;
	else cout<<x.d;
	cout<<"/";
	if(x.m<10) cout<<"0"<<x.m;
	else cout<<x.m;
	cout<<"/"<<x.y;
}
void outputGT(int x){
	if(x){
		cout<<"Nam";	
	} else{
		cout<<"Nu";
	}	
}
void outputStatusThe(int x){
	if(x){
		cout<<"DANG HOAT DONG";	
	} else{
		cout<<"BI KHOA";
	}
}
void outputDocGia(DOC_GIA x){
	cout<<"\nMa Doc Gia              : "<<x.maDocGia;
	cout<<"\nHo & Ten                : "<<x.hoVaLot<<" "<<x.ten;
	//cout<<"\nTen                     : "<<x.ten;
	cout<<"\nSo CMND                 : "<<x.cmnd;
	cout<<"\nNgay sinh               : "; outputTime(x.birth);
	cout<<"\nGioi tinh (1:Nam, 0:Nu) : "; outputGT(x.gt);
	cout<<"\nSo dien thoai           : "<<x.sdt;
	cout<<"\nEmail                   : "<<x.email;
	cout<<"\nDia chi                 : "<<x.diaChi;
	cout<<"\nNgay lap the            : "; outputTime(x.lapThe);
	cout<<"\nNgay het han            : "; outputTime(x.hetHan);
	cout<<"\nT.T.H.D (1:HD, 0:Khoa)  : "; outputStatusThe(x.statusThe);
}
void outputSach(SACH y){
	cout<<"\nMa sach      : "<<y.maSach;
	cout<<"\nTen sach     : "<<y.tenSach;
	cout<<"\nNha xuat ban : "<<y.nxb;
	cout<<"\nNam xuat ban : "<<y.namXB;
	cout<<"\nThe loai     : "<<y.theLoai;
	cout<<"\nGia bia      : "<<y.giaBia;
	cout<<"\nSL sach co   : "<<y.soSachCo;
	cout<<"\nSL sach con  : "<<y.soSachCon;
}
void outputPhieuMuonTra(PHIEU_MUONvTRA x){
	cout<<"\nMa Doc Gia              : "<<x.maDocGia;
	cout<<"\nNgay muon               : "; outputTime(x.ngayMuon);
	if(x.tra){
		cout<<"\nNgay tra                : "; outputTime(x.ngayTra);
	} else{
		cout<<"\nSo ngay da muon         : "<<soNgayMuon(x.ngayMuon);
	}
	cout<<"\nBan da muon "<<x.SLSachMuon<<" cuon sach :";
	for(int i=0; i<x.SLSachMuon; i++){
		cout<<endl;
		cout<<i+1<<". "<<x.dsMaSachMuon[i]; //Toi da 5 cuon, maSach 8 ky tu
		cout<<x.dsMaSachMuon[4];
	}
}

void ghiDocGia(DOC_GIA *x){
	ofstream f("DOCGIA.bin", ios::binary|ios::trunc);
	f.write(reinterpret_cast<char *> (&x),sizeof(DOC_GIA)*4);
	cout<<"Ghi thanh cong!!!";
	f.close();
}
void docDocGia(DOC_GIA *x){
	ifstream f("DOCGIA.bin", ios::binary);
	
	f.read(reinterpret_cast<char *> (&x),sizeof(DOC_GIA)*4+29);
	for(int i=0; i<5; i++){
		outputDocGia(x[i]);
		cout<<endl;
	}
	cout<<endl;
	f.close();
}

void ghiSach(SACH x){
	ofstream f("SACH.bin", ios::binary|ios::trunc);
	f.write(reinterpret_cast<char *> (&x),sizeof(SACH));
	f<<endl;
	cout<<"done";
	f.close();
}
void docSach(SACH &x){
	ifstream f("SACH.bin", ios::binary);
//	while(reinterpret_cast<char *> (&x),sizeof(SACH)){
//		outputSach(x);
//	}
	f.read(reinterpret_cast<char *> (&x),sizeof(SACH));
	outputSach(x);
	cout<<endl;
	f.close();
}

int main(){
	DOC_GIA x[1000];
	SACH y[10000];
	PHIEU_MUONvTRA t;
	//getPhieuMuonTra(t);
	//ngayHienTai(z);
	//outputTime(z);
//	getDocGia(x);
	//getSach(y);
	themDocGia(x);
	cout<<endl;
	//ghiSach(y);
//	ghiDocGia(x);
	//outputDocGia(x);
	//outputSach(y);
	//outputPhieuMuonTra(t);
//	docDocGia(x);
	//docSach(y);
	//system("cls");
	
	
	return 0;
}

