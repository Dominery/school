#include<stdio.h>
int main()
{
	int i,x,k,flag=0;
	printf("请输入大于1的数，Ctrl+z结束\n");
	while(scanf("%d",&x)!=EOF)
	{
		flag=0;
		for(i=2,k=x>>1;i<=k;i++)
		{
			if(!(x%i))
			{
				flag=1;
				break;
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
