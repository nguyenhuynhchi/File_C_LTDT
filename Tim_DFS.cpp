#include <stdio.h>
#include <stdlib.h>

int a[10][10],n;
int d[100], S[100], t=0;

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
		 for(int j=1; j<=n; j++)
	    	fscanf(f,"%d",&a[i][j]);
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

void Tim_DFS(int x) //duyet theo chieu sau
{
	S[t]=x;
	t++;
	while(t>0)
	{
		int k=S[t-1];
		t--;
		if(d[k]==0)
		{
			printf("%2d", k);
			d[k]=-1;
		}
		for(int i=n; i>=1; i--)
		{
			if(a[i][k]==1&&d[i]==0)
			{
				S[t]=i;
				t++;
			}
		}
	}
}

int main()
{	
	docfile();
	infile();
	TaoMang_d();
	
	int x;
	printf("\nNhap dinh can duyet x: ");
	scanf("%d", &x);
	printf("Ket qua duyet DFS(%d) la: ", x);
	Tim_DFS(x);
	
	return 0;
}
