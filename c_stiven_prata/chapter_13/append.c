#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define BUF 1024

void	replace(char *str, char target, char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
} 

int		open_file(FILE * fd, char * str, int arg)
{
	char	key[MAX];	

	if (arg == 0)
		strcpy(key, "a+b");
	else
		strcpy(key, "r");
	if ((fd = fopen(str, key)) == NULL)
	{
		fprintf(stderr, "error: can not open file[%s]\n", str);
		if (arg == 0)
			exit(1);
		else
			return(1);
	}
	else
	{
		printf("file [%s] was open\n", str);
		return(0);
	}
}

int		copy_data(FILE * f_in, FILE * f_from)
{
	char	temp[BUF];
	size_t	bytes;
	while ((bytes = fread(temp, sizeof(char), BUF, f_from)) > 0)
		fwrite(temp, sizeof(char), bytes, f_in);
	return (0);
}

int		main(void)
{
	FILE  * f_app = NULL;
	FILE  * f_source = NULL;
	char	name_app[MAX];
	char	name_source[MAX];
	int		count;

	count = 0;
	puts("Hello, this program will add data from file sorce to file app");
	puts("Let's start\nEnter the name of append file");
	fgets(name_app, MAX - 1, stdin);
	replace(name_app, '\n', '\0');
	open_file(f_app, name_app, 0);
	puts("Now enter name of first source file");
	while (fgets(name_source, MAX - 1, stdin) != NULL && name_source[0] != '\n')
	{
		replace(name_source, '\n', '\0');
		if (strcmp(name_app, name_source) == 0)
			printf("can not add file in itself\n");
		else if ((open_file(f_source, name_source, 1)) != 0)
			continue;
		else
		{
			copy_data(f_app, f_source);
			count++;
			puts("now enter other name of source file");
		}
	}
	printf("was copied %i files\n", count);
	puts("good buy");	
	return(0);
}

















