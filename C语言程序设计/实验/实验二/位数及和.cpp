#include<stdio.h>
int main()
{
	int n,m,sum=0;
	scanf("%d",&n);
	do
	{
		sum=sum+n%10;
		m++;
		n/=10;
	}while(n>0);
	printf("%d %d",m,sum);
}
