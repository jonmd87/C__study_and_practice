#include <iostream>
using namespace std;

int				get_data(int *min, int *max)
{
	cout << "please enter number more then 0\n";
	cin >> *min;
	cout << "now enter number, more than " << *min << "\n";
	cin >> *max;
	return (*max - *min);
}

void				calculate(int min, int max)
{
	size_t 			res;
	
	res = 0;
	cout << "sum of all numbers beetwen " << min << " and " << max;
	while (min != max)
	{
		res += (size_t)min;
		min++;
	}
	res += (size_t)min;
	cout << " = [" << res << "]\n";
}

int				main(void)
{
	int 			min;
	int			max;
	
	min = 0;
	max = 0;
	if ((get_data(&min, &max)) > 0)
		calculate(min, max);
	else
		cout << "wrong input data\n";
	cout << "good bye\n";
	return (0);
}
