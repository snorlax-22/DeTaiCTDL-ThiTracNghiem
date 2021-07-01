#pragma once
#include"ctdl.h"
#include"tumlum.h"
#include"doc_ghi_file.h"
#include"giaodien.h"
#include"TreeMonHoc.h"

#define MAX_MONHOC 200

int sl_monhoc = 0;
int sl_cauhoi = 0;
/////////khai bao//////////////
//void DeleteArrPointer(MON_HOC* ds_monhoc[MAX_MONHOC], int sl_monhoc);
void luuMonHoc(TREE_MH  ds_monhoc, int sl_monhoc);
//void DemCauHoi(DS_CAUHOI dsch, string MAMH, int ds[200], int &i);
int DanhSachMonHoc(TREE_MH root, string MAMH, int ds[10000]);
int TimMonHoc(TREE_MH root, int sl_monhoc, int flag, char input[15]);
void Sua_MMH_Tren_Cay(TREE_MH&root, string mamh, string premamh);
bool Kiem_tra_trung_mon(TREE_MH root, string mamonhoc);
//void UserGV(DANH_SACH_LOP &dsl);
////////// cac ham co toa do///////////////
void Plus_Form_quan_ly_mon_hoc(int x, int y, TREE_MH &root);
void Plus_Them_mon_hoc(int x, int y, TREE_MH &root);
void Plus_Xuat_mon_hoc(int x, int y, int vt, TREE_MH root);
void Plus_Nhap_thong_tin_cau_hoi(CAU_HOI &key, int x, int y, bool &exit);
void Plus_them_cau_hoi_vao_mon_hoc(DS_CAUHOI &dsch, int &sl_cauhoi,  int x, int y);
void Plus_Xuat_danh_sach_cau_hoi_thi(TREE_MH root, string tenmonhoc, int x, int y);
void Plus_Sua_Mon_Hoc(TREE_MH &root, int& sl_monhoc, int x, int y,CAU_HOI &dsch);
void Plus_Xuat_1_Cau_Hoi(int pos, CAU_HOI cauhoi, int ds[1000], int x, int y);
void Plus_Xoa_Mon_Hoc(TREE_MH &root, int& sl_monhoc, int x, int y,CAU_HOI &dsch);
/////////////ket thuc khai bao//////////////
/////////////cac ham thuong/////////////
void DemCauHoi(DS_CAUHOI dsch,string maMH,int ds[200]){
	int dem=0;
	for(int i=0;i<dsch.sl;i++){
		if(dsch.cauhoi[i].MAMH==maMH){
			ds[i]= dsch.cauhoi[i].id;
			dem++;
		}
	}
}
int Dem_so_cau_hoi_cua_mon_hoc(DS_CAUHOI dsch, string maMH){
		int dem=0;
	for(int i=0;i<dsch.sl;i++){
		if(dsch.cauhoi[i].MAMH==maMH){
			dem++;
		}
	}
	return dem;
}
int Danh_Sach_Cau_Hoi(DS_CAUHOI dsch, string MAMH, int ds[200])
{
	int i = 0;
	DemCauHoi(dsch, MAMH, ds);
	return i;
}

CAU_HOI timCauHoi(DS_CAUHOI dsch,int id){
	CAU_HOI p;
	for(int i=0;i<dsch.sl;i++){
		if(p.id==dsch.cauhoi[i].id){
			p= dsch.cauhoi[i];
		}
		return p;
	}
}
int KiemTraTrungMaMH(TREE_MH t, string a)
{
    char s[11];
    //strcpy(s, a.c_str());
    //	strupr(s);
    NODEMH* p;
    while (t) {
        if (t->pLeft == NULL) {
            if (strcmp(t->monhoc.MAMH, s) == 0) return 1;
            t = t->pRight;
        }
        else {
            p = t->pLeft;
            while (p->pRight && p->pRight != t) {
                p = p->pRight;
            }
            if (p->pRight == NULL) {
                p->pRight = t;
                t = t->pLeft;
            }
            else {
                p->pRight = NULL;
                if (strcmp(t->monhoc.MAMH, s) == 0) return 1;

                t = t->pRight;
            }
        }
    }
    return 0;
}
void Sua_MMH_Trong_DSCH(DS_CAUHOI &dsch, string maMH,string premaMH){
for(int i=0;i<dsch.sl; i++){
	if(dsch.cauhoi[i].MAMH==premaMH){
		dsch.cauhoi[i].MAMH=maMH;
		}
	}
}

 
void xoa1phantu(DS_CAUHOI a,int *n,int vt)
{
     int i;
     for(i=vt;i<*n-1;i++)
     {
            a.cauhoi[i]=a.cauhoi[i+1];
            *n--;
     }
}
   
