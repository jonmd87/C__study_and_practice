/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:13:59 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:42:51 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_resol			*get_resolution(char *str)
{
	char	**temp;
	t_resol *res;

	temp = NULL;
	res = NULL;
	temp = ft_split(str, ' ');
	if (temp)
		res = (t_resol*)ft_calloc(sizeof(t_resol), 1);
	if (res == NULL)
		ft_quit(EXIT, ALLOC_RES);
	res->width = ft_atoi(temp[0]);
	res->height = ft_atoi(temp[1]);
	clean_arr(temp);
	return (res);
}

t_texture		*get_path(char *str)
{
	t_texture	*text;
	char		*last;

	text = NULL;
	last = NULL;
	text = (t_texture*)ft_calloc(sizeof(t_texture), 1);
	while (*str == ' ' || *str == '\t')
		str++;
	if (text == NULL)
		ft_quit(EXIT, ALLOC_TEXT);
	last = ft_strchr(str, ' ');
	if (last == NULL)
		last = ft_strchr(str, '\t');
	if (last == NULL)
		last = ft_strchr(str, '\0');
	text->path = ft_substr(str, 0, last - str);
	return (text);
}

t_fl_cell		*get_color(char *str)
{
	int			num;
	char		**temp;
	t_fl_cell	*color;

	num = 0;
	temp = NULL;
	color = NULL;
	temp = ft_split(str, ' ');
	if (temp != NULL)
		if (!(color = (t_fl_cell*)ft_calloc(sizeof(t_fl_cell), 1)))
			ft_quit(EXIT, ALLOC_TEXT);
	while (!(ft_isdigit(temp[num][0])))
		num++;
	color->col1 = ft_atoi(temp[num++]);
	while (!(ft_isdigit(temp[num][0])))
		num++;
	color->col2 = ft_atoi(temp[num++]);
	while (!(ft_isdigit(temp[num][0])))
		num++;
	color->col3 = ft_atoi(temp[num++]);
	clean_arr(temp);
	return (color);
}

void			distribut(char *str, t_info *file)
{
	int		ind;

	ind = 0;
	while (str[ind] && (str[ind] == ' ' || str[ind] == '\t'))
		ind++;
	if (str[ind] == 'R')
		file->res = get_resolution(&str[ind + 1]);
	else if ((ft_strncmp(&str[ind], "NO", ft_strlen("NO"))) == 0)
		file->no = get_path(&str[ind + 2]);
	else if ((ft_strncmp(&str[ind], "SO", ft_strlen("SO"))) == 0)
		file->so = get_path(&str[ind + 2]);
	else if ((ft_strncmp(&str[ind], "WE", ft_strlen("WE"))) == 0)
		file->we = get_path(&str[ind + 2]);
	else if ((ft_strncmp(&str[ind], "EA", ft_strlen("EA"))) == 0)
		file->ea = get_path(&str[ind + 2]);
	else if (str[ind] == 'S')
		file->s = get_path(&str[ind + 1]);
	else if (str[ind] == 'F')
		file->f = get_color(&str[ind + 1]);
	else if (str[ind] == 'C')
		file->c = get_color(&str[ind + 1]);
	else
		return ;
}

t_list			*get_data(t_list *head, t_info *file)
{
	t_list	*temp;

	temp = NULL;
	while (head)
	{
		if ((check_is_map(head->content)) > 0)
			break ;
		else
		{
			distribut(head->content, file);
		}
		temp = head;
		head = head->next;
		clean_mem((char**)&temp->content);
		free(temp);
	}
	return (head);
}
