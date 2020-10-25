#include<stdio.h>
#include<stdlib.h>

typedef struct number1{
	int count;
	struct number1 *next;
}Snum;


int num1=0,num2=0;

void creat(Snum**tail1,Snum**tail2);
Snum* cacul(Snum*tail1,Snum*tail2);
void show(Snum*p);

int main()
{
	Snum*tail1=NULL;
	Snum*tail2=NULL,*p;
	creat(&tail1,&tail2); 
	p=cacul(tail1,tail2);

	show(p);
}

void creat(Snum**tail1,Snum**tail2)
{
	printf("please input a number:");
	char m;
	while((m=getchar())!='\n')
	{
		Snum*p=(Snum*)malloc(sizeof(Snum));
		p->count=m-'0';
		p->next=*tail1;
		*tail1=p;
		num1++;		
	}
	printf("please input another number:");
	while((m=getchar())!='\n')
	{
		Snum*p=(Snum*)malloc(sizeof(Snum));
		p->count=m-'0';
		p->next=*tail2;
		*tail2=p;
		num2++;		
	}	
	
}
int left=0;
Snum* cacul(Snum*tail1,Snum*tail2)
{
	int sum,m;
	Snum*p=num1>=num2?tail1:tail2;
	Snum*g=num1>=num2?tail2:tail1; 
		while(p!=NULL)
		{
			if(g==NULL)
			{
				sum=p->count;
				m=(sum+left)%10;
				p->count=m;
				left=(sum+left)/10;
				p=p->next;
			}
			else
			{
				sum=p->count+g->count;
				m=(sum+left)%10;
				p->count=m;
				left=(sum+left)/10;
				g=g->next;
				p=p->next;
			}			
		}
		if(left)
		{
			Snum*n=(Snum*)malloc(sizeof(Snum));
			n->count=left;
			p=num1>=num2?tail1:tail2;
			while(p->next!=NULL) p=p->next;
			p->next=n;
			n->next=NULL;
		}
	return num1>=num2?tail1:tail2;		
}
void show(Snum*p)
{
		if(p!=NULL)
		{
			show(p->next);
			printf("%d",p->count);
		} 
		else
		{
			return;
		}	
}
