/*
Digital images are especially those that are transmitted to the radio channel by a 
	spacecraft. 
They may be subject to short-term pulse interference.
Add a function to exercise 13/13.12.c that suppresses this interference. 
It should compare each value with neighboring values located on the left and right, 
	bottom and top. 
If this value differs by more than 1 from its neighbors, 
	replace it with the average value of neighboring values. 
The program must round the average value to the smallest integer value. 
Note that the points on the borders had fewer than four neighbors, 
	so they require special processing.
*/


#include <stdio.h>
#include <stdlib.h>

#define MAX 20
const char	rep[11] = " .~^*<%$#@";

void	replace(char * str, const char target, const char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
}

void	read_file(FILE * fd, const char *str)
{
		int		ch;

		puts(str);
		rewind(fd);
		while ((ch = getc(fd)) != EOF)
			putchar(ch);
}

FILE *	open_file(const char *name, const char *argm)
{
	FILE  * fd;
	
	if ((fd = fopen(name, argm)) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name);
		exit(1);
	}
	else
	{
		printf("file [%s] was open\n", name);  
		return(fd);
	}
}

void	fill(FILE * fd, int **pnt)
{
	int 	line;
	int 	col;
	int		ch;

	line = 0;
	while (line < MAX)
	{
		col = 0;
		while (col < COL)
		{
			ch = getc(fd);
			if (ch != ' ' && ch != '\n')
			{
				pnt[line][col] = ch;
				putchar(pnt[line][col]);
				col++;
			}
		}
		pnt[line][col] = '\0';
		putchar('\n');
		line++;
	}
}

void	copy_in_file(int **pnt, FILE * fd)
{
	int		line;
	int		col;
	int 	ind;

	line = 0;
	while (line < MAX)
	{
		col = 0;
		while (col < COL)
		{
				ind = pnt[line][col] - '0';
				putc(rep[ind], fd);
				col++;
		}
		putc('\n', fd);
		line++;
	}
}

void	close_file(FILE * fd, char *name)
{
	int		val;
	
	val = fclose(fd);
	if (val != 0)
	{
		fprintf(stderr, "error: can not close file [%s]\n", name);
		exit(2);
	}
	else
		printf("file [%s] was close.\n", name);
}

int		main(void)
{
	FILE  * fd;	// file descriptor for source file
	char	name[MAX];
	int		** arr;	// pointer for creating a multidimensional array
	int		line;
	
	line = 0;
	puts("Enter name of source file");
	fgets(name, MAX - 1, stdin);
	replace(name, '\n', '\0');
	fd = open_file(name, "r");
	read_file(fd, "CONTENT OF SOURCE FILE:");
	rewind(fd);
	arr = (int**)malloc(sizeof(int*) * MAX);
	while (line < MAX)
		arr[line++] = (int*)malloc(sizeof(int) * COL);
	fill(fd, arr);
	close_file(fd, name);
	puts("Enter name of destination file");
	fgets(name, MAX - 1, stdin);
	replace(name, '\n', '\0');
	fd = open_file(name, "w+");
	copy_in_file(arr, fd);
	line -= 1;
	while (line != -1)
		free(arr[line--]);
	rewind(fd);
	read_file(fd, "CONTENT OF DESTINATION FILE");
	close_file(fd, name);
	puts("Good Buy");	
	return (0);
}

