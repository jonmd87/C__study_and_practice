// Modify Listing 13.1 so that it solicits the user to enter the filename and reads the user's
// response instead of using command-line arguments.

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

void	read_file(FILE * fd)
{
	long	count;
	int		ch;

	count = 0;
	while ((ch = getc(fd)) != EOF)
	{
		putchar(ch);
		count++;
	}
	printf("was read %li charachters\n", count);
}

int		main(void)
{
	FILE  * fd;
	char	name[MAX];

	puts("enter name of file which i need to read");
	fgets(name, MAX - 1, stdin);
	replace(name, '\n', '\0');
	if ((fd = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name);
	read_file(fd);
	if (fclose(fd) != 0)
	{	
		fprintf(stderr, "error: can not close file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was closed.\ngood buy\n", name); 
	return(0);
}
