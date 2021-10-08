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
// требуется разработать функцию которая считывает первое слово игнорируя 
// остальную часть строки. Слово это последовательность любых символов,
// без символов пробела, символов табуляции и символов новой строки.
//
//
// created by jonmd87
//
//


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 100

void word( char  *ar); // this function save the first word in array! 

int main()
{
	char mas[SIZE];
	
	puts("please, enter some words:");
	word(mas);
	putchar('\n');
	printf("first word : %s", mas);
	
	putchar('\n');
	puts(" !!! Good BUY !!!");
	
	
	return 0;
}

void word( char  *ar)
{
	int i; 
	
	while((ar[i] = getchar()) != NULL && (ar[i] != ' ' && ar[i] != '\n' && ar[i] != '\t'))
		i++;
}
