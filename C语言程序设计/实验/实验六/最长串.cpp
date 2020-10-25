#include<stdio.h>
#include<string.h>
void search(char *lines);
int getline(char *,int);
#define max 100
int main()
{
	char lines[max];
	search(lines);
	printf("%s",lines);
	
}

int getline(char*s,int n)
{
	int c,i=0;
	while((c=getchar())!=EOF&&c!='\n'&&--n>0)
		s[i++]=c;
	if(c=='\n')
		s[i++]='\0';
	return i;
}

void search(char *lines)
{
	int len,nlines=0;
	char s[max];
	while((len=getline(s,max))>0)
	{
		if(len>nlines)
		{
			strcpy(lines,s);
			nlines=len;
		}
	}
}
