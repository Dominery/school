#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *fp;
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
struct student * create1();
struct student *create();
void output(struct student *tail);
void average(struct student *tail);
void change(struct student *tail);
void allout(struct student *tail);
void sort(struct student *tail);
int main()
{
	fp = NULL;
	struct student *head=NULL,*p,*l,*k;
	char order;
	if (fopen_s(&fp, "stu.dat", "wb+"))
	{
		printf("fail to open the file");
			exit(EXIT_FAILURE);
	}
	printf("\t 班级成绩管理,请选择下列功能\n");
	printf("1.输入各项信息\n2.输出信息\n3.修改成绩\n4.统计平均成绩\n5.输出成绩分析\n6.排序\n7.读取文件\n0.退出\n");
	while(1) 
	{
		
		printf("please enter your order!\n");
		order=getchar();
		getchar();
		switch(order)
		{
			case '1':
				l=p=create();
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
			case '7':
				k=p=create1();
				break;
			default:
			     printf("请输入正确数字\n");
		}
	}
	while (l != 0)
	{
		struct student *q = l;
		l = l->next;
		free(q);
	}
	while (k != 0)
	{
		struct student*q = k;
		k = k->next;
		free(q);
	}
	fclose(fp);
	
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
		getchar();int i;
		for( i=0;i<4;i++)
		{
			printf("%s:",couse[i]);
			scanf("%u",&p->course[i]);			
		}
		p->sum=p->course[0]+p->course[1]+p->course[2]+p->course[3];
		p->average=(float)p->sum/4;
		fwrite(p->name, 10, 1, fp);
		fwrite(&(p->id), 10, 1, fp);
		for(i=0;i<4;i++)
		{
			fwrite(&(p->course[i]), sizeof(double), 1, fp);
		}
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
 	
 	struct student*p=tail;int i;
 	while(p!=NULL)
 	{
 		printf("%u %s\n",p->id,p->name);
 		for( i=0;i<4;i++)
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
 	
 	for(i=0;i<4;i++)
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
 				unsigned n;int i;
				n=m->id;
				m->id=p->id;
				p->id=n;
				char copy[5];
				strcpy(copy,m->name);
				strcpy(m->name,p->name);
				strcpy(p->name,copy);
				for( i=0;i<4;i++)
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
 struct student* create1()
{
	struct student*tail = NULL,*p = NULL,*q = NULL;int i;
	rewind(fp);	
	do
	{
		p = (struct student*)malloc(sizeof(struct student));
		if (fread(p->name, 10, 1, fp))
		{
			fread(&(p->id), 10, 1, fp);
			for( i=0;i<4;i++)
			{
				fread(&(p->course[i]), 8, 1, fp);
			}
			p->next=tail;
			tail=p;
		}
		else
			break;
	} while (p->name);
	
	return tail;
}
