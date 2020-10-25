#include<stdio.h>
#include<stdlib.h>

typedef struct input{
	char word;
	struct input *next;
	struct input *former;
}in; 

int compare(in*tail,in*head);
int main()
{
	in*head=NULL,*tail=NULL;
	char m;
	int count=0,result;
	while((m=getchar())!='\n')
	{
	
		in*p=(in*)malloc(sizeof(in));
		p->word=m;
		if(count==0)
		{
			head=p;
			tail=p;
		}
		else
		{
			tail->next=p;
			p->former=tail;	
			tail=p;
		}
		
		
		count++;
	}
	result=compare(tail,head);
	if(result)
	{
		printf("Yes");
	}
	else
	{
	printf("NO");
	}
	
}
int compare(in*tail,in*head)
{
	while(tail!=head&&tail->next!=head)
	{
		if(tail->word!=head->word)
		return 0;
		tail=tail->former;
		head=head->next;
	}
	return 1;
}
