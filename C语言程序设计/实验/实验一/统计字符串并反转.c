#include<stdio.h>
void strReverse(char*s);
int strLength(char s[]);
int main()
{
	char s[1000];
	printf("输入一个字符串\n");
	scanf("%s",s);
	printf("串%s的长度为：%d\n",s,strLength(s));
	strReverse(s);
	printf("反转后：%s",s);
	return 0;
}
int strLength(char s[])
{
	int i=0;
	while(s[i++]);
	return i-1;
}
void strReverse(char*s)
{
	int i ,j;
	for(i=0,j=strLength(s);i<j;i++,j--)
	{
		char t;
		t=s[i];s[i]=s[j-1];s[j-1]=t;
	}
}
