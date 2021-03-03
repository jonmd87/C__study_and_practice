/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_filds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/02/19 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct		s_fild {
	unsigned int	a : 1;
	unsigned int	b : 2;
	unsigned int	c : 3;
	unsigned int	d : 4;
	
}					t_fild;

static void			show(unsigned int *num)
{
	puts("in show");
	if (num)
		printf("num[%u]\n", *num);
	*num = 257;
	puts("in show");
}

int					main(void)
{
	t_fild			fild;
	unsigned int	*p;

	p = NULL;
	fild.a = 1;
	fild.b = 3;
	fild.c = 7;
	fild.d = 15;
	printf("sizeof(unsignedINT)[%lu]\n", sizeof(unsigned int));
	printf("sizeof(fild)[%lu]\n", sizeof(fild));
	p = (unsigned int*)&fild;
	show(p);
	printf("fild.a[%u]\n", fild.a);
	printf("fild.b[%u]\n", fild.b);
	printf("fild.c[%u]\n", fild.c);
	printf("fild.d[%u]\n", fild.d);
	printf("unsigned int[%u]\n", *p);
//	printf("t_fild.a[%p]\n", &fild.a);	
//	printf("t_fild.b[%p]\n", &fild.b);	
//	printf("t_fild.c[%p]\n", &fild.c);	
//	printf("t_fild.d[%p]\n", &fild.d);	
	return (0);
}
