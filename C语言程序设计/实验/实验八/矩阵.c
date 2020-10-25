#include<stdio.h>
#include <stdio.h>
#include<stdlib.h>
FILE *p;
void reverse(int *p,int j,int i,FILE *q);
int main()
{
	
	int m, n,i,j;
	
	if ((fopen_s(&p,"matrix.in.txt", "r")) != 0) {
		printf("fail to open the %s file","matrix.in.txt");
		exit(-1);
	}
	fscanf(p, "%d %d", &m, &n);
	int num[m][n];
	for (i = 0; i < m; i++)
		for ( j = 0; j < n; j++)
			fscanf(p, "%d", &num[i][j]);
	fclose(p);
	if (( fopen_s(&p,"matrix.out.txt", "w+")) != NULL) {
		printf("fail to open the file");
		exit(-1);
	}
	fprintf(p, "%d %d\n", n, m);
	reverse(num,m,n,p);
	rewind(p);
	char s[20][20];
	i = 0;
	while (fgets(s[i], 20, p) != 0)
	{
		fputs(s[i], stdout);
		i++;
	}
	fclose(p);
}
void reverse(int *p,int m,int n,FILE *q)
{
	int i,j;
	for ( j = n - 1; j >= 0; j--)
	{
		for ( i = 0; i < m; i++) {
			printf("%d ",*(p+i*n+j));
			fprintf(q, "%d ", *(p+i*n+j));
		}
		putchar('\n');
		fputc('\n', q);
	}
}

