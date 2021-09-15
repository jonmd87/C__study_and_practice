//
//
//
// программа подсчитвает количество символов во входных данных, пока не встретит EOF
//
//
// created by jonmd87
//
//


#include<stdio.h>

int main(void)
{
	int val = 0;
	char ch;

	while( (ch = getchar() )  != EOF)
	{
		putchar(ch);
		val++;
	}

	printf("\nIn this text is %i \n", val );

	return 0;
}