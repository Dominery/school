#include<stdio.h>
#include<math.h>
#define s(a,b,c)(((a)+(b)+(c))/2) 
#define area(a,b,c,s)(sqrt((s)*((s)-(a))*((s)-(b))*((s)-(c))))
int main()
{
	float a,b,c,s,y;
	scanf("%f %f %f",&a,&b,&c);
	s=s(a,b,c);
	y=area(a,b,c,s);
	printf("%.2f",y);
	
}
