#include<stdio.h>
long long sum_fac(int n);
long long fac(int n);

int main()
{
    int k;
    for(k=1;k<=20;k++)
    {
        printf("k=%d\t the sum is%lld\n",k,sum_fac(k));
    }
    
    return 0;
}
long long sum_fac(int n)
{
    if(n==1)
    {
    return 1;
    }
    else
    {
    return (sum_fac(n-1)+fac(n));
    }
    


}
long long fac (int n)
{
    long long m=1,i;
    for( i=1;i<=n;i++)
    {
    m*=i;
    
    }
    return m;


}
