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
// Требуется содать функцию которая читает строки и прекращает чтение
// на десятой строке включительно или при появлении символа EOF,
// в зависимости от того, какое из этих событий произойдет первым.
// Функция должна предложить пользователю меню с пятью вариантами:
// 1) печать исходного списка строк
// 2) печать строк в виде упорядоченной последовательности в кодировке ASCII
// 3) печать строк в порядке  возрастания их длины
// 4) печать строк в порядке возрастания длины первого слова строки
// 5) выход из программы. 
// Меню должно выводиться на экран после выполнения каждой операции,
// указанной меню, пока пользователь не выберет вариант выхода из
// программы. Разумеется, программа должна выполнять все 
// указанные в меню задачи.
//
//


#include <unistd.h>
#include <stdio.h>

#define NUM_OF_CH 100       // the number of charachters
#define LIMIT 10

void 	read_str(char **str);
void 	menu();
int 	choose_variant();
int 	ft_strlen(char *str, char ch);
int 	ft_chcmp(const char c1, const char c2);
void	display(char **str);
void	sort_by_ascii(char **str);
void	sort_by_leight(char **str, char ch);
void	ft_putstr(char *str);
void	ft_putchar(char ch);

int 	main()
{
	char	arr[LIMIT][NUM_OF_CH];
	char	*pnt[LIMIT];
	int 	choose;
	int 	ind;
	
	ind = 0;
	ft_putstr("This program will displays text in select mode");
	ft_putchar('\n');
	while (ind < LIMIT)
	{
		pnt[ind] = &arr[ind];
		ind++;
	}
	read_str(pnt);
	while ((choose = choose_variant()) != 5)
	{
		if (choose < 5 && choose > 0)
		{
			switch(choose)
			{
				case 1:
					display(pnt);
					putchar('\n');
					break;
				case 2:
					sort_by_ascii(pnt);
					display(pnt);
					putchar('\n');
					break;
				case 3:
					sort_by_leight(pnt, '\n');
					display(pnt);
					putchar('\n');
					break;
				case 4:
					sort_by_leight(pnt, ' ');
					display(pnt);
					putchar('\n');
					break;
			}
		}
		while (getchar() != '\n');
		read_str(pnt);
	}
		
	if (choose == 5)
		ft_putstr("GOOD BUY");
	else
		ft_putstr("ERROR");
	return (0);
}

void 	read_str(char **str)
{
	int 	i;
	
	i = 0;
	puts("please, enter some text");
	while (i < LIMIT && fgets(str[i], NUM_OF_CH, stdin) != NULL && str[i][0] != '\n')
	{
		//del_new_str(str[i]);
		i++;
	}
	if (i > 0)
		puts("ok, lets start!\nchoose mode");
	else 
		puts("nothing turned in");
	menu();
}

void	menu()
{
	ft_putstr("please,select mode");
	ft_putchar('\n');
	ft_putstr("1) original");
	ft_putstr("                   ");
	ft_putstr("3) order for the length of the line");
	ft_putchar('\n');
	ft_putstr("2) ordered by ASCII");
	ft_putstr("          ");
	ft_putstr("4) in order the length of the first words");
	ft_putchar('\n');
	ft_putstr("                     ");
	ft_putstr("5) exit");
	ft_putchar('\n');
}

int 	choose_variant()
{
	int 	select;
	int 	rembr;
	
	rembr = 1;
	while (scanf("%i", &select) < 1 || select > 5)
	{
		if (rembr == 5)
		{
			rembr = 0;
			menu();
		}
		else
			ft_putstr("only [1] [2] [3] [4] [5]");
		rembr++;
		ft_putchar('\n');	
	}
	return (select);
}

int 	ft_chcmp(const char c1, const char c2)
{
	return (c1 - c2);
}

void	display(char **str)
{
	int		i;
	
	i = 0;
	while (str[i] != NULL && str[i][0] != '\n')
	{
		ft_putstr(str[i]);
		i++;
	}
}

void	sort_by_ascii(char **str)
{
	int 	i;
	int 	n;
	char	*temp;
	
	i = 0;
	while (str[i][0] != '\n')
	{
		n = i + 1;
		while (str[n][0] != '\n')
		{
			if (ft_chcmp(str[i][0],str[n][0]) > 0)
			{
				temp = str[i];
				str[i] = str[n];
				str[n] = temp;
			}
			n++;
		}
		i++;
	}
}

void	sort_by_leight(char **str, char ch)
{
	int 	i;
	int 	n;
	char	*temp;
	
	i = 0;
	while (str[i][0] != '\n')
	{
		n = i + 1;
		while (str[n][0] != '\n')
		{
			if (ft_strlen(str[i], ch) > ft_strlen(str[n], ch))
			{
				temp = str[i];
				str[i] = str[n];
				str[n] = temp;
			}
			n++;
		}
		i++;
	}
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int 	ft_strlen(char *str, char ch)
{
	int		val;
	
	val = 0;
	while (str[val] != ch)
		val++;
	return (val);
}
