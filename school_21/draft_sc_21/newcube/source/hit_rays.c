/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 07:36:09 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/02 17:42:51 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"


static void			put_column(t_info *f, int len, int x)
{
	int				cel;
	int				size;
	int				ind;
	int				max;

	ind = 0;
	cel =  0;
	max = 0;
	size = 64 * f->dist / len;
	cel =  (f->hei - size) / 2;
	while (ind < cel && ind < f->hei)
	{
		my_pxl_put(f, 1, ind, x, 0x0000FF);
		ind++;
	}
	max = size + cel;
	while (ind < max && ind < f->hei - 1)
	{
		get_color_from_txt(f, ind - cel, size);	
		my_pxl_put(f, 1, ind, x, f->col);
		ind++;
	}
	while (ind < f->hei  - 1)
	{
			my_pxl_put(f, 1, ind, x, 0x00FF00);
			ind++;
	}
	
	
}

static void			hit_ray(t_info *f, double angle, int index)
{
	double			len;

	f->y = f->plr->y;
	f->x = f->plr->x;
	len = 1;
	while(!ft_strchr("12", f->map->map[(int)f->y / f->scale][(int)f->x / f->scale]))
	{
		f->y += sinf(angle);
		f->x += cosf(angle);
	}
	len = sqrt(pow((int)f->x - f->plr->x, 2) + pow((int)f->y - f->plr->y, 2));
	len *= cos(angle - f->plr->pov);
	len = round(len);
	put_column(f, (int)len, index);
}
void			hit_rays(t_info *f, double step)
{
	double		start;
	double		end;
	double		angle_step;
	
	f->plr->pov += step;
	start = f->plr->pov - (FOV / 2);
	angle_step = FOV / f->wid;
	end = start + FOV;
	int		ind = 0;
	while (start < end)
	{
		hit_ray(f, start, ind);
		start += angle_step;
		ind++;
	}
}
