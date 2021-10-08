/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_picture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:03:36 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/14 11:36:18 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int				my_pxl_put(t_info *f, int sc, int yy, int xx, int col)
{
	int			y;
	int			x;
	char		*dst;

	y = 0;
	while (y < sc)
	{
		x = 0;
		while (x < sc)
		{
			dst = f->img->data + ((yy + y) * f->img->size_l + (xx + x) *(f->img->bpp / 8));
			*(unsigned int*)dst = col;	
			x++;
		}
		y++;
	}
	return (0);
}

void			make_picture(t_info *f)
{
	int			y;
	int			x;

	y = 0;
	while (f->map->map[y])
	{
		x = 0;
		while (f->map->map[y][x])
		{
			if (f->map->map[y][x] == '1')
				my_pxl_put(f, f->scale, y * f->scale, x * f->scale, 0xFF0000);
			else if (f->map->map[y][x] == '2')
				my_pxl_put(f, f->scale, y * f->scale, x * f->scale, 0xFF00FF);
			else if (ft_strchr("NSEW", f->map->map[y][x]))
				my_pxl_put(f, f->scale / f->scale, f->plr->y, f->plr->x, 0x00FF00);
			x++;
		}
		y++;
	}
}
