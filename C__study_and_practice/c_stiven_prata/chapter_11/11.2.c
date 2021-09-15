//**************************************************************************** /
//                                                                            */
//                        #' ,#,    #    #  #.  .`#  #==,    .*.  + + +       */
// ~~~CREATED~~~         #  #   #  # #  #  # *.* #  #   #   *._.*    +        */
// ~~~~~BY~~~~~~    #. .#  #   #  #   ##  #     #  #  ,#    ,' ',   +         */
// ~<<jonmd87>>~     ###    '#'  #    #  #     #  #==*       *.*   +          */
//                                                                            */
//**************************************************************************** ///
//
// требуется разработать функцию которая принимает с устройства ввода N символов 
// или по достижению первого символа пробела, табуляции или новой строки
// и сохраняет их в массив адресс которого  был передан ей в качестве аргумента  
// затем все выводится на экран.
//
//
// created by jonmd87
//
//


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define NUM 100

int		save( char *ar);

int		main()
{
	char mass[NUM];
	int 	i;
	puts("HELLO!");
	puts("This programe will save the string, which you enter.");
	printf("was saved %d symbols.\n\n", save(&mass));
	puts("here they are:");
	while(mass[i])
	{
		putchar(mass[i]);
		i++;
	}
	putchar('\n');
	putchar('\n');
	puts("!!! Good Buy !!!");
	putchar('\n');
	return 0;
}


int save( char *ar)
{
	int i = 0;

	while((ar[i] = getchar())  != '\n' && !isblank(ar[i]) )
		i++;
	return (i);
}
