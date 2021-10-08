/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:28:58 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/28 18:43:53 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*marker(char *str, char ***line, const ssize_t *read_b)
{
	char	*temp_str;
	char	*last;
	size_t	len;

	temp_str = NULL;
	len = 0;
	if (!(last = ft_strchr(str, '\n')))
		last = str + ft_strlen(str);
	len = last - str;
	**line = ft_substr(str, 0, len);
	if (*read_b > 0)
	{
		last++;
		temp_str = ft_substr(last, 0, ft_strlen(last));
	}
	return (temp_str);
}

int		get_next_line(int fd, char **line)
{
	static char	*stat_s;
	char		*temp;
	char		*buf;
	ssize_t		read_b;

	temp = NULL;
	read_b = 1;
	if (fd < 0 || !line || BUFFER_SIZE < 1 ||
(!(buf = (char*)ft_calloc(sizeof(char), BUFFER_SIZE + 1))))
		return (-1);
	stat_s == NULL ? stat_s = ft_calloc(1, 1) : NULL;
	while ((!(ft_strchr(stat_s, '\n')) &&
				(read_b = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[read_b] = '\0';
		temp = ft_strjoin(stat_s, buf);
		clean_mem(&stat_s);
		stat_s = temp;
	}
	clean_mem(&buf);
	if (read_b > -1)
		temp = marker(stat_s, &line, &read_b);
	clean_mem(&stat_s);
	stat_s = temp;
	return ((int)read_b);
}
