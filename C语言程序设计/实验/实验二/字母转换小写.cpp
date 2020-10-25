#include<stdio.h>
int main()
{
	char c;
	c=getchar();
	c=(c>='A'&&c<='Z')?c-'A'+'a':c;
	putchar(c);
}

