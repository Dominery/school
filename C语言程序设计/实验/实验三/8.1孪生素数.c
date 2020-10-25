#include<stdio.h>

int main()
{
    int m[300];
    int a=-1,i=2,b=1,n,j,x=0;
    scanf("%d",&a);
    m[0]=2;
    m[1]=3;
    for( n=4;n<=a;n++)
    {
        b=1;
        for( j=0;j<i;j++)
        {
             

            if(n%m[j]==0)
            {
                 
                    b=0;break;
            }
        }
        if(b==1)
        {
         m[i]=n;
        i++;
        }
    }
    for(j=0;j<i-1;j++)
       {
        if(m[j+1]-m[j]==2)
        {
        	x++;
        	if(x%5==0)
        	{
        		printf("%4.c%d,%d)\n",'(',m[j],m[j+1]);
			}
			else
			{
				printf("%4.c%d,%d)    ",'(',m[j],m[j+1]);
			}
		}
        
        }
         

  
    return 0;
}
