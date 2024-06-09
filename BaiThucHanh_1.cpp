#include<stdio.h>
#include<stdlib.h>

int a[10][10],n;

void ghiFile() {
	FILE *f;
	f = fopen("MTK.txt", "w");
	if (f == NULL) {
		printf("Khong the mo file");
		exit(0);
	}
	else {
		printf("\nNhap so dinh (kich thuoc cua ma tran): ");
		scanf("%d", &n);
		fprintf(f, "%d\n", n);
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++) 
			{
				printf("ViTri a[%d][%d]: ", i, j);
				scanf("%d", &a[i][j]);
				fprintf(f, "%2d ", a[i][j]);
			}
			fprintf(f, "\n");
		}
	}
	fclose(f);
}

void docfile(){
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

void infile(){
	printf("ma tran ke:\n");
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
	    	printf("%2d",a[i][j]);
	    	printf("\n");
	}
}

int KTDoiXung()
{
	int dem=0;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i][j]==a[j][i])
			{
				dem++;
			}
		}
	 
	}
	return dem;
}

int KTDuongCheo()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(i==j)
			{
				if(a[i][j]!=0)
				{
					return 1;
				}
			}
		}
	}
	return 0;
}

int KTDonDT()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(a[i][j]>1)
			{
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	
	docfile();
	infile();
	
	if(KTDoiXung()==n*n)
	{
		if(KTDuongCheo()==0)
		{
			if(KTDonDT()==1)
			{
				printf("\nDo thi tuong ung la DON do thi VO HUONG");
			}
			else
			{
				printf("\nDo thi tuong ung la DA do thi VO HUONG");
			}	
		}
		
		else
		{
			printf("\nDo thi tuong ung la GIA do thi");
		}
	
	}
	
	else
	{
		if(KTDonDT()==1)
		{
			printf("Do thi tuong ung la DON do thi CO HUONG");
		}
		
		else
		{
			printf("Do thi tuong ung la DA do thi CO HUONG");
		}
	}

}











