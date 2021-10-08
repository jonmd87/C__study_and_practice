//
//
//
// программа запрашивает три аргумента, символ и два целых числа
// и выводит на экран сетку из введенного символа
// первое число это количество символов в строке
// второе число это количество строк
// 
//
// created by jonmd87 
//
//
//

#include <stdio.h>

int num_check();
void printing(char symb, int q, int s);

int main(void)
{
	char ch;
	int qua;     // quantity of symbols in string
	int str;     // quantity of strings
	
	printf("please enter the charachter would you like\n");
        scanf("%c", &ch);
        
        printf(" enter quantity of symbols:\n");
        qua = num_check();
        
        printf(" now enter quantity of strings:\n");
        str = num_check();
        
        printing(ch, qua, str);
        
	
	
	
	
	return 0;
}


int num_check()
{
	
	int num;
	scanf("%i", &num);
	while( num <= 1 )
	{
         	printf("only integer positive number!!!\n");
		scanf("%i", &num);
		continue;
	}
	
	return num;
	
}

void printing(char symb, int q, int s)
{ 
	
	
	for(int strings = 0; strings < s; strings++)
	{
		for(int qua = 0; qua < q; qua++)
		      printf("%c", symb);
		putchar('\n');
	}
	
	return ;
	
}
