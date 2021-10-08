#include <iostream>

using namespace std;

typedef struct 			s_str {
	char 				name[20];
	int					num;	
}						t_str;

t_str &	ft_swap(t_str &st);

int				main(void)
{
	t_str 		fst = {"evgen",0};
	t_str 		sec = {"ivan", 22};
 	cout << "num		:" << fst.num << endl;
 	ft_swap(fst);
	cout << "num		:" << fst.num << endl;
	ft_swap(ft_swap(fst));
	cout << "num		:" << fst.num << endl;
	ft_swap(fst) = sec;
	cout << "name		:" << sec.name << endl;
	cout << "num		:" << sec.num << endl;
	return (0);
}

t_str &	ft_swap(t_str &st)
{
	cout << "name		:" << st.name << endl;
	st.num++;
	return (st);
}