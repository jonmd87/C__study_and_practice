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
// требуется создать и потестировать функцию которая находит требуемый символ в строке
// функция принимает два параметра, первый — строка, второй — искомый символ.
// если найден искомый символ, то функция возвращает указатель на этот символ
// если символ не найден функция возвращает 0
// требуется использовать цикл для передачи входных значений рассматриваемой функции
//
//
// created by jonmd87 
//
//


#include <stdio.h>
#include <string.h>
#include<ctype.h>
#define SIZE 1000

char	*find_symb( char  ar[], char letter);

int		main()
{  
	char	isk_symb;
	char	mass[SIZE];
	char	*point;
	int		size;

	
	puts("this program wiil find the symbol which you want, enter a designer symbol:");
	isk_symb = getchar();
	while(getchar() != '\n');
	printf("a designer symbol is \"%c\"\n", isk_symb);
	puts("please enter some text:");
	fgets(mass, SIZE, stdin);
	size = strlen(mass);
	for(int i = 0; i < size -1; i++)
		printf("value - %c; adress %p\n", mass[i], &mass[i]);
	printf("\n\nin this passage is %i characters.\n\n", strlen(mass));
	point = find_symb(mass, isk_symb);
		
	if(point)								
		printf(" in this text program finded the letter \"%c\" it's her adress %p \n",isk_symb, point);		
	else
		puts(" in this text not exist this letter!");
	return 0;
}

char *find_symb( char ar[], char letter)
{
	int	i;
	
	i = 0;
	while(ar[i] != letter && ar[i])
		i++;
	if(ar[i] == letter)
		return &ar[i];
	else 
		return 0;
}

