/*
** write a template of function that take an argument an array.
** this array has five elements.
** function must find ansld return the bigger value in this array.
** check this function in program:
** first array will be int, second array wil be double
** 
*/

#include <iostream>

const int			MAX = 5;

template <class Any>
Any		max5(Any arr[]);

int 						main(void)
{
	double					arr_d[MAX] = { 2.8, 3.6, 0.2, 4.4, 0.3};
	int						arr_in[MAX] = { 1, 3, 2, 15, 45};
	
	std::cout << "bigerr in integer array " << max5(arr_in) << std::endl;
	std::cout << "bigerr in double array " << max5(arr_d) << std::endl;
	std::cout << "GoodBay!!!" << std::endl;
	return (0);
}

template <class Any>
Any							max5(Any arr[])
{
	Any						temp;
	int						ind;
	
	ind = 0;
	temp = arr[0];
	while (ind < MAX)
	{
		if (arr[ind] > temp)
			temp = arr[ind];
		ind++;
	}
	return (temp);
}
