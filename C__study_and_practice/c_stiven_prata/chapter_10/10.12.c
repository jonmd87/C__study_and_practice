//
//
// требуется создать программу которая:
// запрашивает у пользователя три набора по пять чисел типа double
// эти три набора программа записывает в массив 3x5
// программа выполняет следующее:
// вычислить среднее значение каждого набора из пяти чисел
// вычислить среднее значение всех чисел
// определить наибольшее и наименьшее значение из всех чисел
// вывести все результаты вычислений на дисплей 
//
//
// created by jonmd86
//
//


#include<stdio.h>
#define S 3
#define C 5

double save_ar(double ar[][C], int string);
double average_val_str( const double *ar, int string);
double av_val_ar(const double ar[][C], int string);
double print_ar( const double ar[][C], int string);


int main()
{
	double mas1[S][C];
	
	printf("now enter the double numbers(3x5):\n");
	save_ar(mas1, S);
	printf("\n\n your array looks like this: \n");
	print_ar(mas1, S);
	
	//printf("the average value = %.2lf\n\n", av_val_ar(mas1, S));
	
	printf("first string = %.2lf\n", average_val_str(mas1[0], 0));
	printf("second string = %.2lf\n", average_val_str(mas1[1], 1));
	printf("third string = %.2lf\n", average_val_str(mas1[2], 2));
	
	
	
	
	return 0;
}


double save_ar(double ar[][C], int string)
{
	for( int str = 0; str < string; str ++)
	{
		printf(" now enter %i string: \n", str + 1);
		 
		for(int col = 0; col < C; col++)
		{ 
			printf("enter %i element \n", col + 1);
			scanf("%lf", &ar[str][col]);
		}
	}
	
	return 0;
}

double print_ar( const double ar[][C], int string)
{
	
	for(int str = 0; str < string; str++)
	{
		for( int c = 0; c < C; c++)
			printf("%.2lf \t", ar[str][c]);
		putchar('\n');
	}
	
	return 0;
}


double average_val_str( const double *ar, int string)
{
	double val;
	
			for(int col = 0;col < C; col++)
				val += ar[col];

	
	return val;
}


double av_val_ar(const double ar[][C], int string)
{
	double val;
	
	for(int str = 0, val = 0; str < string; str++)
	{
		for(int col = 0; col < C; col++)
		 val += ar[str][col];
		
	}
	
	
	return val;
}
