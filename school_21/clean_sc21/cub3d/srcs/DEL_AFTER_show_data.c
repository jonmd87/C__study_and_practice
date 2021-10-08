/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 07:56:21 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 20:53:32 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			show_plr(t_plr *plr)
{
	if (!plr)
		return ;
	printf("plr->y[%i]   plr->x[%i]   plr->orient[%c]\n",
												plr->y, plr->x, plr->orient);
}

void			show_lst(t_list *head)
{
	t_list		*temp;

	temp = head;
	while (temp)
	{
		temp = temp->next;
	}
}

void			show_map(t_map *map)
{
	int			ind;

	ind = 0;
puts("IN CHECK MAP");
	if (map == NULL)
		puts("!!!!!!!!!!!!!!!!EMPTY MAP");
	else
	{
		printf("map->map_x[%i]\nmap->map_y[%i]\n",
												map->map_x, map->map_y);
		if (map->map)
		{
			while (map->map[ind])
			{
				ft_putendl_fd(map->map[ind], 1);
				ind++;
			}
		}
	}
}
void			show_win(t_win *win)
{
	if(win)
	{
		if (win->win)
			puts("win->win[OK]\n");
		else
			puts("win->win[BAD]\n");
		if (win->mlx)
			puts("win->mlx[OK]\n");
		else
			puts("win->mlx[BAD]\n");
	}
}

void			show_img(t_img *img)
{
	if (img == NULL)
		puts("!!!!!!!!!!!file->img EMPTY");
	else
	{
		if (img->img == NULL)
			puts("!!!!!!!!!!!file->img->img EMPTY");
		else
			puts("file->img->ptr[OK]");
		if (img->data == NULL)
			puts("!!!!!!!!!!!file->img->addr EMPTY");
		else
		
	puts("@@@@@@@@@@@@@@END");
	}
}

void			show_file(t_info *file)
{
	puts("start SHOW FILE");
	if (file->no)
		printf("NO\n\tNO->path =%s=\n", file->no->path);
	if (file->so)
		printf("SO\n\tSO->path =%s=\n", file->so->path);
	if (file->we)
		printf("WE\n\tWE->path =%s=\n", file->we->path);
	if (file->ea)
		printf("EA\n\tEA->path =%s=\n", file->ea->path);
	if (file->s)
		printf("S\n\tS->path =%s=\n", file->s->path);
	if (file->f)
		printf("F\n\tF->col1 =%i=\n\tF->col2 =%i=\n\tF->col3 =%i=\n",
						file->f->col1, file->f->col2, file->f->col3);
	if (file->c)
		printf("C\n\tC->col1 =%i=\n\tC->col2 =%i=\n\tC->col3 =%i=\n",
						file->c->col1, file->c->col2, file->c->col3);
	if (file->res)
		printf("R\n\tres->height =%i=\n\tres->width =%i=\n",
								file->res->height, file->res->width);
	show_map(file->map);
	show_win(file->win);
	show_img(file->img);
	show_plr(file->plr);
	puts("end SHOW FILE");
}
