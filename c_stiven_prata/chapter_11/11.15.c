//**************************************************************************** /
//                                                                            */
//                        #' ,#,    #    #  #.  .`#  #==,    .*.  + + +       */
// ~~~CREATED~~~         #  #   #  # #  #  # *.* #  #   #   *._.*    +        */
// ~~~~~BY~~~~~~    #. .#  #   #  #   ##  #     #  #  ,#    ,' ',   +         */
// ~<<jonmd87>>~     ###    '#'  #    #  #     #  #==*       *.*   +          */
//                                                                            */
//**************************************************************************** /
//
// Требуется написать программу которая принимает входные данные
// пока не встретит конец файла(EOF), и выводит эти данные на экран
// Программа распознает и реализовывает следующие аргументы 
// командной строки:
// -p Печать входных данных в оригинале.
// -u Печать входных данных преобразованных в верхний регистр
// -l Печать входных данных преобразованых в нижний регистр
//
//

#include <unistd.h>
#include <stdio.h>

#define P "-p"
#define U "-u"
#define L "-l"

void	ft_putchar(char c);
void	ft_putstr(char * str);
void	ft_upper(char *str);
void	ft_lower(char *str);
int 	ft_strcmp(char *s, char *s2);

int 	main(int argc, char ** argv)
{
	char	ch;
	
	
	if (argc == 2)
	{
		if ((ft_strcmp(argv[1], P)) == 0)
		{
			while ((ch = getchar()) ! = EOF)
				ft_putchar(ch);
		}
		else if ((ft_strcmp(argv[1], U)) == 0)
		{
			while ((ch = getchar()) ! = EOF)
				ft_upper(ch);
		}
		else if ((ft_strcmp(argv[1], L)) == 0)
		{
			while ((ch = getchar()) ! = EOF)
				ft_lower(ch);
		}
		else
			ft_putstr("bad flag\n");
	}
	else
		ft_putstr("bad comand\n");
	return (0);
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

void 	ft_upper(char *str)
{
	while (*str != EOF)
	{
		if (*str >= 'a' && *str <= 'z')
			ft_putchar(*str - 32);
		else
			ft_putchar(*str);
		str++;
	}
}

void	ft_lower(char *str)
{
	while (*str != EOF)
	{
		if (*str >= 'A' && *str <= 'Z')
			ft_putchar(*str + 32);
		else 
			ft_putchar(*str);
		str++;
	}
}

int 	ft_strcmp(char *s, char *s2)
{
	while (*s && *s2 && (*s == *s2))
	{
		s++;
		s2++;
	}
	return (*s - *s2);
}
