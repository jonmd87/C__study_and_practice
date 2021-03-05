/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:34:05 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/22 12:42:52 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_win				*init_win(t_info *f)
{
	t_win 			*win;

	win = (t_win*)ft_calloc(sizeof(t_win), 1);
	if (!win)
		ft_quit(FAIL, ALLOC_WIN);
	win->mlx = mlx_init();
	f->win = win;
	check_resolution(f);
	win->win = mlx_new_window(win->mlx, f->wid, f->hei, WIN_NM);
	return (win);
}

t_img				*init_img(t_info *f)
{
	t_img			*img;

	img = (t_img*)ft_calloc(sizeof(t_img), 1);
	if (!img)
		ft_quit(FAIL, ALLOC_IMG);
	img->img = mlx_new_image(f->win->mlx, f->wid, f->hei);
	img->data = (char*)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->end);
	return (img); 
}

t_plr				*init_plr(t_info *f, int x, int y, int view)
{
	t_plr			*plr;

	plr = (t_plr*)ft_calloc(sizeof(t_plr), 1);
	if (!plr)
		ft_quit(FAIL, ALLOC_PLR);
	plr->x = x * f->scale +(f->scale / 2);
	plr->y = y * f->scale +(f->scale / 2);;
	if (view == 'N')
		plr->pov = 3 * (M_PI / 2);
	else if (view == 'S')
		plr->pov = M_PI / 2;
	else if (view == 'W')
		plr->pov = M_PI;
	else if (view == 'E')
		plr->pov = 2 * M_PI;
	return (plr);
}

t_map				*init_map(size_t size)
{
	t_map			*map;

	map = (t_map*)ft_calloc(sizeof(t_map), 1);
	if (!map)
		ft_quit(FAIL, ALLOC_MAP);
	map->map = (char**)ft_calloc(sizeof(char*), (size + 1));
	if (!map->map)
		ft_quit(FAIL, ALLOC_MAP_MAP);
	map->map_x = 0;
	map->map_y = 0;
	return (map);
}
