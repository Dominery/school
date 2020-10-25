#include<stdio.h>
int main()
{
	int num[256]={0};
	char a;
	while((a=getchar())!='\n')
	{
		num[a]++;
	}

	for(int i=0;i<256;i++)
	{
		if(num[i])
		{
			printf("%c",i);
		}
	}
}
