#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 20

void	replace(char *str, char target, char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
}

int		main(void)
{
	FILE * fd;
	char 	name[MAX];
	char	ch;
	long	count;
	long	last;
	
	puts("Please, enter name of file which i need to open");
	fgets(name, MAX - 1, stdin);
	replace(name, '\n', '\0');
	if ((fd = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "can not open file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name);

	fseek(fd, 0L, SEEK_END);
	last = ftell(fd);
	for (count = 1L; count <= last; count++)
	{
		fseek(fd, -count, SEEK_END);
		ch = getc(fd);
		putchar(ch);
	}
	putchar('\n');
	if (fclose(fd) != 0)
	{
		fprintf(stderr, "can not close file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was closed\n", name);
	return (0);
}
