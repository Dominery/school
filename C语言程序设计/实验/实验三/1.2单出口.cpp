#include<stdio.h>
int main()
{
	int i,x,k,flag=0;
	printf("���������1������Ctrl+z����\n");
	while(scanf("%d",&x)!=EOF)
	{
		flag=0;
		for(i=2,k=x>>1;i<=k&&flag==0;i++)
		{
			if(!(x%i))
			{
				flag=1;
				
			}
		}
		if(flag)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
		
	}
} 
