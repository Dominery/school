#include<stdio.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
	char ch;
	int i = 1;
	FILE *fp;
	if (argc != 2)
	{
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s file !\n", argv[1]);
		exit(-1);
	}
	printf("1.");
	while ((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
		if (ch == '\n');
		putchar("%d.", ++i);
		if (i % 25 == 0 && argv[2])
			getchar();
	}
	fclose(fp);
	return 0;
}
