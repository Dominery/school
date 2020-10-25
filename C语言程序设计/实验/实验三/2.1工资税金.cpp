#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	if(x<1000)
	{
		printf("tax is 0");
	}
	else if(x<2000)
	{
		printf("tax is %.2f",x*0.05);
	}
	else if(x<3000)
	{
		printf("tax is %.2f",x*0.1);
	}
	else if(x<4000)
	{
		printf("tax is %.2f",x*0.15);
	}
	else if(x<5000)
	{
		printf("tax is %.2f",x*0.2);
	}
	else 
	{
		printf("tax is %.2f",x*0.25);
	}
}
