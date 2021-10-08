//**************************************************************************** /
//                                                                            */
//                        #' ,#,    #    #  #.  .`#  #==,    .*.  + + +       */
// ~~~CREATED~~~         #  #   #  # #  #  # *.* #  #   #   *._.*    +        */
// ~~~~~BY~~~~~~    #. .#  #   #  #   ##  #     #  #  ,#    ,' ',   +         */
// ~<<jonmd87>>~     ###    '#'  #    #  #     #  #==*       *.*   +          */
//                                                                            */
//**************************************************************************** /
//
//С помощью функций классификации символов создайте
//  свою реализацию функции atoi().
//
//


#include <unistd.h>
#include <stdio.h>

int 	ft_atoi(char *str);

int 	main(int argc, char ** argv)
{
	int 	i;
	
	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			printf("%i\n", ft_atoi(argv[i]));
			i++;
		}
	}
	printf("GOOD BUY\n");
	return 0;
}

int 	ft_atoi(char *str)
{
	int 	res;
	int		min;
	
	res = 0;
	min = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * min);
}
