#include<stdio.h>
void goldBach(int n);
int main()
{
	int i=-1;
	printf("input a number\n");
	scanf("%d",&i);
	if(i%2==0)
	{
		if (i>=4)
		goldBach(i);
		else
		printf("please input a number bigger than 3");
	}
	else
	{
		printf("input a even number\n");
	}
	
	
}
void goldBach(int a)
{
	int b,i=2;
	int m[300];//�洢���� 
    m[0]=2;
    m[1]=3;
    for(int n=4;n<a;n++)//������aС�������� 
    {
        b=1;//��ʼ��b 
        for(int j=0;j<i;j++)
        {
             

            if(n%m[j]==0)//�ж�n�Ƿ�Ϊ���� ��������������ܱ�����С���������� 
            {
                 
                    b=0;break;
            }
        }
        if(b==1)
        {
         m[i]=n;//����������洢 
        i++;
        }
    }
    for(int i=0;m[i]<a;i++)//����������Ѱ���Ƿ�������� 
    {
    	for(int j=0;m[j]+m[i]<=a;j++)
    	{
    		if(m[i]+m[j]==a)
    		{
    			printf("%d=%d+%d\n",a,m[i],m[j]);
			}
		}
	}
}



