#include<stdio.h>
int removeSame(int *p,int n);
int main()
{
	int nums[]={3,3,3,6,6},m;
	int *p=nums,n=sizeof(nums)/sizeof(*(nums+0));
	m=removeSame(p,n);	
	for(int i=0;i<n;i++)
	{
		printf("%d",*(nums+i));
	}
}
int removeSame(int *p,int n)
{
	int num=1; 
	for(int i=1;i<n;i++)
	{
		int flag=1;
		for(int j=i-1;j>=0;j--)
		{
			if(*(p+j)==*(p+i))
			flag=0;
		}
		if(flag)
		{
			*(p+num)=*(p+i);
			num++;
		}

	}
	return num;
} 
