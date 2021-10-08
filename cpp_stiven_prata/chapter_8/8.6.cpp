/*
** create a template of function that take two arguments:
** 		*first argument is an array of elements T
** 		*second argument is a quantity of elements in array
** function must return a bigger value in array, if gave char arr,
** function must return a the longest string.
** check this function in program
**		first check with int array[6]
** 		second check with double arr[4]
** 		third check with char arrays[n][n]
** 
*/

#include <iostream>
#include <cstring>

const int			MAX = 5;

template <class Any>
Any		maxn(Any arr[]);

char	*maxi(char *str[],int len);

int 						main(void)
{
	double					arr_d[MAX] = { 2.8, 3.6, 0.2, 4.4, 0.3};
	int						arr_in[MAX] = { 1, 3, 2, 15, 45};
	char					arr[4][10] = {
						"aaa", "bbbbb", "ccccccc", "qqqqqqqq" };
	char 					***pt;

	pt = &arr;
	
	std::cout << "bigerr in integer array " << maxn(arr_in) << std::endl;
	std::cout << "bigerr in double array " << maxn(arr_d) << std::endl;
	std::cout << "bigerr in char array " << maxi(pt, 4) << std::endl;
	std::cout << "GoodBay!!!" << std::endl;
	return (0);
}

template <class Any>
Any							maxn(Any arr[])
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

char	*maxi(char *str[],int max)
{
	char 		*pnt;
	int 		ind;
	
	ind = 0;
	pnt = (char*)str[ind];
	while (++ind < max)
	{
		if (strlen(pnt) < strlen(str[ind]))
			pnt = (char*)str[ind];
	}
	return (pnt);
}
