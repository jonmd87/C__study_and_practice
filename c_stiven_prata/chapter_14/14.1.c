// Redo Review Question 5, but make the argument the spelled-out name of the month
// instead of the month number. (Don't forget about strcmp().) Test the function in a
// simple program.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define AB 4
#define	M 12

struct	month {
	char	name[MAX];		// name of month
	char	abrv[AB]; 		// abbreviation of month
	int		days;			// quantity of days in month
	int		num;			// number of month
};

void	replace(char *str, const char target, const char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
}
void	norm(char * str)
{
	int		ind;
	int		size;

	ind = 0;
	size = strlen(str);
	while (ind < size)
	{
		str[ind] = tolower(str[ind]);
		ind++;
	}
	str[0] = toupper(str[0]);
}

int		calculate(const struct month * pnt, const char *str)
{
	int		ind;
	int		tot;

	tot = 0;
	ind = 0;
	while (ind < M)
	{
		if ((strcmp(pnt[ind].name, str)) == 0)
		{
			while (ind >= 0)
			{
				tot += pnt[ind].days;
				ind--;
			}
			return (tot);
		}	
		ind++;
	}
	return (tot);
}	
	
int		main(void)
{	
	char	answ[MAX];
	int		total;	       
	struct month year[M] = {
		{"January", "Jan", 31, 1},
  		{"February", "Feb", 28, 2},
   		{"March", "Mar", 31, 3},
		{"April", "Apr", 30, 4},
    	{"May", "May", 31, 5},
   		{"June", "Jun", 30, 6},
    	{"July", "Jul", 31, 7},
    	{"August", "Aug", 31, 8},
    	{"September", "Sep", 30, 9},
    	{"October", "Oct", 31, 10},
    	{"November", "Nov", 30, 11},
    	{"December", "Dec", 31, 12}
};

	total = 0;
	puts("This program will count quantity of days.");
	puts("From begining of the year to the end of the specified month");
	puts("Let's start\nEnter abbreviation of the month(only 3 letters)");
	while ((fgets(answ, MAX - 1, stdin)) != NULL && answ[0] != '\n')
	{
		while (getchar() != '\n');
		replace(answ, '\n', '\0');
		norm(answ);
		total = calculate(&year[0], answ);
		if (total > 0)
			printf("From beginning of the year to the end of the %s are %i days\n", 
					answ, total);
		else
			printf("!!!![%s] is not valid input\n", answ);
		puts("Enter another month name(for exit enter emoty string");
	}
	puts("Good buy");
	return (0);
}
