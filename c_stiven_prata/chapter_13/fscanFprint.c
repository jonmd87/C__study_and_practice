#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX 20
 
void    change(char * str, char target, char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}       
}       
 
int     main(void)
{
	FILE * fd;
	char 	name[MAX];
	char 	temp[MAX];
	char 	ch;
	unsigned int    val;
    
	puts("please enter name of file which i need to open and write in");
	fgets(name, MAX - 1, stdin);
	change(name, '\n', '\0');
	if ((fd = fopen(name, "a+")) == NULL)
	{
		fprintf(stderr, "error: open file [%s]\n", name);
		exit(1);
	}   
	else 
		printf("file [%s] was opened\n", name);

	puts("now enter text which i need to add");
	while (fgets(temp, MAX - 1, stdin) != NULL && temp[0] != '\n')
		fprintf(fd, "%s", temp);
	rewind(fd);
	val = 0;
	while ((ch = getc(fd)) != EOF)
	{
		putchar(ch);
		val++;
	}   
	if (fclose(fd) != 0)
	{   
		fprintf(stderr, "error: can not close file [%s]\n", name);
		exit(1);
	}   
	else
		printf("file [%s] was closed\n", name);
	return(0);
}
