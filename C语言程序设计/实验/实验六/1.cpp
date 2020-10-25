#include<stdio.h>
#include<stdlib.h>
 char*strcopy(char*, char *);
 int main()
 {
 	char *s1,*s2,*s3;
 	char m[10],n[10]; 
 	printf("input a string:\n");
 	scanf("%s",m);
 	s2=m;
 	s1=(char*)malloc(15);
 	strcopy(s1,s2);
 	printf("%s\n",s1);
 	printf("input a string again:\n");
 	scanf("%s",n);
 	s2=n;
 	s3=(char*)malloc(15);
 	strcopy(s3,s2);
 	printf("%s\n",s3);
 	return 0;
 }
 
 char*strcopy(char*t, char *s)
 {
 	while((*t++)=(*s++));
 	return t;
 }
