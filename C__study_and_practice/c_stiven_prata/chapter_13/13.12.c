// Create a text file consisting of 20 rows of 30 integers. The integers should be in the range
// 0-9 and be separated by spaces. The file is a digital representation of a picture, with
// the values 0 through 9 representing increasing levels of darkness. Write a program that
// reads the contents of the file into a 20-by-30 array of ints. In a crude approach toward
// converting this digital representation to a picture, have the program use the values
// in this array to initialize a 20-by-31 array of chars, with a 0 value corresponding to a
// space character, a 1 value to the period character, and so on, with each larger number
// represented by a character that occupies more space. For example, you might use # to
// represent 9. The last character (the 31st) in each row should be a null character, making
// it an array of 20 strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 20		
#define COL	30		// column

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
