//
//
//
// программа считывает входные данные пока не встретит EOF
// и выводит на экран символ и его десятичное значение ASCHI 
// выодится по 10 символов в строке,
// но как встретится символ новой строки то вывод начинается с новой строки
// если это пробел то печатается || 
// символы новой строки и табуляции  \n и \t
// и соответственно колличество символов
//
//
// created by jonmd87
//
//


#include<stdio.h>

int main(void)
{
	int count = 0;
	int val = 0;
	char ch;

	while( (ch = getchar() )  != EOF)
	{
		val++;
		if(ch == '\n')
			{
				printf("\n \\n - \\n \n");
				count = 0;
			}
		else if(ch == '\t')
		{
			printf("\\t - \\t * ");
			count++;
		}
		else if(ch == ' ')
			{
				printf("sp - sp * ");
				count++;
			}
		else
			{
				putchar(ch);
				printf(" - %i * ", ch);
				count++;
			}	

		if(count > 7)
			{
				printf("\n");	
				count = 0;
			}	
	}

	printf("\nIn this text is %i \n", val );

	return 0;
}