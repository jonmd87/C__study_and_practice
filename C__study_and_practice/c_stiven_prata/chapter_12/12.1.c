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
// Требуется создать программу которая требует от пользователя угадать число
//
//
//

#include<unistd.h>
#include<stdio.h>

#define NUM 45

void try(int *num)
{
	int		temp_num;
	scanf("%i", &temp_num);
	*num = temp_num;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while(*str)
		ft_putchar(*str++);
}

int	main(void)
{
	int	user_num;
	
	ft_putstr("Hi, try to guess my age\n");
	scanf("%i", &user_num);
	while (user_num != NUM)
	{
		ft_putstr("let's try again\n");
		try(&user_num);
	}
	if (user_num == NUM)
		ft_putstr("!!!! you guessed it, I'll believed in you!!!!\n");
	ft_putstr("GOOD BUY\n");
	return (0);
}
