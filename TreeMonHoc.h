#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <windows.h>
#include <fstream>
#include <ctype.h>
#include "tumlum.h"

using namespace std;
 #define LH -1
#define EH 0
#define RH 1 

int strcmp1(string a, string b)
{
    int n = 0;
    do
    {
        if (a[n] > b[n])
            return 1;
        else if (a[n] < b[n])
            return -1;
        n++;
    } while (a[n] != '\0' || b[n] != '\0');

    return 0;
}

int SoSanhChuoi(MONHOC x, MONHOC y)// So sanh hai chuoi x va y
{
    return strcmp1(x.MAMH, y.MAMH);

}
int taoId()
{
	
	int a[100001];
	fstream file;
	file.open("ds_id_ngaunhien.config", ios::in );
	
	for(int i=0 ; i <=100000; i++)
	{
		file >> a[i];
		file.ignore();
	}
	file.close();
	
	file.open("ds_id_ngaunhien.config", ios::out | ios::trunc);
	
	for(int i=1 ; i <=100000; i++)
	{
		file << a[i];
		file << ";";

	}
	file.close();
	return a[0];
}

bool kiemTraDaThiMonHoc(PTR_BaiKT p ,string MAMH)
{
	while(p != NULL)
	{
		if(p->bkt.MAMH == MAMH) return true;
		p = p->next;
	}
	
	return false;
}

// HAM LIEN CON CAY NHI PHAN

void CreateTree_MH(TREE_MH &root)
{
      root = NULL;
} 

TREE_MH t = NULL;
void InsertNode(TREE_MH &root,MONHOC mon){

    if (root == NULL)
    {
        NODEMH* q = new NODEMH();
        q->monhoc = mon;
        q->pLeft = q->pRight = NULL;
        root = q;
    }
    else
    {
        if (SoSanhChuoi(root->monhoc, mon) > 0)
        {
            InsertNode(root->pLeft, mon);
        }
        else if (SoSanhChuoi(root->monhoc, mon) < 0)
        {
            InsertNode(root->pRight, mon);
        }
    }
}
TREE_MH TimKiemMonHoc(TREE_MH t, string maMH){
	char s[15];
    strcpy(s, maMH.c_str());
    TREE_MH  p;
    p = t;
    while (p != NULL && strcmp1(s, p->monhoc.MAMH) != 0)
        if (s < p->monhoc.MAMH)
            p = p->pLeft;
        else
            p = p->pRight;
    return p;
}
int TinhsoNode(TREE_MH t)
{
    int dem = 0;
    TREE_MH p;
    while (t)
    {
        if (t->pLeft == NULL) {
            dem++;
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
                dem++;
                t = t->pRight;
            }
        }
    }
    return dem;
}
void DuyetCay(TREE_MH t, MONHOC A[], int& dem)
{
    if (t != NULL)
    {
        DuyetCay(t->pLeft, A, dem);
        A[dem] = t->monhoc;

        dem++;
        DuyetCay(t->pRight, A, dem);
    }
}
void SapXepTheoTenMH(MONHOC A[])
{
    int i, j;
    int n = TinhsoNode(t);
    MONHOC t;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (strcmp1(A[j - 1].TENMH, A[j].TENMH) > 0)
            {
                t = A[j - 1];
                A[j - 1] = A[j];
                A[j] = t;
            }
        }
    }
}
void NodeTheMang(TREE_MH &x, TREE_MH&y){
	//TÌM NODE TRÁI NHAT CUA CÂY CON PHAI
	if(y->pLeft !=NULL){
		NodeTheMang(x,y->pLeft);
	}
	else {
		x->monhoc=y->monhoc;
		x=y;
		y=y->pRight;
	}
	
}
void XoaNode(TREE_MH &root, MONHOC mon){
	if(root==NULL){
		return;
	}
	else{
		 if (SoSanhChuoi(root->monhoc, mon) > 0)
        {
            XoaNode(root->pLeft, mon);
        }
        else if (SoSanhChuoi(root->monhoc, mon) < 0)
        {
            XoaNode(root->pRight, mon);
        }
        else {
        	NODEMH * T=root;
        	if(root->pLeft==NULL){
        		root=root->pRight;
			}
			else if(root->pRight==NULL){
				root=root->pLeft;
			}
			else{
				NodeTheMang(T,root->pRight);
			}
			delete T;
		}
		
	}
}
void DelTree(TREE_MH &root)
{
	if(root != NULL)
	{
		DelTree(root->pLeft);
		DelTree(root->pRight);
		delete root;	
	}
	root = NULL;
}
 
