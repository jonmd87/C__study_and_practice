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
// Требуется написать и протестировать в цикле функции,
// которая возвращает количество ее вызовов.
//
//

#include<unistd.h>
#include<stdio.h>

int		number_of_call;

#define STR "hello \"great\" RUSSIA"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		main()
{
	int		user_call;

	ft_putstr("enter number of call\n");
	scanf("%i", &user_call);
	while (number_of_call <= user_call)
	{
		ft_putstr(STR);
		ft_putchar('\n');
		number_of_call++;
	}
	printf("%i - call of function\n", number_of_call);
	return (0);
}
