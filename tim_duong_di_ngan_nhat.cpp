#include<stdlib.h>
#include<stdio.h>
#define vocung 1000
#define size 50

int a[size][size], L[size], d[size], truoc[size], n, u, y;
void DocFile();
void DDNN();
void KhoiTao (int u);
int ViTriDinhMin();
void CapNhatKe(int p);
void TimDuong(int s, int f);

void DocFile()
{
	FILE *f;
	f=fopen("MTK.txt","rt");
	if(f==NULL)
	{
		printf("khong tim thay file ");
		exit(0);
	}
	else{
		fscanf(f,"%d",&n);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
	    			fscanf(f,"%d",&a[i][j]);
			}
		}	 
	}
	fclose(f);
}

void InFile()
{
	printf("ma tran ke:\n");
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
	    	printf("%2d",a[i][j]);
	    	printf("\n");
	}
}

void DDNN()
{
	printf ("\nNhap dinh xuat phat: ");
	scanf ("%d", &u);
	KhoiTao(u);
	int s;
	printf("\n*******************************************************************************\n");
	printf("\t");
	for(int i=1;i<=n;i++)
	{
		printf("\tDinh %d",i);
	}
	printf("\n");
	for (int i=1;i<n;i++)
	{
		printf("Lan lap %d:\t",i);
		s = ViTriDinhMin();
		d[s]=1;
		CapNhatKe(s) ;
		for (int i=1;i<=n;i++)
		{
			printf("%d\t", L[i]);
		} 
		printf ("\n");
	}
	printf("*******************************************************************************\n");
	printf ("\nNhap dinh ket thuc: ");
	scanf ("%d",&y);
	printf ("\nDuong di ngan nhat tu dinh %d den %d la:%d\n",u,y,L[y]);
	printf("Cac dinh di qua:");
	TimDuong (u,y);
}

void KhoiTao(int u)
{
	for(int i=1; i<=n; i++)
	{
		L[i]=vocung;
		d[i]=0;
		truoc[i]=0;
	}
	L[u]=0;
}

int ViTriDinhMin()
{
	int min=vocung, u=0;
	for(int i=1;i<=n;i++){
		if(min>L[i]&&d[i]==0)
		{
			min=L[i];
			u=i;
		}
	}
	return u;
}

void CapNhatKe(int p)
{
	for(int i=1; i<=n; i++)
	{
		if(a[p][i]!=0 && d[i]==0)
		{
			if(L[i] > L[p]+a[p][i])
			{
				L[i]=L[p]+a[p][i];
				truoc[i]=p;
			}
		}
	}
}

void TimDuong(int s,int f)
{
	int y=f, b[size], i=1;
	while(y!=s)
	{
		b[i]=y;
		y=truoc[y];
		i++;
	}
	b[i]=s;

	for(; i>1; i--){
		printf(" %d -->", b[i]);
	}
	printf("%d", b[i]);	
}
	
int main()
{
	DocFile();
	InFile();
	DDNN();
}	
	
	
