#include<stdio.h>
int main(void)
{
	char c, numchar,numline,word;
	numchar=0;
	numline=0;
	word=0;
	
	printf("���������ı���Ctrl+z����\n");
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
	printf("�ַ�����%d",numchar);
	printf("������%d\n",numline);
	printf("��������%d\n",word);
	return 0;
}
