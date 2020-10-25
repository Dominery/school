#include <stdio.h>
#include<string.h>
void orderlow (int *num,int number);
void orderup (int *num,int number);
int main(int argc, char *argv[])
{
	char numb[2];
	int number=0;
	strcpy(numb,argv[1]);
	for(int i=0;numb[i]!='\0';i++)
	{
		number=number*10+numb[i]-'0';
	}
	int num[number];
	

	
 
	for(int i = 0; i < number; i++)
	{
		scanf("%d",num+i);
	}
	if(strcmp(argv[2],"-d")==0)
	{
		orderlow(num,number);
	}
	else
	{
		orderup(num,number);
	}
		for(int i = 0; i < number; i++)
	{
		if(i%5==0)
		printf("\n");
		printf("%7.d",*(num+i));
	}
 
	return 0;
}
void orderlow(int *num,int number)
{
	for(int i=0;i<number;i++)
    {
        for(int j=i+1;j<number;j++)
        {
            int n;
           if (*(num+i)<*(num+j))
        {
          	n=*(num+j)  ;
            *(num+j)=*(num+i);
            *(num+i)=n;
        }
        }
    
    }
}
void orderup(int *num,int number)
{
	for(int i=0;i<number;i++)
    {
        for(int j=i+1;j<number;j++)
        {
            int n;
           if (*(num+i)>*(num+j))
        {
          	n=*(num+j)  ;
            *(num+j)=*(num+i);
            *(num+i)=n;
        }
        }
    
    }
}
