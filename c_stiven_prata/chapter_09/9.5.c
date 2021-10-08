//
//
//
// программа тестирует функцию large_of, 
// в свою очередь функция large_of 
// заменяет содержимое двух переменных типа double 
// большим значением из этих двух переменных
//
//
// created by jonmd87
//
//


#include <stdio.h>

void large_of(double * x, double * y);
double num_check(void);

int main()
{
	double first;
	double second;
	
	
     printf(" this program assigns a larger value to the two variables received\n");
     printf("please enter two float numbers, ");
     printf("first number:\n");
     first = num_check();
     
     printf("now enter second number:\n");
     second = num_check();
     
     printf(" first number = %.2lf\nsecond number = %.2lf\n", first, second);
     printf("now function \"large_of\" will calculate the largest number and assign it to both variables.");
     
     large_of(&first, &second);
     printf("\nfirst number = %.2lf\nsecond number = %.2lf\n", first, second);
     
     
     
	
	return 0;
}



void large_of(double * x, double * y)
{
	if(*x < *y)
	     *x = *y;
	else
	    *y = *x;
	
	return;
	
}



double num_check()
{
	
	double num;
	
	while( scanf("%lf", &num) != 1 )
	{
         	printf("only number!!!\n");
		
		continue;
	}
	
	return num;
	
}
