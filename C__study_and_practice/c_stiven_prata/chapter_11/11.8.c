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
// требуется создать функцию которая принимает строку как аргумент,
// и заменяет содержимое этой строки, этой же строкой но в обратном
// порядке.
// требуется протестировать эту функцию в программе используя цикл
// для передачи входных значении рассматриваемои функции.
//
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

char nw_str( char ar[]);
char change_string ( char *ar);

int main()
{
	char mas[SIZE];
	puts("enter the string");
	
	while( fgets(mas, SIZE, stdin) != NULL && mas[0]!= '\n' )
	{
		nw_str(mas);
		change_string(&mas);
		fputs(mas, stdout);
		putchar('\n');
	}
	
	
	puts(" !!! Good buy !!! ");
	return 0;
}


char change_string ( char *ar)
{
	char	mass[SIZE];
	int 	i;
	int 	f;

	i = 0;
	f = 0;
	while (*(ar+i))
	{
		mass[i] = *(ar+i);
		i++;
	}
	i--;
	while (i >= 0)
	{	
		ar[f] = mass[i];
		f++;
		i--;
	}

	return 0;
}

char nw_str( char ar[])
{
	while(*ar)
	{
		if(*ar == '\n')
			*ar ='\0';
		ar++;
	}
	return 0;
}
