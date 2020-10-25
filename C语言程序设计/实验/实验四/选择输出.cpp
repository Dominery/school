#include<stdio.h>
#define CHANGE 1
#define CHANGE 2
int main()
{
	char c;
	printf("想要原文输出？(y or n)\n");
	c=getchar();
	printf("\n");
	getchar();
	if(c=='y')
	{
		#ifdef CHANGE 1
			while((c=getchar())!='\n')
			{
				putchar(c);
			}
		#endif
	}
	else
	{
		#ifdef CHANGE 2
		   while((c=getchar())!='\n')
		   {
		   		if(c>='A'&&c<='Z')
				{
					c=c-'A'+'a';
				}
		   		else if(c>='a'&&c<='z')
		   		{
		   			c=c-'a'+'A';		   			
				}
				else
				{
					
				}
				
				putchar(c);
		   }
		#endif
	}
}
