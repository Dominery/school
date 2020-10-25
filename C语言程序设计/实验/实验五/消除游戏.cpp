#include<stdio.h>
#define n 4
#define m 5
int main()
{
	int num[n][m];
	int copy[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&num[i][j]);
			copy[i][j]=num[i][j];
		}
		
			printf("\n");
			
	}
	for(int i=0;i<n;i++)
	{
		int resu[m-1];
		for(int j=0;j<m-1;j++)
		{
			resu[j]=num[i][j]-num[i][j+1];
		}
		for(int j=0;j<m-2;j++)
		{
			if(resu[j]==0&&resu[j+1]==0)
			{
				num[i][j]=0;
				num[i][j+1]=0;
				num[i][j+2]=0;
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		int resu[n-1];
		for(int j=0;j<n-1;j++)
		{
			resu[j]=copy[j][i]-copy[j+1][i];
		}
		for(int j=0;j<n-2;j++)
		{
			if(resu[j]==0&&resu[j+1]==0)
			{
				copy[j][i]=0;
				copy[j+1][i]=0;
				copy[j+2][i]=0;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(copy[i][j]==num[i][j])
			printf("%d",num[i][j]);
			else
			printf("0");
		}
		
			printf("\n");
			
	}
}
