#include<stdio.h>
#include<string.h>
void strnins(char *t,char *s,int n);
int main()
{
	char t[100],s[100];
	int n;
	scanf("%s",t);
	scanf("%s",s);
	scanf("%d",&n);
	strnins(t,s,n);
	printf("%s",t);
}
void strnins(char *t,char *s,int n)
{
	int m=0;
	int j=0;
	char mid[80];
	m=strlen(s);
	j=strlen(t);		
	for(int i=0;i<j;i++)
	{
		*(mid+i)=*(t+n+i);
	}
	for(int i=0;i<m;i++)
	{
		*(t+n+i)=*(s+i);
	}
	for(int i=0;i<j;i++)
	{
		*(t+n+m+i)=*(mid+i);
	}
	*(t+j+m)='\0';
}
