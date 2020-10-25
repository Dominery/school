#include<stdio.h>
int main()
 {
 	unsigned long m;	
 	int n[4];
 	while(scanf("%d", &m) != EOF)
 	{
 		n[3]=m&0xff;
 		n[2]=(m&0xff00)>>8;
 		n[1]=(m&0xff0000)>>16;
 		n[0]=(m&0xff000000)>>24;
 		for(int i=0;i<4;i++)
 		{
 			if(i!=3)
 			printf("%d.",n[i]);
		 
		 else
		 {
		 	printf("%d",n[3]); 
		 }
		} 
	}
 	
 }
 
 
 
 

