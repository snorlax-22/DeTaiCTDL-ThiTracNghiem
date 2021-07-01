#pragma once
#include"xulylophoc.h"
//#include"xulymonhoc.h"
//#include"AVL.h"
void Them_Vao_Cuoi(DANH_SACH_SINH_VIEN& l, NODESINHVIEN*p);
void luuMonHoc(MonHoc* ds_monhoc[MAX_MONHOC], int sl_monhoc);
NODESINHVIEN* KhoiTaoSinhVien(SINHVIEN sv);
#define MAX_MONHOC 200
#define true 1
#define false 0

void Ghi_file_danh_sach_lop(DANH_SACH_LOP dsl){
	ofstream f("danhsach_lop.txt",ios::out);
//	f << dsl.sl << endl;
	for (int i = 0; i < dsl.sl; i++)
	{
		f << dsl.ds[i]->maLop;
		f << ',';
		f << dsl.ds[i]->tenLop;
		f << ',';
		f << dsl.ds[i]->isnotempty;
		f << "\n";
	}
	f.close();

}

void Doc_file_danh_sach_lop(DANH_SACH_LOP &dsl)
{
	ifstream f("danhsach_lop.txt", ios::in);
	while (!f.eof())
	{
		dsl.ds[dsl.sl] = new LOP; 
		getline(f, dsl.ds[dsl.sl]->maLop,',');
		getline(f, dsl.ds[dsl.sl]->tenLop,',');
		f >> dsl.ds[dsl.sl]->isnotempty;
		f.ignore();
		dsl.sl++;
	}
	dsl.sl--;
	f.close();
}

void Ghi_file_dssv(DANH_SACH_LOP dsl)
{
	for (int i = 0; i < dsl.sl; i++)
	{
		ofstream f;
		string tenfile = dsl.ds[i]->maLop;
		tenfile.append(".txt");
		if (dsl.ds[i]->isnotempty==1)
		{
			f.open(tenfile.c_str(), ios::out);
			for (NODESINHVIEN* k = dsl.ds[i]->dssv.phead; k != NULL;k = k->pnext)
			{
				if (k->data.MASV.length() != 0)
				{
					f << k->data.MASV;
					//cout << k->sv.MASV;
					f << ",";
					f << k->data.HO;
					f << ",";
					f << k->data.TEN;
					f << ",";
					f << k->data.PHAI;
					f << ",";
					f << k->data.password;
					f << endl;
					
				}
			}
			f.close();
		}
	}
}
void Doc_file_dssv(DANH_SACH_LOP &dsl)
{
	for (int i = 0; i < dsl.sl; i++)
	{
		if (dsl.ds[i]->isnotempty == 1)
		{
			ifstream f;
			string tenfile = dsl.ds[i]->maLop;
			tenfile.append(".txt");
			f.open(tenfile.c_str(), ios::in);
			while (f.eof() != true)
			{
				SINHVIEN sv;
				getline(f, sv.MASV, ',');
				getline(f, sv.HO, ',');
				getline(f, sv.TEN, ',');
				getline(f, sv.PHAI, ',');
				getline(f, sv.password,'\n');
				f.ignore(0, '\n');
				NODESINHVIEN* p = KhoiTaoSinhVien(sv);
				//loadBaiTap(sv.MASV, p->data.ds_bkt);
				Them_Vao_Cuoi(dsl.ds[i]->dssv, p);
				if (sv.MASV.length() != 0)
				{
					dsl.ds[i]->soLuongsv++;
				}
			}
			f.close();
		}
	}
}


