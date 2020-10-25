#include<stdio.h>

int main()
{
    int n,i;
    for(n=1000;n<10000;n++)
    {
    
        if(n/1000!=(n/100)%10)
        {
            continue;
        }
        if(n%10!=(n%100)/10)
        {
            continue;
        }
        else
        {
            if(n%10==n/1000)
            {
            	continue;
			}
            
        }
        for(i=30;i*i<=n;i++)
        {
            
            if(i*i==n)
             printf("%d\n",n);
        }
        
    
    }
    return 0;
}
