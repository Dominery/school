#include<stdio.h>
int main()
{
	int m[10][10];
	
	for (int i=0;i<10;i++)
	{
		m[i][0]=1;//����ÿ�е�һ����Ϊ1 
		for(int j=1;j<=i;j++)
		{
			m[i][j]=m[i][j-1]*(i-j+1)/j;//����˳�Ʒ����i�е�j�е��� 
		}
	}

		for(int i=0;i<10;i++)
		{
			int j=0; 
			printf("%*.d",20-i*2,m[i][0]);//��ӡÿһ�е�һ�������ո�ÿ����һ�ж����� 
			for( j=1;j<=i;j++)
			{
			
				if(m[i][j]>0)
				{
					printf("%4.d",m[i][j]);
				}
			
			}
			if(j>i)
			{
				printf("\n");
			}
		}

 } 
 
