// Write a program that opens a text file whose name is obtained interactively. Set up a
// loop that asks the user to enter a file position. The program then should print the part of
// the file starting at that position and proceed to the next newline character. Let negative
// or nonnumeric input terminate the user-input loop.


#include <stdlib.h>
#include <stdio.h>

#define MAX 20

char	name[MAX];
FILE  * fd;
long int	quantity;

void	replace(char target, char rep)
{
	char * pnt;

	pnt = name;
	while (*pnt)
	{
		if (*pnt == target)
			*pnt = rep;
		pnt++;
	}
}

void	open_file()
{
	if ((fd = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name); 
}

void	calculating()
{
	rewind(fd);
	fseek(fd, 0, SEEK_END);
	quantity = ftell(fd);
	rewind(fd);	
}

void	read_from(int	pos)
{
	int		ch;

	if (pos < 0)
		puts("!!!!ONLY POSITIVE NIMBER!!!!");
	else if (pos > quantity)
		puts("POSITION OUTSIDE THE FILE");
	else
	{
		fseek(fd, pos, SEEK_SET);
		while ((ch = getc(fd)) != '\n')
			putchar(ch);		
	}
	putchar('\n');
}

void	close_file(void)
{
	if (fclose(fd) != 0)
	{
		fprintf(stderr, "error: can not close file [%s]\n", name);
		exit(2);
	}
	else
		printf("file [%s] was close\n", name);
}

int		main(void)
{
	long int	position;

	position = 0;
	puts("Hi, this program will read file from position which you enter, before the new line");
	puts("Ok, lets start\nEnter the name of file:");
	fgets(name, MAX - 1, stdin);
	replace('\n', '\0');
	open_file();
	calculating();
	puts("Now enter position in the file(for exit enter letter)\n!!!!ONLY POSITIVE NUMBER!!!!");
	while (scanf("%li", &position) == 1)
	{
		read_from(position);
		rewind(fd);
		puts("Enter positive number(for exit enter letter)");
	}	
	close_file();
	puts("Good Buy!!!");	
	return (0);
}
