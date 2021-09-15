#include <iostream>
using namespace std;

const double		simple = 0.10;
const double		difficult = 0.05;

int				calculate(double *dafna, double *kleo)
{
	int 			years;
	double		simple_dep;
	
	years = 0;
	simple_dep = *dafna;
	while (*kleo <= *dafna)
	{
		*kleo += (difficult * (*kleo));
		*dafna += (simple_dep * simple); 
		years++;
	}
	return (years);
}

int				main(void)
{
	double		dafna;
	double		kleo;
	int			years;
	
	dafna = 100.0;
	kleo = 100.0;
	years = calculate(&dafna, &kleo);
	cout << "after [" << years << "] years kleos deposite will be bigger ";
	cout << "to dafnas deposite\n";
	cout << "dafna deposite [" << dafna << "]\n";
	cout << " kleo deposite [" << kleo << "]\n";
	cout << "good bye\n";
	return (0);
}
