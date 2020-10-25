#include<stdio.h>
int main()
{
	int c,max=-1;
	int m[100]={0};
	int i=0;//用于记录第几个数 
	printf("输入数字，用空格间隔，最后输入空格和enter结束\n");
	while((c=getchar())!='\n')
	{
		if(c!=32)
		{
			
			
			m[i]=m[i]*10+c-'0'; 
			
		}
		else
		{
			if(i>1)
			{
				if(m[i]-m[i-1]>0)
				{
					if(m[i]-m[i-1]>max)
					{
						max=m[i]-m[i-1];
					}
				}
				if(m[i]-m[i-1]<0)
				{
					if(m[i-1]-m[i]>max)
					{
						max=m[i-1]-m[i];
					}
				}
			}
			if(i==1)
			{
				if(m[i]-m[i-1]>0)
				{
				
					max=m[i]-m[i-1];
					
				}
				if(m[i]-m[i-1]<0)
				{
					
					max=m[i-1]-m[i];
					
				}
			}
			i++;
		}
		
		
	}
	printf("%d",max);
 } 
