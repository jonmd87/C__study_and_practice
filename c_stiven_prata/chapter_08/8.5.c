//
//
//
// программа пытается отгадать число загаданное пользователем
// используется бинарный поиск
//
//
// created by jonmd87
//
//

#include<stdio.h>
#include<ctype.h>
#define HIGH_NUM 100
#define LOW_NUM 0

 
void menu(void);    // this function display menu
char check_answer (void);  // function for checks
void clean_string(void);       // this function discards the unnecessary characters
int guess_number (int number);


int main (void)
{
	int num = HIGH_NUM / 2;
	int max = HIGH_NUM;
	int min = LOW_NUM;
	int last_num = num;
	char answer;


	menu();
	answer = check_answer();

	while(answer != 'Q')
	{
		printf("The guess number is %i ?\n Y/N\n", num);
		clean_string();
		if (check_answer() == 'Y')
		{
			printf("Continue?\nY/N\n");
			clean_string();
			if (check_answer() == 'N')
			{
				answer = 'Q';
				continue;
			}	
			else
			{
				num = HIGH_NUM / 2;
	            max = HIGH_NUM;
	            min = LOW_NUM;
				continue;
			}
		}

		else
		{
			printf("more or less?\n [*Y*](more{больше})  /   [*N*](less{меньше})\n");
			clean_string();
			
			oif(check_answer() == 'Y')
				{
					min = num;
					num = min + (max - min)/2; 
					continue;
				}	
			else
				{
					max = num;
					num = num -((max - min)/2);
					continue;
				}	

		}

	}



	printf("!!!Good Buy!!!\n");
	return 0;
}


void menu(void)
{
	printf("Hello, make a number from %i to %i :\n", LOW_NUM, HIGH_NUM);
	printf("If number is guessed, press:\n");
	printf("[Y] - Yes\n");
	printf("[N] - No\n");
	printf("[Q] - Quit\n");

	return ;
}

char check_answer ()
{	


	char ch;

	ch = getchar();
	ch = toupper(ch);

	while(ch != 'N' && ch != 'Y' )
	{
		clean_string();
		printf("I andestand only [Y] or [N]\n");
		ch = getchar();
		ch = toupper(ch);

	}


	return ch;
}



int guess_number (int number)
{
	int conj;         // conjecture number

	conj = number / 2;

	return conj;
}

// this function discards the unnecessary characters
void clean_string(void)
{
	while(getchar()!= '\n')
	continue;

	return;
}

























