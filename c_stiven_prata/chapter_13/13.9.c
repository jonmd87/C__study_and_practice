// Modify the program in Listing 13.3 so that each word is numbered according to the order
// in which it was added to the list, starting with 1. Make sure that, when the program is
// run a second time, new word numbering resumes where the previous numbering left off.

#include <stdlib.h>
#include <stdio.h>

#define MAX 40

FILE  * fd;
int		num;

void	replace(char *str, char target, char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
}

void	open_file(char *str)
{
	if ((fd = fopen(str, "a+")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", str);
		exit(1);
	}
	else
		printf("file [%s] was open\n", str);
}

void		counting(void)
{
	char 	temp[MAX];

	while ((fscanf(fd, "%s", temp)) == 1)
		num++;
}

void	add_data(void)
{
	char  temp[MAX];
	while ((fgets(temp, MAX - 1, stdin)) != NULL && (temp[0] != '\n'))
		fputs(temp, fd);
}

void	read_file(void)
{
	int 	val; 
	char	temp[MAX];

	val = 1;
	while ((fscanf(fd, "%s", temp)) == 1)
	{
		if (val > num)
			printf("%i ", val - num);
		printf("%s\n", temp);
		val++;
	}
}

void	close_file(void)
{
	if (fclose(fd) != 0)
	{
		fputs("eror: can not close file", stderr);
		exit(2);
	}
	else
		puts("file was close");
}

int		main()
{
	char	name[MAX];

	puts("This program will add words in file which you will write");
	puts("Ok, let's start, enter name of file");
	fgets(name, MAX - 1, stdin);
	replace(name, '\n', '\0');
	open_file(name);
	rewind(fd);
	counting();
	rewind(fd);
	puts("OK, now enter words, which I need to add in file");
	add_data();
	rewind(fd);
	puts("Content of file:");
	read_file();
	close_file();
	puts("All done\nGood Buy!");
	return(0);
}
