#include<stdio.h>
int main()
{
	int i,x,k,flag=0;
	printf("���������1������Ctrl+z����\n");
	while(scanf("%d",&x)!=EOF)
	{
		i=2;
		flag=0;
		do
		{	k=x>>1;
			if(!(x%i))
			{
				flag=1;
				
			}
			i++;
		}while(i<=k&&flag==0);
		if(flag)
		{
			printf("no");
		}
		else
		{
			printf("yes");
		}
		
	}
}
