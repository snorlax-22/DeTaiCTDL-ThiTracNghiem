#pragma once
#include"tumlum.h"

void vebang4cot(int x,int y,int w,int h){
	//dongdau
	gotoxy(x, y);
	for(int i=0;i<w;i++){
		if (i == 0)
			cout << (char(201));
		else if (i == w - 1)
			cout << char(187);
		else if (i == w / 4 || i == 3 * w / 5 || i == 3 * w / 4)
			cout << (char)203;
		else
			cout << (char)205;
	}
	gotoxy(x,y+1);
	for(int i=0;i<h;i++){
		if(i ==1){
			for(int j=0;j<w;j++){
				if(j==0)
					cout<<(char)204;
				else if(j==w-1)
					cout<<(char)185;
				else if(j == w / 4 || j == 3 * w / 5 || j == 3 * w / 4)
				{
					cout << (char)206;
				}
				else cout << (char)205;
			}
		}
		else{
			for(int j=0;j<w;j++){
				if(j==0 || j==w-1)
					cout<<(char)186;
				else if(j==w/4||j==3*w/5 ||j==3*w/4)
					cout<<(char)186;
				else cout<<" ";
			}
		}
		gotoxy(x, y + i + 2);
	}
	//dong cuoi
	gotoxy(x,y+h+1);
	for(int i=0;i<w;i++){
		if(i==0)
			cout<<char(200);
		else if(i==w-1)
			cout<<(char)188;
		else if (i == w / 4 || i == 3 * w / 5 || i == 3 * w / 4)
				cout<<(char)202;
		else 
			cout<<(char)205;
	}
}

void vebang2cot(int w, int h,int x, int y)
{
	//dong dau
	gotoxy(x, y);
	for (int i = 0; i < w;i++)
	{
		if (i == 0)
			cout << (char(201));
		else if (i == w - 1)
			cout << char(187);
		else if (i == w / 3 )
			cout << (char)203;
		else
			cout << (char)205;
	}
	//cout << endl;
	gotoxy(x, y + 1);
	//doan giua
	for (int i = 0;i < h;i++)
	{
		if (i == 1)
		{
			for (int j = 0;j < w;j++)
			{
				if (j == 0)
					cout << (char)204;
				else if (j == w - 1)
					cout << (char)185;
				else if (j == w / 3 )
				{
					cout << (char)206;
				}
				else cout << (char)205;
			}
			//cout << endl;
			
		}
		else
		{
			for (int j = 0;j < w;j++)
			{
				if (j == 0 || j == w - 1)
					cout << (char)186;
				else if (j == w / 3 )
				{
					cout << (char)186;
				}
				else cout << " ";
			}
			//cout << endl;
			
		}
		gotoxy(x, y + i + 2);
	}
	//dong cuoi
	gotoxy(x, y + h + 1);
	for (int i = 0; i < w;i++)
	{
		if (i == 0)
			cout << char(200);
		else if (i == w - 1)
			cout << char(188);
		else if (i == w - 1)
			cout << (char(188));
		else if (i == w / 3 )
			cout << (char)202;
		else
			cout << (char)205;
	}

}

void Ve_HCN(int w,int h,int x,int y){
	gotoxy(x,y);
	for(int i=0;i<w;i++){
		if(i==0)
			cout<<(char)218;
		else if(i== w-1)
			cout<<(char)191;
		else 
			cout<<(char)196;
		
	}
	cout<<endl;
	//doangiua
	gotoxy(x,y+1);
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(j==0||j==w-1)
				cout<<(char)179;
			else cout<<" ";
		}
		gotoxy(x,y+i+2);
	}
	//dong cuoi
	gotoxy(x,y+1+h);
	for (int i=0;i<w;i++)
	{
		if(i==0)
			cout<<(char)192;
		else if(i==w-1)
			cout<<(char)217;
		else cout<<(char)196;
	}
	
}
void Ke_line(int w, int x, int y)
{
	gotoxy(x, y);
	for (int i = 0; i < w; i++)
	{
		if (i == 0)
			cout << (char)195;
		else if (i == w - 1)
			cout << (char)180;
		else
			cout << (char)196;
	}
}
void Ke_column(int h, int x, int y)
{
	
	for (int i = 0; i < h; i++)
	{
		gotoxy(x, y+i);
		if (i == 0)
			cout << (char)194;
		else if (i == h - 1)
			cout << (char)193;
		else
			cout << (char)179;
	}
}
//// KHUNG GIAO DIEN

