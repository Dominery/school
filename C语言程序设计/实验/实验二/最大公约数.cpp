#include<stdio.h>
int main()
{
    int m,n,k,p,i,d;
    printf("input m, n\n");
    scanf("%d %d",&m,&n);
    if(m<n)
    {
      m=m^n;n=n^m;m=m^n;
    }
    k=0;
    while ((m&0x0001)==0&&(n&0x0001)==0)
    {
        m=(unsigned)m>>1;
        n=(unsigned)n>>1;
        k++;
    }
    for(p=1,i=0;i<k;i++)  p=p<<1;
    while((d=m-n)!=n)
    {
        	d<=n?m=n,n=d:m=d;

    }
    d*=p;
    printf("great common divisor : %d",d);
    return 0;

}








