//**************************************************************************** /
//                                                                            */
//                        #' ,#,    #    #  #.  .`#  #==,    .*.  + + +       */
// ~~~CREATED~~~         #  #   #  # #  #  # *.* #  #   #   *._.*    +        */
// ~~~~~BY~~~~~~    #. .#  #   #  #   ##  #     #  #  ,#    ,' ',   +         */
// ~<<jonmd87>>~     ###    '#'  #    #  #     #  #==*       *.*   +          */
//                                                                            */
//**************************************************************************** /
//
//
// Требуется создать функцию которая,
// возводит число с плавающей точкой (double) в степень.
// Эта програграмма принимает два аргумента:
// 1) число типа (double)
// 2) число тип (int)
//
//

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int 	ft_atoi(char *str);
double	ft_double_atoi(char *str);

int 	main(int argc, char **argv)
{
	int 	degree;
	double 	erected;
	double	res;
	
	if (argc == 3)
	{
		degree = ft_atoi(argv[2]);
		erected = ft_double_atoi(argv[1]);
		res = erected;
		while (degree > 1)
		{
			res *= erected;
			degree--;
		}
		printf("(%lf in %i) = %lf\n", erected, ft_atoi(argv[2]), res);
	}
	else
		ft_putstr("bad argument\n");	
	ft_putstr("GOOD BUY\n");
	return (0);
}

int 	ft_atoi(char *str)
{
	int 	degree;
	int 	minus;
	
	minus = 1;
	degree = 0;
	while(*str == ' ' || *str == '\t' || *str == 'n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+' )
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		degree = degree * 10 +(*str -'0');
		str++;	
	}
	return (degree * minus);
}

double	ft_double_atoi(char *str)
{
	double	erected;
	double	minus;
	int 	ifpoint;
	
	ifpoint = 0;
	minus = 1.0;
	erected = 0.00;
	while (*str == ' ' || *str == '\n' || *str == '\t' || 
			*str == '\f' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1.0;
		str++;
	}
	while ((*str >= '0' && *str <= '9') ||
	 (*str == '.' || *str == ',') && !(ifpoint))
	{
		if (*str == '.' || *str ==',')
		{ 
			ifpoint = 1;
			str++;
		}
		else
		{
			erected = erected * 10 + (*str - '0');
			str++;
			ifpoint *= 10;
		}	
	}
	if (ifpoint < 1)
		ifpoint = 1;
	return ((erected * minus) / (double)ifpoint);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}
