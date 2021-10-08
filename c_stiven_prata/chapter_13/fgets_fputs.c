#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 20

void	replace(char * str, char target, char rep)
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
	FILE	* fd;
	char	temp[MAX];
	char	name[MAX];
	
	puts("please enter name of file which i need to open");
	fgets(name, MAX - 1, stdin);
	replace(name, '\n', '\0');
	if ((fd = fopen(name, "a+")) == NULL)
	{
		fprintf(stderr, "can not open file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name);

	puts("now enter some text< which i need to write in file");
	while (fgets(temp, MAX - 1, stdin) != NULL && temp[0] != '\n')
		fputs(temp, fd);

	if (fclose(fd) != 0)
	{
		fprintf(stderr, "can not close file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was closed\n", name);
	return (0);
}
