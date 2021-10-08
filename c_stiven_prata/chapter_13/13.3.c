// Write a file copy program that prompts the user to enter the name of a text file to act as
// the source file and the name of an output file. The program should use the toupper()
// function from ctype.h to convert all text to uppercase as it's written to the output file.
// Use standard I/O and the text mode.


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

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
	FILE  * fd_sour;
	FILE  * fd_dest;
	char	name_sour[MAX];
	char	name_dest[MAX];
	char	ch;

	puts("Hi, this program will copy taxt from one file to another");
	puts("when copying, all text will be converted to uppercase");
	puts("let's start\nEnter name of source file");
	fgets(name_sour, MAX - 1, stdin);
	replace(name_sour, '\n', '\0');
	if ((fd_sour = fopen(name_sour, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name_sour);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name_sour);
	
	puts("OK, now enter name of destination file");
	fgets(name_dest, MAX - 1, stdin);
	replace(name_dest, '\n', '\0');
	if ((fd_dest = fopen(name_dest, "a+")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name_dest);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name_dest);
	
	while ((ch = getc(fd_sour)) != EOF)	
	{
		if (islower(ch))
			ch = toupper(ch);
		putc(ch, fd_dest);
	}
	
	rewind(fd_sour);
	puts("\n\nCONTENT OF SOURCE FILE");
	while ((ch = getc(fd_sour)) != EOF)
		putc(ch, stdout);	
	
	puts("\n\nCONTENT OF DESTINATION FILE");
	rewind(fd_dest);
	while ((ch = getc(fd_dest)) != EOF)
		putc(ch, stdout);	

	if ((fclose(fd_sour) != 0) && ((fclose(fd_dest)) != 0))
	{
		fprintf(stderr, "error: can not close files [%s] or [%s]\n", name_sour, name_dest);
		exit(1);
	}
	puts("GOOD BUY");
	return(0);
}
















