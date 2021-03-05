/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_resived_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:49:55 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:56:52 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			check_max_resol(t_info *f)
{
	int			x;
	int			y;

	x = 1920;
	y = 1020;
	if (f->res->height > y)
		f->res->height = y;
	if (f->res->width > x)
		f->res->width = x;
}

int			get_scale(t_info *f)
{
	int		small_res = 0;
	int		big_map_side = 0;
	int		scale;

	scale = 0;
	if (f->res->height > f->res->width)
		small_res = f->res->width;
	else
		small_res = f->res->height;
	if (f->map->map_y > f->map->map_x)
		big_map_side = f->map->map_x;
	else
		big_map_side = f->map->map_y;
	scale = small_res / big_map_side;
	return (scale - 1);
}

void			check_res(t_info *file)
{
	if (file->res->height < 1 || file->res->width < 1)
		ft_quit(EXIT, BAD_RES);
}

static int		check_ch(t_info *f, const char c, const int y, const int x)
{
	char		ch;
	char		*ptr;

	ch = (char)c;
	if ((ft_isalnum(ch)) || ch == ' ')
	{
		if (ch == ' ')
			return (1);
		else if (ch > 47 && ch < 51)
			return (1);
		else if ((ptr = ft_strchr("NSWE", ch)))
		{
			if (f->plr != NULL)
				ft_quit(EXIT, MORE_PLR);
			f->plr = init2_plr(f, y, x);
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void			check_map_and_init_plr_pos(t_info *f)
{
	char	**str;
	int		x;
	int		y;

	y = 0;
	x = 0;
	str = f->map->map;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (check_ch(f, str[y][x], y, x))
				x++;
			else
				ft_quit(EXIT, BAD_MAP);
		}
		y++;
	}
	if (f->plr == NULL)
		ft_quit(EXIT, NO_PLR);
}
