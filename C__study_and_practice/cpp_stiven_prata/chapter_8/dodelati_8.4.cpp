/*
** the header file is set:
** 
** const int LEN = 40;
** typedef struct s_golf {
** 		char fullname[LEN];
**		int	 handicap;
** }			  t_golf;
** 
** int	setgolf(t_golf &g);
** void setgolf(t_golf &g, const char *str, int hc);
** void handicap(t_golf &g, int hc);
** void showgolf(const t_golf &g);
**
** 	compil some files with this header file, first file must have descriptions 
** of functions that are in header file.
** second file must contain main function, in main function you have to releze
** all 	functions that are prototiped in header file.
** for example:
** you declare an array of struct t_golf, then you realeze loop that gets data
** for each structure in array, if was entered empty string taking data is stoped
** then your program must show all geted data.
*/


#include <iostream>

const int LEN = 40;
const int MAX = 10;

typedef struct			s_golf {
	char 				fullname[LEN];
	int					handicap;
}			 			t_golf;

int						setgolf(t_golf &g);
void					setgolf(t_golf &g, const char *str, int hc);
void					handicap(t_golf &g, int hc);
void					showgolf(const t_golf &g);

int						main(void)
{
	t_golf				golf[MAX];
	int 				ind;
	
	ind = 0;
	while (1)
	{
		while (ind < MAX || (setgolf(golf[ind]) > 0)
			ind++;
	}
	return (0);
}

int						setgolf(t_golf &g)
{
	char 				name[LEN];
	long int			num;
	
	std::cout << "please, enter the full name of player:" << std::endl;
	while (!(cin.getline(name, LEN - 1)))
	{
		std::cout << "please, enter the full name of player:" << std::endl;
	}
	while (!(cin >> g.handicap))
	{
		
	}
	return(0);
}
void					setgolf(t_golf &g, const char *str, int hc);
void					handicap(t_golf &g, int hc);
void					showgolf(const t_golf &g);
