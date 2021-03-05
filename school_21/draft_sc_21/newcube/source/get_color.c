/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:20:06 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/02 17:15:04 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_texture	*get_texture(t_info *f, int *xx)
{
	t_texture		*txt;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;

	no = &f->map->map[((int)f->y + 1) / 64][(int)f->x/64];
	so = &f->map->map[((int)f->y - 1) / 64][(int)f->x/64];
	we = &f->map->map[(int)f->y / 64][((int)f->x - 1)/64];
	ea = &f->map->map[(int)f->y / 64][((int)f->x + 1)/64];
	txt = NULL;
	if (*no != '1')
	{
		txt = f->no;
//		puts("NO");
	}
	else if (*so != '1')
	{
		txt = f->so;
//		puts("so");
	}
	else if (*ea != '1')
	{
		txt = f->ea;
//		puts("ea");
	}
	else if (*we != '1')
	{
		txt = f->we;
//		puts("we");
	}
	if (*no != '1' || *so != '1')
		*xx = (int)f->x % 64;
	else
		*xx = (int)f->y % 64;
	if (txt == NULL)
		txt = f->so;
	return (txt);
}

void			get_color_from_txt(t_info *f, int ind, int size)
{
	double		y;
	int			x;
	int			loc;
	t_texture	*txt;

	y = ((double)f->no->hei / (double)size) * (double) ind; 
	txt = get_texture(f, &x);
	loc = (int)y * txt->img->size_l + x *(txt->img->bpp / 8);
	f->col = txt->img->data[loc];
//	printf("col=[%i]\n", f->col);
}
