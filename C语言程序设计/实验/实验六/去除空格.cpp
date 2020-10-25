#include<stdio.h>
#include<string.h>
void clear(char *str);

int main()
{
	int n;
	printf("input the number of lines:\n");
	scanf("%d",&n);
	char str[n][80];
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str[i]);
		clear(*(str+i));
	}
	for(int i=0;i<n;i++)
	{
		printf("%s\n",*(str+i));
	 } 
}
void clear(char *str)
{
	
	if(*str==' '||*str=='\t')
	{
		for(int i=0;i<strlen(str)-1;i++)
		{
			
			*(str+i)=*(str+i+1);
		}
	}
}
