#include<stdio.h>
#include<stdlib.h> 
#define M 5
#define N 10

typedef struct member{
	int id;
	struct member *next;
}mem;
void create(mem**tail);
void loop(mem*tail);
mem* remove(mem*tail);
int main()
{
	printf("the number of people is:%d\nthe count is:%d\n",N,M);
	mem*tail=NULL;
	create(&tail);
	loop(tail);
}

void create(mem**tail)
{
	mem*n=NULL;
	for(int i=N;i>0;i--)
	{
		mem*p=(mem*)malloc(sizeof(mem));
		if(i==N)n=p;
		p->id=i;
		p->next=*tail;
		*tail=p;
	}
	n->next=*tail;
}
void loop(mem*tail)
{
	while(tail->next!=NULL)
	{
		for(int i=1;i<M;i++)
		{
			tail=tail->next;
		}
		tail=remove(tail);
	}
	printf("the winner is: %d",tail->id);
	free(tail); 
}

mem* remove(mem*tail)
{
	mem*p=tail;
	while(p->next!=tail)p=p->next;
	if(tail->next==p)
	{
		p->next=NULL;
		printf("%d\n",tail->id);
		free(tail);
		return p;
	}
	else
	{
		p->next=tail->next;
		printf("%d\n",tail->id);
		free(tail);
		return p->next;
	}
	 
	
}



