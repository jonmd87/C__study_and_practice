/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:11:54 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/13 12:20:07 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void		show_map(t_map *map)
{
	int		y;

	y = 0;
int	z = 1;
printf("map[000]-->[");
for (int x = 0; x < map->map_x; x++)
{
	if ( z == 10)
		z = 0;
	printf("%i", z++);
}
puts("]<--|");
	if (map)
		if (map->map)
			while (map->map[y])
			{
				printf("map[%03i]-->[%s]<--|\n", y, map->map[y]);
				y++;
			}
	printf("map_x[%i]map_y[%i]\n", map->map_x, map->map_y);
}

void		show_color(const t_color *color)
{
	if (color)
		printf("R[%i]G[%i]B[%i]\n", color->r, color->g, color->b);
}

void		show_res(const int wid, const int hei)
{
	printf("RESOLUTION:wid[%i]hei[%i]\n", wid, hei);
}

void		show_list(const void *data)
{
	if (data)
		ft_putendl_fd((char*)data, 1);
}

void		show_texture(const char *name, t_texture *text)
{
	if (text)
		if (text->path)
			printf("show -->%s [%s]\n", name, text->path);
}

void		show_plr(t_plr *plr)
{
	if (plr)
		printf("PLR->Y[%i]PLR->X[%i]PLR->view[%lf]\n", plr->y, plr->x, plr->pov);
}

void		show_all(t_info *f)
{
	show_res(f->wid, f->hei);
	if (f->no)
		show_texture("NO", f->no);
	if (f->so)
		show_texture("SO", f->so);
	if (f->we)
		show_texture("WE", f->we);
	if (f->ea)
		show_texture("EA", f->ea);
	if (f->spirit)
		show_texture("SPIRIT", f->spirit);
	if (f->roof)
		show_color(f->roof);
	if (f->flor)
		show_color(f->flor);
	if (f->map)
		show_map(f->map);
	if (f->plr)
		show_plr(f->plr);
}
