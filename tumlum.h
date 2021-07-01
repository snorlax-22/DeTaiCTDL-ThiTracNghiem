#pragma once
#include"ctdl.h"
using namespace std;

int Kiem_Tra_Ma_Mon_Hoc_Tren_Cay(TREE_MH root, string mamh, int &dem1)
{
	if (root != NULL)
	{
		
		Kiem_Tra_Ma_Mon_Hoc_Tren_Cay(root->pLeft, mamh, dem1);
		if (root->monhoc.MAMH == mamh)
			dem1++;
		Kiem_Tra_Ma_Mon_Hoc_Tren_Cay(root->pRight, mamh, dem1);		
	}
	return dem1;
}
int Dem_Sl_Cau_Hoi_Co_MaMHH_Tren_Cay(TREE_MH root, string mamh, int &count)
{
	if (root != NULL)
	{
		Dem_Sl_Cau_Hoi_Co_MaMHH_Tren_Cay(root->pLeft, mamh,count);
		//do some thing
		if (root->monhoc.MAMH == mamh)
			count++;
		Dem_Sl_Cau_Hoi_Co_MaMHH_Tren_Cay(root->pRight, mamh,count);
	}
	return count;
}
void ChuanHoaChu(string &a){
	while(a[0]==' ')
		a.erase(a.begin()+0);
	while(a[a.length()]==' ')
		a.erase(a.begin()+a.length());
	for(int i=0;i<a.length();i++){
		if(a[i]==' '){
			if(a[i+1]==' '){
				a.erase(a.begin()+i+1);
				i--;
			}
		}
	}
	if (a[0] >= 97 && a[0] <= 132)
		a[0] -= 32;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ' ')
		{
			if (a[i + 1] >= 97 && a[i + 1] <= 132)
				a[i + 1] -= 32;
		}
		else
			if (a[i + 1] >= 65 && a[i + 1] <= 90)
			{
				a[i + 1] += 32;
			}
	}
}
void In_Hoa(string &a){
	for(int i=0;i<a.length();i++){
		if(a[i]>=97 && a[i]<=132 )
			a[i] -=32;
		if(a[i]== ' '){
			a.erase(a.begin()+i);
			i--;
		}
		
	}
}

void gotoxy(short x, short y){
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = {x,y};
	SetConsoleCursorPosition(h, c);
}

bool SetWindowSize(size_t width, size_t height)
{
	HANDLE output_handle = ::GetStdHandle(STD_OUTPUT_HANDLE);
	if (output_handle == INVALID_HANDLE_VALUE)
		return false;

	COORD coord = {};
	coord.X = static_cast<SHORT>(width);
	coord.Y = static_cast<SHORT>(height);
	if (::SetConsoleScreenBufferSize(output_handle, coord) == FALSE)
		return false;

	SMALL_RECT rect = {};
	rect.Bottom = coord.X - 1;
	rect.Right = coord.Y - 1;
	return (::SetConsoleWindowInfo(output_handle, TRUE, &rect) != FALSE);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
bool ahaveb(string a, string b)
{
	int pos[10];
	int count = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == b[0])
		{
			pos[count] = i;
			count++;
		}
	}
	for (int k = 0; k < count; k++)
	{
		for (int i = 0; i < b.length(); i++)
		{
			if (b[i] != a[pos[k]+i])
				break;			
			if (i == b.length()-1)
				return true;
		}
		
	}
	return false;
}

void SetColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
void SetBGColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	color <<= 4;
	wAttributes &= 0xff0f;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

void HighLight() {
	SetColor(15);
	SetBGColor(1);
}
void hidecur(bool flag)
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	if (!flag)
	{
		ConCurInf.bVisible = TRUE;
	}
	else
	{
		ConCurInf.bVisible = FALSE;
	}
	SetConsoleCursorInfo(hOut, &ConCurInf);
}

void XoaManHinh(int x,int y,int w,int h){
	
	hidecur(true);
	gotoxy(x, y);
	//SetConsoleTextAttribute(console, 135);
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
			cout << " ";
		gotoxy(x, y + i + 1);
	}
	hidecur(false);
}