void khungDN(int x,int y){
	Ve_HCN(60, 15, x, y);
	Ke_line(60, x, y + 2);
	gotoxy(25+ x, 1 + y);
	cout << "DANG NHAP ";
	
	gotoxy(3 + x, 4 + y);
	cout << "Username:  ";
	Ve_HCN(43, 1, 13 + x, 3 + y);

	gotoxy(3 + x, 7 + y);
	cout << "Password:  ";
	Ve_HCN(43, 1, 13 + x, 6 + y);
	
	Ve_HCN(25,2,20+x,12+y);
	gotoxy(30+x,y+13);
	cout<<"LOGIN";
	gotoxy(30+x,y+14);
	cout<<"QUIT";
	
	
	
	
	
}

void khungquanlylophoc(int x, int y)
{
	//SetConsoleTextAttribute(console, 135);
	gotoxy(x, y);
	Ve_HCN(156, 35, x, y);
	gotoxy(x + 3, y + 2);
	cout << "Tim kiem: ";
	Ve_HCN(70, 1, x + 14, y + 1);//khung tim kiem
	Ve_HCN(50, 19, x + 1, y + 4);//khung danh sach lop
	Ke_line(50, x + 1, y + 6);
	Ve_HCN(104, 19, x + 51, y + 4);//khung danh sach sinh vien
	Ke_line(104, x + 51, y + 6);
	gotoxy(x + 18, y + 5);
	cout << "Danh sach lop hoc";
	gotoxy(x + 96, y + 5);
	cout << "Danh sach sinh vien";
	Ve_HCN(107, 9, x + 1, y + 25);//khung thong bao
	Ke_column(11, x + 48, y + 25);
	Ke_line(48, x + 1, y + 27);
	gotoxy(x + 20, y + 26);
	cout << "Thong bao";
	//gotoxy(x, y + 37);
	gotoxy(x + 65, y + 26);
	cout << "Phim tat kha dung";


}
void Khung_Nhap_Sinh_Vien(int x, int y)
{
	//XoaManHinh(x + 96, y + 5, 30, 1);
	gotoxy(x + 96, y + 5);
	cout << "Nhap sinh vien";
	gotoxy(x + 70, y + 9);
	cout << "Ma sinh vien: ";
	gotoxy(x + 70, y + 10);
	cout << "(Duoc tao tu dong ";
	gotoxy(x + 66, y + 11);
	cout<<"sau khi nhap thong tin)";
	Ve_HCN(20, 1, x + 90, y + 8);
	gotoxy(x + 55, y + 15);
	cout << "Ho:";
	Ve_HCN(30, 1, x + 65, y + 14);// ho

	gotoxy(x + 55, y + 19);
	cout << "Phai:";
	Ve_HCN(30, 1, x + 65, y + 18);// ten

	gotoxy(x + 105, y + 15);
	cout << "Ten:";
	Ve_HCN(30, 1, x + 115, y + 14);// gioi tinh

	gotoxy(x + 105, y + 19);
	cout << "Password:";
	Ve_HCN(30, 1, x + 115, y + 18);// pass
}
void Khung_nhap_cau_hoi(int x, int y)
{
	XoaManHinh(x + 96, y + 5, 30, 1);
	gotoxy(x + 96, y + 5);
	cout << "Nhap cau hoi thi";
	//gotoxy(x, y);
	gotoxy(x + 52, y + 7);
	cout << "Cau hoi:";
	Ve_HCN(85, 5, x + 65, y + 7);

	gotoxy(x + 55, y + 15);
	cout << "Dap an A:";
	Ve_HCN(30, 2, x + 65, y + 14);// dap an 1

	gotoxy(x + 55, y + 19);
	cout << "Dap an C:";
	Ve_HCN(30, 2, x + 65, y + 18);// dan an 3

	gotoxy(x + 105, y + 15);
	cout << "Dap an B:";
	Ve_HCN(30, 2, x + 115, y + 14);// dap an 2

	gotoxy(x + 105, y + 19);
	cout << "Dap an D:";
	Ve_HCN(30, 2, x + 115, y + 18);// dap an 2

	gotoxy(x + 85, y + 22);
	cout << "Dap an dung: ";
	Ve_HCN(12, 1, x + 100, y + 21);
}
void Khung_sua_mon_hoc(int x, int y)
{
	/*int x = a - 45;
	int y = b - 16;*/
	gotoxy(x + 107-45, y + 29-16);
	cout << "Ma mon hoc:";
	Ve_HCN(30, 1, x + 125-45, y + 28-16);
	gotoxy(x + 107-45, y + 32-16);
	cout << "Ten mon hoc:";
	Ve_HCN(50, 1,x + 125-45, y + 31-16 );
	
}
void khungquanlymonhoc(int x, int y)
{
	//SetConsoleTextAttribute(console, 135);
	gotoxy(x, y);
	Ve_HCN(156, 35, x, y);
	gotoxy(x + 3, y + 2);
	cout << "Tim kiem: ";
	Ve_HCN(70, 1, x + 14, y + 1);//khung tim kiem
	Ve_HCN(50, 19, x + 1, y + 4);//khung danh sach lop
	Ke_line(50, x + 1, y + 6);
	Ve_HCN(104, 19, x + 51, y + 4);//khung danh sach sinh vien
	Ke_line(104, x + 51, y + 6);
	gotoxy(x + 18, y + 5);
	cout << "Danh sach moc hoc";
	gotoxy(x + 96, y + 5);
	cout << "Danh sach cau hoi thi";
	Ve_HCN(107, 9, x + 1, y + 25);//khung thong bao
	Ke_column(11, x + 48, y + 25);
	Ke_line(48, x + 1, y + 27);
	gotoxy(x + 20, y + 26);
	cout << "Thong bao";
	//gotoxy(x, y + 37);
	gotoxy(x + 65, y + 26);
	cout << "Phim tat kha dung";
}
void stringcopy(int size, int pos, string original, string &result)
{
	//string result;
	for (int i = pos; i < pos + size; i++)
	{
		//result[i - pos] = original[pos];
		Insert_string(result, result.length(), original[i]);
	}
}
void Xuat_Thanh_Phan_Cau_Hoi(string cauhoi, int x, int y, int max)
{
	string temp[5];
	//xsmax[0].copy()
	//string cauhoi = timCauHoi(root, ds[i])->key.qus;
	int n = (cauhoi.length() - cauhoi.length() % max) / max + 1;
	if (n == 1)
	{
		gotoxy(x + 67, y + 15);
		cout << cauhoi;
	}
	else
	{
		for (int i = 1; i < n; i++)
		{
			gotoxy(x + 67, y + (i - 1) + 15);
			stringcopy(max, (i - 1) * max, cauhoi, temp[i - 1]);
			//temp[i-1], 78, (i-1) * 79);
			cout << temp[i - 1];
		}
		gotoxy(x + 67, y + n - 1 + 15);
		stringcopy(cauhoi.length() % max, (n - 1) * max, cauhoi, temp[n - 1]);
		cout << temp[n - 1];
	}
}

