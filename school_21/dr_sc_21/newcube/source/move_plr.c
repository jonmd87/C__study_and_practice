/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_plr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:57:35 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/02 17:43:54 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_info		*check_w(t_info *f)
{
	double 			y;
	double			x;

	y = (double)f->plr->y + sin(f->plr->pov) * f->step;
	x = (double)f->plr->x + cos(f->plr->pov) * f->step;
	if (!(ft_strchr("0NSEW", f->map->map[(int)y / f->scale][(int)x / f->scale])))
		return (f);
	f->plr->y = (int)y;
	f->plr->x = (int)x;
	return (f);
}

static t_info		*check_a(t_info *f)
{
	double 			y;
	double			x;

	y = (double)f->plr->y + sin(f->plr->pov - (M_PI / 2)) * f->step;
	x = (double)f->plr->x + cos(f->plr->pov - (M_PI / 2)) * f->step;
	if (!(ft_strchr("0NSEW", f->map->map[(int)y / f->scale][(int)x / f->scale])))
		return (f);
	f->plr->y = (int)y;
	f->plr->x = (int)x;
	return (f);
}

static t_info		*check_s(t_info *f)
{
	double 			y;
	double			x;

	y = (double)f->plr->y + sin(f->plr->pov + M_PI) * f->step;
	x = (double)f->plr->x + cos(f->plr->pov + M_PI) * f->step;
	if (!(ft_strchr("0NSEW", f->map->map[(int)y / f->scale][(int)x / f->scale])))
		return (f);
	f->plr->y = (int)y;
	f->plr->x = (int)x;
	return (f);
}

static t_info		*check_d(t_info *f)
{
	double 			y;
	double			x;

	y = (double)f->plr->y - sin(f->plr->pov - M_PI / 2) * f->step;
	x = (double)f->plr->x - cos(f->plr->pov - M_PI / 2) * f->step;
	if (!(ft_strchr("0NSEW", f->map->map[(int)y / f->scale][(int)x / f->scale])))
		return (f);
	f->plr->y = (int)y;
	f->plr->x = (int)x;
	return (f);
}

void		move_plr(t_info *f)
{
		f->img->img = mlx_new_image(f->win->mlx, f->wid, f->hei);
		f->img->data = mlx_get_data_addr(f->img->img, &f->img->bpp, &f->img->size_l, &f->img->end);
		hit_rays(f, 0);
		if (f->save > 0)
			save_image(f);
		mlx_put_image_to_window(f->win->mlx, f->win->win, f->img->img, 0, 0);
}

void		put(t_info *f)
{
		move_plr(f);
}

int			my_key_hook(int key, t_info *f)
{
	if (key == KEY_W)
		put(check_w(f)); 
	else if (key == KEY_S)
		put(check_s(f)); 
	else if (key == KEY_A)
		put(check_a(f)); 
	else if (key == KEY_D)
		put(check_d(f)); 
	else if (key == KEY_RIGHT)
	{
		hit_rays(f, FOV_STEP);
		put(f);
	}
	else if (key == KEY_LEFT)
	{
		hit_rays(f, (FOV_STEP * -1));
		put(f);
	}
	else if (key == KEY_ESC )
		ft_quit(0, "Bye, see you later");
	return (0);
}