int menu(string s[10], int n, int x, int y, int cmd)
{
	hidecur(true);
	int now = cmd;
	int prenow = -1;
	char key;
	for (int i = 0; i < n; i++)
	{
		gotoxy(x, y + i);
		if (i == now)
		{
			SetConsoleTextAttribute(console, 240);
			cout << s[i];			
			SetConsoleTextAttribute(console, 15);
		}
		else
		{
			cout << s[i];
		}
	}

	while (true)
	{
		for (int i = 0; i < n; i++)
		{
			gotoxy(x, y + i);
			if (i == now)
			{
				SetConsoleTextAttribute(console, 240);
				cout << s[i];	
				SetConsoleTextAttribute(console, 15);
			}
			if (i == prenow)
			{
				SetConsoleTextAttribute(console, 15);
				cout << s[i];			
			}
		}
		key = _getch();
		while (key == -32)
		{
			key = _getch();
		}
		if (key == 72)
		{
			if (now == 0)
			{
				prenow = now;
				now = n - 1;
			}
			else
			{
				prenow = now--;
			}
		}
		if (key == 80)
		{
			if (now == n - 1)
			{
				prenow = now;
				now = 0;
			}
			else
			{
				prenow = now++;
			}
		}
		if (key == 13)
		{		
			return now;
		}
		if (key == 27)
		{
			
			return 99;
		}
	}
}
int menuadvanced(string s[] , int x, int y,  int cmd,int max)
{
	int vt = 0;
start:
	XoaManHinh(x-10, y, 40, 16);
	hidecur(true);
	int n = 16;
	int now = cmd;
	int prenow = -1;
	char key;
	if (n + vt >= max )
		n = max - vt ;
	for (int i = 0 + vt; i < n + vt; i++)
		{
			gotoxy(x, y + i%16);
			if (i%16 == now)
			{

				SetConsoleTextAttribute(console, 240);
				cout << s[i];
				SetConsoleTextAttribute(console, 15);
			}
			else
			{
				cout << s[i];
			}
		}
	
	while (true)
	{		
			for (int i = 0 + vt; i < n + vt; i++)
			{
				gotoxy(x, y + i%16);
				if (i%16 == now)
				{

					SetConsoleTextAttribute(console, 240);
					cout << s[i];				
					SetConsoleTextAttribute(console, 15);
				}
				if (i%16 == prenow)
				{
					SetConsoleTextAttribute(console, 15);
					cout << s[i];					
				}
			}
		key = _getch();
		while (key == -32)
		{
			key = _getch();
		}
		if (key == 72)// phim len
		{
			if (now == 0)
			{
				prenow = now;
				now = n - 1;
			}
			else
			{
				prenow = now--;
			}
		}
		if (key == 80)// xuong
		{
			if (now == n - 1)
			{
				prenow = now;
				now = 0;
			}
			else
			{
				prenow = now++;
			}
		}
		if (key == 13)
		{		
				return now + vt;			
		}
		if (key == 27)
		{
			return 99;
		}
	
		// bo sung
		if (key == 77)//sang phai
		{
			if (vt < max - 16)
			{
				vt += 16;
				XoaManHinh(x-10,y, 40, 17);//xoa man hinh o danh sach lop
				goto start;
			}
			
		}
		if (key == 75)//sang trai
		{
			if (vt>= 16)
			{
				vt -= 16;			
				XoaManHinh(x-10, y, 40, 17);
				goto start;
			}
		}	
		
	}
}
void HD()
{
    char l = 179;

    for (int i = 0; i <= 91; i++)
    {
        gotoxy(i, 34);
        cout << "_";
    }
    gotoxy(1, 35);
    cout << "+LUU Y:";
    gotoxy(50, 35);
    cout << "+Nhap phim ESC de thoat/tro ve.";

    gotoxy(50, 36);
    cout << "+ UP/DOWN ( mui ten)  di chuyen len xuong ";
     gotoxy(50, 38);
     cout<<"+ Khi nhap xong user thi nhan ENTER de xuong nhap tiep pass .";
	 gotoxy(50, 39);
	 cout<<"Sau do nhan DOWN(mui ten) de chuyen xuong LOGIN/QUIT";
}
void AnDauNhay()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

