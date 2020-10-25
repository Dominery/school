#include<stdio.h>
#include<string.h>
int delSubstr(char *str,char *substr);
//int repeat(char*str,char *substr);
int main()
{
	char str[40],substr[10];
	scanf("%s",str);
	scanf("%s",substr);
	if(delSubstr(str,substr))
	{
		
		printf("%s",str);
	}


	
}
int delSubstr(char *str,char *substr)
{
	
	char *p;
	int m=strlen(substr),i;

	if(strstr(str,substr)==NULL)
	{
		return 0;
	}
	else
	{
		p=strstr(str,substr);
		for( i=0;*(p+m+i)!='\0';i++)
		{
			*(p+i)=*(p+m+i);
			
		}
		*(p+i)='\0'; 
		if(strstr(str,substr)==NULL)
		{
			return 1;
		}
		else
		{
			return delSubstr(str,substr);
		}
		
		
	}
}
