/////#####################################################################
/////#######			PLEASE DON'T REMOVE THIS COMMENT           #######
/////#####################################################################
/////###		ho ten:                       MSSV:                    ###
/////###		lop :CN08A                                             ###
/////###		BAI THUC HANH MON CAU TRUC DU LIEU VA GIAI THUAT       ###
/////###		Moi truong thuc hien: C-Free 4.1                       ###
/////###  khoa CNTT - DH GIAO THONG VAN TAI TPHCM                      ###
/////#####################################################################

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;
//============khai bao dulieu=========
struct sach
{
	char maSach[6];
	char tenSach[30];
	char theLoai[30];
	char nxb[30];
	int tongsl;
	int slHienTai;
};
typedef sach dsSach[100];
//====het du lieu sach================
struct thoiGian
{
	int ngay;
	int thang;
	int nam;
};
//====het du lieu ngay thang==========
struct phieuMuon
{
	char soPhieu[6];
	char tenNguoiMuon[30];
	thoiGian ngayMuon;
};
typedef phieuMuon dsPhieuMuon[100];
//====het du lieu phieu muon==========
struct ctPhieuMuon
{
	char soPhieu[6];
	char maSach[6];
	char tinhTrang[20];
	int tra; //==0  neu da tra ,==1 neu chua tra
};
typedef ctPhieuMuon dsctPhieuMuon[300];
//====het du lieu chi tiet phieu muon==
//====het phan khai bao du lieu========
/*===================================================================*/
//====khai bao ham==================
int kiemTraSach(dsSach a,int *numBook,sach maKT);
int kiemTraPhieu(dsPhieuMuon b,int *tongPhieu,phieuMuon phieuKT);
void manHinh();
void thongTin();
void themSach(dsSach a,int *numBook);
void timSach(dsSach a,int *numBook);
void xoaSach(dsSach a,int *numBook);
void suaSach(dsSach a,int *numBook);
void sachTheLoai(dsSach a,int *numBook);
void sachMuonHet(dsSach a,int *numBook);
void inSach(sach sachCanIn);
void inTatCaSach(dsSach a,int numBook);
void themPhieu(dsPhieuMuon b,dsctPhieuMuon c,dsSach a,int *tongPhieu,int *tongCTPM,int *numBook);
int kiemTraNam(int namKT);
int soNgayTrongThang(int thangCanTinh,int namCanTinh);
int soNgayTrongNam(thoiGian a);
int soNgay(thoiGian sau,thoiGian truoc);
void nhapThoiGian(thoiGian *tg);
void suaPhieuMuon(dsPhieuMuon b,dsctPhieuMuon c,dsSach a,int *tongPhieu,int *tongCTPM,int *numBook);
void xoaPhieuMuon(dsPhieuMuon b,dsctPhieuMuon c,dsSach a,int *tongPhieu,int *tongCTPM,int *numBook);
void timPhieu(dsPhieuMuon b,dsctPhieuMuon c,int *tongPhieu,int *tongCTPM);
void inPhieuMuon(phieuMuon phieuIn);
void inPhieuQuaHan(dsPhieuMuon b,dsctPhieuMuon c,int tongPhieu,int tongCTPM);
void inTatCaPhieu(dsPhieuMuon b,int tongPhieu);
int kiemTraViTriCTPM(dsctPhieuMuon c,int *tongCTPM,ctPhieuMuon ctPhieuCoMaKT);
void themctPhieuMuon(dsctPhieuMuon c,dsPhieuMuon b,dsSach a,int *tongCTPM,int *tongPhieu,int *numBook,phieuMuon maSo);
void muonSach(dsctPhieuMuon c,dsPhieuMuon b,dsSach a,int *tongCTPM,int *tongPhieu,int *numBook);
void xoactPhieuMuon(dsctPhieuMuon c,dsSach a,int *tongCTPM,int *numBook,ctPhieuMuon ctPhieuCanXoa);
void xoactPhieuMuonTheoMaPhieu(dsctPhieuMuon c,dsSach a,int *tongCTPM,int *numBook,phieuMuon PhieuXoa);
void inctPhieuMuon(ctPhieuMuon ctPhieuIn);
void inctPhieuMuonTheoMa(dsctPhieuMuon c,int *tongCTPM,phieuMuon phieuCanIn);
void xoaSachDaTra(dsctPhieuMuon c,dsPhieuMuon b,int *tongCTPM,int *tongPhieu);
void traSach(dsctPhieuMuon c,dsPhieuMuon b,dsSach a,int *tongCTPM,int *tongPhieu,int *numBook);
void ghiFileDuLieu(dsSach a,dsPhieuMuon b,dsctPhieuMuon c,int numBook,int tongPhieu,int tongCTPM);
void docTuFileDuLieu(dsSach a,dsPhieuMuon b,dsctPhieuMuon c,int *numBook,int *tongPhieu,int *tongCTPM);
//====ket thuc khai bao ham=========
/*===================================================================*/
//====ham kiem tra ma sach=============
int kiemTraSach(dsSach a,int *numBook,sach maKT)
{
	for(int i=0;i<=*numBook-1;i++)
	{
		if(strcmp(a[i].maSach,maKT.maSach)==0)
		return i;//tra ve i neu ma sach ton tai 
	}
	return -1;// tra ve -1 neu chua ton tai ma sach
}
//====het ham kiem tra ma sach=========
/*===================================================================*/
//====ham them sach====================
void themSach(dsSach a,int *numBook)
{
	sach sachThem;
	int dieuKien,soSach;
	cout<<"\n Nhap so sach can them: ";
	cin>>soSach;
	for(int k3=1;k3<=soSach;k3++)
	{
		cout<<"\n Nhap sach thu :"<<k3;
		do{
			cout<<"\n nhap ma sach:";
			cin>>sachThem.maSach;
			dieuKien=kiemTraSach(a,numBook,sachThem);
			if(dieuKien==-1)
				break;
			system("cls");
			cout<<"\n ma sach da ton tai .xin vui long nhap lai";
		}while(1);
		cout<<"\n Nhap ten sach: ";
		cin.ignore();
		cin.getline(sachThem.tenSach,30);
		cout<<"\n Nhap the loai: ";
		cin.getline(sachThem.theLoai,30);
		cout<<"\n Nhap ten nha xuat ban: ";
		cin.getline(sachThem.nxb,30);	
		cout<<"\n nhap so luong sach: ";
		cin>>sachThem.tongsl;
		sachThem.slHienTai=sachThem.tongsl;
		//cout<<"\n nhap so luong hien tai: ";
		//cin>>sachThem.slHienTai;
		a[*numBook]=sachThem;
		*numBook=*numBook+1;	
	}
}
//====het ham them sach================
/*===================================================================*/
//====ham xuat man hinh giao dien======
void manHinh()
{
	cout<<"\n 		################### QUAN LY THU VIEN ###################";
	cout<<"\n 		#======================================================#";
	cout<<"\n 		###  lop : CN08A khoa CNTT - DH GTVT TPHCM           ###";
	cout<<"\n 		#======================================================#";
	cout<<"\n 		#=====================quan ly sach=====================#";
	cout<<"\n 		#======================================================#";
	cout<<"\n 		# 1-Them sach moi         ## 5-Xoa sach                #";
	cout<<"\n 		# 2-Tim sach              ## 6-Sach muon het           #";
	cout<<"\n 		# 3-Sua sach              ## 7-Muc luc sach            #";
	cout<<"\n 		# 4-Sach theo the loai    ## 0-Thoat chuong trinh      #";
	cout<<"\n 		#======================================================#";
	cout<<"\n 		#===================quan ly phieu muon=================#";
	cout<<"\n 		#======================================================#";
	cout<<"\n 		# 8 -Them phieu muon      ## 13-Muon them sach         #";
	cout<<"\n 		# 9 -Tim phieu muon       ## 14-Tra sach               #";
	cout<<"\n 		# 10-Sua phieu muon       ## 15-Xoa sach da tra        #";
	cout<<"\n 		# 11-Xoa phieu muon       ## 16-Tat ca phieu muon      #";
	cout<<"\n 		# 12-Phieu qua han        ## 17-Thong tin chuong trinh #";
	cout<<"\n 		#======================================================#";
	cout<<"\n 		########################################################";
}
//=========================================
void thongTin()
{
	cout<<"\n 		chuong trinh quan ly thu vien  ";
	cout<<"\n 		moi truong thuc hien :C-Free 4.1";
	cout<<"\n 		theo cau truc danh sach dac";
	cout<<"\n 		sinh vien: NGUYEN TRONG LONG ";
	cout<<"\n 		MSSV : 0851120041";
	cout<<"\n 		Lop : CN08A - Truong GTVT TP.HCM";
}
//====ket thuc ham xuat man hinh giao dien==
/*====================================================================*/
//====ham tim sach==========================
void timSach(dsSach a,int *numBook)
{
	int viTri;
	sach sachTim;
	cout<<"\n tim sach";
	do{
		cout<<"\n nhap ma sach can tim:";
		cin>>sachTim.maSach;
		viTri=kiemTraSach(a,numBook,sachTim);
		if(viTri!=-1)
			break;
			//system("cls");
		cout<<"\n ma sach khong ton tai .xin vui long nhap lai";
	}while(1);
	cout<<"\n +===============THONG TIN SACH===============+";
	inSach(a[viTri]);
}
//====het ham tim sach======================
/*====================================================================*/
//====ham xoa sach==========================
void xoaSach(dsSach a,int *numBook)
{
	sach sachCanXoa;
	int viTri,bienLap;
	cout<<"\n xoa sach...";
	do{
		cout<<"\n nhap ma sach:";
		cin>>sachCanXoa.maSach;
		viTri=kiemTraSach(a,numBook,sachCanXoa);
		if(viTri!=-1)
			break;
		system("cls");
		cout<<"\n ma sach khongton tai .xin vui long nhap lai";
	}while(1);
	if(a[viTri].slHienTai==a[viTri].tongsl)
	{
	for(bienLap=viTri;bienLap<=*numBook-1;bienLap++)
	a[bienLap]=a[bienLap+1];
	*numBook=*numBook-1;
	cout<<"\n Da xoa xong";
	}
	else
	cout<<"\n khong xoa duoc sach vi van co nguoi muon sach ";
}
//====het ham xoa sach===============
/*====================================================================*/
//====ham sua chi tiet sach==========
void suaSach(dsSach a,int *numBook)
{
	int viTri,soSachThem=0;
	sach sachCanSua;
	cout<<"\n SUA CHI TIET SACH ";
	do{
	cout<<"\n Nhap ma sach can sua :";
	cin>>sachCanSua.maSach;
	viTri=kiemTraSach(a,numBook,sachCanSua);
	if(viTri!=-1)
	break;
	cout<<"\n Ma sach khong ton tai .vui long nhap lai";
	}while(1);
	cout<<"\n tim thay ma sach -lan luot sua thong tin:";
	if(a[viTri].slHienTai==a[viTri].tongsl)
	{
		cout<<"\n Nhap ten sach: ";
		cin.ignore();
		cin.getline(sachCanSua.tenSach,30);
		cout<<"\n Nhap the loai: ";
		cin.getline(sachCanSua.theLoai,30);
		cout<<"\n Nhap ten nha xuat ban: ";
		cin.getline(sachCanSua.nxb,30);	
		cout<<"\n nhap so luong sach: ";
		cin>>sachCanSua.tongsl;
		sachCanSua.slHienTai=sachCanSua.tongsl;
		a[viTri]=sachCanSua;
	}
	else
	{
		cout<<"\n khong sua duoc ten sach vi van co nguoi muon sach nay";
		cout<<"\n ban chi co the them so luong sach .\n So luong sach them la: ";
		cin>>soSachThem;
		a[viTri].tongsl=a[viTri].tongsl+soSachThem;
		a[viTri].slHienTai=a[viTri].slHienTai+soSachThem;
	}

	cout<<"\n Da sua xong ";
}
//====het ham sua chi tiet sach============
/*=======================================================================*/
//====ham thong ke sach theo the loai======
void sachTheLoai(dsSach a,int *numBook)
{
	char theLoaiSach[30];
	int bienKT=0,i;
	cout<<"\n Nhap the loai muon thong ke: ";
	cin.ignore();
	cin.getline(theLoaiSach,30);
	cout<<"\n +========THONG TIN SACH THEO THE LOAI========+";
	cout<<"\n +============================================+";
	for(i=0;i<=*numBook-1;i++)
	{
		if(strcmp(a[i].theLoai,theLoaiSach)==0)
		{
			bienKT++;
			cout<<"\n # Sach tim thay thu :"<<bienKT;
			inSach(a[i]);
		}
	}
	if(bienKT==0)
	{
		system("cls");
		cout<<" khong co the loai sach nay ";
	}
}
//====het ham thong ke the loai sach=======
/*=======================================================================*/
//====ham thong ke sach da cho muon het====
void sachMuonHet(dsSach a,int *numBook)
{
	int i,bienKT=0;
	cout<<"\n +========THONG TIN SACH CHO MUON HET=========+";
	cout<<"\n +============================================+";
	for(i=0;i<=*numBook-1;i++)
	{
		if(a[i].slHienTai==0)
		{
			bienKT++;
			cout<<"\n # Sach tim thay thu :"<<bienKT;
			inSach(a[i]);
		}
	}
	if(bienKT==0)
	{
		system("cls");
		cout<<" Tat ca cac sach trong thu vien deu co the cho muon ";
	}
}
//====het ham thong ke sach cho muon het=====
/*=======================================================================*/
//====ham in tat ca sach co trong thu vien===
void inTatCaSach(dsSach a,int numBook)
{
	int i;
	cout<<"\n +==============MUC LUC SACH==================+";
	for(i=0;i<=numBook-1;i++)
	{
	cout<<"\n # Sach tim thay thu :"<<i+1;
	inSach(a[i]);
	}
}
//====het ham in tat ca sach=================
/*=======================================================================*/
//====ham in chi tiet sach===================
void inSach(sach sachCanIn)
{
	cout<<"\n +============================================+";
	cout<<"\n # 	Ma sach:           "<<sachCanIn.maSach;
	cout<<"\n # 	Ten sach:          "<<sachCanIn.tenSach;
	cout<<"\n # 	The loai:          "<<sachCanIn.theLoai;
	cout<<"\n # 	Nha xuat ban:      "<<sachCanIn.nxb;
	cout<<"\n # 	Tong so luong:     "<<sachCanIn.tongsl;
	cout<<"\n # 	So luong hien tai: "<<sachCanIn.slHienTai;
	cout<<"\n +============================================+";
}
//====het ham in chi tiet sach===============
/*=======================================================================*/
//====ham kiem tra ma so phieu===============
int kiemTraPhieu(dsPhieuMuon b,int *tongPhieu,phieuMuon phieuKT)
{
	for(int i=0;i<=*tongPhieu-1;i++)
	{
	if(strcmp(b[i].soPhieu,phieuKT.soPhieu)==0)
	return i;
	}
	return -1;

}
//====het ham kiem tra so phieu==============
/*=======================================================================*/
//====ham them phieu muon====================
void themPhieu(dsPhieuMuon b,dsctPhieuMuon c,dsSach a,int *tongPhieu,int *tongCTPM,int *numBook)
{
	phieuMuon phieuThem;
	int dieuKien;
	thoiGian nhapNgay;
	do{
		cout<<"\n nhap so phieu:";
		cin>>phieuThem.soPhieu;
		dieuKien=kiemTraPhieu(b,tongPhieu,phieuThem);
		if(dieuKien==-1)
			break;
		system("cls");
		cout<<"\n so phieu da ton tai .xin vui long nhap lai so phieu khac";
	}while(1);
	cout<<"\n Nhap ten nguoi muon: ";
	cin.ignore();
	cin.getline(phieuThem.tenNguoiMuon,30);
	nhapThoiGian(&nhapNgay);
	phieuThem.ngayMuon=nhapNgay;
	b[*tongPhieu]=phieuThem;
	cout<<"\n Them chi tiet phieu muon(muon sach): ";
	themctPhieuMuon(c,b,a,tongCTPM,tongPhieu,numBook,b[*tongPhieu]);
	*tongPhieu=*tongPhieu+1;	
}
//====het ham them phieu muon================
/*=======================================================================*/
//====cac ham xu ly thoi gian ===============
int kiemTraNam(int namKT)
{
	if((namKT%4==0&&namKT%100!=0)||namKT%400==0)
	return 366;
	return 365;
}
//===================================================
int soNgayTrongThang(int thangCanTinh,int namCanTinh)
{
	switch(thangCanTinh)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if(kiemTraNam(namCanTinh)==366)
		return 29;
		return 28;
		break;
	default:
		return 31;
	}

}
//===================================================
int soNgayTrongNam(thoiGian a)
{
	int S=0;
	for(int i=1;i<=a.thang-1;i++)
	{
		S=S+soNgayTrongThang(i,a.nam);
	}
	S=S+a.ngay;
	return S;
}
//===================================================
int soNgay(thoiGian sau,thoiGian truoc)
{
	int soNam,S_Ngay=0;
	soNam=sau.nam-truoc.nam	;
	for(int i=0;i<=soNam-1;i++)
	{
		S_Ngay=S_Ngay+kiemTraNam(truoc.nam+i);
	}
	S_Ngay=S_Ngay+soNgayTrongNam(sau)-soNgayTrongNam(truoc);
	return S_Ngay;
}
//====================================================
int soNgayMuonSach(thoiGian ngayBatDau)
{
	int ketqua;
	thoiGian hienTai;
	 tm *today ;
	time_t ltime;
	time( &ltime );
	today = localtime( &ltime );
	hienTai.ngay=today->tm_mday;
	hienTai.thang=today->tm_mon+1;
	hienTai.nam=today->tm_year+1900;
	ketqua=soNgay(hienTai,ngayBatDau);
	return ketqua;
}
//====================================================
void nhapThoiGian(thoiGian *tg)
{
	do
	{
	cout<<"\n Nhap ngay : ";
	cin>>tg->ngay;
	cout<<"\n Nhap thang: ";
	cin>>tg->thang;
	cout<<"\n Nhap nam : ";
	cin>>tg->nam;
	if(tg->ngay>0 && tg->ngay<=soNgayTrongThang(tg->thang,tg->nam) && tg->thang>0 && tg->thang<=12 && tg->nam>0)
	break;
	cout<< "\n ngay thang khong co that.Vui long nhap lai:";
	}while(1);
}
//====het cac ham xu ly thoi gian=====================
/*======================================================================*/
//====ham sua phieu muon==============================
void suaPhieuMuon(dsPhieuMuon b,dsctPhieuMuon c,dsSach a,int *tongPhieu,int *tongCTPM,int *numBook)
{
	phieuMuon phieuCanSua;
	int viTriPhieu;
	thoiGian ngaySua;
	do{
		cout<<"\n nhap so phieu:";
		cin>>phieuCanSua.soPhieu;
		viTriPhieu=kiemTraPhieu(b,tongPhieu,phieuCanSua);
		if(viTriPhieu!=-1)
			break;
		system("cls");
		cout<<"\n so phieu khong ton tai .xin vui long nhap lai so phieu khac";
	}while(1);
	inPhieuMuon(b[viTriPhieu]);
	inctPhieuMuonTheoMa(c,tongCTPM,b[viTriPhieu]);
	cout<<"\n Tim thay ma so phieu tien hanh chinh sua:";
	xoactPhieuMuonTheoMaPhieu(c,a,tongCTPM,numBook,b[viTriPhieu]);
	cout<<"\n Nhap ten nguoi muon: ";
	cin.ignore();
	cin.getline(phieuCanSua.tenNguoiMuon,30);
	nhapThoiGian(&ngaySua);
	phieuCanSua.ngayMuon=ngaySua;
	b[viTriPhieu]=phieuCanSua;
	cout<<"\n Phieu da duoc sua, du lieu muon sach da duoc xoa ";
	themctPhieuMuon(c,b,a,tongCTPM,tongPhieu,numBook,b[viTriPhieu]);
}
//====het ham sua phieu muon==========================
/*======================================================================*/
//====ham xoa phieu muon==============================
void xoaPhieuMuon(dsPhieuMuon b,dsctPhieuMuon c,dsSach a,int *tongPhieu,int *tongCTPM,int *numBook)
{
	phieuMuon phieuCanXoa;
	int viTriPhieu,k;
	int bienLap;
	do{
		cout<<"\n XOA PHIEU";
		cout<<"\n nhap so phieu:";
		cin>>phieuCanXoa.soPhieu;
		viTriPhieu=kiemTraPhieu(b,tongPhieu,phieuCanXoa);
		if(viTriPhieu!=-1)
			break;
		system("cls");
		cout<<"\n so phieu khong ton tai .xin vui long nhap lai so phieu khac";
	}while(1);
	inctPhieuMuonTheoMa(c,tongCTPM,b[viTriPhieu]);
	xoactPhieuMuonTheoMaPhieu(c,a,tongCTPM,numBook,b[viTriPhieu]);
	for(bienLap=viTriPhieu;bienLap<=*tongPhieu-1;bienLap++)
	b[bienLap]=b[bienLap+1];
	*tongPhieu=*tongPhieu-1;
	cout<<"\n Da xoa xong";
}
//====het ham xoa phieu muon==========================
/*======================================================================*/
//====ham in tim phieu muon===========================
void timPhieu(dsPhieuMuon b,dsctPhieuMuon c,int *tongPhieu,int *tongCTPM)
{
	phieuMuon phieuCanTim;
	int viTriPhieuTim;
	do{
		cout<<"\n nhap so phieu:";
		cin>>phieuCanTim.soPhieu;
		viTriPhieuTim=kiemTraPhieu(b,tongPhieu,phieuCanTim);
		if(viTriPhieuTim!=-1)
			break;
		//system("cls");
		cout<<"\n so phieu khong ton tai .xin vui long nhap lai so phieu khac";
	}while(1);
	inPhieuMuon(b[viTriPhieuTim]);
	inctPhieuMuonTheoMa(c,tongCTPM,b[viTriPhieuTim]);
}
//====het ham tim phieu muon==========================
/*======================================================================*/
//====ham in phieu muon===============================
void inPhieuMuon(phieuMuon phieuIn)
{
	cout<<"\n +============================================+";
	cout<<"\n # 	So phieu:          "<<phieuIn.soPhieu;
	cout<<"\n # 	Ten nguoi muon:    "<<phieuIn.tenNguoiMuon;
	cout<<"\n # 	Ngay muon:         "<<phieuIn.ngayMuon.ngay<<"-"<<phieuIn.ngayMuon.thang<<"-"<<phieuIn.ngayMuon.nam;
	cout<<"\n # 	Da muon duoc:      "<<soNgayMuonSach(phieuIn.ngayMuon)<<" ngay";
	cout<<"\n +============================================+";	
}
//====het ham in phieu muon===========================
/*=======================================================================*/
//====ham kiem tra vi tri chie tiet phieu muon========
void inPhieuQuaHan(dsPhieuMuon b,dsctPhieuMuon c,int tongPhieu,int tongCTPM)
{
	int i,k,dem=0;
	cout<<"\n +=============PHIEU QUA HAN==================+";
	cout<<"\n +============================================+";
	for(i=0;i<=tongPhieu-1;i++)
	{
		for(k=0;k<=tongCTPM-1;k++)
		{		
			if((strcmp(c[k].soPhieu,b[i].soPhieu)==0)&&(soNgayMuonSach(b[i].ngayMuon)>=30)&&(c[k].tra==1))
			{
			dem++;
			cout<<"\n +============================================+";
			cout<<"\n # Sach tim thay thu :"<<dem;
			inPhieuMuon(b[i]);
			inctPhieuMuon(c[k]);
			cout<<"\n\n";
			}
		}

	}
}
//====het ham in phieu muon===========================
/*=======================================================================*/
//====ham in tat ca phieu muon========================
void inTatCaPhieu(dsPhieuMuon b,int tongPhieu)
{
	int j;
	cout<<"\n +=============CAC PHIEU MUON=================+";
	cout<<"\n +============================================+";
	for(j=0;j<=tongPhieu-1;j++)
	{
	cout<<"\n # Phieu tim thay thu :"<<j+1;
	inPhieuMuon(b[j]);
	}
}

