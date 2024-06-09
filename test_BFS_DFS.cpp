#include <stdio.h>
#include <stdlib.h>

int n, a[10][10], d[100], T[100], t=0; 

void DocFile()
{
	FILE *f=fopen("MTK.txt", "r");
	
	if(f==NULL)
	{
		printf("ERROR");
		exit(0);
	}
	
	else
	{
		fscanf(f, "%d", &n);
		
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				fscanf(f, "%d", &a[i][j]);
			}
		}
	}
	
	fclose(f);
}

void inMaTran()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			printf("%2d", a[i][j]);
		}
		printf("\n");
	}
}

void KhoiTaoArrD()
{
	for(int i=1; i<=n; i++)
	{
		d[i]=0;
	}
}

void TimBFS(int v) //duyet theo chieu rong
{
	T[t]=v;
	t++;
	d[v]=-1;
	while(t>0)
	{
		int k=T[0];
		printf("%2d", k);
		
		for(int i=0; i<t; i++)
		{
			T[i]=T[i+1];
		}
		t--;
		
		for(int i=1; i<=n; i++)
		{
			if(a[k][i]==1 && d[i]==0)
			{
				T[t]=i;
				t++;
				d[i]=-1;
			}
		}
	}
}

void TimDFS(int x)
{
	T[t]=x;
	t++;
	while(t>0)
	{
		int k=T[t-1];
		t--;
		if(d[k]==0)
		{
			printf("%2d", k);
			d[k]=-1;
		}
		for(int i=n; i>=1; i--)
		{
			if(a[i][k]==1 && d[i]==0)
			{
				T[t]=i;
				t++;
			}
		}
	}
}

int main()
{
	DocFile();
	inMaTran();
	KhoiTaoArrD();
	
	int v, x;
	printf("Nhap vao dinh can duyet BFS: ");
	scanf("%d", &v);
	
	printf("Ket qua duyet BFS(%d) la: ", v);
	TimBFS(v);
	
	printf("\n\nNhap vao dinh can duyet DFS: ");
	scanf("%d", &x);
	
	printf("Ket qua duyet DFS(%d) la: ", v);
	KhoiTaoArrD();
	TimDFS(x);
	
	return 0;
}

