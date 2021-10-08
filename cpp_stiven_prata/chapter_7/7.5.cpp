#include <iostream>

using namespace				std;

int 							fill_arr(double *arr, int max);
int							get_number(void);
void							show_arr(double *arr, int max);
void				reverse_arr(double *arr, int max, int f_ecl, int sec_ecl);

int 							main(void)
{
	double 					*arr;
	int						len;
	
	len = 0;
	while ((len = get_number()) > 0)
	{	
		arr = new double [len];
		len = fill_arr(arr, len);
		cout << "array before reverse:" << endl;
		show_arr(arr, len);
		reverse_arr(arr, len, 0, len - 1);
		cout << "array after reverse:" << endl;
		show_arr(arr, len);
		delete[] arr;
	}
	cout << "Goodbye!" << endl;
	return (0);
}


void				reverse_arr(double *arr, int max, int f_ecl, int sec_ecl)
{
	double		*temp;

	max -= 1;
	if (max > 0 && f_ecl > -1 && sec_ecl != f_ecl)
	{
		temp = new double[max];
		for (int ind = 0; ind <= max; ind++)
		{
			if (ind == f_ecl || ind == sec_ecl)
				temp[max - ind] = arr[max - ind];
			else
				temp[max - ind] = arr[ind];
		}
		for (int ind = 0; ind <= max; ind++)
			arr[ind] = temp[ind];
	}
	if (temp)
		delete[] temp;
}

int							get_number(void)
{
	int						num;
	char						ch;
	
	num = 0;
	ch = 0;
	cout << "enter len of arr:" << endl;
	while (!(cin >> num) || num < 1)
	{
		if (cin.fail())
		{
			cin.clear();
			if (cin >> ch)
				if (tolower(ch) == 'q')
					return (0);
		}
		cin.ignore(INT_MAX, '\n');
		cout << "only positive numbers, or [q] for exit:" << endl;
		cout << "enter len of arr:" << endl;
	}
	cin.ignore(INT_MAX, '\n');
	return (num);
}

int 							fill_arr(double *arr, int max)
{
	int						ind;
	
	ind = 0;
	cout << "Please, enter 1th number" << endl;
	while (ind < max && cin >> arr[ind])
	{
		ind++;
		cin.ignore(INT_MAX, '\n');
		if (ind < max)
			cout << "enter " << ind + 1 << "th number" << endl;
	}
	return (ind);
}

void 						show_arr(double arr[], int max)
{
	int						ind;
	
	ind = 0;
	while (ind < max && arr[ind])
		cout << ind + 1 << "t number [" << arr[ind++] << "]\n";
}
