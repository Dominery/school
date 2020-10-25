#include<stdio.h>
int main()
{
	int i,x,k,flag=0,a,b=100;
	
	while(b<=999)
	{
		flag=0;
		for(a=0,x=b;a<3&&flag==0;a++,x/=10)
		{
			
			for(i=2,k=x>>1;i<=k&&flag==0;i++)
			{
				if(!(x%i))
				{
					flag=1;
					
				}
			}
			if(k<2)
			{
				flag=1;
			}
			
		}
			
			if(flag==0)
			{
				printf("%6.d",b);
			}
		
		b++;
		
	}
	
}
