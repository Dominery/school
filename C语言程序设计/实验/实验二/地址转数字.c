#include<stdio.h>

int main()
{
    int c,a=0,b=1; 
    long sum=0;
    long m[4]={0,0,0,0};
    while((c = getchar()) != '\n') 
    { 
       if((c>='0'&&c<='9')||(c=='.'))
      {
       	if (c!='.')
        {
           		m[a] =m[a]*10+c-'0';
           		if(m[a]>255)
            	{
                	b=0;break;
            	}
        }
        
        else 
        {
            a++;
        }
      }
	   
        else 
        
       {
        b=0;break;
        }
    }
    
     
    if (a!=3)
    b=0;
    if (b==1)
    {
		int j,i;
    	for( j=0;j<4;j++)
    	{
    		m[j]=m[j]<<8*(3-j);
		}
    
    	for( i=0;i<4;i++)
    	{
    		 sum+=m[i];
		}
   
    	printf("%u\n",sum); 
    }
    else 
    {
        printf("wrong\n");
    }
   
    return 0; 
}
