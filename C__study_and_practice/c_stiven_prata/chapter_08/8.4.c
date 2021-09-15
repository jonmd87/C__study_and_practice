//
//
// програма считывает входные данные и высчитывает 
// количество символов
// количество слов
// среднее количество букв на слово
// количество знаков препинания
// количество пробелов
// и выводит эту информацию на экран
//
//
// created by jonmd87
//
//

#include<stdio.h>
#include<ctype.h>

int main(void)
{
	long int let = 0;
	long int words = 0;
	long int punct = 0;
	long int spaces = 0;
	long int all_ch = 0;	

	char ch;
	char prev_ch;


	while ( (ch = getchar()) != EOF)
	{
		all_ch++;
		if(isalpha(ch))
		{
		 	let++;
			if(isspace(prev_ch) && isalpha(ch)) 
			words++;
		}
		else if(ispunct(ch))
			punct++;
		else
			spaces++;

		prev_ch = ch;
	}

	printf("Int this text is:\n");
	printf("all symbols - %li\n", all_ch);
	printf("letters - %li\n", let);
	printf("words - %li\n", words);
	printf("average number of letters per words - %li\n", let/words);
	printf("punctuation charachters - %li\n", punct);
	printf("spaces & new string - %li\n", spaces);

	printf("!!! Good buy!!!\n");
	return 0;
}