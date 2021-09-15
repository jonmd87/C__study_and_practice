// Revise the book-listing program in Listing 14.2 so that it prints the book descriptions in
// the order entered, then alphabetized by title, and then in order of increased value.



#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 40

struct book {
	char	name[MAX];
	char	title[MAX];
	double	cost;
};

void	replace(char * str, const char target, const char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}	
}

char	get_data(struct book * pnt)
{
	char  ch;
	
	puts("Enter name of author");
	fgets(pnt->name, MAX - 1, stdin);
	ch = pnt->name[0];
	replace(pnt->name, '\n', '\0');
	puts("Now enter title of book");
	fgets(pnt->title, MAX - 1, stdin);
	replace(pnt->title, '\n', '\0');
	puts("And enter the price of this book");
	scanf("%lf", &pnt->cost);
	while (getchar() != '\n');
	puts("book was read");	
	return (ch);
}

void	sort_by_title(struct book * pnt[], const int *val)
{
	struct book		* pt;
	int		f;
	int		s;


	f = 0;
	while (f < *val - 1)
	{
		s = f + 1;
		while (s < *val)
		{
			if (strcmp (pnt[f]->title, pnt[s]->title) > 0 )
			{
				pt = pnt[s];
				pnt[s] = pnt[f];
				pnt[f] = pt;
			}
			s++;
		}
		f++;
	}
	
}

void	sort_by_cost(struct book * pnt[], const int *val)
{
	struct book		* pt;
	int		f;
	int		s;

	f = 0;
	while (f < *val - 1)
	{
		s = f + 1;
		while (s < *val)
		{
			if (pnt[f]->cost > pnt[s]->cost)
			{
				pt = pnt[f];
				pnt[f] = pnt[s];
				pnt[s] = pt;	
			}
			s++;
		}
		f++;
	}
}

void	print_info(struct book * pnt[], const int *val)
{
	int 	ind;

	ind = 0;
	while (ind < *val)
	{
		printf("%s %s %.2lf\n", pnt[ind]->name, pnt[ind]->title, pnt[ind]->cost);
		ind++;
	}
}

int		main(void)
{
	struct book lib[MAX];
	struct book * point[MAX];
	int		ind;

	ind = 0;
	puts("This program will sort you library that you enter(MAX - 40 books).");
	puts("For exit enter empty string");
	while (ind < MAX && get_data(&lib[ind]) != '\n')
	{
			point[ind] = &lib[ind];
			puts("Enter another book(for exit enter empty string)");
			ind++;
	}
	puts("LIST OF BOOKS");
	print_info(point, &ind);
	puts("SORT BY TITLE");
	sort_by_title(point, &ind);
	print_info(point, &ind);
	puts("SORT BY COST");
	sort_by_cost(point, &ind);
	print_info(point, &ind);
	return (0);
}
