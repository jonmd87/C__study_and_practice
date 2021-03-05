/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:04:52 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/03 06:40:13 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_info		*create(const int save)
{
	t_info		*f;

	f = NULL;
	f = (t_info*)ft_calloc(sizeof(t_info), 1);
	if (!f)
		ft_quit(FAIL, ALLOC_MAIN_STRUCT);
	if (f)
	{
		if (save == 1)
			f->save = 1;
		else
			f->save = 0;
		f->scale = 0;
		f->step = 0;
		f->wid = 0;
		f->hei = 0;
		f->col = 0;
		f->dist = 0;
		f->x = 0;
		f->y = 0;
		f->no = NULL;
		f->so = NULL;
		f->we = NULL;
		f->ea = NULL;
		f->spirit = NULL;
		f->map = NULL;
		f->plr = NULL;
		f->win = NULL;
		f->img = NULL;
	}
	return (f);
}

static void			make_plr(t_info *f)
{
	int			x;
	int			y;
	char		**map;

	y = 0;
	map = f->map->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_isalpha(map[y][x]))
			{
				if (ft_strchr("NSWE", map[y][x]) && !f->plr)
					f->plr = init_plr(f, x, y, map[y][x]);
				else
					ft_quit(FAIL, BAD_PLR);
			}
			x++;
		}
		y++;
	}
	if (f->plr == NULL)
		ft_quit(FAIL, BAD_PLR);
}

static void			open_window(t_info *f)
{
	f->win = init_win(f);	
	f->img = init_img(f);
	init_texture_img(f, f->no);
	init_texture_img(f, f->so);
	init_texture_img(f, f->we);
	init_texture_img(f, f->ea);
	hit_rays(f, 0);
	save_image(f);
	mlx_hook(f->win->win, 2, 1L<<0, &my_key_hook, f);
	mlx_put_image_to_window(f->win->mlx, f->win->win, f->img->img, 0, 0);
}

int					main(int argc, char **argv)
{
	t_info		*f;
	int			save;

	f = NULL;
	save = 0;
	if (argc < 2)
		ft_quit(FAIL, BAD_ARG);
	if (argc == 3)
		check_save(&save, argv[2]);
	f = create(save);
	parser(f, argv[1]);
	f->scale = 64;
	f->step = 8;
	f->dist = (f->wid / 2) / (tan(FOV / 2));
	make_plr(f);
	open_window(f);
	mlx_loop(f->win->mlx);
	return (0);
}
