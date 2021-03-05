/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 07:15:10 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:52:08 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map		*init_map(size_t size)
{
	t_map	*map;

	map = (t_map*)ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		ft_quit(EXIT, ALLOC_MAP);
	map->map_x = 0;
	map->map_y = 0;
	map->map = (char**)ft_calloc(sizeof(char*), size + 1);
	if (map->map == NULL)
		ft_quit(EXIT, ALLOC_MAP_MAP);
	return (map);
}

t_img		*init_img(t_info *f)
{
	t_img	*img;
	if(f)
		img = NULL;
	img = (t_img*)ft_calloc(sizeof(t_img), 1);
	if (img == NULL)
		ft_quit(EXIT, ALLOC_IMG);
	img->img = mlx_new_image(f->win->mlx, f->res->width, f->res->height);
	img->data = (int*)mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->end);
	return (img);
}

t_win		*init_win(t_info *f)
{
	t_win	*win;
	win = (t_win*)ft_calloc(sizeof(t_win), 1);
	if (win == NULL)
		ft_quit(EXIT, ALLOC_WIN);
	win->mlx = mlx_init();
	check_max_resol(f);
	win->win = mlx_new_window(win->mlx, f->res->width, f->res->height, NAME_WIN);
	return (win);
}

void		init_struct(t_info *file)
{
	if (file)
	{
		file->res = NULL;
		file->no = NULL;
		file->so = NULL;
		file->we = NULL;
		file->ea = NULL;
		file->s = NULL;
		file->f = NULL;
		file->c = NULL;
		file->map = NULL;
		file->win = NULL;
		file->img = NULL;
		file->plr = NULL;
	}
}

t_info		*create(void)
{
	t_info	*file;

	file = NULL;
	file = (t_info*)ft_calloc(1, sizeof(t_info));
	if (!file)
		return (NULL);
	init_struct(file);
	return (file);
}
