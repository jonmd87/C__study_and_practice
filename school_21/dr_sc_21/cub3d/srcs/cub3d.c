/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:33:43 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:50:21 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#define PATH "./maps/"

int			main(int argc, char *argv[])
{
	t_info	*file;

	file = NULL;
	if (argc < 2)
		ft_putendl_fd(WRONG_ARG, 1);
	else
	{
		if ((check_file_name(argv[1])) == 0)
			ft_quit(EXIT, NOT_CUB_FILE);
		file = create();
		parser(argv[1], file);
		check_map_and_init_plr_pos(file);
		check_max_resol(file);
		start_mlx(file);
	}
	return (0);
}
