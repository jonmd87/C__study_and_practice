// write a program that opens two files. You can obtain the filenames either by using
// command-line arguments or by solicting the user to enter them.

// a. Have the program print line 1 of the first file, line 1 of the second file, line 2 of the
//    first file, line 2 of the second file, and so on, until the last line of the longer file (in
//    terms of lines) is printed.

// b. Modify the program so that lines with the same line number are printed on the
//    same line.


#include <stdio.h>
#include <stdlib.h>

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

int 	main(void)
{
	FILE  * fd_first;
	FILE  * fd_second;
	char 	name_first[MAX];
	char	name_second[MAX];
	unsigned int 	line;
	int		ch1;
	int		ch2;
	
	line = 0;
	puts("Hi, this program will read two files and will display data from this file");
	puts("will display first line from first file and first line from second file");
	puts("second line from first file and second line from second file .......");
	puts("while display until the last line of the longer of file");
	puts("Let's start\nEnter name of first file");
	fgets(name_first, MAX - 1, stdin);
	replace(name_first, '\n', '\0');
	if ((fd_first = fopen(name_first, "r")) == NULL)	
	{
		fprintf(stderr, "error: can not open file [%s]\n", name_first);
		exit(1);
	}
	else
		printf("file [%s] was open,",name_first);
	puts("now enter name of second file");
	fgets(name_second, MAX - 1, stdin);
	replace(name_second, '\n', '\0');
	if ((fd_second = fopen(name_second, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name_second);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name_second);
	ch1 = getc(fd_first);
	ch2 = getc(fd_second);
	while (ch1 != EOF || ch2 != EOF)
	{
		while (ch1 != EOF && ch1 != '\n')
		{
			putchar(ch1);
			ch1 = getc(fd_first);
		}
		if (ch1 == '\n')
		{
			putchar(ch1);
			ch1 = getc(fd_first);
		}
		while (ch2 != EOF && ch2 != '\n')
		{
			putchar(ch2);
			ch2 = getc(fd_second);
		}
		if (ch2 == '\n')
		{
			putchar(ch2);
			ch2 = getc(fd_second);
		}
	}

	if ((fclose(fd_first) != 0) && (fclose(fd_second) != 0))	
	{	
		fprintf(stderr, "error: can not close files");
		exit(1);
	}
	return (0);
}
