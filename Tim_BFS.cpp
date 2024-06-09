#include <stdio.h>
#include <stdlib.h>

int a[10][10],n;
int d[100], T[100], t=0;

void docfile()
{
	FILE *f;
	f=fopen("MTK.txt","r");
	if(f==NULL)
	{
		printf("khong tim thay");
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

void infile()
{
	printf("ma tran ke:\n");
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
	    	printf("%2d",a[i][j]);
	    	printf("\n");
	}
}

//tao mang 1 chieu khoi tao tac ca gia tri bang 0
void TaoMang_d()
{
	for(int i=1; i<=n; i++)
	{
		d[i]=0;
	}
}

void Tim_BFS(int v) //duyet theo chieu rong
{
	T[t]=v;
	t++;
	d[v]=-1;
	while(t>0)
	{
		int x=T[0];
		printf("%2d", x);
		
		for(int i=0; i<t; i++)
		{
			T[i]=T[i+1];
		}
		t--;
		
		for(int i=1; i<=n; i++)
		{
			if(a[x][i]==1&&d[i]==0)
			{
				T[t]=i;
				t++;
				d[i]=-1;
			}
		}
	}
}
	
int main()
{	
	docfile();
	infile();
	TaoMang_d();
	
	int v;
	printf("\nNhap dinh can duyet v: ");
	scanf("%d", &v);
	printf("Ket qua duyet BFS(%d) la: ", v);
	Tim_BFS(v);
	
	return 0;
}
