// Programs using command-line arguments rely on the user's memory of how to use them
// correctly. Rewrite the program in Listing 13.2 so that, instead of using command-line
// arguments, it prompts the user for the required information.



#include <stdio.h>
#include <stdlib.h>

#define	MAX 20

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
	FILE  * fd_dest;
	FILE  * fd_sour;
	char	name_dest[MAX];
	char	name_sour[MAX];
	unsigned int	count;
	int		ch;
	
	count = 1;
	puts("Hi, this program compresses your source file to one third of the size");
	puts("And writes it in destination file");
	puts("Let's start!\nEnter name of destination file");
	fgets(name_dest, MAX - 1, stdin);
	replace(name_dest, '\n', '\0');
	if ((fd_dest = fopen(name_dest, "w")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name_dest);
		exit(1);
	}	
	else
		printf("file [%s] was open\n", name_dest);
	puts("OK, now enter name of source file");
	fgets(name_sour, MAX - 1, stdin);
	replace(name_sour, '\n', '\0');
	if ((fd_sour = fopen(name_sour, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name_sour);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name_sour);
	while ((ch = getc(fd_sour)) != EOF)
	{
		if ((count % 3) == 0)
			putc(ch, fd_dest);
		count++;
	}
	if ((fclose(fd_dest)) != 0)
	{
		fprintf(stderr, "error: can not close file [%s]\n", name_dest);
		exit(1);
	}
	else
		printf("file [%s] was close\n", name_dest);
	if ((fclose(fd_sour)) != 0)
	{
		fprintf(stderr, "error: can not close file [%s]\n", name_sour);
		exit(1);
	}
	else
		printf("file [%s] was close\n", name_sour);
	puts("Good buy");
	return (0);
}









