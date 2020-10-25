#include<stdio.h>
int main(void)
{
	char c, numchar,numline;
	numchar=0;
	numline=0;
	printf("输入若干文本，Ctrl+z结束\n");
	while((c=getchar())!=EOF)
	{
		
		if (c=='\n')
		{
			++numline;
			
		}
		

		numchar++;
	
		
		
	}
	printf("字符数：%d",numchar);
	printf("行数：%d\n",numline);
	return 0;
}
