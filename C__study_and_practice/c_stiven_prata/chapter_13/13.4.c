// Write a program that sequentially displays on screen all the files listed in the command
// line. Use argc to control a loop.



#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char * argv[])
{
	int		count;
	int		ch;
	FILE  * fd;

	count = 1;
	if (argc < 2)
		puts("wrong value of arguments\nGood buy");
	else
	{
		while (count < argc)
		{
			if ((fd = fopen(argv[count], "r")) == NULL)
			{
				fprintf(stderr, "error: can not open file[%s]\n", argv[count]);
				exit(1);
			}
			else
				printf("file [%s] was open\n\n====content of file====:\n\n", argv[count]);
			while ((ch = getc(fd)) != EOF)
				putc(ch, stdout);
			if (fclose(fd) != 0)
			{
				fprintf(stderr, "error: can not close file %s\n", argv[count]);
				exit(1);
			}
			count++;
		}
	}
	if (count > 1)
		printf("\n%s was open, read and close\nGood buy!\n", 
		count > 2 ? "All files" : "file");

	return(0);
}
