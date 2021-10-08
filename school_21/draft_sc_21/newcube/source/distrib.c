/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distrib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:43:44 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/10 07:57:19 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_color		*make_color(char **str)
{
	int				ind;
	t_color			*color;

	ind = 0;
	color = (t_color*)ft_calloc(sizeof(t_color), 1);
	if (!color)
		ft_quit(FAIL, ALLOC_COLOR);
	if (str[ind] && (str[ind][0] == '-' || ft_isdigit(str[ind][0])))
		color->r = ft_atoi(str[ind]);
	ind++;
	if (str[ind][0] == ',')
		ind++;
	if (str[ind] && (str[ind][0] == '-' || ft_isdigit(str[ind][0])))
		color->g = ft_atoi(str[ind]);
	if (str[ind][0] == ',')
		ind++;
	if (str[ind] && (str[ind][0] == '-' || ft_isdigit(str[ind][0])))
		color->b = ft_atoi(str[ind]);
	clean_arr(str);
	return (color);
}

static t_color		*get_color(const char *str)
{
	int				color;
	char			**temp;
	int				ind;

	color = 0;
	temp = NULL;
	ind = 0;
	if (str)
	{
		temp = ft_split(str, ' ');
		if (!temp)
			ft_quit(FAIL,
					"Can alloc mem for tem ar in func get_color(distrib.c)");
	}
	return (make_color(temp));
}

static void			get_resolution(const char *str, t_info *f)
{
	char			**temp;
	int				ind;

	temp = NULL;
	ind = 0;
	if (str && f)
	{
		temp = ft_split(str, ' ');
		f->wid = ft_atoi(temp[ind]);
		ind++;
		f->hei = ft_atoi(temp[ind]);
		check_resolution(f);
	}
}

static t_texture	*get_path(const char *str, t_texture *tex)
{
	t_texture		*text;
	char			**temp;

	text = NULL;
	temp = NULL;
	if (tex)
		ft_quit(FAIL, DOUBLE_TEX); 
	text = (t_texture*)malloc(sizeof(t_texture) * 1);
	if (!text)
		ft_quit(FAIL, ALLOC_TEXT);
	temp = ft_split(str, ' ');
	if (!temp)
		ft_quit(FAIL, ALLOC_TEXT);
	text->path = ft_strdup(temp[0]);
	clean_arr(temp);
	text->img = NULL;
	text->wid = 0;
	text->hei = 0;
	return (text);
}

void				distrib(const char *str, t_info *f)
{
	if ((ft_strncmp("NO", str, 2)) == 0)
		f->no = get_path(str + 2, f->no);
	else if ((ft_strncmp("SO", str, 2)) == 0)
		f->so = get_path(str + 2, f->so);
	else if ((ft_strncmp("WE", str, 2)) == 0)
		f->we = get_path(str + 2, f->we);
	else if ((ft_strncmp("EA", str, 2)) == 0)
		f->ea = get_path(str + 2, f->ea);
	else if (*str == 'R')
		get_resolution(str + 1, f);
	else if (*str == 'S')
		f->spirit = get_path(str + 1, f->spirit);
	else if (*str == 'F')
		f->flor = get_color(str + 1);
	else if (*str == 'C')
		f->roof = get_color(str + 1);
	else
		return ;
}