void Khung_Nhap_Thong_Tin_Bai_Thi(int x, int y)
{
	Ve_HCN(75, 11, x, y);
	gotoxy(x + 10, y + 3);
	cout << "Mon thi";
	Ve_HCN(30,1,x+33,y+2);
	gotoxy(x + 10, y + 6);
	cout << "Thoi gian thi (phut)";
	Ve_HCN(30, 1, x + 33, y + 5);
	gotoxy(x + 10, y + 9);
	cout << "So cau hoi thi";
	Ve_HCN(30, 1, x + 33, y + 8);

}

void Khung_Thi_Trac_Nghiem(int x, int y)
{
	
	XoaManHinh(x + 96, y + 5, 30, 1);
	Ve_HCN(120, 24, x + 45, y + 2);
	gotoxy(x + 96, y + 5);
	cout << "ID cau hoi: ";
	//gotoxy(x, y);
	gotoxy(x + 52, y + 7);
	cout << "Cau hoi:";
	Ve_HCN(85, 5, x + 65, y + 7);

	gotoxy(x + 55, y + 15);
	cout << "Dap an 1:";
	Ve_HCN(30, 2, x + 65, y + 14);// dap an 1

	gotoxy(x + 55, y + 19);
	cout << "Dap an 3:";
	Ve_HCN(30, 2, x + 65, y + 18);// dan an 3

	gotoxy(x + 105, y + 15);
	cout << "Dap an 2:";
	Ve_HCN(30, 2, x + 115, y + 14);// dap an 2

	gotoxy(x + 105, y + 19);
	cout << "Dap an 4:";
	Ve_HCN(30, 2, x + 115, y + 18);// dap an 2

	gotoxy(x + 85, y + 22);
	cout << "Nhap dap an: ";
	Ve_HCN(12, 1, x + 100, y + 21);
}
void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void Tron_Mang_Ngau_Nhien(int arr[],int n)
{
	srand(time(NULL));

	int minPosition;
	int maxPosition = n - 1;
	int swapPosition;

	int i = 0;
	while (i < n - 1)
	{
		minPosition = i + 1;
		swapPosition = rand() % (maxPosition - minPosition + 1) + minPosition;

		Swap(arr[i], arr[swapPosition]);
		i++;
	}
}
void khungChonMonHoc(int flag)
{
	gotoxy(47, 1);
	cout << "---CHON MON THI---";
	gotoxy(40, 3);
	cout << "Ma mon";
	gotoxy(57, 3);
	cout << "Ten mon hoc ";

	gotoxy(36, 2);
	cout << (char)201;
	gotoxy(80, 2);
	cout << (char)187;
	gotoxy(36, 16);
	cout << (char)200;
	gotoxy(80, 16);
	cout << (char)188;

	if (flag == -1)
	{
		gotoxy(55, 16);
		cout << "...<<";
	}
	if (flag == 1)
	{
		gotoxy(55, 16);
		cout << ">>...";
	}
	if (flag == 0)
	{
		gotoxy(51, 16);
		cout << "...<<..>>...";
	}


}
void clr_xy(int x, int y, int _x, int _y)
{
	string emp = "";
	for (int i = 0; i < _x - x; i++)
	{
		emp.insert(0, " ");
	}

	for (int i = 0; i <= _y - y; i++)
	{
		gotoxy(x, y + i);
		cout << emp;
	}
}
void khungCauHoiRong(int sl_cauhoiKT)
{
	int x = 26;
	int y = 18;

	gotoxy(0, y - 1);
	cout << "---------------------------------------------------------------------------------------------";

	gotoxy(x - 13, y);
	cout << "Answer sheet: ";

	for (int i = 0; i < sl_cauhoiKT; i++)
	{
		gotoxy(x, y);
		cout << i + 1;
		x += 4;

		if (i % 10 == 9)
		{
			x = 26;
			y++;
		}
	}
}
int getNumber(int x, int y)
{
	//	int max, int x, int y
	string num = "";
	hidecur(false);
	int key = 0;
	while (true)
	{
		do{
			key = getch();
		} while (!((key > 47 && key < 58) || key == 13 || key == 27 || key == 8));

		if (key == 13) break;
		if (key == 27) return -1;
		if (key == 8)
		{
			if (num.length() > 0)
			{
				num.erase(num.size() - 1);
			}
		}
		else
		{
			if (num.size() < 3)
			{
				num.push_back((char)key);
			}
		}

		gotoxy(x, y);
		cout << "    ";
		gotoxy(x, y);
		cout << num;
	}

	return toInt(num);
}
void khungquanlydiemthi1sv(int x, int y)
{
	//SetConsoleTextAttribute(console, 135);
	gotoxy(x, y);
	Ve_HCN(102, 35, x, y);
	gotoxy(x + 3, y + 2);
	cout << "Tim kiem: ";
	Ve_HCN(70, 1, x + 14, y + 1);//khung tim kiem
	Ve_HCN(50, 19, x + 1, y + 4);//khung danh sach lop
	Ke_line(50, x + 1, y + 6);
	Ve_HCN(50, 19, x + 51, y + 4);//khung danh sach sinh vien
	Ke_line(50, x + 51, y + 6);
	//Ve_HCN(50, 19, x + 101, y + 4);// khung danh sach cau hoi da thi
	//Ke_line(50, x + 101, y + 6);
	gotoxy(x + 18, y + 5);
	cout << "Danh sach sinh vien";
	gotoxy(x + 65, y + 5);
	cout << "Danh sach mon hoc";
	Ve_HCN(100, 9, x + 1, y + 25);//khung thong bao
	/*gotoxy(x + 111, y + 5);
	cout << "Danh sach cau hoi da thi";*/
	Ke_column(11, x + 48, y + 25);
	Ke_line(48, x + 1, y + 27);
	gotoxy(x + 20, y + 26);
	cout << "Thong bao";
	//gotoxy(x, y + 37);
	gotoxy(x + 65, y + 26);
	cout << "Phim tat kha dung";
}
void khungquanlydiemthi1lop(int x, int y)
{
	//SetConsoleTextAttribute(console, 135);
	gotoxy(x, y);
	Ve_HCN(102, 35, x, y);
	gotoxy(x + 3, y + 2);
	cout << "Tim kiem: ";
	Ve_HCN(70, 1, x + 14, y + 1);//khung tim kiem
	Ve_HCN(50, 19, x + 1, y + 4);//khung danh sach lop
	Ke_line(50, x + 1, y + 6);
	Ve_HCN(50, 19, x + 51, y + 4);//khung danh sach sinh vien
	Ke_line(50, x + 51, y + 6);
	//Ve_HCN(50, 19, x + 101, y + 4);// khung danh sach cau hoi da thi
	//Ke_line(50, x + 101, y + 6);
	gotoxy(x + 18, y + 5);
	cout << "Danh sach lop";
	gotoxy(x + 65, y + 5);
	cout << "Danh sach mon hoc";
	Ve_HCN(100, 9, x + 1, y + 25);//khung thong bao
	/*gotoxy(x + 111, y + 5);
	cout << "Danh sach cau hoi da thi";*/
	Ke_column(11, x + 48, y + 25);
	Ke_line(48, x + 1, y + 27);
	gotoxy(x + 20, y + 26);
	cout << "Thong bao";
	//gotoxy(x, y + 37);
	gotoxy(x + 65, y + 26);
	cout << "Phim tat kha dung";
}
void Khung_Tim_Lop_Hoc(int x, int y)
{
	gotoxy(x, y);
	Ve_HCN(85, 25, x-5, y);
	gotoxy(x + 3 -5, y + 2);
	cout << "Ten/Ma lop: ";
	Ve_HCN(55, 1, x + 13, y + 1);//khung tim kiem
	//Ve_HCN(35, 19, x + 14, y + 4);//khung danh sach lop
	//Ke_line(35, x + 14, y + 6);
}
void Giai_Phong_Danh_Sach_Sinh_Vien(danh_sach_sinh_vien &l)
{

	NODESINHVIEN *k = NULL;
	while (l.phead != NULL)
	{
			PTR_BaiKT p = l.phead->data.ds_bkt, temp;
			while(p != NULL)
			{
				temp = p;
				p = p->next;
				delete temp;
			}
			
		k = l.phead;
		l.phead = l.phead->pnext;
		delete k;
	}
}

void Giai_Phong_Tat_Ca_Danh_Sach_Sinh_Vien(DANH_SACH_LOP &dsl)
{
	for (int i = 0; i< dsl.sl;i++)
	{
		Giai_Phong_Danh_Sach_Sinh_Vien(dsl.ds[i]->dssv);
	}
}


