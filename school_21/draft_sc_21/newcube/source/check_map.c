/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:19:18 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/04 14:37:56 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			del_tails(char **str, size_t *size)
{
	char		**map;
	size_t		len;

	map = NULL;
	len = *size;
	while (len)
	{
		if (check_empty_line(str[len - 1]))
			break ;
		len--;
	}
	if (len < *size)
		clean_arr(&str[len]);
	str[len] = NULL;
	*size = len;
}

void			check_map(t_map *map)
{
	int			y;

	y = 0;
	while (map->map[y])
	{
		if (y == 0 || (map->map[y + 1]))
		{
			if (!(check_allowed_char("1 \t", map->map[y])))
				ft_quit(FAIL, BAD_MAP);
		}
		else
		{
			if (!(check_allowed_char("012 NSWE\t", map->map[y])))
				ft_quit(FAIL, BAD_MAP);
		}
		y++;
	}
}
