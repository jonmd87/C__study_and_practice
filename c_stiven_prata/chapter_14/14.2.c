// Writing a program that prompts the user to enter the day, month, and year. The month
// can be a month number, a month name, or a month abbreviation. The program then
// should return the total number of days in the year up through the given day. (Do take
// leap years into account.)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 20
#define M 12
#define AB 4
	
int		ind;

struct	month {
		char	name[MAX];
		char	abrv[AB];
		int		days;
		int		num;
};

const struct month annum[M] = {
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

const struct month l_annum[M] = {
		{"January", "Jan", 31, 1},
  		{"February", "Feb", 29, 2},
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

const struct month * pnt;
	
void	replace(char * str, const char target, const char rep)
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
	int		i;
	int		size;

	i = 0;
	size = strlen(str);
	while (i < size)
	{
		str[i] = tolower(str[i]);
		i++;
	}
	str[0] = toupper(str[0]);
}

void	adapt(char *str)
{
	int		month;
	
	ind = 0;
	month = atoi(str);
	if (month > 0 && month < M + 1)
	{
		ind = month - 1;
		strncpy(str, pnt[month - 1].name, MAX - 1); 
	}
	else 
	{
		while (ind < M)
		{
			if (strcmp(str, pnt[ind].name) == 0)
			{
				strncpy(str, pnt[ind].name, MAX - 1);
				break; 
			}
			else if (strcmp(str, pnt[ind].abrv) == 0)	
			{
				strncpy(str, pnt[ind].name, MAX - 1); 
				break;
			}
			else
				ind++;
		}
	}
}

int		calculate(const int * day)
{
	int		num;
	int		tot;

	num = 0;
	tot = 0;
	if (*day > 0 && (*day <= pnt[ind].days))
	{
		while (num < ind) 
		{
			tot += pnt[num].days;
			num++;
		}
		tot += *day;
	}	
	return (tot); 
}

void	get_info(int * day, char * str, int * year)
{
	puts("Enter the number of day");
	scanf("%i", day);
	puts("Now enter month");
	scanf("%s", str);
	replace(str, '\n', '\0');
	norm(str);
	adapt(str);
	puts("Enter the year");
	scanf("%i", year);
}	

int		main(void)
{	
	char	month[MAX];
	int		total;
	int		year;
	int		day;
	
	pnt = &annum[0];
	get_info(&day, month, &year);	
	if (year > 0 && (year % 4) == 0)
		pnt = &l_annum[0];
	if (ind < M && year > 0 && (total = calculate(&day)) > 0)
			printf("From beginnig of %i year to %i %s are %i days\n", year, day, pnt[ind].name, total );
	else
		printf("Wrong input data\n");	
	puts("Good Buy"); 
	return (0);
}
