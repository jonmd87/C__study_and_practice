/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:40:25 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:22:48 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_map		*make_map(t_list **head, size_t size)
{
	t_list	*temp;
	t_map	*map;
	int		ind;

	map = NULL;
	temp = *head;
	ind = 0;
	map = init_map(size);
	while (temp)
	{
		map->map[ind] = temp->content;
		temp = temp->next;
		if (map->map_x < (int)ft_strlen(map->map[ind]))
			map->map_x = (int)ft_strlen(map->map[ind]);
		ind++;
	}
	map->map[ind] = NULL;
	temp = NULL;
	map->map_y = ind;
	return (map);
}

void		parser(char *name, t_info *file)
{
	int		fd;
	char	*line;
	t_list	*head;

	head = NULL;
	line = NULL;
	fd = open_file(name, "r");
	if (fd < 0)
		ft_quit(EXIT, WRONG_FILE_NAME);
	while (get_next_line(fd, &line))
	{
		if (check_line(line) == 0)
			ft_lstadd_back(&head, ft_lstnew(line));
		else
			clean_mem(&line);
		line = NULL;
	}
	line = NULL;
	head = get_data(head, file);
	file->map = make_map(&head, ft_lstsize(head));
	close_file(fd);
}
