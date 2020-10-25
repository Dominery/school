#include<stdio.h>
int main(void)
{
	char c, numchar,numline,word;
	numchar=0;
	numline=0;
	word=0;
	
	printf("输入若干文本，Ctrl+z结束\n");
	while((c=getchar())!=EOF)
	{
		
		if (c=='\n')
		{
			++numline;
			++word;
			
		}
		else if(c==32)
		{
			++word;
		}
		else
		{
			numchar++;
		}

		
	
		
		
	}
	printf("字符数：%d",numchar);
	printf("行数：%d\n",numline);
	printf("单词数：%d\n",word);
	return 0;
}
