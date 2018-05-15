#include<stdio.h>
#include<conio.h>
struct thanh_vien
{
	int ID;
	char ho_ten[34];
	int tuoi;
	int group;
	
};
void Nhap (thanh_vien *tv)
{
	printf("\n Nhap ID: ");
	scanf("%d",&tv->ID);
	printf("\n Nhap ho va ten sinh vien:  ");
	fflush(stdin);
	gets(tv->ho_ten);
	printf("\n Nhap tuoi: ");
	scanf("%d",&tv->tuoi);
	printf("\n Nhap group: ");
	scanf("%d",&tv->group);
	
}
void In(thanh_vien *tv)
{
	printf("\n Ten thanh vien:\t %s",tv->ho_ten);
	printf("\n ID: \t %d",tv->ID);
	printf("\n Tuoi: \t %d",tv->tuoi);
	printf("\n Group: \t %d",tv->group);
}
void Them (thanh_vien *tv,int them,int *sl)
{
	int i;
	for (i=*sl;i< (*sl+them);i++)
		Nhap (&tv[i]);
	*sl=*sl+them;
}
int Tim (thanh_vien *tv, int ma)
{
	int dem=0;
	while(tv->ID != ma)
	{
		tv=tv+1;
		dem++;
	}
	return dem;
}
void Xoa(thanh_vien *tv,int x,int *sl)
{
	int i;
	for (i=x;i<(*sl-1);i++)
	{
		tv[i]=tv[i+1];
	}
	*sl=*sl-1;
}
void Sua(thanh_vien *tv,int x)
{
	tv=tv+x;
	Nhap(&tv[x]);

}
main()
{
    thanh_vien sv[100];
	int i,j,sl,ma,k,them,f,x,m;
	char tl;
	printf(" Nhap so luong thanh vien: \t ");
	scanf("%d",&sl);
	for(i=0;i<sl;i++)
	{
		Nhap (&sv[i]);
	};
	for (j=0;j<sl;j++)
	{
		In(&sv[j]);
	};
	while ((tl!='k')&&(tl!='K'))
	{
	printf("\n Ban can thao tac gi?? \n 1. Them \n 2. Tim \n 3. Xoa \n 4. Sua \n ");
	scanf("%d",&m);
	switch (m)
	{
		case 1: {	printf("\n Nhap so thanh vien can them:\t ");
					scanf("%d",&them);
					Them(&sv[0],them,&sl);
					for(k=0;k<sl;k++)
					{
						In (&sv[k]);
		
					}
				}break;
		case 2: {	printf("\n Nhap ma ID can tim:\t ");
					scanf("%d",&ma);
					f= Tim(&sv[0],ma);
					In(&sv[f]);
				} break;
		case 3: {
					printf("\n Nhap ID nguoi can xoa:\t  ");
					scanf ("%d",&ma);
					fflush(stdin);
					x=Tim(&sv[0],ma);
					Xoa(&sv[0],x,&sl);
					for(k=0;k<sl;k++)
					{
						In (&sv[k]);
	
					};
	        	}break;
	    case 4: {
	    				printf ("\n Nhap ID nguoi can sua:\t ");
						scanf("%d",&ma);
						x=Tim(&sv[0],ma);
						Sua(&sv[0],x);
						for(k=0;k<sl;k++)
						{
							In (&sv[k]);
						};
				}break;
	}
	printf ("\n Ban co muon tiep tuc khong?(C/K) \t");
	fflush(stdin);
	scanf("%s",&tl);
	}
	
	printf("\n Cam on ban da tuong tac voi chung toi !!! ");
}


	


	


