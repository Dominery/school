#include<stdio.h>
int main()
{
	int n,b=0;
	int state;
	scanf("%d",&n);
	int m[n];
	for(int i=0;i<n;i++)
	{
	    scanf("%d",&m[i]);
	}
	int a[6];
	for(int i=1;i<n;i++)
	{
		
		m[i-1]>m[i]?a[i-1]=1:a[i-1]=0;
	}
	for(int i=1;i<6;i++)
	{
		if(a[i-1]!=a[i])
		{
			b++;
		}
	}
	printf("%d",b);
}
