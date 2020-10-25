#include<stdio.h>
int main () {
	char u[]="UVWXYZ",v[]="xyz";
	struct T {
		int x;
		char c;
		char *t;
	} a[]= {{11,'A',u},{100,'B',v}},*p=a;
	printf("%d\n",(++p)->x);
	p=a;
	p++;
	printf("%c\n",p->c);
	p=a;
	printf("%c ",*p++->t);
	printf("%c\n",*p->t);
	p=a;
	printf("%c\n",*(++p)->t);
	p=a;
	printf("%c\n",*++p->t);
	p=a;
	printf("%c",++*p->t);

}
