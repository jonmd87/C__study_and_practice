// write programe that calculate all entered numbers,
// programe will stop when user enter zero

#include <iostream>
using namespace std;

int 				main(void)
{
	int			num;
	int			res;
	
	num = 1;
	res = 0;
	while ( num != 0)
	{
		cout << "enter numer(zero for exit):\n";
		cin >> num;
		res += num;
		cout << " sum =[" << res << "]\n";
	}
	cout << "good bye\n";
	return (0);
}