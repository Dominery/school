#include<stdio.h>
int main()

{
	int c;
	int state=1;
	while((c=getchar())!=EOF)
	{
		switch(state)//转换空格态与非空格态 
		{
			case 1:	putchar(c);
				if (c==32)
				{
					
					state=0;
				}
				else
				{
				
					state=1;
				}
				break;
			case 0:
				if(c==32)
				{
					state=0;	
				}
				else
				{
					putchar(c);
					state=1;
				}
				break;
			
		}
	}
}
