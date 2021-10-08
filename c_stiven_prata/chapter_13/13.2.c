// Write a file-copy program that takes the original filename and the copy file from the
// command line. Use standard I/O and the binary mode, if possible.

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define	MAX 20

int		main(int argc, char *argv[])
{
	FILE  * fd_from;
	FILE  * fd_in;
	long	count;
	int		ch;

	if (argc != 3)
		printf("wrong value of arguments.\ngood buy\n");
	else
	{
		if ((fd_from = fopen(argv[1], "rb")) == NULL)
		{
			fprintf(stderr, "error: can not open file [%s]\n", argv[1]);
			exit(1);
		}
		else
			printf("file [%s] was open\n", argv[1]);
		if ((fd_in = fopen(argv[2], "wb")) == NULL)
		{
			fprintf(stderr, "error: can not open file [%s]\n", argv[2]);
			exit(2);
		}
		else 
			printf(" file[%s] was open\n", argv[2]);
		
		count = 0;
		while ((ch = getc(fd_from)) != EOF)
		{
			putc(ch, fd_in);
			count++;
		}
		printf("was copied %li charachters\n", count);
		if ((fclose(fd_from)) != 0)
		{
			fprintf(stderr, "error: can not close file [%s]\n", argv[1]);
			exit(1);
		}
		else 
			printf("file [%s] was closed\n", argv[1]);
		if ((fclose(fd_in)) != 0)
		{
			fprintf(stderr, "error: can not close file [%s]\n", argv[2]);
			exit(2);
		}
		else
			printf("file [%s] was closed\n", argv[2]);
	}
	return(0);
}

