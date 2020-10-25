#include<stdio.h>
int main()
{
	int m[10][10];
	
	for (int i=0;i<10;i++)
	{
		m[i][0]=1;//设置每行第一个数为1 
		for(int j=1;j<=i;j++)
		{
			m[i][j]=m[i][j-1]*(i-j+1)/j;//利用顺推法求第i行第j列的数 
		}
	}

		for(int i=0;i<10;i++)
		{
			int j=0; 
			printf("%*.d",20-i*2,m[i][0]);//打印每一行第一个数，空格每增加一行多两个 
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
 
