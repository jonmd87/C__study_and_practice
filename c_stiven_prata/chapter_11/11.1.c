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
// требуется разработать функцию которая принимает с устройства ввода N символов 
// ( буквы цифры пробелы знаки пунктуации знак новой строки)
// и сохраняет их в массив адресс которого  был передан ей в качестве аргумента  
//
//



#include <stdio.h>
#include <string.h>
#define NUM 10

int		save(char *ar, int val);

int		main()
{
	int		val;
	char	mass[NUM];
	char	*pnt;
	
	pnt = mass;
	
	puts("HELLO!");
	puts("This programe will save the string, which you enter.");
	val = save(&mass, NUM);
	pnt = mass;
	printf("was saved %d symbols.\n", val );
	puts("here they are:");
	while(*pnt)
		putchar(*pnt++);
	putchar('\n');
	printf("\nmass === %s\n", mass);
	puts("!!! Good Buy !!!");
	return 0;
}


int		save( char *ar, int val)
{
	int i = 0;
	
	while ((ar[i] = getchar()) != '\n')
		i++;
	return i;
}
