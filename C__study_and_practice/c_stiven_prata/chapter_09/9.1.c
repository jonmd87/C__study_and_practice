//
//
// программа запрашивает два числа типа double
// и с помощью функции min(double x, double y)
// возвращает наименьшее число
//
//
// 
// created by jonmd87
//
//

#include <stdio.h>

double minimum(double x, double y);   // this function calculates the minimum number
double check_num(void);        // this function checs the entered numbers

int main(void)
{
	double first;
	double second;
	
	printf("please enter two floating point numbers:\n");
	
	printf("first number:\n");              
	first = check_num();                   // scan and check first number
	
	printf("now enter second number:\n");       
	second = check_num();                   // scan and check second number
	
	minimum(first, second);	
	
	printf("!!! Good Buy !!!\n");
	
	return 0;
}

double check_num(void)
{
	
	double num;
	
	while( scanf("%lf", &num)  == -1 )
	{
		printf("only numbers\n");
		continue;
	}
	
	
	return num;
}



double minimum (double x, double y)
{
    double  min = 0;
	
      if(x < y)
         min = x;
     
      if else(y < x)
             min = y;  
     else 
         printf(" these numbers are equal \n");
     
     
     return min;
     
}