//hien thi dau nhay len
void HienThiDauNhay()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void kiemtraphim()
{
	char key_press;
	int ascii_value;
//	cout << "\n\t\tNhap phim bat ky de kiem tra ma ASCII\n\t\t\An ESC de thoat\n\n\n";
	while (1)
	{
		key_press = _getch();
		ascii_value = key_press;
		if (ascii_value == 27) // For ESC
			break;
		cout << "Ban nhap phim-> \" " << key_press << " \" Gia tri ASCII =  " << ascii_value << "\n";
	}
	
}
string Lay_ma_lop_tu_ma_sinh_vien(string a)
{
	a.erase(a.size() - 1);
	a.erase(a.size() - 1);
	a.erase(a.size() - 1);
	a.erase(a.size() - 1);
	a.erase(a.size() - 1);
	return a;
}

void Insert_string(string &a, int pos, char x)
{

	a.push_back(a[a.length()]);
	for (int i = a.length(); i > pos; i--)
	{
		a[i] = a[i - 1];
	}
	a[pos] = x;

}
void Delete_pos(string &s, int pos)
{

int n = s.length();
	if (n != 0)
	{
		for (int i = pos - 1; i < n - 1; i++)
		{
			s[i] = s[i + 1];
			
		}
		s.erase(s.size() - 1);
	}
}
string Nhap_thong_tin(int x, int y, bool &exit, int limited)
{
	string infor;
	int pos = infor.length();
	//string hidepass;
	/*XoaManHinh(x + 15, y + 4, 30, 1);
	XoaManHinh(x + 15, y + 7, 30, 1);*/
	gotoxy(x + 15, y + 4);
	if (infor.length() != 0);
	cout << infor;
	while (true)
	{
		gotoxy(x + 15 + pos, y + 4);
		char k = _getch();
		while (k == -32)
		{
			k = _getch();
		}

		if (k == 8)//phim backspace
		{
			if (infor.length() >= 1)
			{
			//	XoaManHinh(x + 14 + infor.length(), y + 4, 1, 1);
				Delete_pos(infor, pos);
				pos--;
				gotoxy(x + 15, y + 4);
				if (infor.length() != 0)
				{
					cout << infor;
				}
			}
		}
		if ((k >= 32 && k <= 64 || k >= 91 && k <= 126 || k == 95) && infor.length()<=limited)//hang phim so
		{
			Insert_string(infor, pos, k);
			pos++;
			gotoxy(x + 15, y + 4);
			cout << infor;
		}
		
		if (k == 27)
		{
			exit = true;
			return "a";
		}

		if (k == 13)
		{
			if (infor.length() >= 1)
				break;
		}
		if (k == 77)//phim sang phai
		{
			if (pos < infor.length())
			{
				pos++;
				gotoxy(x + 15 + pos, y + 4);
			}
		}
		if (k == 75)//phim sang trai
		{
			if (pos>0)
			{
				pos--;
				gotoxy(x + 15 + pos, y + 4);
			}
		}

	}
	return infor;
}
string Nhap_Dap_An(int x, int y)
{
	string temp[2];
	int count = 0;
	string final;
	int line = 2;
enter:
	string qus;
	int pos = qus.length();
	gotoxy(x + 68, y + 3 + line);
	if (qus.length() != 0);
	cout << qus;
	while (true)
	{
	//	hidecur(false);
	char k ;
			while (true)
			{
				k = _getch();
				if (k == -32)
				{
					k = _getch();
					if (k == 72 || k == 75 || k == 80 || k == 77)
					{
						continue;
					}										
				}
				else								
					break;
			}
		//	hidecur(true);
		if (k == 8)//phim backspace
		{
			if (qus.length() > 0)
			{

				//XoaManHinh(x + 67 + qus.length(), y + 3 + line, 1, 1);
				Delete_pos(qus, pos);
				pos--;
				gotoxy(x + 68, y + 3 + line);
				if (qus.length() != 0)
				{
					cout << qus;
				}
			}
			else
			{
				if (count >= 1)
				{
					line--;
					qus = temp[count - 1];
					count--;
					gotoxy(x + 68, y + 3 + line);			
					pos = qus.length();
					cout << qus;					
				}
			}
		}
		if ((k >= 32 && k <= 43 || k >= 91 && k <= 126 || k == 95 || k >= 45 && k <= 90) && count <= 1)// insert k
		{
			if (qus.length() > 25 )
			{
				if (count < 1)
				{
					temp[count] = qus;
					if (count <= 1)
					{
						line++;
						count++;
						goto enter;
					}
				}
				
			}
			else
			{
				Insert_string(qus, pos, k);
				pos++;
				gotoxy(x + 68, y + 3 + line);
				cout << qus;
			}			
		}	
		if (k == 13)
		{
			for (int i = 0; i <= count; i++)
			{				
				final.append(temp[i]);			
			}
			final.append(qus);
			if (final.length() >= 1)
			{
				//canexit = true;
				return final;
			}
		}
	}
}
string getlastname(string a)
{
	string result;
	int i = a.length();
	while (i >=0 )
	{
		if (a[i] == ' ')
		{
		//	result.pop_back();
			result.erase(result.size()-1);
			return result;
		}
		else
		{
			Insert_string(result, 0, a[i]);
			if (i>=0)
				i--;
		}
	}
	//result.pop_back();
	result.erase(result.size()-1);
	return result;
}
int toInt(string s)
{
	int res = 0;
	for (int i = 0; i < s.length(); i++)
	{
		res = res * 10 + s[i] - 48;
	}
	return res;
}
int so_sanh_string(string s1, string s2)
{
	int a = s1.length();
	int b = s2.length();
	int max;
	if (a > b)
		max = a;
	else
		max = b;
	for (int i = 0; i < max; i++)
	{
		if (s1[i] > s2[i])
		{
			return 1;
			break;
			//Chuoi dau lon hon
		}
		if (s1[i]<s2[i])
		{
			return 2;
			break;
			//Chuoi sau lon hon
		}
		if (s1[i] == s2[i] && i == max - 1)
			return 0;
		//hai chuoi bang nhau
	}
}
int so_sanh_ho_ten(string t1, string t2, string h1, string h2)
{
	if (so_sanh_string(getlastname(t1), getlastname(t2)) == 0)
	{
		if (so_sanh_string(h1, h2) == 1)
			return 1;
		else if (so_sanh_string(h1, h2) == 2)
			return 2;
		else if (so_sanh_string(h1, h2) == 0)
			return 0;
	}
	else if (so_sanh_string(getlastname(t1), getlastname(t2)) == 1)
		return 1;
	else if (so_sanh_string(getlastname(t1), getlastname(t2)) == 2)
		return 2;
}
void Swap_lop(LOP* &a, LOP* &b)
{
	LOP* temp;
	temp = a;
	a = b;
	b = temp;
}
void Swap_sv(SINHVIEN &a, SINHVIEN &b)
{
	SINHVIEN temp;
	temp = a;
	a = b;
	b = temp;
}
void Sap_xep_ho_ten_tang_dan(DANH_SACH_SINH_VIEN& dssv)
{
	for (NODESINHVIEN* k = dssv.phead; k != NULL; k = k->pnext)
	{
		for (NODESINHVIEN* i = dssv.phead; i != NULL; i = i->pnext)
		{
			if (so_sanh_ho_ten(k->data.TEN, i->data.TEN, k->data.HO, i->data.HO) == 2)
				Swap_sv(k->data, i->data);
		}
	}
}
string rut_gon_text(string a, int sl)
{

	string rs;
	if (sl >= a.length())
		return a;
	else
	{
		for (int i = 0; i < sl; i++)
		{
			Insert_string(rs, rs.length(), a[i]);
		}
		rs.append("...");
		return rs;
	}
}


