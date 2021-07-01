#pragma once
#include"xulylophoc.h"
#include"xulymonhoc.h"
//#include"xulybaithi.h"
#include"tumlum.h"
#include"giaodien.h"

void DangNhap(DANH_SACH_LOP &dsl);
void UserGV(DANH_SACH_LOP &dsl);
TREE_MH root;
void DangNhap(DANH_SACH_LOP &dsl){

	bool exist = false;
	int x=70;
	int y=17;
	khungDN(x,y);
reenter:
	string user; 
enteruser:
	string pass;
	HD(); 
	int pos=user.length();
	XoaManHinh(x + 15, y + 4, 30, 1);
	XoaManHinh(x + 15, y + 7, 30, 1);
	
	gotoxy(x + 15, y + 4);
	hidecur(false);
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
			if (user.length() >= 1 && pos > 0)
			{
				XoaManHinh(x + 14 + user.length(), y + 4, 1, 1);
			
				Delete_pos(user,pos);
				pos--;
				gotoxy(x + 15 , y + 4);
				if (user.length() != 0)
				{
					cout << user;
				}
			}
		}
		if ((k >= 48 && k <= 57 || k == 95) && user.length() <= 30)//hang phim so
		{
			Insert_string(user, pos, k);
			pos++;
			gotoxy(x + 15 , y + 4);
			cout << user;
		}
		if (k >= 97 && k <= 122 && user.length() <= 30)//phim ki tu va space
		{
			Insert_string(user, pos, k);
			pos++;
			gotoxy(x + 15 , y + 4);
			cout << user;
		}
		if (k == 27 )
			return;
		if (k == 13)
		{	
			gotoxy(3 + x, 7 + y);
			if (user == "gv" || user.length()>=5)
			break;
		}
		if (k == 77)//phim sang phai
		{
			if (pos < user.length())
			{
				pos++;
				gotoxy(x + 15  + pos, y + 4);
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
	gotoxy(x + 15, y + 7);
	while (true)
	{
		char k = _getch();
		gotoxy(x + 15 + pass.length(), y + 7);
		if (k == 8)//phim backspace
		{
			if (pass.length() >= 1 )
			{
				XoaManHinh(x + 14 + pass.length(), y + 7, 1, 1);
				pass.erase(pass.size()-1);
				//hidepass.pop_back();
				gotoxy(x + 14 + pass.length(), y + 7);
			}
		}
		if (k >= 48 && k <= 57 && pass.length()<=20)//hang phim so
		{
			pass.push_back(k);
			//hidepass.push_back('*');
			gotoxy(x + 14 + pass.length(), y + 7);
			cout << '*';
		}
		if (k >= 97 && k <= 122 && pass.length()<=20)//phim ki tu va space
		{
			pass.push_back(k);
			gotoxy(x + 14 + pass.length(), y + 7);
			//hidepass.push_back('*');
			cout << '*';
		}
		if (k == 27 && pass.length() != 0)
			return;
		
		if (k == 72)// phim len
		{
			XoaManHinh(x + 14, y + 7, 30, 1);
			goto enteruser;
		}
		
		if(k==80)//phim xuong
		{
			string s[] = {
			"         LOGIN         ",
			"         QUIT          ",
			};
		int cmd = 0;
		hidecur(true);
			//system("cls");
			cmd = menu(s, 2, x + 21, y + 13,  0);
			switch (cmd)
			{
			case 0:
				//formquanlylophoc(dsl);
				In_Hoa(user);//chuan hoa ma lop
				In_Hoa(pass);
				if (user == "GV")
				{
					if (pass == "GV")
					{
						system("cls");
						UserGV(dsl);
					}
					else
					{
						gotoxy(x + 25, y + 10);
						SetColor(4);
						cout << "Sai mat khau!";
						goto reenter;
						SetColor(15);
					}
				}
				else
				{
					for (int i = 0; i < dsl.sl; i++)
					{
						if (Lay_ma_lop_tu_ma_sinh_vien(user) == dsl.ds[i]->maLop)
						{
							for (NODESINHVIEN* k = dsl.ds[i]->dssv.phead; k != NULL; k = k->pnext)
							{
								if (k->data.MASV == user)
								{
									exist = true;
									reenterpw:
									if (k->data.password == pass)
									{
										system("cls");
										//thiTracNghiem(k->data.MASV);
										break;
									}
								else
									{
										gotoxy(x+15, y + 12);							
										goto reenter;
									}						
	
								}
							}
						}
					}

				}
		
				if (exist == false)
				{
					gotoxy(x+20, y + 10);
					cout << "User khong ton tai!";
					goto reenter;			
				}
				
				
					break;
					case 1:
					//cout << "=============DANH SACH CAC LOP============" << endl;
						exit(0);
					break;
				}
			}
		}

	}
	


void UserGV(DANH_SACH_LOP &dsl)
{
	
	//SetConsoleTextAttribute(console, 135);
	while (true)
	{
		int x = 0;
		int y = 0;
		//cout << "XIN CHAO ADMIN";
		string s[] = {
			"           Quan ly lop hoc            ",
			"           Quan ly mon hoc            ",
			"           Quan ly bai kiem tra       ",
			"           Luu du lieu                ",
			"           Dang xuat                  ",
			"           Thoat                      ",
		};
		int cmd = 0, flag;
		//bool check;
		while (true)
		{
			Ve_HCN(40, 8, x, y);
			Ke_line(40, x, y + 2);
			gotoxy(x + 9, y + 1);
			cout << "USER MODE: Administrator";
			hidecur(true);
			//system("cls");
			cmd = menu(s, 6, x + 1, y + 3,  0);
			switch (cmd)
			{
			case 0:
				//formquanlylophoc(dsl);
				Plus_Form_quan_ly_lop_hoc(x, y,dsl);
				break;
			case 1:
				//cout << "=============DANH SACH CAC LOP============" << endl;
			//	Plus_Form_quan_ly_mon_hoc(x, y,root);
				break;

			case 2:
				
				//Plus_Quan_Ly_Bai_Kiem_Tra(dsl, x+41, y+6);
				
				break;

			case 3:
				gotoxy(0, 11);
				//Ghi_file_danh_sach_lop(dsl);
				//Ghi_file_dssv(dsl);
			//	luuMonHoc(ds_monhoc, sl_monhoc);
				cout << "Luu du lieu thanh cong! ";
				Sleep(500);
				XoaManHinh(0, 11, 100, 30);
				break;
			case 4:
				system("cls");
				hidecur(false);
				DangNhap(dsl);

			case 5:
				exit(0);
			}

		}
	}
}



