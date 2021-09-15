//
//
// программа подсчитывает количество букв верхнего и нижнего регистра во входном тексте
// и выводит эту информацию на экран
//
//
// created by jonmd87
//
//

#include<stdio.h>
#include<ctype.h>

int main (void)
{
	char ch;
	int upper_case =0;
	int lower_case = 0;
	int all_ch = 0;

	while( (ch = getchar() ) != EOF)
	{
		if(isupper(ch))
			upper_case++;
		else if(islower(ch))
			lower_case++;
		else
			all_ch++;
	}

	printf("In this text is :\n");
	printf("all characters - %i\n", all_ch + upper_case + lower_case);
	printf("upper case - %i\n", upper_case);
	printf("lower case - %i\n", lower_case);

	return 0;
}