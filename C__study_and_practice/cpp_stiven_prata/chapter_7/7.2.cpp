#include <iostream>

using namespace				std;

const int						LEN = 10;

int 							get_data(double arr[], int  	max);
void 						show_data(double arr[], int  max);
double						make_average(double arr[], int max);

int							main(void)
{
	int						len;
	double					golf[LEN];
	
	len = LEN;
	cout << "enter  " << len << " scores(or letter for exit):" << endl;
	while (get_data(&golf[0], len) == 0)
	{
		show_data(&golf[0], len);
		cout << "\naverage of " << len << " matches is ";
		cout << make_average(&golf[0], len) << endl;
		len = LEN;
		cout << "enter next " << len << " scores(or letter for exit):" << endl;
	}
	cout << "Goodbye" << endl;
	return (0);
}


double						make_average(double arr[], int max)
{
	double 					res;
	int						ind;
	
	res = 0;
	ind = 0;
	while (ind < max)
		res += arr[ind++];
	return (res / (double)max);
}

void 						show_data(double arr[], int  max)
{
	int 						ind;
	
	ind = 0;
	while (ind < max)
		cout << "[" << arr[ind++] << "] ";
}

int 							get_data(double arr[], int  max)
{
	int						ind;
	
	ind = 0;
	cout << "enter 1th result\n";
	while (ind < max)
	{
		cin >> arr[ind];
		if (cin.fail() == true)
			return (1);
		else
			ind++;
		cout << "enter " << ind + 1 << "th result\n";
	}
	return (0);
}
