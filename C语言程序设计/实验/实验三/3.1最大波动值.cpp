#include<stdio.h>
int main()
{
	int c,max=-1;
	int m[100]={0};
	int i=0;//���ڼ�¼�ڼ����� 
	printf("�������֣��ÿո������������ո��enter����\n");
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
