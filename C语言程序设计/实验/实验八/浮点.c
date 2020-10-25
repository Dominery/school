#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
	float num[10],cou[10];
	int i;
	
	for (i = 0; i < 10; i++)
		scanf("%f", &num[i]);
	FILE*fp = NULL;
	fp= fopen("float.dat", "wb+");
	for (i = 0; i < 10; i++)
		fwrite(&num[i], sizeof(float), 1, fp);
	rewind(fp);
	
	fread(cou, sizeof(float), 10, fp);
	for (i = 0; i < 10; i++)
		printf("%.6f", cou[i]);
	fclose(fp);
}
