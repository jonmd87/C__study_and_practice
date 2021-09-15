
//
//
// 
// программа   выводит на экран меню
// 
//    а.сложение     b.умножение
//    c.вычитание    d.деление
//            e.выход
//
// пользователь должен выбрать действие нажав соответсвеющую букву,
// после программа просит пользователя ввести два числа, 
// программа проверяет введенные данные, числа ли это если да, 
// то производится вычисление и выводится на экран
// все повторяется пока пользователь не ввел е.выход
//
//
// created by jonmd87
//
//


#include<stdio.h>
#include<ctype.h>
#include <stdbool.h>

void menu(void);                 // display the menu
void clear_string(void);         // this function clening the string   
double check_num(bool fl);  	 // this function checks the entered number	
char check_char(void);           // this function checks entered charachtet



int main(void)
{	
	bool flag;
	char choose;

	double num1;
	double num2;

    printf("HEllo my dear user))!!!\n");
	menu();
	choose = check_char();

	while( choose != 'e' )
	{
		flag = false;
		clear_string();
		num1 = check_num(flag);
		flag = true;
		num2 = check_num(flag);

		switch(choose)
		{
			case 'a':
			printf("%.2lf + %.2lf = %.2lf \n", num1, num2, (num1 + num2) );
			break;

			case 's':
			printf("%.2lf - %.2lf = %.2lf \n", num1, num2, (num1 - num2) );
			break;

			case 'm':
			printf("%.2lf * %.2lf = %.2lf \n", num1, num2, (num1 * num2) );
			break;

			case 'd':
			printf("%.2lf / %.2lf = %.2lf \n", num1, num2, (num1 / num2) );
			break;
		}

		
		menu();
		clear_string();
		choose = check_char();
		continue;


	}


	printf("GOOD BUY !!!!!!\n");
	return 0;
}


void menu(void)
{
	
	        printf("\n\n");
		printf("please choose the arithmetic operation:\n");
		printf("***************************************\n");
		printf("*a)addition[+]       s)subtracyion[-] *\n");
		printf("*m)multiplication[*] d)division[/]    *\n");
		printf("*           e)exit                    *\n");
		printf("***************************************\n");

	return;
}



void clear_string(void)
{
	while( getchar() != '\n')
	return;
}



double check_num(bool fl)
{
	double a;
	printf("please enter %s number!!!\n", (!fl) ? "first" : "second");

	while( (scanf("%lf", &a)) != 1)
	{
		clear_string();
		printf("only numbers !!!!\n");
		continue;
	}
	return a;
}


char check_char(void)
{
	char ch;
	ch = getchar();
	ch = tolower(ch);
	
   
	while( ch != 'a' && ch != 's' && ch != 'm' && ch != 'd' && ch != 'e' )
	{
		clear_string();
		printf("only a, s, m, d, or e!!!!!!!\n");
		ch = getchar();
		ch = tolower(ch);
		
		
		continue;
	}
	return ch;
}



