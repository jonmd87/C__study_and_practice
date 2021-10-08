// Modify the program in Listing 13.6 so that it uses a command-line interface instead of an
// interactive interface.



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUF 1024

void	append(FILE * sour, FILE * dest)
{
	size_t bytes;
	static char temp[BUF];
	
	while((bytes = fread(temp, sizeof(char), BUF, sour)) > 0)
		fwrite(temp, sizeof(char), bytes, dest);
}

int		main(int argc, char * argv[])
{
	FILE  * fd_dest;
	FILE  * fd_sour;  // source file descriptor
	int		count;
	
	count = 2;
	if (argc < 3)
		puts("wrong value of arguments.");
	else
	{
		if ((fd_dest = fopen(argv[1], "a+")) == NULL)
		{
			fprintf(stderr, "error: can not open file [%s]\n", argv[1]);
			exit(1);
		}
		else
			printf("-file [%s] was open\n", argv[1]);
		if (setvbuf(fd_dest, NULL, _IOFBF, BUF) != 0)
		{
			fprintf(stderr, "error: can not creat a buffer\n");
			exit(2);
		}
		else
			puts("bufer was creat");

		while (count < argc)
		{
			if (strcmp(argv[1], argv[count]) == 0)
				puts("can not add file to itself");
			else if ((fd_sour = fopen(argv[count], "r")) == NULL)
			{
				fprintf(stderr, "error: can not open file [%s]\n", argv[count]);
				exit(1);
			}
			else
			{
				printf("-file [%s] was open\n", argv[count]);
				if (setvbuf(fd_dest, NULL, _IOFBF, BUF) != 0)
				{
					fprintf(stderr, "error: can not creat a bufferi\n");
					continue;
				}
				else
					puts("bufer was creat");
				append(fd_sour, fd_dest);
				if (fclose(fd_sour) != 0)
					fprintf(stderr, "error: can not close file [%s]\n", argv[count]);
				else
					printf("file [%s] was close\n", argv[count]);
			}			
			count++;
		}
		if (fclose(fd_dest) != 0)
			fprintf(stderr, "error: can not close file [%s]\n", argv[1]);
		else 
			printf("file [%s] was close\n", argv[1]);
	}
	puts("Good buy");
	return(0);
}

