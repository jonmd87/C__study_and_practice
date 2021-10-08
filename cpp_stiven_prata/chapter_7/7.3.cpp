#include <iostream>
#include <cstring>

using namespace 				std;
const unsigned int				L = 40;
const char					*name = "Bboxes";

typedef struct					s_box{
	char						maker[L];
	double						height;
	double						width;
	double						lenth;
	double						volume;
}								t_box;

void							make_volume(t_box *box)
{
	if (box)
		box->volume = box->height * box->width * box->lenth;	
}

void							show_data(t_box *box)
{
	cout << " Maker:		" << box->maker << endl;
	cout << "height:		" << box->height << endl;
	cout << " width:		" << box->width << endl;
	cout << " lenth:		" << box->lenth << endl;
	cout << "volume:		" << box->volume << endl;
}

void						init(t_box *box)
{
	strncpy(box->maker, name, strlen(name) + 1);
	box->height = 4;
	box->width = 6;
	box->lenth = 2;
	box->volume = 0;
}

int							main(void)
{
	t_box					box;
	
	init(&box);
	make_volume(&box);
	show_data(&box);
	return (0);
}
