#include<stdio.h>
int main()
{
	int x;
	scanf("%d",&x);
	switch((x/1000)) 
	{
		case 0:	
			printf("tax is 0");
			break;
		case 1:
			printf("tax is %.2f",x*0.05);
			break;
		case 2:
			printf("tax is %.2f",x*0.1);
			break;
		case 3:
			printf("tax is %.2f",x*0.15);
			break;
		case 4:
			printf("tax is %.2f",x*0.2);
			break;
		default:
			printf("tax is %.2f",x*0.25);
	}
	
	}