//====het ham in tat ca phieu muon====================
/*=======================================================================*/
//====ham kiem tra vi tri chi tiet phieu muon=========
int kiemTraViTriCTPM(dsctPhieuMuon c,int *tongCTPM,ctPhieuMuon ctPhieuCoMaKT)
{
	int j;
	for(j=0;j<=*tongCTPM-1;j++)
	{
	if((strcmp(c[j].maSach,ctPhieuCoMaKT.maSach)==0)&&(strcmp(c[j].soPhieu,ctPhieuCoMaKT.soPhieu)==0))
	return j;
	}
	return -1;
}
//====het ham kiem tra vi tri chi tiet phieu muon=====
/*======================================================================*/
//====ham them chi tiet phieu muon====================
void themctPhieuMuon(dsctPhieuMuon c,dsPhieuMuon b,dsSach a,int *tongCTPM,int *tongPhieu,int *numBook,phieuMuon maSo)
{
	sach sachTam;
	ctPhieuMuon phieuTam;
	int viTriPhieuTim,soSachMuon,dieuKienMuonSach;
	int dieuKhien=0;
	strcpy(phieuTam.soPhieu,maSo.soPhieu);

	cout<<"\n Nhap so luong sach can muon: ";
	cin>>soSachMuon;
	for(int i=1;i<=soSachMuon;i++)
	{
		cout<<"\n thong tin sach thu: ";
		if(i==1) cout<<" nhat"; else cout<<i; 
		do
		{
			cout<<"\n Nhap ma so sach: ";
			cin>>sachTam.maSach;
			dieuKienMuonSach=kiemTraSach(a,numBook,sachTam);
			if((dieuKienMuonSach!=-1)&&(a[dieuKienMuonSach].slHienTai!=0))						
				break;			
			cout<<"\n Ma sach khong co that hoac sach da bi muon het";		
		}while(1);
		for(int k1=0;k1<=*tongCTPM-1;k1++)
		{
			if((strcmp(c[k1].soPhieu,maSo.soPhieu)==0)&&(strcmp(c[k1].maSach,sachTam.maSach)==0)&&(c[k1].tra==1))
			{
				cout<<"\n Ban da muon sach nay roi";
				dieuKhien=1;
				break;
			}
		}
		if(dieuKhien==1) continue;
		a[dieuKienMuonSach].slHienTai--;
		strcpy(phieuTam.maSach,sachTam.maSach);
		cout<<"\n Nhap tinh trang sach : ";
		cin.ignore();
		cin.getline(phieuTam.tinhTrang,20);
		phieuTam.tra=1;
		c[*tongCTPM]=phieuTam;
		*tongCTPM=*tongCTPM+1;
		cout<<"\n Muon thanh cong sach:"<< a[dieuKienMuonSach].tenSach<<endl;
	}

}
//====het ham them chi tiet phieu muon================
/*======================================================================*/
//====ham muon sach===================================
void muonSach(dsctPhieuMuon c,dsPhieuMuon b,dsSach a,int *tongCTPM,int *tongPhieu,int *numBook)
{
	sach sachTam;
	phieuMuon phieuCanTim;
	int viTriPhieuTim;
	do{
		cout<<"\n vui long nhap so phieu:";
		cin>>phieuCanTim.soPhieu;
		viTriPhieuTim=kiemTraPhieu(b,tongPhieu,phieuCanTim);
		if(viTriPhieuTim!=-1)
			break;
		//system("cls");
		cout<<"\n so phieu khong ton tai .xin vui long nhap lai so phieu khac";
	}while(1);
	inPhieuMuon(b[viTriPhieuTim]);
	cout<<"\n # 	Sach da muon:";
	inctPhieuMuonTheoMa(c,tongCTPM,b[viTriPhieuTim]);
	themctPhieuMuon(c,b,a,tongCTPM,tongPhieu,numBook,b[viTriPhieuTim]);

}
//====het ham muon sach================*/
/*======================================================================*/
//====ham xoa chi tiet phieu muon=====================
void xoactPhieuMuon(dsctPhieuMuon c,dsSach a,int *tongCTPM,int *numBook,ctPhieuMuon ctPhieuCanXoa)
{
	int viTriXoactpm,bienLapctpm,viTriSachTra;
	sach tam00;
	viTriXoactpm=kiemTraViTriCTPM(c,tongCTPM,ctPhieuCanXoa);
	strcpy(tam00.maSach,c[viTriXoactpm].maSach);
	viTriSachTra=kiemTraSach(a,numBook,tam00);
	if(c[viTriXoactpm].tra==1) 
	a[viTriSachTra].slHienTai++;
	for(bienLapctpm=viTriXoactpm;bienLapctpm<=*tongCTPM-1;bienLapctpm++)
	c[bienLapctpm]=c[bienLapctpm+1];
	*tongCTPM=*tongCTPM-1;
}
//====================================================
void xoactPhieuMuonTheoMaPhieu(dsctPhieuMuon c,dsSach a,int *tongCTPM,int *numBook,phieuMuon PhieuXoa)
{
	int k;
	for(k=0;k<=*tongCTPM-1;k++)
	{
		if(strcmp(c[k].soPhieu,PhieuXoa.soPhieu)==0)
		{
			xoactPhieuMuon(c,a,tongCTPM,numBook,c[k]);
			k--;
		}
	}
}
//====het ham xoa chi tiet phieu muon=================
/*======================================================================*/
//====ham in chi tiet phieu muon======================
void inctPhieuMuon(ctPhieuMuon ctPhieuIn)
{
	cout<<"\n +============================================+";
	cout<<"\n # 	Ma sach :          "<<ctPhieuIn.maSach;
	cout<<"\n # 	Tinh trang:        "<<ctPhieuIn.tinhTrang;
	cout<<"\n # 	Tra chua:          ";
	if(ctPhieuIn.tra==0) cout<<"da tra";
	else cout<<"chua tra";
	cout<<"\n +============================================+";		
}
//====het ham in chi tiet phieu muon==================
/*======================================================================*/
//====ham in chi tiet phieu theo ma phieu=============
void inctPhieuMuonTheoMa(dsctPhieuMuon c,int *tongCTPM,phieuMuon phieuCanIn)
{
	int k;
	for(k=0;k<=*tongCTPM-1;k++)
	{
		if(strcmp(c[k].soPhieu,phieuCanIn.soPhieu)==0)
		inctPhieuMuon(c[k]);
	}
}
//====het ham in chi tiet phieu muon theo ma phieu====
/*======================================================================*/
//====ham tra sach da muon============================
void traSach(dsctPhieuMuon c,dsPhieuMuon b,dsSach a,int *tongCTPM,int *tongPhieu,int *numBook)
{
	sach sachTam;
	ctPhieuMuon phieuTam;
	phieuMuon phieuCanTim;
	int viTriPhieuTim,soSachTra,dieuKienTraSach,viTrictPhieu;
	int demSoLuong=0;
	do{
		cout<<"\n vui long nhap so phieu:";
		cin>>phieuCanTim.soPhieu;
		viTriPhieuTim=kiemTraPhieu(b,tongPhieu,phieuCanTim);				
		if(viTriPhieuTim!=-1)
			break;
		//system("cls");
		cout<<"\n so phieu khong ton tai .xin vui long nhap lai so phieu khac";
	}while(1);	
	inPhieuMuon(b[viTriPhieuTim]);
	inctPhieuMuonTheoMa(c,tongCTPM,phieuCanTim);
	strcpy(phieuTam.soPhieu,phieuCanTim.soPhieu);
	for(int k2=0;k2<=*tongCTPM-1;k2++)
	{
		if((strcmp(c[k2].soPhieu,phieuTam.soPhieu)==0)&&(c[k2].tra==1))
		demSoLuong=demSoLuong+1;
	}	
	do
	{
	cout<<"\n Nhap so luong sach tra: ";
	cin>>soSachTra;
	if((soSachTra>=0)&&(soSachTra<=demSoLuong))
	break;
	cout<<"\n So luong sach tra khong dung.\n So luong sach ban co the tra nhieu nhat la :"<<demSoLuong;
	}while(1);
	for(int i=1;i<=soSachTra;)
	{
		cout<<"\n\n Sach tra thu : "<<i;
		do
		{
			cout<<"\n Nhap ma so sach: ";
			cin>>sachTam.maSach;
			dieuKienTraSach=kiemTraSach(a,numBook,sachTam);
			if(dieuKienTraSach!=-1)						
				break;			
			cout<<"\n Ma sach khong co that";		
		}while(1);
		strcpy(phieuTam.maSach,sachTam.maSach);
		viTrictPhieu=kiemTraViTriCTPM(c,tongCTPM,phieuTam);
		if(viTrictPhieu==-1)
		{
			cout<<"\n ban khong muon sach nay";
			continue;
		}
		for(int k4=0;k4<=*tongCTPM;k4++)
		{
			if((strcmp(c[k4].maSach,phieuTam.maSach)==0)&&(strcmp(c[k4].soPhieu,phieuTam.soPhieu)==0)&&(c[k4].tra==1))
			viTrictPhieu=k4;
		}
		if(c[viTrictPhieu].tra==0)
		{
			cout<<"\n sach nay da tra";
			continue;
		}
		a[dieuKienTraSach].slHienTai++;
		c[viTrictPhieu].tra=0;
		cout<<"\n sach da duoc tra";
		i++;
	}
	cout<<"\n da tra xong";
}
//====het ham tra sach da muon =======================
/*======================================================================*/
//====ham xoa sach da muon tu mot phieu===============
void xoaSachDaTra(dsctPhieuMuon c,dsPhieuMuon b,int *tongCTPM,int *tongPhieu)
{
	ctPhieuMuon phieuTam00;
	phieuMuon phieuCanTim00;
	int viTriPhieuTim00,viTrictPhieu00;
	do{
		cout<<"\n vui long nhap so phieu:";
		cin>>phieuCanTim00.soPhieu;
		viTriPhieuTim00=kiemTraPhieu(b,tongPhieu,phieuCanTim00);				
		if(viTriPhieuTim00!=-1)
			break;
		//system("cls");
		cout<<"\n so phieu khong ton tai .xin vui long nhap lai so phieu khac";
	}while(1);	
	inPhieuMuon(b[viTriPhieuTim00]);
	inctPhieuMuonTheoMa(c,tongCTPM,phieuCanTim00);
	strcpy(phieuTam00.soPhieu,phieuCanTim00.soPhieu);
	for(int k5=0;k5<=*tongCTPM-1;k5++)
	{
		if((strcmp(c[k5].soPhieu,phieuTam00.soPhieu)==0)&&(c[k5].tra==0))
		{
			c[k5]=c[k5+1];
			*tongCTPM=*tongCTPM-1;
		}

	}	
	cout<<"\n Da xoa xong ";
}

