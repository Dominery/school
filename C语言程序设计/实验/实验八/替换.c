#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count;
void replace(char*, char*, char*);
int main(int argc, char*argv[])
{
	FILE *fp = NULL;
	FILE*fp2 = NULL;
	int j,k;
	if (argc != 5)
	{
		printf("arguments error!\n");
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("fail to open the file ");
	}
	char st[100][100];
	int i = 0;
	while (fgets(st[i], 100, fp))
		i++;
	fclose(fp);
	fp2 = fopen(argv[2], "w");
	for (j = 0; j < i; j++) {
		replace(st[j], argv[4], argv[3]);
		fprintf(fp2, "%s", st[j]);
	}
	fclose(fp2);
	fp = fopen(argv[2], "r");
	i = 0;
	while (fgets(st[i], 100, fp))
		i++;
	for (k = 0; k < i; k++)
		fputs(st[k], stdout);
	printf("%d", count);
	return 0;
}
void replace(char*p, char*m, char*q)
{
	char*c = strstr(p, m);
	if (c != NULL)
	{
		count++;
		int i;
		*c = '\0';
		char*ch = (char*)malloc(100 * sizeof(char));
		strcpy(ch, p);
		strcat(ch, q);
		strcat(ch, c + strlen(m));
		for (i = 0; i < strlen(ch) + 1; i++)
			p[i] = ch[i];
		free(ch);
		replace(p, m, q);
	}
}
