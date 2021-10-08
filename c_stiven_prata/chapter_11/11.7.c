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
// Требуется создать функцию string_in которая принимает в качестве
// аргумента два указателя на строки функция должна найти строку s1 
// в строке s2, если строка найдена то функция возвращает адресс с
// которого начинается строка s2 в строке s1. Если соответсвия
// не найдны то функция возвращает нулевой указатель
// Функцию необходимо тестировать в рамках завершенной программы, 
// которая использует цикл для передачи входных значений.
//
//


#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1000
#define STOP "quitEXIT"

void	del_ne_string(char *str, char ch);
char *ft_strstr(char *str, char *to_find);

int		main()
{
	char 	mas1[SIZE];
	char 	mas2[SIZE];
	char 	*pnt;
	int 	i;
	
	i = 0;
	puts("this program will check the function \"string_in\"");
	puts("function \"string_in\", takes two arguments as strings");
	puts("function searches for the second string in first string,");
	puts("you need enter two strings");
	puts("first line is introduced once, but the second is entered many times");
	puts("to the end the program enter empty string.");
	puts("enter first string");
	fgets(mas1, SIZE - 1, stdin);
	puts("ok, now enter second string:");
	while( fgets(mas2, SIZE - 1, stdin) != NULL &&  mas2[0]!= '\n' )
	{
		del_ne_string(mas1, '\0');
		del_ne_string(mas2, '\0');
		if (pnt = ft_strstr(&mas1, &mas2))
		{
			while(mas1[i])
			{
				printf("[%c] == [%p]\n", mas1[i], &mas1[i]);
				i++;
			}
			printf("main  %p \n", pnt);
			for(; *pnt; pnt++)
				putchar(*pnt);
		}
		else
			puts("nothing");
		puts("OK! now enter another string. ");		
	}
	puts(" !!! Good Buy !!! ");
	return 0;
}

void	del_ne_string(char *str, char ch)
{
	while(*str != '\n')
		str++;
	if(*str == '\n')
		*str = ch;
}

char *ft_strstr(char *str, char *to_find)
{
	int s;
	int f;
	char *pnt;
	
	s = 0;
	while(str[s] != '\0')
	{
		if(str[s] == *to_find)
		{
			pnt = &str[s];
			f = 0;
			while(to_find[f] == *pnt)
			{	
				pnt++;
				f++;
			}
			if(to_find[f] == '\0')
				return &str[s];
		}
		s++;
	}
	return (NULL);
}
