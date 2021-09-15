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
// Требуется написать программу которая выводит аргументы командной
// строки в обратном порядке.
//
//

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str);
void	ft_putchar(char ch);

int 	main(int argc, char **argv)
{
	int		i;
	
	if (argc > 1)
	{
		i = argc - 1;
		while (i != 0)
		{
			ft_putstr(argv[i]);
			ft_putchar(' ');
			i--;
		}
		ft_putchar('\n');	
	}
	ft_putstr("!!!GOOD BUY!!!\n");
	return 0;
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}
