/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 18:43:17 by lbardly           #+#    #+#             */
/*   Updated: 2020/09/02 20:46:32 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <fcntl.h>
# define O_ER "CAN NOT OPEN FILE OR FILE EXIST"
# define C_ER "CAN NOT CLOSE FILE OR FILE EXIST"

int			open_file(char *name, char *flags)
{
	int		fd;
	int		mode;
	
	fd = 0;
	mode = -1;
	if ((ft_strnstr(flags, "rw", ft_strlen(flags))))
		mode = O_RDWR;
	else if ((ft_strnstr(flags, "w", ft_strlen(flags))))
		mode = O_WRONLY;
	else if ((ft_strnstr(flags, "r", ft_strlen(flags))))
		mode = 0;
	else
		return (-1);
	if ((fd = open(name, mode)) < 0)
	{
		ft_putendl_fd(O_ER, 1);
		exit(1);	
	}
	return (fd);
}

void		close_file(int	fd)
{
	if ((close(fd)) != 0)
	{
		ft_putendl_fd(C_ER, 1);
		exit(1);
	}
}
