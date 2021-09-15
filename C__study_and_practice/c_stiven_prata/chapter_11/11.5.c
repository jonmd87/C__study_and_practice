//**************************************************************************** /
//                                                                            */
//                        #' ,#,    #    #  #.  .`#  #==,    .*.  + + +       */
// ~~~CREATED~~~         #  #   #  # #  #  # *.* #  #   #   *._.*    +        */
// ~~~~~BY~~~~~~    #. .#  #   #  #   ##  #     #  #  ,#    ,' ',   +         */
// ~<<jonmd87>>~     ###    '#'  #    #  #     #  #==*       *.*   +          */
//                                                                            */
//**************************************************************************** /
//
// требуется создать и потестировать функцию которая находит требуемый
// символ в строке. Функция принимает два параметра, 
// первый — указатель на строку,второй — искомый символ.
// если найден искомый символ, функция возвращает ненулевое 
// значение(true),если символ не найден функция возвращает(false)
// требуется использовать цикл для передачи входных значений 
// рассматриваемой функции
//
//
// created by jonmd87 
//
//


#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 1000

char *find_symb( char * ar, char letter);


int main()
{  
	char isk_symb;
	char mass[SIZE];
	char * point;
	int size;

	fputs("this program wiil find the symbol which you want, ", stdout); 
	puts("enter a designer symbol:");
	isk_symb = getchar();
	while(getchar() != '\n');
	printf("a designer symbol is \"%c\"\n", isk_symb);
	puts("please enter some text:");
	fgets(mass, SIZE, stdin);
	size = strlen(mass);
	for(int i = 0; i < size -1; i++)
		printf("value - %c; adress %p\n", mass[i], &mass[i]);

	printf("\n\nin this passage is %i characters.\n\n", strlen(mass));
	if(find_symb(&mass, isk_symb))
		printf("in this text program finded the letter \"%c\"\n",isk_symb);
	else 
		puts(" in this text not this letter!");
	return 0;
}

char	*find_symb(char * ar, char letter)
{
	while( *ar && *ar!= letter)
		ar++;
	if(*ar == letter)
		return (true);
	else 
		return (false);
}

