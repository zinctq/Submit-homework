#include<stdio.h>
#include<conio.h>
#include<string.h>

struct ThongTin
{
	int ID;
	char hoten[20];
	int tuoi;
	int nhom;
};

void ThemThanhVien(struct ThongTin VIT)
{
	printf("\n Them thong tin cho thanh vien: ");
	printf("\n \t Ho ten: ");
	scanf("\t %s", &VIT.hoten);
	printf("\n \t Tuoi: ");
	scanf("\t %d", &VIT.tuoi);
	printf("\n \t Nhom: ");
	scanf("\t %d", &VIT.nhom);
	printf("\n \t ID: ");
	scanf("\t %d", &VIT.ID);
}

void SuaThongTin(struct ThongTin VIT)
{
	int a;
	printf("\n Can sua thong tin:");
	printf("\n \t 1. Ho ten.");
	printf("\n \t 2. Tuoi.");
	printf("\n \t 3. Nhom.");
	printf("\n \t 4. ID.");
	scanf("\n %d", &a);
	if(a=1)
	{
		printf("\n \t Ho ten: ");
		scanf("\t %s", &VIT.hoten);
	}
	else if(a=2)
	{
		printf("\n \t Tuoi: ");
		scanf("\t %d", &VIT.tuoi);
	}
	else if(a=3)
	{
		printf("\n \t Nhom: ");
		scanf("\t %d", &VIT.nhom);
	}
	else
	{
		printf("\n \t ID: ");
		scanf("\t %d", &VIT.ID);
	}
}

void XoaThanhVien(struct ThongTin VIT) 
{
	char tencanxoa[20];
	printf("\n Nhap ten thanh vien can xoa:");
	scanf("\n %s", &tencanxoa);
	if(tencanxoa==VIT.hoten)
	{
		for(int i=0;i<strlen(VIT.hoten);i++)
		{
			VIT.hoten[i]=NULL;
		}
		VIT.ID=NULL;
		VIT.nhom=NULL;
		VIT.tuoi=NULL;
	}
}

main()
{

	struct ThongTin VIT;
	int x;
	printf("\n 1. Them thanh vien.");
	printf("\n 2. Sua thong tin thanh vien.");
	printf("\n 3. Xoa thanh vien.");
	printf("\n Nhap cong viec: ");
	scanf("\n %d \n", &x);
	if(x=1)
	{
		ThemThanhVien(VIT);
	}
	if(x=2)
	{
		SuaThongTin(VIT);
	}
	if(x=3)
	{
		XoaThanhVien(VIT);
	}
	getch();
}