void Xoa_Mon_Hoc_Trong_DSCH(DS_CAUHOI &dsch, string mamh, int &sl_cauhoi)
{
	if(dsch.sl <0)
		return ;
	for(int i=0;i<dsch.sl;i++){
		if(dsch.cauhoi[i].MAMH==mamh){
			xoa1phantu(dsch,&sl_cauhoi,i);
			i--;
		}
	}	
}

void Plus_Form_quan_ly_mon_hoc(int x,int y,TREE_MH &root){
	khungquanlymonhoc(x,y);
	gotoxy(x + 16, y + 2);
	string a;
	string s[200]; //mang luu ten mon hoc
	string ma[200]; // mang luu ma mon hoc
	int count = 0;
	int tam = 0;
	for (int i = 0; i < sl_monhoc; i++)
	{
		if (tam < 16)
		{
			gotoxy(x + 5, y + 7 + tam);
			cout << root->monhoc.MAMH;
			gotoxy(x + 20, y + 7 + tam);
			cout << rut_gon_text(root->monhoc.TENMH,20);
		}
		s[tam] =root->monhoc.TENMH;//gan ten lop cho chuoi s
		ma[tam] = root->monhoc.MAMH;
		tam++;
		count = tam;
	}
	if (tam > 16)
	{
		gotoxy(x + 20, y + 7 + 16);
		cout << "(And " << tam - 16 << " more...)";
	}
	while (true)
	{
		find:
		XoaManHinh(x + 49, y + 28, 55, 5);//xoa man hinh khung chuc nang//xoa man hinh khung chuc nang
		gotoxy(x + 50, y + 28);
		cout << "F1: Nhap moc hoc";
		gotoxy(x + 80, y + 28);
		cout << "F2: Luu du lieu ";
		gotoxy(x + 50, y + 29);
		cout << "F11: Xuat danh sach mon hoc";
		gotoxy(x + 80, y + 29);
		cout << "F4: Nhap cau hoi thi";
		gotoxy(x + 50, y + 30);
		cout << "F5: Sua mon hoc";
		gotoxy(x + 80, y + 30);
		cout << "F6: Xoa mon hoc";
		gotoxy(x + 50, y + 31);
		cout << "ESC: THOAT";
		XoaManHinh(x + 2, y + 28, 46, 7);//XOA MAN HINH KHUNG NOTI
		gotoxy(x + 16 + a.length(), y + 2);// dua con tro chi vi ve thanh tim kiem
		hidecur(false);
		char k = _getch();
		while (k == 72 || k == -32)
		{
			k = _getch();
		}
		if (k == 64)// phim f6 -> Xoa mon hoc
		{
			//Plus_Xoa_Mon_Hoc(ds_monhoc, sl_monhoc, x, y, root);
			XoaManHinh(x + 110, y + 25, 45, 9);//xoa man hinh khung nhap thong tin
			XoaManHinh(x + 49, y + 28, 55, 5);//xoa man hinh khung chuc nang
			XoaManHinh(x + 52, y + 7, 102, 16);//xoa man hinh o danh sach sinh vien
			Sleep(1500);
		}
		if (k == 27)// esc -> return
		{
			system("cls");
			return;
		}
		if (k == -123)//Nhan f11 de show toan bo lop
		{
			XoaManHinh(x + 5, y + 7, 40, 17);//xoa man hinh o danh sach lop
			XoaManHinh(x + 49, y + 28, 55, 5);//xoa man hinh khung chuc nang
			gotoxy(x + 60, y + 30);
			cout << "ESC: Quay lai khung tim kiem";
			int vt = 0;
			gotoxy(x + 3, y + 30);
			cout << "Dung phim mui ten trai/phai de xem danh sach";
			while (true)
			{
			//	Plus_Xuat_mon_hoc(x, y, vt, ds_monhoc);															// todo(1) viet ham xuat mon hoc (done)
				char k = _getch();
				hidecur(false);
				if (k == 77)
				{
					if (vt <= sl_monhoc - 16)
					{
						vt += 16;
						XoaManHinh(x + 10, y + 7, 40, 17);
					}//xoa man hinh o danh sach lop
				}
				if (k == 75)
				{
					if (vt >= 16)
					{
						vt -= 16;
						XoaManHinh(x + 10, y + 7, 40, 15);
					}//xoa man hinh o danh sach lop
				}
				if (k == 27)
				{
					XoaManHinh(x + 2, y + 28, 46, 7);//XOA MAN HINH KHUNG NOTI
					XoaManHinh(x + 10, y + 7, 40, 17);//xoa man hinh o danh sach lop
					break;
				}
				hidecur(true);
			}
			XoaManHinh(x + 2, y + 28, 46, 7);//XOA MAN HINH KHUNG NOTI
			gotoxy(x + 10, y + 30);
		}
		if (k == 59)//nhan phim f1 de them lop hoc
		{		
			//Plus_Them_mon_hoc(x, y, root);
			XoaManHinh(x + 110, y + 25, 45, 9);//xoa man hinh khung nhap thong tin
		}
		if (k == 60)//phim f2. chuc nang luu du lieu ra file
		{
			//luuMonHoc(ds_monhoc, sl_monhoc);
			//luuCauHoi(root, sl_cauhoi);
			XoaManHinh(x + 2, y + 28, 46, 7);//XOA MAN HINH KHUNG NOTI
			gotoxy(x + 10, y + 30);
			cout << "LUU DU LIEU THANH CONG";
			Sleep(1000);
		}
		if (k == 62)// phim f4, chuc nang nhap cau hoi thi
		{
		//	Plus_them_cau_hoi_vao_mon_hoc(root, sl_cauhoi, x, y);
			XoaManHinh(x + 110, y + 25, 45, 9);//xoa man hinh khung nhap thong tin
		}
		if (k == 8)//phim backspace
		{
			if (a.length() >= 1)
			{
				XoaManHinh(x + 15 + a.length(), y + 2, 1, 1);
				a.erase(a.size()-1);
				gotoxy(x + 15 + a.length(), y + 2);
			}
		}
		if (k >= 48 && k <= 57 && a.length() < 40)//hang phim so
		{
			a.push_back(k);
			gotoxy(x + 15 + a.length(), y + 2);
			cout << k;
		}
		if ( a.length() < 14 && (k >= 97 && k <= 122) || k == ' ')//phim ki tu va space
		{
			a.push_back(k);
			gotoxy(x + 15 + a.length(), y + 2);
			cout << k;
		}
		if (k == 80 && count != 0)//phim xuong
		{
			XoaManHinh(x + 49, y + 28, 55, 5);//xoa man hinh khung chuc nang
			gotoxy(x + 60, y + 30);
			cout << "ESC: Quay lai khung tim kiem";
			hidecur(true);
			break;
		}
		hidecur(true);
		//chuan hoa chu nhap vao
		string a1 = a;
		ChuanHoaChu(a1);
		string a2 = a;
		In_Hoa(a2);
		XoaManHinh(x + 5, y + 7, 40, 17);//xoa man hinh o danh sach lop
		int temp = 0;
		if (a.length() != 0)// xoa het
		{

			for (int i = 0; i < sl_monhoc; i++)
			{
				if (ahaveb(root->monhoc.MAMH, a2) || ahaveb(root->monhoc.TENMH, a1))//kiem tra dieu kien tim kiem
				{
					if (temp < 16)
					{
						gotoxy(x + 5, y + 7 + temp);
						cout << root->monhoc.MAMH;
						gotoxy(x + 20, y + 7 + temp);
						cout << rut_gon_text(root->monhoc.TENMH, 20);
					}
					s[temp] = root->monhoc.TENMH;//gan ten lop cho chuoi s
					ma[temp] = root->monhoc.MAMH;
					temp++;
					count = temp;
				}
			}
			if (temp > 16)
			{
				gotoxy(x + 20, y + 7 + 16);
				cout << "(And " << temp - 16 << " more...)";
			}
		}
		else // ton tai ki tu
		{
			for (int i = 0; i < sl_monhoc; i++)
			{
				if (temp < 16)
				{
					gotoxy(x + 5, y + 7 + temp);
					cout << root->monhoc.MAMH;
					gotoxy(x + 20, y + 7 + temp);
					cout << rut_gon_text(root->monhoc.TENMH, 20);
				}
				s[temp] = root->monhoc.TENMH;//gan ten lop cho chuoi s
				ma[temp] = root->monhoc.MAMH;
				temp++;
				count = temp;
			}
			if (temp > 16)
			{
				gotoxy(x + 20, y + 7 + 16);
				cout << "(And " << temp - 16 << " more...)";
			}
		}
		gotoxy(x + 16 + a.length(), y + 2);//dua con tro chi vi ve thanh tim kiem
		hidecur(false);
	}
	XoaManHinh(x + 5, y + 7, 40, 17);//xoa man hinh o danh sach lop
	hidecur(true);
	int vt1 = 0;
	while (true)
	{
		if (count > 16)
		{
			gotoxy(x + 3, y + 30);
			cout << "Dung phim mui ten trai/phai de xem danh sach";
		}
		int cmd = menuadvanced(s, x + 15, y + 7, 0, count);
		if (cmd == 99)
		{
			gotoxy(x + 16 + a.length(), y + 16);//nhan enter vao o "quay lai thanh tim kiem"
			hidecur(false);
			goto find;
		}
		// xuat danh sach cau hoi
		XoaManHinh(x + 2, y + 28, 46, 7);//XOA MAN HINH KHUNG NOTI
		XoaManHinh(x + 49, y + 28, 55, 5);//xoa man hinh khung chuc nang
		gotoxy(x + 60, y + 30);
		cout << "ESC: Quay lai danh sach lop";
	//	Plus_Xuat_danh_sach_cau_hoi_thi(root, ma[cmd], x, y);
		
	}
}

