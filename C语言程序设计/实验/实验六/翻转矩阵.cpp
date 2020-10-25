#include<stdio.h>
void reverse(int *p,int j,int i);
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int num[n][m];
	int *p=&num[0][0];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",*(num+i)+j);
		}
		printf("\n");
	}
	reverse(p,m,n);
 } 
 void reverse(int *p,int m ,int n)
 {
 	
 for(int j=m-1;j>=0;j--)
 	{
 		for(int i=0;i<n;i++)
 		{
			printf("%5.d",*(p+i*m+j));
		}
		printf("\n");
	}
			
 } 
