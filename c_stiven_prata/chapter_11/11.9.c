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
// Требуется написать функцию которая принемает строку в качестве 
// аргумента, и удаляет все пробелы из этой строки.
// Протестировать эту функцию в рамках программы, которая использует
// цикл для чтения строк до тех пор, пока не будет введена пустая строка.
// Программа должна применять эту функцию к каждой входной строке 
// и отображать результат на экране.
//
//

#include <stdio.h>

#define S 100

void	del_spaces(char *str);
int		ft_strlen(char *str);
void	del_new_str(char *str);

int 	main()
{
	char	mas[S];
	
	puts("Hello, this program will remove all spaces from incoming line");
	puts("For exit enter empty string");
	puts("OK, Let's start!!!");
	puts("Enter some words");
	while ((fgets(mas, S, stdin)) != NULL && mas[0] != '\n')
	{
		printf("%i\n", ft_strlen(mas));
		del_new_str(mas);
		printf("%i\n", ft_strlen(mas));
		del_spaces(mas);
		puts(mas);
		puts("enter another string:");
		printf("%i\n", ft_strlen(mas));
	}
	
	return (0);
}

void	del_spaces(char *str)
{
	char	temp_ch;
	int 	i;
	int		next;
	
	next = 0;
	i = 0;
	while (str[i])
	{
		if (str[next] == ' ' && str[next] != '\0')
		{
			while (str[next] == ' ')
				next++;
		}
		str[i] = str[next];
		if (str[next])
			next++;
		i++;
	}
}

int 	ft_strlen(char *str)
{
	int 	val;
	
	val = 0;
	while (str[val])
		val++;
	return (val);
}

void	del_new_str(char *str)
{
	while (*str != '\n')
		str++;
	if (*str = '\n')
		*str = '\0';
}
