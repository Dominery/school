#include<stdio.h>
void order();
void input();
void output();
void search(int brow); 
void insert();
int num=0;
struct student
{
	char name[20];
	int score;
}student[100];
int main()
{
	int brow;
	printf("——欢迎使用学生成绩管理系统——\n");
	printf("1.输入学生信息\n");
	printf("2.打印学生信息\n");
	printf("3.对学生按成绩排序\n");
	printf("4.查找学生\n");
	printf("5.插入学生\n");
	printf("0.退出\n");	
	while(1) 
	{
		
		char n;
		n=getchar();
		getchar();
		switch(n)
		{
			case '1':
				input();
				break;
			case '2':
				output();
				break;
			case '3':
				order();
				break;
			case '0':
				return 0;
			case '4':
				printf("请输入待查找学生成绩：\n");
				scanf("%d",&brow);
				getchar();
				search(brow);
				break;
			case '5':
				insert();
				break; 
			default:
			printf("请输入正确数字\n");
		}
	}
	
	
}
void input()
{
	printf("请输入学生姓名和成绩：\n"); 
	
	for(int i=0;getchar()!='\n';i++)
	{
		num++;
		scanf("%s %d",&student[i].name,&student[i].score);
	}
}
void order()
{
	 for(int i=0;i<num;i++)
    {
        for(int j=i+1;j<num;j++)
        {
            struct student n;
           if (student[i].score<student[j].score)
        	{
          		n=student[j] ;
          		student[j]=student[i];
          		student[i]=n;
            	
        	}
        }
    
    }
}
void output()

{
	for(int i=0;i<num;i++)
	{
		printf("%s %d\n",student[i].name,student[i].score);
	}
}
void search(int brow)
{
	int i=0,j=num-1,m;
	while(i<=j)
	{
		m=(i+j)/2;
		if(student[m].score<brow)
		{
			j=m-1;
		}
		else if(student[m].score>brow)
		{
			i=m+1;
		}
		else
		{
			printf("%s %d\n",student[m].name,student[m].score);
			break;
		}
	}
	if(i>j)
	{
		printf("not found!");
	}
	
}
void insert()
{	int i; 
	printf("请输入要插入的学生姓名与分数：\n");
	
	scanf("%s %d",&student[num].name,&student[num].score);
	getchar();
	struct student n=student[num];
	for(i=0;i<num;i++)
	{
		if(student[num].score>student[i].score)
		{
			break;
		}
	 } 
	 for(int j=num-1;j>=i;j--)
	 {
	 	student[j+1]=student[j];
	 	
	 }
	 student[i]=n;
	 num++;
}
