#include "dscauhoi.h"
const int x = 60;
const int y =22;
int xd;
int id[MAX4];
//moi thay doi tg nay
int Empty(TREE root){
	return(root==NULL? true: false);
}

void KhoiTaoCay(TREE &t)
{
	t=NULL;// cay rong
}

bool KT_MaCH_DSMH(listMH &lmh, string mamh)
{
	for(int i = 0 ; i<lmh.soluong;i++)
	{
		if(stricmp(lmh.dsmh[i]->MAMH,mamh.c_str())==0)
		{
			return true;
		}
	}
	return false;
}
void Khoitaoidngaunhien(STACKID &stkid)
{
	int n, b;
	n=10000;
	int *a = new int[n];// cap phat dong mot mang so nguyen chua n so 
	stkid.listid = new int[n];// cap phat dong cho danh sach id
	srand(time(NULL));
	for (int i = 1; i <= n; i++)
	{
		a[i] = i;
	}
	// sinh tung so ngau nhien r bo vao trong stack id 
	while (n>0)
	{
		b = 1 + rand()%n;
		stkid.listid[++stkid.top]=a[b];
		a[b] = a[n];
		n--;
	}
	delete[] a;
}
void Nhap_Cau_Hoi(CAUHOI &ch, listMH &lmh)
{
	gotoxy(x,++xd);	
	fflush(stdin);
	string temp;
	do
	{
		temp.clear();
		gotoxy(x,++xd);
		cout<<" Nhap vao ma mon hoc :";
		XuLiNhapMa(temp);
		if(KT_MaCH_DSMH(lmh,temp)==false)
		{
			gotoxy(x,++xd);
			cout<<" Nhap lai ma mon hoc!!!Khong co trong danh sach mon hoc ";
		}
	}while(KT_MaCH_DSMH(lmh,temp)==false);
	Xoa_KT_Thua_Giua_Ky_Tu(temp);
	Xoa_KT_Thua_O_Dau_Cuoi(temp);
	strcpy(ch.MAMH,(char*)temp.c_str());
	do
	{
		gotoxy(x,++xd);
		cout<<" Nhap vao noi dung : ";
		getline(cin,ch.noidung);
		if(ch.noidung.length()<=0)
		{
			gotoxy(x,++xd);
			cout<<" Nhap lai cau hoi thi ";
		}
	}while(ch.noidung.length()<=0);
	Xoa_KT_Thua_Giua_Ky_Tu(ch.noidung);
	Xoa_KT_Thua_O_Dau_Cuoi(ch.noidung);
	do
	{
		gotoxy(x,++xd);
		cout<<" Nhap vao dap an a :";
		getline(cin,ch.A);
		if(ch.A.length()<=0)
		{
			gotoxy(x,++xd);
			cout<<" Nhap lai dap an ";
		}
	}while(ch.A.length()<=0);
	Xoa_KT_Thua_Giua_Ky_Tu(ch.A);
	Xoa_KT_Thua_O_Dau_Cuoi(ch.A);
	do
	{
		gotoxy(x,++xd);
		cout<<" Nhap vao dap an b :";
		getline(cin,ch.B);
		if(ch.B.length()<=0)
		{
			gotoxy(x,++xd);
			cout<<" Nhap lai dap an ";
		}
	}while(ch.B.length()<=0);
	Xoa_KT_Thua_Giua_Ky_Tu(ch.B);
	Xoa_KT_Thua_O_Dau_Cuoi(ch.B);
	do
	{
		gotoxy(x,++xd);
		cout<<" Nhap vao dap an c : ";
		getline(cin,ch.C);
		if(ch.C.length()<=0)
		{
			gotoxy(x,++xd);
			cout<<" Nhap lai dap an ";
		}
	}while(ch.C.length()<=0);
	Xoa_KT_Thua_Giua_Ky_Tu(ch.C);
	Xoa_KT_Thua_O_Dau_Cuoi(ch.C);
	do
	{
		gotoxy(x,++xd);
		cout<<" Nhap vao dap an d :";
		getline(cin,ch.D);
		if(ch.D.length()<=0)
		{
			gotoxy(x,++xd);
			cout<<" Nhap lai dap an ";
		}
	}while(ch.D.length()<=0);
	Xoa_KT_Thua_Giua_Ky_Tu(ch.D);
	Xoa_KT_Thua_O_Dau_Cuoi(ch.D);
	string temp1;
	gotoxy(x,++xd);
	cout<<"Nhap vao dap an :(A B C D)";
	while(true)// nguoi dung nhap 4 dap A B C D
	{
		if(kbhit())
		{
			ch.dapan = getch();
			if(ch.dapan==65||ch.dapan==97)
			{
				ch.dapan=char(65);
			}
			if(ch.dapan==66||ch.dapan==98)
			{
				ch.dapan=char(66);
			}
			if(ch.dapan==67||ch.dapan==99)
			{
				ch.dapan=char(67);
			}
			if(ch.dapan==68||ch.dapan==100)
			{
				ch.dapan=char(68);
			}
			break;
		}
	}
}
void Xuat_Cau_Hoi(CAUHOI &ch)
{
	gotoxy(x+32,++xd);
	cout<<ch.id<<"."<<ch.MAMH<<"."<<ch.noidung;
	gotoxy(x+25,++xd);
	cout<<ch.A;
	gotoxy(x+25,++xd);
	cout<<ch.B;
	gotoxy(x+25,++xd);
	cout<<ch.C;
	gotoxy(x+25,++xd);
	cout<<ch.D;
	gotoxy(x+25,++xd);
	cout<<"Dap an : "<<ch.dapan;
}
void Insert_Node(TREE &t, CAUHOI &ch)
{
	if(t==NULL)
	{
		NODE *p= new NODE;
		t->data=ch;
		t->pLEFT=NULL;
		t->pRIGHT=NULL;
	}
	else
	{
	if(ch.id<t->data.id)
	Insert_Node(t->pLEFT,ch);
	else if(ch.id>t->data.id)
	Insert_Node(t->pRIGHT,ch);
	}
}

