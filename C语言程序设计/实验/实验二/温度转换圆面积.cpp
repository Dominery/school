#include<stdio.h>
#define Pi 3.14159
int main()
{
	int f;
	short p,k,newint;
	double c,r,s;
	printf("input Fahrenheit");
	scanf("%d",&f);
	c=(double)5/9*(f-32);
	printf("\n%d(F)=%.2f(C)\n\n",f,c);
	printf("input the radius r:");	getchar();
	scanf("%lf",&r);
	s=Pi*r*r;

	printf("\nThe acreage is %.2lf\n\n",s);
	k=0xa1b2,p=0x8423;
	newint=p&0xff00|k>>8;
	printf("new int =%d\n\n",newint);
	return 0;
	
 } 
