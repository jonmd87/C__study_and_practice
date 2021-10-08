/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:33:03 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/28 20:51:19 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_plr			*init2_plr(t_info *f, const int y, const int x)
{
	t_plr		*plr;

	plr = (t_plr*)ft_calloc(sizeof(t_plr), 1);
	if (plr == NULL)
		ft_quit(EXIT, ALLOC_PLR);
	plr->x = (int)x;
	plr->y = (int)y;
	plr->orient = f->map->map[y][x];
	return (plr);
}