void remove_case_3(TREE &r)
{
	TREE rp;
	if(r->pLEFT!=NULL)
	remove_case_3(r->pLEFT);
	else
	{
		rp->data=r->data;
		rp=r;
		r=r->pRIGHT;
	}
}

void Xoa_Cau_Hoi_Thi(TREE &p,int x)
{ 	TREE rp;
	if(p==NULL)
	{
		cout<<" Khong tim thay cau hoi!";

	}
	else
	{
		if(x<p->data.id)
		{
			Xoa_Cau_Hoi_Thi(x,p->pLEFT);
		}
	
		else if(x>p->data.id)
		{
			Xoa_Cau_Hoi_Thi(x,p->pRIGHT);
		}
		else
		{
			rp=p;
			if(rp->pRIGHT==NULL)
			{
				p=rp->pLEFT;
			}
			else if(rp->pLEFT==NULL)
			{
				p=rp->pRIGHT;
			}
			else{
				remove_case_3(rp->pRIGHT);
			}
			free(rp);

		}
	}
}

void Hieu_Chinh_Cau_Hoi_Ma(TREE &t,string mact,string mamoi)
{
	if(t==NULL)
	{
		gotoxy(x,++xd);
		cout<<"danh sach cau hoi thi rong";
	}
	else
	{
		Hieu_Chinh_Cau_Hoi_Ma(t->pLEFT,mact,mamoi);
		Hieu_Chinh_Cau_Hoi_Ma(t->pRIGHT,mact,mamoi);
		if(stricmp(t->data.MAMH,(char *)mact.c_str())==0)
		{
			strcpy(t->data.MAMH,(char *)mamoi.c_str());
		}
	}
}
NODE* TimKiem(TREE t, CAUHOI &ch)
{ 
	// n?u cây r?ng
	if (t == NULL)
	{
		return NULL;
	}
	else
	{
		// n?u ph?n t? c?n tìm ki?m mà nh? hon node g?c thì duy?t(d? quy) sang bên trái d? tìm
		if (ch.id < t->data.id)
		{
			TimKiem(t->pLeft, ch);
		}
		else if (ch.id > t->data.id) // duy?t sang bên ph?i
		{
			TimKiem(t->pRight, ch);
		}
		else // <=> t->data == x
		{
			return t; // tr? v? node c?n tìm ki?m
		}
	}

}
void Save_CauHoi(ofstream &fo, CAUHOI &ch)
{
	fo<<ch.id<<"."<<ch.id<<endl;
	fo<<ch.MAMH<<"."<<ch.noidung<<endl;
	fo<<ch.A<<endl;
	fo<<ch.B<<endl;
	fo<<ch.C<<endl;
	fo<<ch.D<<endl;
	fo<<ch.dapan<<endl;
}
void Save_ListCauHoi(TREE &t)
{
	ofstream fo;
	fo.open("danhsachcauhoithi.txt",ios::out);
	fo<<DemSoHang(t)<<endl;
	int stacksize=100;
	struct phantu
	{
		TREE diachi;
		int kieu;// danh dau nut cha hay nut con ben phai
	};
	phantu Stack[stacksize];
	int typ = 1;
	int top = 0;
	TREE p=t;
	Stack[0].diachi=NULL;// khoi tao stack
	do{
		while(p!=NULL&&typ==1)
		{
			Stack[++top].diachi=p;
			Stack[top].kieu=0;//nut cha
			if(p->pRIGHT!=NULL)
			{
				Stack[++top].diachi=p->pRIGHT;
				Stack[top].kieu=1;//nut con
			}
			p=p->pLEFT;
		}
		if(p!=NULL)
			Save_CauHoi(fo,p->data);
		p=Stack[top].diachi;
		typ=Stack[top--].kieu;
	}while(p!=NULL);
	fo.close();
}
void Duyet_cay_LNR(TREE &t)
{
	const STACKSIZE = 500;
	TREE stack[STACKSIZE];
	TREE p=t;
	int sp=-1;//khoi tao stack rong
	do
	{
		while(p!=NULL)
		{
			stack[++sp]=p;
			p=p->pLEFT;
		}
		if(sp!=-1)
		{
			p=stack[sp--];
			cout<<p->data<<" ";
			p=p->pRIGHT;
		}
		else break;
	}while(1);
}
bool Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(TREE &t,char mamh[15])
{
	int stacksize=100;
	struct phantu
	{
		TREE diachi;
		int kieu;// danh dau nut cha hay nut con ben phai
	};
	phantu Stack[stacksize];
	int typ = 1;
	int top = 0;
	TREE p=t;
	Stack[0].diachi=NULL;// khoi tao stack
	do{
		while(p!=NULL&&typ==1)
		{
			Stack[++top].diachi=p;
			Stack[top].kieu=0;//nut cha
			if(p->pRIGHT!=NULL)
			{
				Stack[++top].diachi=p->pRIGHT;
				Stack[top].kieu=1;//nut con
			}
			p=p->pLEFT;
		}
		if(p!=NULL)
		{
			if(strcmp(p->data.MAMH,mamh)==0)
			{
				return true;
			}
		}
		p=Stack[top].diachi;
		typ=Stack[top--].kieu;
	}while(p!=NULL);
	return false;
}
int DemSoHang(TREE &t)// dem so hang de luu vao file text, mot cau hoi se co 6 dong
{
	int dem=0;
		int stacksize=100;
		struct phantu
		{
			TREE diachi;
			int kieu;// danh dau nut cha hay nut con ben phai
		};
		phantu Stack[stacksize];
		int typ = 1;
		int top = 0;
		TREE p=t;
		Stack[0].diachi=NULL;// khoi tao stack
		do{
			while(p!=NULL&&typ==1)
			{
				Stack[++top].diachi=p;
				Stack[top].kieu=0;//nut cha
				if(p->pRIGHT!=NULL)
				{
					Stack[++top].diachi=p->pRIGHT;
					Stack[top].kieu=1;//nut con
				}
				p=p->pLEFT;
			}
			if(p!=NULL)
			{
				dem=dem+6;
			}
			p=Stack[top].diachi;
			typ=Stack[top--].kieu;
		}while(p!=NULL);
	return dem;
}
int DemSoHang(TREE &t)// dem so hang de luu vao file text, mot cau hoi se co 6 dong
{
	int dem=0;
		int stacksize=100;
		struct phantu
		{
			TREE diachi;
			int kieu;// danh dau nut cha hay nut con ben phai
		};
		phantu Stack[stacksize];
		int typ = 1;
		int top = 0;
		TREE p=t;
		Stack[0].diachi=NULL;// khoi tao stack
		do{
			while(p!=NULL&&typ==1)
			{
				Stack[++top].diachi=p;
				Stack[top].kieu=0;//nut cha
				if(p->pRIGHT!=NULL)
				{
					Stack[++top].diachi=p->pRIGHT;
					Stack[top].kieu=1;//nut con
				}
				p=p->pLEFT;
			}
			if(p!=NULL)
			{
				dem=dem+6;
			}
			p=Stack[top].diachi;
			typ=Stack[top--].kieu;
		}while(p!=NULL);
	return dem;
}
void Read_CauHoi(ifstream &fi,CAUHOI &ch,STACKID &stk)
{
	// doc cau hoi tu file text, cac id se sinh ngau nhien tu danh sach id da tao 
	ch.id=stk.listid[stk.top];
	stk.top--;
	fflush(stdin);
	string str;
	fi.getline(ch.MAMH,15,'.');
	getline(fi,ch.noidung);
	getline(fi,ch.A);
	getline(fi,ch.B);
	getline(fi,ch.C);
	getline(fi,ch.D);
	fi>>ch.dapan;
	getline(fi,str);
}
void Read_ListCauHoi(TREE &t,STACKID &stk)
{
	ifstream fi;
	fi.open("danhsachcauhoithi.txt",ios::in);
	KhoiTaoCay(t);
	int soluong;
	fi>>soluong;
	string str;
	getline(fi,str);
	for(int i=0;i<soluong;i=i+6)
	{
		CAUHOI ch; 
		Read_CauHoi(fi,ch,stk);
		//ThemCauHoiThi(t,ch);
	}
	fi.close();
}
// lay cau hoi thi theo ma tu ngan hang danh sach cau hoi thi
void Boc_Cau_Hoi_Thi_Theo_MA(TREE &t,char maMH[15],CAUHOIMA &chm)
{
	chm.count=0;
	/*for(int i = 0;i<MAX3;i++)
	{
		chm.stkch[i] = new CAUHOI;
	}*/
	int stacksize=10000;
	struct phantu
	{
		TREE diachi;
		int kieu;// danh dau nut cha hay nut con ben phai
	};
	phantu Stack[stacksize];
	int typ = 1;
	int top = 0;
	TREE p=t;
	Stack[0].diachi=NULL;// khoi tao stack
	do{
		while(p!=NULL&&typ==1)
		{
			Stack[++top].diachi=p;
			Stack[top].kieu=0;//nut cha
			if(p->pRIGHT!=NULL)
			{
				Stack[++top].diachi=p->pRIGHT;
				Stack[top].kieu=1;//nut con
			}
			p=p->pLEFT;
		}
		if(p!=NULL)
		{
			if(strcmp(maMH,p->data.MAMH)==0)// tim thay ma mon hoc thich hop
			{
				chm.stkch[chm.count] = new CAUHOI;// cap phat vung nho cho con tro thanh vien trong danh sach cau hoi thi
				chm.stkch[chm.count] = &p->data;// gan cau hoi da tim dc sang con tro cau hoi theo ma
				chm.count++; // tang so luong danh cau hoi theo ma len mot don vi
			}
		}
		p=Stack[top].diachi;
		typ=Stack[top--].kieu;
	}while(p!=NULL);
}
//void Duyet_LRN_Khudequi(TREE &t)
//{
//	xd=2;
//	int stacksize=10000;
//	struct phantu
//	{
//		TREE diachi;
//		int kieu;// danh dau nut cha hay nut con ben phai
//	};
//	phantu Stack[stacksize];
//	int typ = 1;
//	int top = 0;
//	TREE p=t;
//	Stack[0].diachi=NULL;// khoi tao stack
//	do{
//		while(p!=NULL&&typ==1)
//		{
//			Stack[++top].diachi=p;
//			Stack[top].kieu=0;//nut cha
//			if(p->pRIGHT!=NULL)
//			{
//				Stack[++top].diachi=p->pRIGHT;
//				Stack[top].kieu=1;//nut con
//			}
//			p=p->pLEFT;
//		}
//		if(p!=NULL)
//		{
//			Xuat_Cau_Hoi(p->data);
//		}
//		p=Stack[top].diachi;
//		typ=Stack[top--].kieu;
//	}while(p!=NULL);
//	//gotoxy(x,xd++);
//	//cout<<DemSoHang(t);
//}
//void Xuat_Cau_Hoi_Theo_Ma(TREE &t,char mamh[15])
//{
//	int dem = 0;
//	int stacksize=10000;
//	struct phantu
//	{
//		TREE diachi;
//		int kieu;// danh dau nut cha hay nut con ben phai
//	};
//	phantu Stack[stacksize];
//	int typ = 1;
//	int top = 0;
//	TREE p=t;
//	Stack[0].diachi=NULL;// khoi tao stack
//	do{
//		while(p!=NULL&&typ==1)
//		{
//			Stack[++top].diachi=p;
//			Stack[top].kieu=0;//nut cha
//			if(p->pRIGHT!=NULL)
//			{
//				Stack[++top].diachi=p->pRIGHT;
//				Stack[top].kieu=1;//nut con
//			}
//			p=p->pLEFT;
//		}
//		if(p!=NULL)
//		{
//			if(strcmp(mamh,p->data.MAMH)==0)
//			{
//				Xuat_Cau_Hoi(p->data);
//				dem++;
//			}
//		}
//		p=Stack[top].diachi;
//		typ=Stack[top--].kieu;
//	}while(p!=NULL);
//	//gotoxy(x,xd++);
//	//cout<<DemSoHang(t);
//	if(dem>0)
//	{
//		gotoxy(x,++xd);
//		cout<<"Tong so cau hoi thi la : "<<dem;
//	}
//	else
//	{
//		gotoxy(x,++xd);
//		cout<<"Xin Nhap Cau Hoi Vao Danh Sach";
//	}
//	system("pause");
//}
////void ThemCauHoiThi(TREE &t,CAUHOI &ch)
////{
////	Insert_balance(t,ch);
////}
////void XemBF(TREE &t)
////{
////	if(t!=NULL)
////	{
////		XemBF(t->pLEFT);
////		XemBF(t->pRIGHT);
////		cout<<t->bf<<" ";
////	}
////}
//int DemSoHang(TREE &t)// dem so hang de luu vao file text, mot cau hoi se co 6 dong
//{
//	int dem=0;
//		int stacksize=100;
//		struct phantu
//		{
//			TREE diachi;
//			int kieu;// danh dau nut cha hay nut con ben phai
//		};
//		phantu Stack[stacksize];
//		int typ = 1;
//		int top = 0;
//		TREE p=t;
//		Stack[0].diachi=NULL;// khoi tao stack
//		do{
//			while(p!=NULL&&typ==1)
//			{
//				Stack[++top].diachi=p;
//				Stack[top].kieu=0;//nut cha
//				if(p->pRIGHT!=NULL)
//				{
//					Stack[++top].diachi=p->pRIGHT;
//					Stack[top].kieu=1;//nut con
//				}
//				p=p->pLEFT;
//			}
//			if(p!=NULL)
//			{
//				dem=dem+6;
//			}
//			p=Stack[top].diachi;
//			typ=Stack[top--].kieu;
//		}while(p!=NULL);
//	return dem;
//}
//void Save_CauHoi(ofstream &fo, CAUHOI &ch)
//{
//	fo<<ch.MAMH<<"."<<ch.noidung<<endl;
//	fo<<ch.A<<endl;
//	fo<<ch.B<<endl;
//	fo<<ch.C<<endl;
//	fo<<ch.D<<endl;
//	fo<<ch.dapan<<endl;
//}
//void Save_ListCauHoi(TREE &t)
//{
//	ofstream fo;
//	fo.open("danhsachcauhoithi.txt",ios::out);
//	fo<<DemSoHang(t)<<endl;
//	int stacksize=100;
//	struct phantu
//	{
//		TREE diachi;
//		int kieu;// danh dau nut cha hay nut con ben phai
//	};
//	phantu Stack[stacksize];
//	int typ = 1;
//	int top = 0;
//	TREE p=t;
//	Stack[0].diachi=NULL;// khoi tao stack
//	do{
//		while(p!=NULL&&typ==1)
//		{
//			Stack[++top].diachi=p;
//			Stack[top].kieu=0;//nut cha
//			if(p->pRIGHT!=NULL)
//			{
//				Stack[++top].diachi=p->pRIGHT;
//				Stack[top].kieu=1;//nut con
//			}
//			p=p->pLEFT;
//		}
//		if(p!=NULL)
//			Save_CauHoi(fo,p->data);
//		p=Stack[top].diachi;
//		typ=Stack[top--].kieu;
//	}while(p!=NULL);
//	fo.close();
//}
//void Read_CauHoi(ifstream &fi,CAUHOI &ch,STACKID &stk)
//{
//	// doc cau hoi tu file text, cac id se sinh ngau nhien tu danh sach id da tao 
//	ch.id=stk.listid[stk.top];
//	stk.top--;
//	fflush(stdin);
//	string str;
//	fi.getline(ch.MAMH,15,'.');
//	getline(fi,ch.noidung);
//	getline(fi,ch.A);
//	getline(fi,ch.B);
//	getline(fi,ch.C);
//	getline(fi,ch.D);
//	fi>>ch.dapan;
//	getline(fi,str);
//}
//void Read_ListCauHoi(TREE &t,STACKID &stk)
//{
//	ifstream fi;
//	fi.open("danhsachcauhoithi.txt",ios::in);
//	KhoiTaoCay(t);
//	int soluong;
//	fi>>soluong;
//	string str;
//	getline(fi,str);
//	for(int i=0;i<soluong;i=i+6)
//	{
//		CAUHOI ch; 
//		Read_CauHoi(fi,ch,stk);
//		//ThemCauHoiThi(t,ch);
//	}
//	fi.close();
//}
//// lay cau hoi thi theo ma tu ngan hang danh sach cau hoi thi
//void Boc_Cau_Hoi_Thi_Theo_MA(TREE &t,char maMH[15],CAUHOIMA &chm)
//{
//	chm.count=0;
//	/*for(int i = 0;i<MAX3;i++)
//	{
//		chm.stkch[i] = new CAUHOI;
//	}*/
//	int stacksize=10000;
//	struct phantu
//	{
//		TREE diachi;
//		int kieu;// danh dau nut cha hay nut con ben phai
//	};
//	phantu Stack[stacksize];
//	int typ = 1;
//	int top = 0;
//	TREE p=t;
//	Stack[0].diachi=NULL;// khoi tao stack
//	do{
//		while(p!=NULL&&typ==1)
//		{
//			Stack[++top].diachi=p;
//			Stack[top].kieu=0;//nut cha
//			if(p->pRIGHT!=NULL)
//			{
//				Stack[++top].diachi=p->pRIGHT;
//				Stack[top].kieu=1;//nut con
//			}
//			p=p->pLEFT;
//		}
//		if(p!=NULL)
//		{
//			if(strcmp(maMH,p->data.MAMH)==0)// tim thay ma mon hoc thich hop
//			{
//				chm.stkch[chm.count] = new CAUHOI;// cap phat vung nho cho con tro thanh vien trong danh sach cau hoi thi
//				chm.stkch[chm.count] = &p->data;// gan cau hoi da tim dc sang con tro cau hoi theo ma
//				chm.count++; // tang so luong danh cau hoi theo ma len mot don vi
//			}
//		}
//		p=Stack[top].diachi;
//		typ=Stack[top--].kieu;
//	}while(p!=NULL);
//}
//void Boc_Cau_Hoi_Thi_Ngau_Nhien(TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion)
//{
//	int b;
//	srand(time(NULL));
//	// cap phat vung nho cho danh sach cau hoi ngau nhien theo so luong cau hoi thi ma nguoi dung nhap vao ( mang con tro)
//	for(int i=0;i<randomquestion.socauhoithi;i++)
//	{
//		randomquestion.chnn[i] = new CAUHOI;
//	}
//	randomquestion.vitri_chnn=0;// khoi tao chi so cua cau hoi ngau nhien bang 0
//	int temp = chm.count-1;//cho bien temp bang voi so luong cau hoi theo ma tru di 1
//	int tempsocauhoithi= randomquestion.socauhoithi;// cho mot bien tempso cau hoi thi = so luong cau hoi thi nguoi dung nhap vao
//	// tien hanh boc cau hoi ngau nhien tu danh sach cau hoi theo ma
//	while(tempsocauhoithi>0)
//	{
//		b =rand()%(temp+0);// cho mot bien b random tu so 0 den temp ( temp o day chinh la so luong cau hoi theo ma)
//		// b o day chinh la vi tri ngau nhien trong danh sach cau hoi theo ma
//		randomquestion.chnn[randomquestion.vitri_chnn] = chm.stkch[b];
//		// lan luot cho tung phan tu cua danh sach cau hoi ngau nhien bang voi phan tu co vi tri ngau nhien b trong dnah sach cau hoi theo ma 
//		chm.stkch[b] = chm.stkch[temp];
//		// dem phan tu o vi tri cuoi cung trong danh sach cau hoi theo ma chen len phan tu thu b trong danh sach cau hoi theo ma
//		randomquestion.vitri_chnn++;// tang chi so cau hoi ngau nhien len 1 don vi
//		tempsocauhoithi--;// giam di bien tam so cau hoi thi di 1
//		temp--;// giam di bien temp di 1 (vi da lay 1 phan tu trong danh sach cau hoi theo ma )
//	}
//}
//void menuCAUHOI(TREE &t,listMH &lmh,STACKID &stk)
//{
//	CAUHOI ch;
//	int Amount_Menu=5;
//	int pointer2 = 0;
//	char* menucauhoi[]={"1.Them cau hoi thi","2.Xoa cau hoi thi","3.Hieu chinh ma cho cau hoi thi","4.Xem cau hoi thi","5.Exit"};
//	while(true)
//	{
//		system("cls");
//		textcolor(10);
//		VemenuTONG();
//		gotoxy(20,26);
//		cout<<"Quan Cau Hoi Thi";
//		VeKhungCH(1,25,50,3,true);
//		gotoxy(1,28);
//		for(int i=0;i<Amount_Menu;i++)
//		{
//			if(pointer2==i)
//			{
//				textcolor(20);
//				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menucauhoi[i];
//			}
//			else
//			{
//				textcolor(10);
//				cout<<"\n\n"<<char(179)<<setw(4)<<right<<" "<<menucauhoi[i];
//			}
//		}
//		textcolor(10);
//		while(true)	// xu li key board
//		{
//			if(kbhit())// neu co phim nao nhap vao 
//			{
//				char key =getch();// luu phim do lai de xu li 
//				if(key == 72)// len
//				{
//					if(pointer2>0){
//						--pointer2;
//					}
//					else{
//						pointer2=Amount_Menu-1;
//					}
//					break;
//				}
//				if(key==80)//xuong
//				{
//					if(pointer2<Amount_Menu-1)
//					{
//						++pointer2;
//					}
//					else
//					{
//						pointer2 = 0;
//					}
//					break;
//					}
//				if(key==13)//enter
//				{
//					if(pointer2==0)
//					{
//						xd=2;
//						if(t==NULL)
//						{
//							gotoxy(x,++xd);
//							cout<<"Ban muon thuc hien thao tac nay chu ? No se tao moi lai danh sach trong danhsachcauhoithi.txt?(OK : ENTER, ESC : thoat)";
//							char key1 = getch();
//							if(key1==13)
//							{
//								gotoxy(x,++xd);
//								Nhap_Cau_Hoi(ch,stk,lmh);
//								//ThemCauHoiThi(t,ch);
//								Save_ListCauHoi(t);
//								system("pause");
//								break;
//							}
//							else if(key1==27)
//							{
//								break;
//							}
//						}
//						gotoxy(x,++xd);
//						Nhap_Cau_Hoi(ch,stk,lmh);
//						//ThemCauHoiThi(t,ch);
//						Save_ListCauHoi(t);
//						system("pause");
//						break;
//					}
//					else if(pointer2==1)
//					{
//						if(t==NULL)
//						{
//							gotoxy(x,20);
//							cout<<"Danh Sach Cau Hoi trong";
//							system("pause");
//							break;
//						}
//						int k = 5;
//						xd = 7;
//						string tenmonh;
//						char mamonhoc[15];
//						int flag = 0;
//						gotoxy(x+40,3);
//						cout<<"Danh Sach Mon Hoc";
//						VeKhungCH(x,2,100,2,true);
//						gotoxy(x,5);
//						cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma mon hoc"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten mon hoc";
//						VeKhungCH(x,2,100,4,true); 
//						for(int i =0;i<lmh.soluong;i++)
//						{
//							xd=xd+2;
//							gotoxy(x,xd);
//							Xuat_MonHoc(*lmh.dsmh[i]);
//							k=k+2;
//						}
//						VeKhungCH(x,2,100,k+1,true);
//						xd=xd+2;
//						gotoxy(x,++xd);
//						cout<<"Nhap vao ten mon hoc ";
//						XuLiNhap(tenmonh);
//						for(int i = 0 ;i<lmh.soluong;i++)
//						{
//							if(stricmp(lmh.dsmh[i]->tenMH.c_str(),tenmonh.c_str())==0)
//							{
//								strcpy(mamonhoc,lmh.dsmh[i]->MAMH);
//								flag = 1;
//								break;
//							}
//						}
//						if(flag==1)
//						{
//							string id;
//							id.clear();
//							Xuat_Cau_Hoi_Theo_Ma(t,mamonhoc);
//							VeKhungCH(x,++xd,80,3,true);
//							gotoxy(x+5,++xd);
//							cout<<"NHAP VAO ID CAU HOI CAN XOA | ";
//							NhapSoKoChu(id);
//							VeKhungCH(x,xd+5,80,3,true);
//							gotoxy(x+5,xd+6);
//							cout<<"Ban muon xoa cau hoi nay ? (ENTER : dong y, ESC : thoat)";
//							char key2 = getch();
//							if(key2==13)
//							{
//								//Xoa_Cau_Hoi_Thi(t,atoi(id.c_str()));
//								Save_ListCauHoi(t);
//							}
//							else if(key2==27)
//							{
//								break;
//							}
//							system("pause");
//						}
//						else
//						{
//							gotoxy(x,++xd);
//							cout<<"KHONG TIM DC MON HOC !!!";
//							break;
//						}		
//						
//					}
//					else if(pointer2==2)
//					{
//						if(t==NULL)
//						{
//							gotoxy(x,20);
//							cout<<"Danh Sach Cau Hoi trong";
//							system("pause");
//							break;
//						}
//						xd=5;
//						string mact;
//						string mamoi;
//						do{
//							mact.clear();
//							gotoxy(x,++xd);
//							cout<<"Nhap vao ma mon hoc can thay the : ";
//							XuLiNhapMa(mact);
//							if(Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(t,(char *)mact.c_str())==false)
//							{
//								gotoxy(x,++xd);
//								cout<<"Khong co ma can thay the nhap lai ";
//							}
//						}while(Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(t,(char *)mact.c_str())==false);
//						gotoxy(x,++xd);
//						cout<<"Nhap vao ma mon hoc moi cho cau hoi : ";
//						XuLiNhapMa(mamoi);
//						gotoxy(x,++xd);
//						cout<<"Ban muon tiep tuc chu (Enter : OK , Esc :Thoat) ";
//						char key3 = getch();
//						if(key3==13)
//						{
//							Hieu_Chinh_Cau_Hoi_Ma(t,mact,mamoi);
//							Save_ListCauHoi(t);
//						}
//						else if(key3==27)
//						{
//							break;
//						}
//					}
//					else if(pointer2==3)
//					{
//						if(t==NULL)
//						{
//							gotoxy(x,20);
//							cout<<"Danh Sach Cau Hoi trong";
//							system("pause");
//							break;
//						}
//						int k = 5;
//						xd = 7;
//						string tenmonhoc;
//						char mamonhoc[15];
//						int flag = 0;
//						gotoxy(x+40,3);
//						cout<<"Danh Sach Mon Hoc";
//						VeKhungCH(x,2,100,2,true);
//						gotoxy(x,5);
//						cout<<setw(5)<<right<<" "<<setw(45)<<left<<"Ma mon hoc"<<char(179)<<setw(5)<<" "<<setw(45)<<left<<"Ten mon hoc";
//						VeKhungCH(x,2,100,4,true); 
//						for(int i =0;i<lmh.soluong;i++)
//						{
//							xd=xd+2;
//							gotoxy(x,xd);
//							Xuat_MonHoc(*lmh.dsmh[i]);
//							k=k+2;
//						}
//						VeKhungCH(x,2,100,k+1,true);
//						xd=xd+2;
//						gotoxy(x,++xd);
//						cout<<"Nhap vao ten mon hoc muon xem cau hoi thi : ";
//						XuLiNhap(tenmonhoc);
//						for(int i = 0 ;i<lmh.soluong;i++)
//						{
//							if(stricmp(lmh.dsmh[i]->tenMH.c_str(),tenmonhoc.c_str())==0)
//							{
//								strcpy(mamonhoc,lmh.dsmh[i]->MAMH);
//								flag = 1;
//								break;
//							}
//						}
//						if(flag==1)
//						{
//							Xuat_Cau_Hoi_Theo_Ma(t,mamonhoc);
//						}
//						else
//						{
//							gotoxy(x,++xd);
//							cout<<"KHONG TIM DC MON HOC !!!";
//							break;
//						}		
//						system("pasue");
//					}
//					else if(pointer2==4)
//					{
//						return;
//					}
//					break;
//				}
//			}
//		}
//	}
//}
