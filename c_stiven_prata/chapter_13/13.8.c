// Write a program that takes as command-line arguments a character and zero or more
// filenames. If no arguments follow the character, have the program read the standard
// input. Otherwise, have it open each file in turn and report how many times the character
// appears in each file. The filename and the character itself should be reported along with
// the count. Include error-checking to see whether the number of arguments is correct and
// whether the files can be opened. If a file can't be opened, have the program report that
// fact and go on to the next file.


#include <stdio.h>
#include <stdlib.h>

#define	MAX 1024

static char * buffer;

int		count_char(char target)
{
	int		count;
	char	temp[MAX];

	count = 0;	
	while((fgets(temp, MAX - 1, stdin) != NULL) && (temp[0] != '\n'))
	{
		for(int	ind = 0; temp[ind] != '\0'; ind++)
			if (temp[ind] == target)
				count++;	
	}
	return(count);	
}

int		counting(char * str, char  target)
{
	int		val;

	val = 0;
	while (*str)
	{
		if (*str == target)
			val++;
		str++;
	}	
	return(val);
}
long int	count(FILE * fd)
{
	long int	val;

	val = 0;
	fseek(fd, 0, SEEK_END);
	val = ftell(fd);
	rewind(fd);
	return(val);
}
	
void	 buf(long int val)
{

	buffer = (char *) malloc(sizeof(char) * val);
	if (buffer == NULL)
		fputs("malloc can not create temporary array", stderr);
	else
		puts("buffer was create");
}

int		main(int argc, char * argv[])
{
	FILE  * fd;
	int		ind;
	long int	val;	

	if (argc < 2)
		printf("wrong value of arguments\n");
	else
	{
		if (argc == 2)
		printf("in this text letter \"%c\" was appered %i times\n", argv[1][0], count_char(argv[1][0]));
		else
		{
			ind = 2;
			while (ind < argc)
			{
				if ((fd = fopen(argv[ind], "r")) == NULL)
				{
					fprintf(stderr, "error: can not open file [%s]\n", argv[ind]);
					exit(1);
				}
				val = count(fd);
				buf(val);
				fread(buffer, 1, val, fd);
				printf("in this text letter \"%c\" was appered %i times\n", argv[1][0], counting(buffer, argv[1][0]));
				fclose(fd);
				free(buffer);
				val = 0;	
				ind++;
			}
		}
	}
	printf("Good Buy\n");	
	return(0);
}
