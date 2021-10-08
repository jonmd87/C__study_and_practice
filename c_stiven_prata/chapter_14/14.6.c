// A text file holds information about a softball team. Each line has data arranged as
// follows:
//
// 4 Jessie Joybat 5 2 1 1
//
// The first item is the player's number, conveniently in the range 0-18. The second item
// is the player's first name, and the third is the player's last name. Each name is a single
// word. The next item is the player's official times at bat, followed by the number of hits,
// walks, and runs batted in (RBIs). The file may contain data for more than one game,
// so the same player may have more than one line of data, and there may be data for
// other players between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and last names, the
// at bats, hits, walks, and RBIs (runs batted in), and the batting aevrage (to be calculated
// later). You can use the player number as an array index. The program should read to end-
// of-file, and it should keep cumulative totals for each player.
//
// The world of baseball statistics is an involved one. For eaxmple, a walk or reaching base
// on an error doesn't count as an at-bat but could possibly produce an RBI. But all this
// program has to do is read and process the data file, as described next, without worrying
// about how realistic the data is.
//
// The simplest way for the program to proceed is to initialize the structure contents to
// zeros, read the file data into temporary variables, and then add them to the contents of
// the corresponding structure. After the program has finished reading the file, it should
// then calculate the batting average for each player and store it in the corresponding
// structure member. The batting average is calculated by dividing the cumulative number
// of hits for a player by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each player along
// with a line showing the combined statistics for the entire team.


#include <stdio.h>
#include <stdlib.h>

#define MAX 30
#define I 4 
#define TEAM 19

struct 	person {
	int		num;
	char	name[MAX];
	char	last[MAX];
	int		arr[I];
	double	aver;
};

FILE  * fd;

void	initial(struct person * pnt)
{
	int		y;
	int		x;

	y = 0;
	while (y < TEAM)
	{
		pnt[y].num = - 1;
		x = 0;
		while (x < I)
		{
			pnt[y].arr[x] = 0;
			x++;
		}
		pnt[y].aver = 0;
		y++;
	}
}

void	replace(char * str, const char target, const char rep)
{
	while (*str)
	{
		if (*str == target)
			*str = rep;
		str++;
	}
}

void	get_name(char * str)
{
	puts("Please enter name of file which I need to read");
	fgets(str, MAX - 1, stdin);
	replace(str, '\n', '\0');
}

void	open_file(const char *str)
{
	if ((fd = fopen(str, "r")) == NULL)
	{
		fprintf(stderr, "error: can not open file [%s]\n", str);
		exit(1);
	}
	else
		printf("File [%s] opened\n", str);
}

double	make_aver(const int	* arr)
{
	return ((double)arr[1] / (double)arr[0]);
}

int		copy_in_file(struct person * pnt)
{
	int		y;
	int		x;
	int		ind;
	int		temp_int;
	char 	temp[MAX];

	y = 0;
	while (y < TEAM && fscanf(fd, "%i", &ind) != EOF)
	{
		ind -= 1;    // here function read the number of player, then this (number -1) is used as struct index
		if (pnt[ind].num == ind + 1) // if there was such a player's number then skip the first and last name
		{
			fscanf(fd, "%s", temp);
			fscanf(fd, "%s", temp);
		}
		else
		{
			pnt[ind].num = ind + 1;
			fscanf(fd, "%s", pnt[ind].name);
			fscanf(fd, "%s", pnt[ind].last);
			y++;
		}
		x = 0;
		while (x < I)
		{
			fscanf(fd, "%i", &temp_int);
			pnt[ind].arr[x] += temp_int;
			x++;
		}	
		pnt[ind].aver = make_aver(&pnt[ind].arr[0]);
	}
	return (y);
}

void	print_info(const struct person * pnt, const int * max)
{
	int		y;
	int		x;
	int		team_res[I] = {0, 0, 0, 0};
	
	y = 0;
	while (y < *max)
	{
		x = 0;
		printf("%-3i %10s %-20s %-9s", pnt[y].num, pnt[y].name, pnt[y].last, " ");
		while (x < I)
		{
			printf("%i ", pnt[y].arr[x]);
			team_res[x] += pnt[y].arr[x];
			x++;
		}
		printf("%10.2lf\n", pnt[y].aver);
		y++;
	}
	x = 0;
	printf("\n\n%-44s", "TEAM RESULT");
	while (x < I)
		printf("%i ", team_res[x++]);
	putchar('\n'); 
}

void	close_file(const char * name)
{
	if (fclose(fd) != 0)
	{
		fprintf(stderr, "error: can not close file [%s]\n", name);
		exit(2);
	}
	else
		printf("File [%s] closed\n", name);
}

int		main(void)
{
	struct person team[TEAM];
	char	file_name[MAX];
	int		ind;

	initial(&team[0]);
	get_name(file_name);	
	open_file(file_name);
	ind = copy_in_file(&team[0]);
	print_info(&team[0], &ind);
	close_file(file_name);
	return (0);
}
