#include<stdio.h>
#include<stdlib.h>

int a[10][10],n;

void docfile()
{
	FILE *f;
	f=fopen("MTK.txt","r");
	if(f==NULL)
	{
		printf("khong tim thay file ");
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

void TinhBac()
{
	int x, demBac=0;
	printf("\nNhap so dinh can tinh bac: ");
	scanf("%d", &x);
	
	if(KTDoiXung()==n*n)
	{
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
		    	{
		    		if(i==x)
		    		{
		    			if(i==j)
			    		{
			    			demBac+=a[i][j]*2;
			    		}
			    		else
			    		{
			    			demBac+=a[i][j];
			    		}
			    	}
		    	}
		}
		printf("\n-->Bac cua dinh %d la: %d", x, demBac);
	}
	else
	{
		int demBV=0, demBR=0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
		    	{
		    		if(i==j&&i==x)
		    		{
		    			demBV+=a[i][j];
					demBR+=a[i][j];
				}
		    		else
		    		{
		    			if(i==x)
			    		{
			    			demBR+=a[i][j];
				    	}
				    	else if(j==x)
				    	{
				    		demBV+=a[i][j];
				    	}
		    		}
					
		    	}
		}
		printf("\n-->Bac VAO cua dinh %d la: %d", x, demBV);
		printf("\n-->Bac RA cua dinh %d la: %d", x, demBR);
	}
}

int main()
{
	docfile();
	infile();
	TinhBac();
	return 0;	
}
