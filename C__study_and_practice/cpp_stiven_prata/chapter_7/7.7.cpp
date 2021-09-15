#include <iostream>
#include <climits>
#include <cstring>

using namespace				std;

void 						calculate(const double n1, const double n2, double (*fun)(double, double));
double						add(const double num1, const double num2);
double						sub(const double num1, const double num2);
double						mul(const double num1, const double num2);
double						div(const double num1, const double num2);
int 							get_data(double *num1, double *num2);
int							get_number(double *num);

int							main(void)
{
	double					num1;
	double 					num2;
	double					(*pnt[5])(double, double);
	
	num1 = 0;
	num2 = 0;
	pnt[0] = add;
	pnt[1] = sub;
	pnt[2] = mul;
	pnt[3] = div;
	pnt[4] = NULL;
	int ind = 0;
	while ((get_data(&num1, &num2)) == 0)
		while (pnt[ind])
			calculate(num1, num2, pnt[ind++]);	
	cout << "Goodbye" << endl;
	return (0);
}

void 						calculate(const double n1, const double n2, double (*fun)(double, double))
{
	cout << "result of " << fun(n1, n2) << endl;
}

double						add(const double n1, const double n2)
{
	cout << " sum = ";
	return (n1 + n2);
}

double						sub(const double num1, const double num2)
{
	cout << " sub = ";
	return (num1 - num2);
}

double						mul(const double num1, const double num2)
{
	cout << " mul = ";
	return (num1 * num2);
}

double						div(const double num1, const double num2)
{
	cout << " div = ";
	return (num1 / num2);
}

int 							get_data(double *num1, double *num2)
{
	cout << "enter first number:\n";
	if ((get_number(num1)) == 1)
		return (1);
	cout << "enter second number:\n";
	if ((get_number(num2)) == 1)
		return (1);
	return (0);
}

int							get_number(double *num)
{
	char 					ch;
	
	ch = 0;
	cout << "for exit enter [q]:" << endl;
	while (!(cin >> *num))
	{
		cin.clear();
		ch = cin.get();
		if (tolower(ch) == 'q')
			return (1);
		cout << "only number(or [q] for exit)!!!\n";
		cin.ignore(INT_MAX, '\n');
	}
	return (0);
}
