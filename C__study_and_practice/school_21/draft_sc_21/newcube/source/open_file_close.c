/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 18:16:51 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/04 14:02:22 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int		check_flag(const char *flag)
{
	if (ft_strncmp(flag, "r", ft_strlen(flag)) == 0)
		return (O_RDONLY);
	else if (ft_strncmp(flag, "w", ft_strlen(flag)) == 0)
		return (O_WRONLY);
	else if (ft_strncmp(flag, "rw", ft_strlen(flag)) == 0)
		return (O_RDWR);
	else
		return (-1);
}

int				ft_openfile(const char *name, const char *flag)
{
	int			fd;
	int			mode;

	fd = -1;
	if ((mode = check_flag(flag)) < 0)
		ft_quit(FAIL, BAD_FLAGS);
	else
		fd = open(name, mode);
	if (fd < 0)
		ft_quit(FAIL, BAD_FILE);
	return (fd);
}

void			close_fd(int fd)
{
	if ((close(fd)) != 0)
		ft_quit(FAIL, BAD_CLOSE);
}
