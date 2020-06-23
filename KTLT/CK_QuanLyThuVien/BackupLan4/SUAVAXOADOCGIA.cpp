void xoathongtindocgia(reader  a,int *numberperson)
{
	reader   docgiaCanXoa;
	int 	viTri,bienLap;
	cout<<"\n xoa thong tin  doc gia...";
	do{
		cout<<"\n nhap so thu tu  doc gia :";
		cin>>docgiaCanXoa.numberperson;
		viTri=kiemTradsdocgia(a,numberperson ,docgiaCanXoa);
		if(viTri!=-1)
			break;
		system("cls");
		cout<<"\n so thu tu doc gia  khong ton tai .xin vui long nhap lai";
	}while(1);
	if(a[viTri].slHienTai==a[viTri].tongsl)
	{
	for(bienLap=viTri;bienLap<=*numberperson -1;bienLap++)
	a[bienLap]=a[bienLap+1];
	*numberperson =*numberperson -1;
	cout<<"\n Da xoa xong";
	}
	else
	cout<<"\n khong xoa duoc sach vi van co nguoi muon sach ";
}
//====het ham xoa sach===============
/*====================================================================*/
//====ham sua chi tiet sach==========
void suadanhsachdocgia (reader  a,int *numperson )
{
	int viTri,docgiaThem=0;
	reader  docgiaCanSua;
	cout<<"\n SUA danh sach doc gia : ";
	do{
	cout<<"\n Nhap thu tu danh sach can sua: :";
	cin>>docgiaCanSua.maID;
	viTri=kiemTradsdocgia(a,numberperson ,docgiaCanSua);
	if(viTri!=-1)
	break;
	cout<<"\n Ma sach khong ton tai .vui long nhap lai";
	}while(1);
	cout<<"\n tim thay ma sach -lan luot sua thong tin:";
	if(a[viTri].slHienTai==a[viTri].tongsl)
	{
		cout<<"\n Nhap ID doc gia : ";
		cin.ignore();
		cin.getline(docgiaCanSua.idOfReaders  ,5);
		cout<<"\n Nhap ho va ten lot  doc gia : ";
		cin.getline(docgiaCanSua.lastname  ,30);
		cout<<"\n Nhap ten doc gia : ";
		cin.getline(docgiacansua.firstname ,30);	
		cout<<"\n nhap so CMND  : ";
		cin.getline(docgiaCanSua.IDcard,12);
		cout<<"\n Nhap ngay sinh : ";
		cin.getline(docgiacansua.DATE dayOfBirth,30);	
		cout<<"\n Nhap gioitinh : ";
		cin.getline(docgiacansua.gender,30);
		cout<<"\n Nhap ngay sinh : ";
		cin.getline(docgiacansua.DATE dayOfBirth,30);
		cout<<"\n so dien thoai  : ";
		cin.getline(docgiacansua.phoneNumber,11);
		cout<<"\n so email : ";
		cin.getline(docgiacansua.email ,40);
		cout<<"\n nhap dia chi   : ";
		cin.getline(docgiacansua.address,256);
		cout<<"\n nhap so luong nguoi doc : ";
		cin>>docgiaCanSua.tongsl;
		docgiaCanSua.slHienTai=docgiaCanSua.tongsl;
		a[viTri]=docgiaCanSua;
	}
	else
	{
		cout<<"\n khong sua duoc ten sach vi van co nguoi muon sach nay";
		cout<<"\n ban chi co the them so luong sach .\n So luong sach them la: ";
		cin>>soSachThem;
		a[viTri].tongsl=a[viTri].tongsl+sodocgiaThem;
		a[viTri].slHienTai=a[viTri].slHienTai+sodocgiaThem;
	}

	cout<<"\n Da sua xong ";
}
