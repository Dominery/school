#include<stdio.h>
int ziMiShu(int i,int k);
int main()
{
	int c;
	char *name[]={"��λ��ˮ�ɻ���","��λ��õ����","��λ���������","��λ��������","��λ�ı���������","��λ�İ�����"};
	do
	{
		int k,a=1,b=0;
		int m[10];
		printf("input a number between 3 and 8\n");
		scanf("%d",&k);
		for(int i=1;i<k;i++)
		{
			a*=10;
		}
		for(int i=a;i<10*a;i++)
		{
			if (ziMiShu(i,k))
			{
				m[b]=i;
				b++;	
			}
			
		}
		printf("%s����%d��",name[k-3],b);
		for(int i=0;i<b;i++)
		{
			printf("%d ",m[i]);
		}
	printf("�������\n");
	getchar(); 
	c=getchar();
	}while(c=='Y'||c=='y');
	
	
} 
int ziMiShu(int i,int k)
{
	int m[8];
	int su[8]={1,1,1,1,1,1,1,1};
	int sum=0,x=i;
	for(int j=0;j<k;j++)
	{
		m[j]=i%10;
		i/=10;
		for(int a=0;a<k;a++)
		{
			su[j]*=m[j];
		}
	}
	for(int j=0;j<k;j++)
	{
		sum+=su[j];
	}
	if(sum==x)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}






