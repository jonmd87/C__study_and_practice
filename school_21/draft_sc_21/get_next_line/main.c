/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:31:43 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/30 22:15:55 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
# define STR "\n------------------------------------\n"
# define OP "FILE OPENED"
# define ER "CAN NOT OPEN FILE OR FILE EXIST"
# define STD_IN "READ MODE 1 [STDIN]"

int		open_file(int val, char *str)
{
	int		num;
	num = 0;
	if (val == 2)
	{
		if ((num = open(str, O_RDONLY)) < 0)
		{
			puts(ER);
			exit(1);
		}
	}
	if (num == 0)
		puts(STD_IN);
	return (num);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;	
	size_t	cnt;
	char	*line;

	cnt = 1;
	line = NULL;
	if (argc == 2 || argc == 1)
	{
		fd = open_file(argc, argv[1]);
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("%lu)[ret %i]\t%s\n", cnt, ret, line);
			ft_bzero(line, ft_strlen(line));
			free(line);
			cnt++;
		}
		printf("outside loop");
		printf("\t\t%lu)[ret %i] -", cnt, ret);
		if (ret > -1)
		{
			printf("[%s]", line);
			ft_bzero(line, ft_strlen(line));
			free(line);
			line = NULL;
		}
		puts("-");
		if (close(fd) != 0)
		{
			printf("error: can not close file [%s]\n", argv[1]);
			return (0);
		}
		else
			puts("File closed");
	}
	return (0);
}

