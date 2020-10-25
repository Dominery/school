#include<stdio.h>
int main()
{
	int number,n[8];
	scanf("%d",&number);
	int *p=&number;
	for(int i=0;i<8;i++)
	{
		int mask=0x0f;
		
			
			n[7-i]=(*p>>i*4)&mask;
				
	}
	for(int i=0;i<8;i++)
	{
		printf("%x",n[i]);
		if(i%2)
		printf("\n");
		
	}
		
}
