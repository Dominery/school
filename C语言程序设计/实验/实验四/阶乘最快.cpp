#include<stdio.h>
void sum_fac(int n);
long long s=0;
long long fac=1;
int main()
{
    int k;
    for(k=1;k<=20;k++)
    {
		sum_fac(k);
        printf("k=%d\t the sum is%lld\n",k,s);
    }
    
    return 0;
}
void sum_fac(int n)
{
    
    long long i;
    fac=fac*n;       
	s+=fac;


}
