#ifndef DSCAUHOITHI_H
#define DSCAUHOITHI_H
#include "thuvienlaptrinh.h"
#include "DSMonHoc.h"
#include "DSlop.h"
//moi thay doi tg nay lan thu 2 cho thu oc xem
using namespace std;
#define MAX4 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct cauhoithi
{
	int id;
	char MAMH[15];
	string noidung;
	string A;
	string B;
	string C;
	string D;
	char dapan;
};typedef struct cauhoithi CAUHOI;
struct node
{
	CAUHOI data; // du lieu cua cai node ==>du lieu node luu tru 
	struct node *pLEFT;// node lien ket ben trai cua cay => c�y con trai
	struct node *pRIGHT;// node lien ket ben phai cua cay => cay con phai 
};
struct Stackid //danh sach id ngau nhien
{
	int top = 0;
	int *listid;
};typedef struct Stackid STACKID;
typedef struct node NODE;
typedef NODE* TREE;
int Empty(TREE root);
void remove_case_3(TREE &t);
void KhoiTaoCay(TREE &t);
NODE* TimKiem(TREE t, CAUHOI &ch);
bool KT_MaCH_DSMH(listMH &lmh, string mamh);
void Nhap_Cau_Hoi(CAUHOI &ch, listMH &lmh);
void Xuat_Cau_Hoi(CAUHOI &ch);
void Insert_Node(TREE &t, CAUHOI &ch);
int Xoa_Cau_Hoi_Thi(TREE &t,int x);
void Hieu_Chinh_Cau_Hoi_Ma(TREE &t,string mact,string mamoi);
void Duyet_cay_LNR(TREE &t);
int DemSoHang(TREE &t);
//void ThemCauHoiThi(TREE &t,CAUHOI &ch);
void Save_CauHoi(ofstream &fo, CAUHOI &ch);
void Save_ListCauHoi(TREE &t);
//void Read_CauHoi(ifstream &fi,CAUHOI &ch,STACKID &stk);
//void Read_ListCauHoi(TREE &t,STACKID &stk);
//void Xuat_Cau_Hoi_Theo_Ma(TREE &t,char mamh[15]);
//void Boc_Cau_Hoi_Thi_Theo_MA(TREE &t,char maMH[15],CAUHOIMA &chm);
//void Boc_Cau_Hoi_Thi_Ngau_Nhien(TREE &t,CAUHOIMA &chm,CAUHOINGAUNHIEN &randomquestion);
//void menuCAUHOI(TREE &t,listMH &lmh,STACKID &stk);
bool Kiem_Tra_Mon_Do_Da_Co_Cau_Hoi_Chua(TREE &t,char mamh[15]);
void Khoitaoidngaunhien(STACKID &stkid);

#endif

