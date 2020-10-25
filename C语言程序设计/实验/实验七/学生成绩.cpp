#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student{
	unsigned id;
	char name[5];
	unsigned course[4];
	float average;
	int sum;
	struct student*next;
}; 
int count=0;
const char *couse[]={"English","Math","Geograph","C language"};
struct student *create();
void output(struct student *tail);
void average(struct student *tail);
void change(struct student *tail);
void allout(struct student *tail);
void sort(struct student *tail);
int main()
{
	struct student *head=NULL,*p;
	char order;
	printf("\t 班级成绩管理,请选择下列功能\n");
	printf("1.输入各项信息\n2.输出信息\n3.修改成绩\n4.统计平均成绩\n5.输出成绩分析\n6.排序\n0.退出\n");
	while(1) 
	{
		
		printf("please enter your order!\n");
		order=getchar();
		getchar();
		switch(order)
		{
			case '1':
				p=create();
				break;
			case '2':
				output(p);
				break;
			case '3':
				change(p);
				break;
			case '0':
				return 0;
			case '4':
				average(p);
				break;
			case '5':
				allout(p);
				break; 
			case '6':
				sort(p);
				break;
			default:
			     printf("请输入正确数字\n");
		}
	}
	
}

	
			
	

struct student *create()
{
	struct student*p=NULL,*tail=NULL;
	char ch;
		
	do{
		p=(struct student *)malloc(sizeof(struct student));
		printf("id:");
		scanf("%u",&p->id);
		getchar();
		printf("name:");
		scanf("%s",p->name);
		getchar();
		for(int i=0;i<4;i++)
		{
			printf("%s:",couse[i]);
			scanf("%u",&p->course[i]);			
		}
		p->sum=p->course[0]+p->course[1]+p->course[2]+p->course[3];
		p->average=(float)p->sum/4;
		p->next=tail;
		tail=p;
		count++;
		getchar();
		printf("是否继续？\n");
		scanf("%c",&ch);		
	}while(ch=='y'||ch=='Y');
	getchar();
	return tail;
	
 } 
 void output(struct student *tail)
 {
 	
 	struct student*p=tail;
 	while(p!=NULL)
 	{
 		printf("%u %s\n",p->id,p->name);
 		for(int i=0;i<4;i++)
 		printf("%s:%d\n",couse[i],p->course[i]); 		
 		p=p->next;
	} 
 }
 void change(struct student *tail)
 {
 	unsigned id,score;
 	int obj,i=1;
 	struct student *p=tail;
 	
 	do{
 		printf("input id\n");
 		scanf("%u",&id);
 		getchar();
 		while(p!=NULL)
		{
			if(id==p->id)
			{	
				i=0;
				break;
			}
			p=p->next;
		}
		p=tail;
		if(i)
		printf("Not found!\n");
	 }while(i);
 	
 	for(int i=0;i<4;i++)
 		printf("%d represents %s ",i,couse[i]);
 	printf("\n");
	scanf("%d %d",&obj,&score); 
	getchar();
	while(p!=NULL)
	{
		if(id==p->id)
		{
			
			p->sum=p->sum-p->course[obj]+score;
			p->course[obj]=score;
			p->average=p->sum/4;
			break;
		}
		p=p->next;
	}
	
 	
 }
 void average(struct student *tail)
 {
 	struct student*p=tail;
 	while(p!=NULL)
 	{
 		printf("%u %s %.2f\n",p->id,p->name,p->average);
 		p=p->next;
	} 
 }
 void allout(struct student *tail)
 {
 	struct student*p=tail;
 	if(p==NULL)
 	{
 		return;
	 }
	 else
	 {
	 	printf("%u %s\n",p->id,p->name);
 		printf("总成绩：%d 平均分：%.2f\n",p->sum,p->average);
 		allout(p->next);
	 }
	 
 }
 void sort(struct student *tail)
 {
 	struct student*p=tail,*m=p->next,*cou=tail;
 	while(cou!=NULL)
 	{
 		p=tail;
 		m=p->next;
		
 		while(m!=NULL)
 		{
 			
 			if(m->average<p->average)
 			{
 				unsigned n;
				n=m->id;
				m->id=p->id;
				p->id=n;
				char copy[5];
				strcpy(copy,m->name);
				strcpy(m->name,p->name);
				strcpy(p->name,copy);
				for(int i=0;i<4;i++)
				{
					n=m->course[i];
					m->course[i]=p->course[i];
					p->course[i]=n;
				 }
				 float aver;
				 aver=m->average;
				 m->average=p->average;
				 p->average=aver;
				 int total;
				 total=m->sum;
				 m->sum=p->sum;
				 p->sum=total;					 	
			}
			m=m->next;
			p=p->next; 			
		}
		cou=cou->next;
	}
 	
 }
