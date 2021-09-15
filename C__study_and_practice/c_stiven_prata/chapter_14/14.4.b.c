// Write a program that creates a structure template with two members according to the
// following criteria:
//      a. The first member is a social security number. The second number is a structure
//         with three members. Its first member contains a first name, its second member
//         contains a middle name, and its final member contains a last name. Create and
//         initialize an array of five such structures. Have the program print the data in this
//         format:
//
//         Dribble, Flossie M. -- 302039823
//
// Only the initial letter of the middle name is printed, and a period is added. Neither the
// initial (of course) nor the period should be printed is the middle name member is empty.
// Write a function to do the printing; pass the structure array to the function.
//      b. Modify part a. by passing the structure value instead of the address.


				// Write a program that creates a structure template with two members according to the
// following criteria:
//      a. The first member is a social security number. The second number is a structure
//         with three members. Its first member contains a first name, its second member
//         contains a middle name, and its final member contains a last name. Create and
//         initialize an array of five such structures. Have the program print the data in this
//         format:
//
//         Dribble, Flossie M. -- 302039823
//
// Only the initial letter of the middle name is printed, and a period is added. Neither the
// initial (of course) nor the period should be printed is the middle name member is empty.
// Write a function to do the printing; pass the structure array to the function.
//      b. Modify part a. by passing the structure value instead of the address.


				/*  PART A */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define CH 40
#define V 5

struct name {
	char	first[CH];
	char	middle[CH];
	char	last[CH];
};

struct data {
	unsigned int ssn;
	struct name person;
};

void	print_info(const struct data temp)
{
		int		ind;
	
		ind = 0;
		while (ind < V)
		{
			if (isalpha(temp[ind].person.middle[0]))
				printf("%s, %s  %c.  -- %-25i\n",
						 temp[ind].person.last, temp[ind].person.first, temp[ind].person.middle[0], temp[ind].ssn);
			else
				printf("%5s, %s %c  -- %i\n",
						 temp[ind].person.last, temp[ind].person.first, ' ', temp[ind].ssn);
			ind++;
		}
}

int		main(void)
{
	struct data arr[V] = {
				{402036353, {"Ivan", "", "Kurdov"}},
				{312834823, {"Petr", "Vasilievich", "Bulochikin"}},
				{242036823, {"Anton", "", "Mamaev"}},
				{572439923, {"Grigorii", "Fedorovich", "Arshavin"}},
				{102036988, {"Maxim", "Alexeevich", "Pavliuchenko"}},
						};
	
	print_info(&arr[0]);
	puts("Good Buy");
	return (0);
}
