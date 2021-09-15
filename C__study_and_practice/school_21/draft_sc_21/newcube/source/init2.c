/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 22:19:23 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/29 17:56:30 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void			init_texture_img(t_info *f, t_texture *tex)
{
	tex->img = (t_img*)ft_calloc(sizeof(t_img), 1);
	if (!tex->img)
		ft_quit(FAIL, ft_strjoin("Can't alloc mem text->img/", tex->path));
	tex->img->img = mlx_xpm_file_to_image(f->win->mlx, tex->path,
													&tex->wid, &tex->hei);
	if (!tex->img->img)
		ft_quit(FAIL, ft_strjoin("Wrong pnt TEX->img->img/", tex->path));
	tex->img->data = (char*)mlx_get_data_addr(tex->img->img, &tex->img->bpp,
											&tex->img->size_l, &tex->img->end);
	if (!tex->img->data)
		ft_quit(FAIL, ft_strjoin("Wrong data TEX->img->data/", tex->path));
}
