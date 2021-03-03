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
// требуется написать и протестировать функцию,
// подобную strncpy( s1, s2, n)которая копирует  n символов
// из строки s2 в строку s1, усекая при необходимости строку s2
// либо заполняет пустые ячейки нулевыми символами
// целевая строка может и не содержать нулевой символ
// если длина строки s2 больше или равна n, функция возвращает 
// строку s1. Протестировать ее в основной программе
//
//

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define SIZE 10
#define S 1000

char string_copy(char * ar1, char *ar2, int num);
void	del_new_string(char *str);

int main()
{
	char mas1[SIZE] = "freddyKry";
	char mas2[S];
	int size;
	
	puts("this program will check the function \"string_copy\"");
	printf("first string \n%s\n", mas1);
	printf("enter second string\n");
	fgets(mas2, S, stdin);
	del_new_string(mas2);
	string_copy(mas1, mas2, SIZE);
	printf("my function:\n%s\n", mas1);	
	puts("\n!!! Good Buy !!!\n");
	return 0;
}


char	string_copy(char *ar1, char *ar2, int num)
{
	int i;
	
	i = 0;
	if (strlen(ar2) >= num)
		return ar1;
	else 
	{
		while (ar2[i])
			ar1[i] = ar2[i++];
		if (i <= num)
			while (i != num)
				ar1[i++] = '\0';
	}
		return (0);
}

void	del_new_string(char *str)
{
	while (*str != '\n')
		str++;
	if (*str == '\n')
		*str = '\0';
}
