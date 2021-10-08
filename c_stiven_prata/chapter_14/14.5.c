// Write a program that fits the following recipe:
//
//      a. Externally define a name structure template with two members: a string to hold the
//         first name and a string to hold the second name.
//
//      b. Externally define a student structure template with three members: a name
//         structure, a grade array to hold three floating-point scores, and a variable to hold
//         the average of those three scores.
//      c. Have the main() function declare an array of CSIZE (with CSIZE = 4) student
//         structures and initialize the name portions to name of your choice. Use functions
//         to perform the tasks described in parts d., e., f., and g.
//
//      d. Interactively acquire scores for each student by prompting the user with a student
//         name and a request for scores. Place the scores in the grade array portion of the
//         appropriate structure. The required looping can be done in main() or in the
//         function, as you prefer.
//
//      e. Calculate the average score value for each structures and assign it to the proper
//         member.
//
//      f. Print the information in each strcuture.
//
//      g. Print the class average for each of the numeric structure members.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CSIZE 4
#define MAX 20
#define G 3

struct name {
	char	last[MAX];
	char	first[MAX];
};

struct student {
	struct name person;
	double grade[G];
	double aver;
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

void	norm(char *str)
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
/*
	This functioni(get_name) read the entered first name and last name, 
	then comparing first name with first names from our array 
	of structs.
	If first name was found, function will comparing last name 
	from this struct. 
	If last names are equal function return the index of struct
	else return (-1)
*/
int		get_name(const struct student * pnt)
{
	char 	f_name[MAX];
	char 	l_name[MAX];
	int		ind;

	ind = 0;
	puts("Enter first name and last name");
	scanf("%s %s", f_name, l_name);
	norm(f_name);
	norm(l_name);
	while (getchar() != '\n');
	while (ind < CSIZE)
	{
		if (strcmp(f_name, pnt[ind].person.first) == 0)
			if (strcmp(l_name, pnt[ind].person.last) == 0)
				return (ind);
		ind++;
	}
	return (-1);
}

void	get_grade(struct student * pnt)
{
	int		x;
	int		y;
	int		ind;
	
	y = 0;
	while (y < CSIZE)
	{
	    while ((ind = get_name(pnt)) < 0)
			printf("Enter correct data\n");
		printf("Enter Grade for %s %s\n", pnt[ind].person.first, pnt[ind].person.last);
		x = 0;
		while (x < G)
		{
			printf("grade №%i ", x + 1);
			scanf("%lf", &pnt[ind].grade[x]);
			while (getchar() != '\n');
			x++;
		}
		y++;
	}
}

void	count_average(struct student * pnt)
{
	int		x;
	int		y;

	y = 0;
	while (y < CSIZE)
	{
		x = 0;
		while (x < G)
		{
			pnt[y].aver += pnt[y].grade[x];
			x++;
		}
	pnt[y].aver = pnt[y].aver / x;
		y++;
	}
}

void	print_info(const struct student * pnt)
{
	int		x;
	int		y;

	y = 0;
	printf("%-20s %-20s \n", "FIRST NAME", "SECOND NAME");
	while (y < CSIZE)
	{
		x = 0;
		printf("%-20s %-20s  ", pnt[y].person.first, pnt[y].person.last);
		while (x < G)
		{
			printf("%5.2lf ", pnt[y].grade[x]);
			x++;
		}
		printf("%5.2lf\n", pnt[y].aver);
		y++;
	}
}

void	aver_class(const struct student * pnt)
{
	int		x;
	int		y;
	double  aver;
	
	x = 0;
	printf("\n%-43s", " ");      // aling to the column
	while (x < G)
	{
		aver = 0;
		y = 0;
		while (y < CSIZE)
		{
			aver += pnt[y].grade[x];
			y++;
		}
		printf("%5.2lf ", aver/(double)y);
		x++;
	}
	putchar('\n');
}

int		main(void)
{
	struct student class[CSIZE] = {
				{{"Kurdov", "Maxim"}, {0, 0, 0}, 0},				
				{{"Petrov", "Aleksei"}, {0, 0, 0}, 0},				
				{{"Ivanov", "Dmitrii"}, {0, 0, 0}, 0},				
				{{"Tiskov", "Genadii"}, {0, 0, 0}, 0},				
			};
	puts("Let's enter the grade for each student from this list");
	for (int i = 0; i < CSIZE; i++)
		printf("%-20s %20s\n", class[i].person.first, class[i].person.last);
	get_grade(&class[0]);
	count_average(&class[0]);
	print_info(&class[0]);
	aver_class(&class[0]);
	puts("Good Buy");
	return (0);
}