//====het ham xoa sach  da muon tu mot phieu =========
/*======================================================================*/
//====ham ghi ra file du lieu=========================
void ghiFileDuLieu(dsSach a,dsPhieuMuon b,dsctPhieuMuon c,int numBook,int tongPhieu,int tongCTPM)
{
	FILE *f;
	int i1,i2,i3;
	f=fopen("DULIEU.NTL","wb");
	fwrite(&numBook,sizeof(int),1,f);
	fwrite(&tongPhieu,sizeof(int),1,f);
	fwrite(&tongCTPM,sizeof(int),1,f);
	for(i1=0;i1<=numBook-1;i1++)
	{
		fwrite(&a[i1],sizeof(a[i1]),1,f);
	}
	for(i2=0;i2<=tongPhieu-1;i2++)
	{
		fwrite(&b[i2],sizeof(b[i2]),1,f);
	}
	for(i3=0;i3<=numBook-1;i3++)
	{
		fwrite(&c[i3],sizeof(c[i3]),1,f);
	}
	fclose(f);
}
//====het ham ghi ra file du lieu=====================
/*======================================================================*/
//====ham doc tu file du lieu=========================
void docTuFileDuLieu(dsSach a,dsPhieuMuon b,dsctPhieuMuon c,int *numBook,int *tongPhieu,int *tongCTPM)
{
	FILE *f ;
	sach sachTam1 ;
	phieuMuon phieuTam1 ;
	ctPhieuMuon ctPhieuTam1  ;
	int j1,j2,j3;
	f=fopen("DULIEU.NTL","rb");
	if (f==NULL )
		cout<<"\n 			DU LIEU KO TON TAI .DA TAO MOI FILE DU LIEU  \n";
	else
	{	cout<<"\n 				DA TAI DU LIEU TU FILE DU LIEU  \n";
		fread(numBook,sizeof(int),1,f);
		fread(tongPhieu,sizeof(int),1,f);
		fread(tongCTPM,sizeof(int),1,f);
		for (j1=0;j1<=*numBook-1;j1++)
		{
			fread(&sachTam1,sizeof(sach),1,f);
			a[j1]=sachTam1;
		}
		for (j2=0;j2<=*tongPhieu-1;j2++)
		{
			fread(&phieuTam1,sizeof(phieuMuon),1,f);
			b[j2]=phieuTam1;
		}
		for (j3=0;j3<=*tongCTPM-1;j3++)
		{
			fread(&ctPhieuTam1,sizeof(ctPhieuMuon),1,f);
			c[j3]=ctPhieuTam1;
		}
		fclose(f);	
	}
}
//====het ham doc tu file du lieu=====================
/*======================================================================*/
//=================HAM MAIN===========================
//#######################################################################
int main()
{
	/* test cac ham thoi gian 
	//thoiGian a1,b1;
	//a1.ngay=8;a1.thang=3;a1.nam=2010;
	//b1.ngay=8;b1.thang=3;b1.nam=2009;
	//int asdf1=soNgay(a1,b1);
	//int asdf2=soNgayTrongNam(a1);
	//int asdf3=soNgayTrongThang(a1.thang,a1.nam);
	//cout<<asdf1<<"\n";
	//cout<<asdf2<<"\n";
	//cout<<asdf3<<"\n";
	//cout<<soNgayMuonSach(a1);*/
	dsSach TV01;int ns=0;
	dsPhieuMuon PM01;int np=0;
	dsctPhieuMuon CTPM01;int nctp=0;
	int luaChon;
	docTuFileDuLieu(TV01,PM01,CTPM01,&ns,&np,&nctp);
giaoDien:
	manHinh();
	cout<<"\n 			Nhap lua chon : ";
	cin>>luaChon;
	system("cls");
	switch(luaChon)
	{
		case 0:
		goto thoatChuongTrinh;
		break;
		case 1:
		themSach(TV01,&ns);			
		break;
		case 2:
		timSach(TV01,&ns);
		break;
		case 3:
		suaSach(TV01,&ns);		
		break;
		case 4:
		sachTheLoai(TV01,&ns);		
		break;
		case 5:
		xoaSach(TV01,&ns);
		break;
		case 6:
		sachMuonHet(TV01,&ns);
		break;
		case 7:
		inTatCaSach(TV01,ns);
		break;
		case 8:
		themPhieu(PM01,CTPM01,TV01,&np,&nctp,&ns);
		break;
		case 9:
		timPhieu(PM01,CTPM01,&np,&nctp);
		break;
		case 10:
		suaPhieuMuon(PM01,CTPM01,TV01,&np,&nctp,&ns);
		break;
		case 11:
		xoaPhieuMuon(PM01,CTPM01,TV01,&np,&nctp,&ns);
		break;
		case 12:
		inPhieuQuaHan(PM01,CTPM01,np,nctp);
		break;
		case 13:
		muonSach(CTPM01,PM01,TV01,&nctp,&np,&ns);
		break;
		case 14:
		traSach(CTPM01,PM01,TV01,&nctp,&np,&ns);
		break;
		case 15:
		xoaSachDaTra(CTPM01,PM01,&nctp,&np);
		break;
		case 16:
		inTatCaPhieu(PM01,np);
		break;
		case 17:
		thongTin();
		break;
		default:
		cout<<"\n 			CHUONG TRINH KHONG CO CHUC NANG NAY";
	}
	do
	{
	cout<<"\n An phim Enter de ve menu : ";
	int menu=getch();
	break;	
	}while(1);
	system("cls");
	goto giaoDien;
thoatChuongTrinh:
do
{
	cout<<"\n Chuong trinh ket thuc.Ban se luu lai nhung gi vua thuc hien chu";
	cout<<"\n chon Y de luu lai va thoat,N de thoat khong luu\n chon M de ve menu tiep tuc cong viec \n chon S de luu file roi tiep tuc cong viec\n";
	cin.ignore();
	int chonThoat=getch();
	if(toupper(chonThoat)=='Y')
	{
		ghiFileDuLieu(TV01,PM01,CTPM01,ns,np,nctp);
		break;
	}
	if(toupper(chonThoat)=='N')
	{
		break;
	}
	if(toupper(chonThoat)=='M')
	{
		system("cls");
		goto giaoDien;
		break;
	}
	if(toupper(chonThoat)=='S')
	{
		ghiFileDuLieu(TV01,PM01,CTPM01,ns,np,nctp);
		system("cls");
		goto giaoDien;
		break;
	}
	system("cls");
	cout<<"\n ban nhap sai chuc nang hay kiem tra lai\n";
}while(1);
}
/////#####################################################################
/////##########			 			THE END           		    ##########
/////#####################################################################
