#include<stdio.h>
#include<string.h>
int main()  
{
    char ch[20];
    scanf("%s",ch);
    int m=1;
    for(int i=0;i<strlen(ch);i++)
    {
    	if(ch[i]>=48&&ch[i]<=57)
    	{
		}
		else{
			m=0;
		}
	}
    if(strlen(ch)!=11)
    {
    	m=0;
	}
	if(ch[0]!='1')
	{
		m=0;
	}
	if(ch[1]>=51&&ch[1]!=54&&ch[1]!=57)
	{
		
	}
	else
	{
		m=0;
	}
    if(m)
    {
		printf("True");
	}
else
    printf("False");
}