void Plus_Them_mon_hoc(int x, int y, TREE_MH &root)
{
	MONHOC monhoc;
	XoaManHinh(x + 49, y + 28, 55, 5);//xoa man hinh khung chuc nang
	gotoxy(x + 60, y + 30);
	cout << "ESC: Quay lai khung tim kiem";
	int sl_monhoc=TinhsoNode(root);
	int temp = 0;
	for (int i = 0; i <sl_monhoc; i++)
	{
		if (i < 16)
		{
			gotoxy(x + 5, y + 7 + i);
			cout << root->monhoc.MAMH;
			gotoxy(x + 20, y + 7 + i);
			cout << rut_gon_text(root->monhoc.TENMH,20);
			temp++;
		}
		
	}
	if (temp>15)
	{
		gotoxy(x + 20, y + 7 + 16);
		cout << "(And " << sl_monhoc - temp << " more...)";
	}
	XoaManHinh(x + 2, y + 28, 46, 7);//XOA MAN HINH KHUNG NOTI
	hidecur(false);
	XoaManHinh(x + 123, y + 28, 28, 1);
	XoaManHinh(x + 123, y + 32, 28, 1);//xoa noi dung cu cua 2 thanh ma lop va ten lop
	Ve_HCN(30, 1, x + 122, y + 27);//tao khung nhap ma lop
	gotoxy(x + 112, y + 28);
	cout << "MA MON: ";//tro toi cho nhap ma lop
	Ve_HCN(30, 1, x + 122, y + 31);//tao khung nhap ten lop
	gotoxy(x + 112, y + 32);
	cout << "TEN MON: ";//tro toi cho nhap ten lop
	
	nhapmamonhoc:
	string a;//ma lop
	string b;//ten lop
	gotoxy(x + 123, y + 28);
}

