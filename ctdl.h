#pragma once

#include"ctdl.h"
#include<iostream>
#include<string.h>
#include<iostream>
#include <iostream>
#include<conio.h>
#include <string>
#include <windows.h>
#include<fstream>
#include <cstdlib>// rand , srand
#include <ctime>
#include<iomanip>
#include <ctype.h>
#define MAX_MONHOC 200

using namespace std;
const int MAX_SL_CAU_HOI_KT= 60;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
struct CauHoi
{
	int id;
	string MAMH;
	string qus;
	string opt[4];
	int ans;
};
typedef struct CauHoi CAU_HOI;
struct ds_CauHoi{
	CAU_HOI cauhoi[MAX_MONHOC];
	int sl=0;
	
};
typedef struct ds_CauHoi DS_CAUHOI;
//Cây nh? phân - Môn Hoc
struct MonHoc{
	char MAMH[15];
	char TENMH[255];
	int sl_CauHoi=0;
	// contro dsch
	DS_CAUHOI dsch;
	
};
typedef struct MonHoc MONHOC;
struct NodeMH{
	MONHOC monhoc;
	NodeMH *pLeft;
	NodeMH *pRight;
};
typedef struct NodeMH  NODEMH;
typedef  NODEMH* TREE_MH;

// danh sach lien ket don - DIEM THI
struct diem_Thi{
	string MaMH;
	float diem;
	// contro 
	diem_Thi *pnext;
};
typedef struct diem_Thi DIEM_THI;
struct ds_diem_thi{
	DIEM_THI* pHead=NULL;
	int so_Luong=0;
};
typedef struct ds_diem_thi DS_DIEM_THI;
struct CauHoiKT
{
	int id;
	int tl=-1;
};
struct BaiKT
{
	string MAMH;
	float diem;  
	int sl_cauhoiKT;
	CauHoiKT ds_cahuhoiKT[MAX_SL_CAU_HOI_KT];
};
struct node_BaiKT
{
	BaiKT bkt;
	struct node_BaiKT *next = NULL;
};
typedef node_BaiKT* PTR_BaiKT;
// danh sach sinh vien 

struct Sinh_Vien{
	string MASV;
	string HO;
	string TEN;
	string PHAI;
	string password;
	// con tro
	PTR_BaiKT ds_bkt = NULL;
};
typedef struct Sinh_Vien SINHVIEN;
struct node_Sinh_Vien{
	SINHVIEN data;
	node_Sinh_Vien *pnext;
};
typedef struct node_Sinh_Vien NODESINHVIEN;
struct danh_sach_sinh_vien
{
	NODESINHVIEN* phead = NULL;
};
typedef struct danh_sach_sinh_vien DANH_SACH_SINH_VIEN;
// Mang con tro - LOP
struct lop{
	string maLop;
	string tenLop;
	int soLuongsv=0;
	bool isnotempty=0;
	//con tro dssv
	DANH_SACH_SINH_VIEN dssv;
	
};
typedef struct lop LOP;
struct ds_Lop{
	LOP* ds[100];
	int sl=0;
};
typedef struct ds_Lop DANH_SACH_LOP;





