/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:28:52 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/06 15:04:51 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int			color(int size)
{
	unsigned char	*src;
	unsigned char	dst[4];
	int				big;

	src = (unsigned char*)(&size);
	big = 4;
	while (big-- > 0)
	{
		dst[big] = *src;
		src++;
	}	
	return (*((int*)dst));
}

static void		little_big(unsigned char *head, int size)
{
	int			big;
	int			little;
	unsigned char	*ar;

	big = 0;
	little = 0;
	ar = (unsigned char*)(&size);
	while (big < 4)
		printf("ar[%x] ", ar[big++]);
	puts("");
	big = 4;
	while (big-- > 0)
	{
		head[little] = ar[big];
printf("%i)AR[%x]-->head[%x]\n", little, ar[big], head[little]);
		little++;
	}
}

static void		write_head(int fd, t_info *f)
{
	unsigned char		head[HEAD_SIZE];
	int					i;

	i = -1;
	while (++i < HEAD_SIZE)
		head[i] = (unsigned char)(0);
	head[0] = (unsigned char)('B');
	head[1] = (unsigned char)('M');
	little_big(head + 2, (f->hei * f->wid * 4 + HEAD_SIZE));
	head[10] = (unsigned char)HEAD_SIZE;
	head[14] = (unsigned char)(40);
	little_big(head + 18, f->wid);
	little_big(head + 22, f->hei);
	head[26] = (unsigned char)(1);
	head[28] = (unsigned char)(32);
	i = write(fd, head, HEAD_SIZE);
	if (i < 0)
		ft_quit(FAIL, ft_strjoin("Can not write head in ", SAVE_NAME));
	else
		ft_putendl_fd("Head writed", 1);
}

static void		write_pixels(int fd, t_info *f)
{
return ;
	int			y;
	int			x;
	int			col;

	y = f->hei;
	col = 0;
	while (y > 0)
	{
		x = 0;
		while (x < f->wid)
		{
			col = *(unsigned int*)f->img->data + y * f->img->size_l
											+ x *(f->img->bpp / 8);
			col = color(col);
			if ((write(fd, &col, 4)) < 0)
				ft_quit(FAIL, "Can not write pixels in screenshot");
			x++;
		}
		y--;
	}
}

void			check_save(int	*save, const char *arg)
{
	if (ft_strncmp(arg, SAVE, ft_strlen(SAVE)) == 0)
		*save = 1;
	else
		ft_quit(FAIL, BAD_ARG2);
}

void			save_image(t_info *f)
{
	int			fd;

	fd = 0;
	if (f->save < 1)
		return ;
	fd = open(SAVE_NAME, O_RDWR | O_CREAT | O_TRUNC , S_IRWXU );
	if (fd < 0)
		ft_quit(FAIL, ft_strjoin("Can not create file", SAVE_NAME));
	ft_putendl_fd("File created\nNow save image in file...", 1);
	write_head(fd, f);
	write_pixels(fd, f);
	close_fd(fd);
	ft_quit(0, ft_strjoin(SAVE_NAME, " created. Bye, see you later!"));
}
