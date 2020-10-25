#include<stdio.h>
int main()
{

	int seat[20][5]={0};
	char m[5]={'A','B','C','D','F'};
	int num[10]={0};
	int sum;
	scanf("%d",&sum);
	for(int i=0;i<sum;i++)
	{
		scanf("%d",&num[i]); 
	}
	for(int i=0;i<sum;i++)
	{
	
		for(int j=0;j<20;j++)
		{
			int l=0;
			for(int k=0;k<5;k++)
			{
				if(seat[j][k]==0)
				{
					l++;
				}
			}
			if(l<num[i])
			{
				continue;
			}
			else
			{
				l=0;
				for(int k=0;k<5&&l<num[i];k++)
				{
					if(seat[j][k]==0)
					{
						seat[j][k]=1;
						printf("%d%c ",j+1,m[k]);
						l++;
					}
					
				}
				printf("\n");
			}
			break;
		}
	}
}
