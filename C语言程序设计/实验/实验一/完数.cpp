#include<stdio.h>
int isPerfect(int x);
int main()
{
	int a;
	printf("1000内的完数有：");
	for(a=1;a<=1000;a++)
	{
		if (isPerfect(a))
		printf("%8d",a);
	}
	return 0;
}
int isPerfect(int x)
{
	int y,s;
	for (s=0,y=1;y<=x/2;y++)
	{
		if (!(x%y))
		{
			s+=y; 
		 } 
	}
	if (s==x)
		{
			return 1;
			
		}
	else 
	{
		return 0;
	}
	
}
