#include <iostream>


using namespace				std;

template <typename T>
void	ft_swap(T &a, T &b);

int							main(void)
{
	int	a = 10;
	int 	b = 6;
	cout << "int a = " << a << endl;
	cout << "int b = " << b << endl;
	ft_swap(a, b);
	cout << "int a = " << a << endl;
	cout << "int b = " << b << endl;
	double da = 1.5;
	double db = 58.7;
	cout << "double a = " << da << endl;
	cout << "double b = " << db << endl;
	ft_swap(da, db);
	cout << "double a = " << da << endl;
	cout << "double b = " << db << endl;
	return (0);
}

template <class T>
void	ft_swap(T &a, T &b)
{
	T 		temp;
	temp = a;
	a = b;
	b = temp;
}
