#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
{
	char name[30];
	int id , age , group;
}	members;
void Longmembers(int *n)
{
	printf("Nhap so luong thanh vien:");
	scanf("%d",&(*n));
}
void Input(members *m , int n)
{
	printf("Nhap danh sach cac thanh vien:\n");
	for(int i = 0 ; i < n ; i++)
	{
		fflush(stdin);
		printf("Thanh vien thu %d:\n",i + 1);
		printf("Nhap ten:");
		gets((m + i)->name);
		printf("Nhap ID:");
		scanf("%d",&(m + i)->id);
		printf("Nhap tuoi:");
		scanf("%d",&(m + i)->age);
		printf("Nhap nhom:");
		scanf("%d",&(m + i)->group);
	}
}
void Output(members *m , int n)
{
	for(int i = 0 ; i < n ; i++)
	{
		printf("%-4d %-4d %-4s %-4d\n",(m + i)->id , (m + i)->group , (m + i)->name , (m + i)->age);
	}
}
void Add(members *m , int *n)
{
	int k;
	members a;
	printf("Nhap vi tri can them vao:");
	scanf("%d",&k);
	printf("Nhap thong tin thanh vien can them:\n");
	fflush(stdin);
	printf("Ho va ten:");
	gets(a.name);
	printf("ID:");
	scanf("%d",&(a.id));
	printf("Tuoi:");
	scanf("%d",&(a.age));
	printf("Nhom:");
	scanf("%d",&(a.group));
	if((*n) >= k)
	{
		for(int i = (*n) ; i >=	k ; i--)
	{
		strcpy((m + i)->name , (m + (i - 1))->name);
		(m + i)->id = (m + (i - 1))->id;
		(m + i)->age = (m + (i - 1))->age;
		(m + i)->group = (m + (i - 1))->group;
	}
	strcpy((m + (k - 1))->name ,a.name);
	(m + (k - 1))->id = a.id;
	(m + (k - 1))->age = a.age;
	(m + (k - 1))->group = a.group;
	(*n)++;
	}
	if(k == ((*n) + 1))
	{
		(*n)++;
		strcpy((m + (k - 1))->name , a.name);
		(m + (k - 1))->id = a.id;
		(m + (k - 1))->age = a.age;
		(m + (k - 1))->group = a.group;
	}
}
void Delete(members *m , int *n)
{
	int k;
	printf("Nhap vi tri can xoa:");
	scanf("%d",&k);
	for(int i = k - 1 ; i < (*n) ; i++)
	{
		strcpy((m + i)->name , (m + (i + 1))->name);
		(m + i)->age = (m + (i + 1))->age;
		(m + i)->group = (m + (i + 1))->group;
		(m + i)->id = (m + (i + 1))->id;
	}
	(*n)--;
}
void Edit(members *m , int n)
{
	int a;
	printf("Nhap so ID cua thanh vien can sua:");
	scanf("%d",&a);
	for(int i = 0 ; i < n ; i++)
	{
		if((m + i)->id == a)
		{
			fflush(stdin);
			printf("Nhap ten can sua:");
			gets((m + i)->name);
			printf("Nhap group can sua:");
			scanf("%d",&((m + i)->group));
			printf("Nhap tuoi can sua:");
			scanf("%d",&((m + i)->age));
			printf("Nhap ID can sua:");
			scanf("%d",&((m + i)->id));
		}
		else
			continue;
	}
}
int main()
{
	members *tv[100];
	int n , lua_chon;
	Longmembers(&n);
	Input(*tv , n);
	Output(*tv , n);
	do
	{
		printf("Moi ban lua chon dich vu:\n");
		printf("1:Them thanh vien vao danh sach.\n");
		printf("2:Xoa thanh vien khoi danh sach.\n");
		printf("3:Sua thanh vien trong danh sach.\n");
		printf("4:Thoat.\n");
		printf("Ban chon:");
		scanf("%d",&lua_chon);
		switch(lua_chon)
		{
			case 1:
				{
					Add(*tv , &n);
					Output(*tv , n);
					break;
				}
			case 2:
				{
					Delete(*tv , &n);
					Output(*tv , n);
					break;
				}
			case 3:
				{
					Edit(*tv , n);
					Output(*tv , n);
					break;
				}
			case 4:
				{
					break;
				}
		}
	} while(lua_chon != 4);
	getch();
	return 0;
}
