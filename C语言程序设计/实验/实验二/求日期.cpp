#include<stdio.h>
int main()
{
	int year,month,day,sum=0;
	int monthdate[12 ]={31,28,31,30,31	,30,31,31,30,31,30,31};
	scanf("%d %d",&year,&day);
	if ((	year%100 && !(year%4) ) || !(year%400))
	{
		monthdate[1]=29;
	}
	
	for (month=0;month<=11;month++)
		{
			sum+=monthdate[month];
			if (sum>=day)
			{
				break;
			}
				
		}
	day=day-sum+monthdate[month];
	month++;
	printf("%dÔÂ%dÈÕ",month,day);
}

