/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_input_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 10:54:09 by lbardly           #+#    #+#             */
/*   Updated: 2020/11/09 20:51:00 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_map		*make_map(t_list **head, size_t size)
{
	t_map			*map;
	size_t			ind;
	t_list			*temp;
	int				len;

	ind = 0;
	temp = *head;
	map = init_map(size);
	len = 0;
	if (!map)
		ft_quit(FAIL, ALLOC_MAP);
	while (temp && ind < size)
	{
		map->map[ind] = temp->content;
		len = (int)ft_strlen(map->map[ind]);
		(map->map_x < len) ? map->map_x = len : map->map_x;
		temp->content = NULL;
		temp = temp->next;
		ind++;
	}
	map->map[ind] = NULL;
	del_tails(map->map, &ind);
	map->map_y = ind;
	check_map(map);
	return (map);
}

static t_list		*make_cup(t_list **head, t_info *f)
{
	t_list			*temp;
	char			*str;

	temp = NULL;
	str = NULL;
	if (*head)
		temp = *head;
	while (temp)
	{
		str = (char*)temp->content;
		if ((check_empty_line(str)) > 0)
		{
			while (*str && (*str == ' ' || *str == '\t'))
				str++;
			if (check_allowed_char("012 NWSE", str) > 0)
				break ;
			else
				distrib(str, f);
		}
		*head = temp->next;
		ft_lstdelone(temp, (void*)clean_str);
		temp = *head;
	}
	check_cup(f);
	return (temp);
}

static char			*marker(const char *stat, char ***line, const ssize_t r_b)
{
	char			*last;
	char			*temp;
	size_t			len;

	temp = NULL;
	if (!(last = ft_strchr(stat, '\n')))
		last = (char*)stat + ft_strlen(stat);
	len = last - stat;
	**line = ft_substr(stat, 0, len);
	if (r_b > 0)
	{
		last++;
		temp = ft_substr(last, 0, ft_strlen(last));
	}
	return (temp);
}

static int			get_next_line(int fd, char **line)
{
	ssize_t			read_b;
	static char		*stat;
	char			*buf;
	char			*temp;

	read_b = 1;
	stat == NULL ? stat = ft_strdup("") : NULL;
	if (fd < 0 || !line ||
						!(buf = (char*)malloc(sizeof(char) * (BUF_SIZE + 1))))
		ft_quit(FAIL, BAD_GNL);
	while ((!ft_strchr(stat, '\n')) && (read_b = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[read_b] = '\0';
		temp = ft_strjoin(stat, buf);
		clean_str(stat);
		stat = temp;
	}
	clean_str(buf);
	if (read_b > -1)
		temp = marker(stat, &line, read_b);
	clean_str(stat);
	stat = temp;
	return ((int)read_b);
}

void				parser(t_info *f, const char *name)
{
	t_list			*head;
	char			*line;
	int				fd;

	head = NULL;
	line = NULL;
	if (!(fd = ft_openfile(name, "r")))
		ft_quit(FAIL, BAD_FILE);
	while (get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		line = NULL;
	}
	close_fd(fd);
	head = make_cup(&head, f);
	f->map = make_map(&head, ft_lstsize(head));
	ft_lstclear(&head, (void*)free);
}
