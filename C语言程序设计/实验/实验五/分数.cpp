#include<stdio.h>
void order();
void input();
void output();
int num=0;
struct student
{
	char name[20];
	int score;
}student[100];
int main()
{
	while(1) 
	{
		printf("������ӭʹ��ѧ���ɼ�����ϵͳ����\n");
		printf("1.����ѧ����Ϣ\n");
		printf("2.��ӡѧ����Ϣ\n");
		printf("3.��ѧ�����ɼ�����\n");
		printf("0.�˳�\n");	
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
			default:
			printf("��������ȷ����\n");
		}
	}

	
	
}
void input()
{
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
