//
//
//
// функция harm_mean принимает два аргумента 
// в виде двух чисел с плавающей точкой
// и высчитывает среднее гармоническое число
//
//
// created by jonmd87
//
//

#include <stdio.h>

double harm_mean(double first, double second);
double num_check(); 

int main()
{
	double first;
	double second;
	
	printf("please enter two floating point numbers:\n");
	
	printf("first number:\n");              
	first = num_check();                   // scan and check first number
	
	printf("now enter second number:\n");       
	second = num_check();                   // scan and check second number
	
	
	printf("harmonic mean of nubers %.2lf & %.2lf = %.2lf",
	         first, second, harm_mean(first, second) );
	
	return 0;
}



double harm_mean(double first, double second)
{
	double result;
	
	result = 2/(1.0/first + 1.0/second);
	return result;
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
