/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 07:20:06 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:56:54 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		draw_map(t_info *f)
{
	if (f)
		puts("draw");
}

int			delay_key(int key, t_info *f)
{
	if (f)
		puts("m_l");
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int			ft_close(t_info *f)
{
	if (f)
		puts("cl");
	exit(0);
	return (0);
}

int			main_loop(t_info *f)
{
	puts("her");
	f->win->scale = get_scale(f);
	puts("her");
	printf("scale =%i=\n", f->win->scale);
	draw_map(f);
	return (0);
}

int			start_mlx(t_info *f)
{
	f->win = init_win(f);
	f->img = init_img(f);
	mlx_hook(f->win->win, EVENT_PRESS, 0, &delay_key, f->win); 
	mlx_hook(f->win->win, EVENT_EXIT, 0, &close, f->win); 
	mlx_loop_hook(f->win->mlx, &main_loop, f->win);
	mlx_loop(f->win->mlx);
	return (0);
}
