#include<stdio.h>
int main()
{
	int num;
	int s[16]={0};
	scanf("%d",&num);
	for(int i=0;num>0;i++)
	{
		s[15-i]=num%2;num/=2;
	}
	for(int i=0;i<16;i++)
	{
		printf("%d",s[i]);
	}
	return 0; 
}
