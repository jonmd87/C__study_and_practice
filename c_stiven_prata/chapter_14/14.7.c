/*
 Modify Listing 14.14 so that as each record is read from the file and shown
to you, you are given the chance to delete the record or to modify its contents. 
If you delete the record, use the vacated array position for the next record to be
read. To allow changing the existing contents, you'll need to use the "r+b" mode instead of the "a+b" mode, and you'll have to pay more attention to positioning the file pointer so that appended records don't overwrite existing records. 
It's simplest to make all changes in the data stored in program memory and then 
write the final set of information to the file. One approach to keeping track is to add a member to the book structure that indicated whether it it to be deleted.
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#define MAX 40
#define LINES 10

struct  book {
	char	auth[MAX];
	char	title[MAX];
	double	cost;
};

FILE  * fd;

void	replace(char * str, char target, char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
}

void	open_file(char * str)
{
	puts("Enter the name of file");
	fgets(str, MAX - 1, stdin);
	replace(str, '\n', '\0');
	if ((fd = fopen(str, "r+")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", str);
		exit(1);
	}
	else
		printf("File [%s] was open\n", str);	
}

char	get_answer(void)
{
	char	ch;
	scanf("%c", &ch);
	while (getchar() != '\n');
	ch = tolower(ch);
	return (ch);
}

int		get_book(struct book * pnt)
{
	puts("Enter new book");
	puts("Enter author");
	fgets(pnt->auth, MAX - 1, stdin);
	replace(pnt->auth, '\n', '\0');
	if (pnt->auth[0] == '\0')
		return (0);
	puts("Now enter book title");
	fgets(pnt->title, MAX - 1, stdin);
	replace(pnt->title, '\n', '\0');
	if (pnt->title[0] == '\0')
		return (0);
	puts("And enter cost of this book");
	scanf("%lf", &pnt->cost);
	while(getchar() != '\n');
	return (1);
}

void	del_str(struct book	* pnt)
{
	int		x;

	x = 0;	
	while (x < MAX)
		pnt->auth[x++] = '\0';
	x = 0;
	while (x < MAX)
		pnt->title[x++] = '\0';
	pnt->cost = 0;
}

void	change_string(struct book * pnt)
{
	char	ch;

	puts("Let's change this line, what element do you want to change?");
	puts("[L] - line\n[A] - author\n[T] - title\n[C] - cost");
	ch = get_answer();
	while (ch != 'l' && ch != 'a' && ch != 't' && ch != 'c')
	{
		puts("Only [l] or [a] or [t] or [c]");
		ch = get_answer();
	}
	if (ch == 'l')
		get_book(pnt);
	else if (ch == 'a')
	{
		puts("Enter author");
		fgets(pnt->auth, MAX - 1, stdin);
		replace(pnt->auth, '\n', '\0');
	}
	else if (ch == 't')
	{
		puts("Enter book title");
		fgets(pnt->title, MAX - 1, stdin);
		replace(pnt->title, '\n', '\0');
	}
	else if (ch == 'c')
	{
		puts("Enter new cost");
		fscanf(fd, "%lf", &pnt->cost);
		while (getchar() != '\n');
	}
}

int		read_file(struct book * pnt)
{
	int		ind;
	int		size;
	char	answ;

	ind = 0;
	size = sizeof(struct book);
	while (ind < LINES && fread(&pnt[ind], size, 1, fd) == 1)
	{
		if (feof(fd))
			break;
		if (ind == 0 && pnt[ind].cost != 0)
			puts("CONTENT OF FILE:");
		printf("[%s %s  -- %.2lf]\n", pnt[ind].auth, pnt[ind].title, pnt[ind].cost);
		puts("Do you want to change this string?\nY/N or D - delete");
		while((answ = get_answer()) != 'n' && answ != 'y' && answ != 'd')
			puts("Only [y] or [n]");
		if (answ == 'y')
		{
			change_string(&pnt[ind]);
			ind++;
		}
		else if (answ == 'n')
			ind++;
		else
		{
			del_str(&pnt[ind]);
			puts("string deleted");
		}
	}
	if (ind == 0)
	{
		del_str(&pnt[ind]);
		puts("File is empty");
	}
	while (ind < LINES && get_book(&pnt[ind]) == 1)
		ind++;
	return (ind - 1);
}

void	copy_in(const struct book * pnt, const int *val)
{
	int		ind;

	ind = 0;
	while (ind <= *val)
	{
		printf("[%s %s  -- %.2lf]\n", pnt[ind].auth, pnt[ind].title, pnt[ind].cost);
		fwrite(&pnt[ind], sizeof(struct book), 1, fd);
		ind++;
	}
}

void	close_file(const char * str)
{
	if (fclose(fd) != 0)
	{	
		fprintf(stderr, "error: can not close file [%s]\n", str);
		exit(2);
	}
	else
		printf("File [%s] closed\n", str);
}

int 	main(void)
{
	struct	book library[LINES];
	char	name[MAX];
	int		val;

	open_file(name);
	rewind(fd);
	val = read_file(&library[0]);
	rewind(fd);
	copy_in(&library[0], &val);
	close_file(name);
	return (0);
}
