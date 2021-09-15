// Write a program that takes two command-line arguments. The first is a string; the
// second is the name of a file. The program should then search the file, printing all lines
// containing the string. Because this task is line oriented rather than character oriented,
// use fgets() instead of getc(). Use the standard C library function strstr() (briefly
// described in exercise 7 of Chapter 11) to search each line for the string.



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

char	  * temp;   // dynamic array for saving string
long int	line;   // lenght of dynamic array 
FILE   	  * fd;

void	open_file(char *  name)     // this function open file
{
	if ((fd = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", name);
		exit(1);
	}
	else
		printf("file [%s] was open\n", name);
}

/*
	this function(calculate) counts how many charachters are 
	from the begining of the string to  
	charachter '\n' charachter
*/
void	calculate(void)  
{
	char	ch;
	
	line = 0;
	while ((ch = getc(fd) != '\n') && ch != EOF)
		line++;
}

/* function[craete_arr] creates a dynamic array for copying a string*/
void	create_arr(void)           
{
	temp = (char*) malloc(sizeof(char) * line);
	if (temp == NULL)
		fputs("function \"malloc\" can not create array", stderr);
	else
		puts("dynamic array  created");
}

/* function[copy_line] copy string in dynamic array*/
void	copy_line(void)
{
	char	ch;
	int		ind;

	ind = 0;
	while (((ch = getc(fd)) != '\n') && ch != EOF)
	{
		temp[ind] = ch; 
		ind++;	
	}
}

void	close_file(char * name)
{
	if (fclose(fd) != 0)
	{
		fprintf(stderr, "error: can not close file [%s]\n", name);
		exit(2);
	}
	else
		printf("file [%s] was closed\n", name);
}

int		main(int argc, char *argv[])
{
	char	*pnt;    // entry point
	int		ch;      // charachter for detecting the end of file
	if (argc == 3)
	{
		open_file(argv[2]);
		while ((ch = getc(fd)) != EOF)
		{	
			if (ch == '\n')
				putchar('|');
			ungetc(ch, fd);
			calculate();
			fseek(fd, -line, SEEK_CUR);
			create_arr();
			copy_line();
			if ((pnt = strstr(temp, argv[1])) != NULL)
			puts(pnt);
		}
		pnt = NULL;	
		free(temp);	
		close_file(argv[2]);
	}
	else
	{
		puts("wrong value of arguments\n\t\tfirst argument - string being searched for");
		puts("\t\tsecond argument - file in which need to searc this string");
	}
	puts("Good buy");
	return (0);
}
