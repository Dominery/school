#include <stdio.h>
 int main()
{
	unsigned short x, m, n;
	scanf("%hx %hd %hd", &x, &m, &n);
	if (  m/16  != 0 || n < 1 || n>16 - m)
	{
		printf("Wrong");
		return 0;
	}
	unsigned short q = 0;
	printf("%#x", (x&((~q << m)&((unsigned short)~q >> 16 - m - n))) << 16 - m - n);

}
