/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_input_file_data.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 06:47:07 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/28 19:05:36 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			check_is_map(const char *str)
{
	int		ind;

	ind = 0;
	while (str[ind] && (ft_strchr("012NSEW ", str[ind]) != NULL))
		ind++;
	if (((int)ft_strlen(str)) == ind)
		return (1);
	return (0);
}

int			check_line(const char *str)
{
	int		ind;

	ind = 0;
	if (str)
	{
		while (str[ind] && str[ind] == ' ' && str[ind] == '\t')
			ind++;
		if (ind == (int)ft_strlen(str) && str[ind] == '\0')
			return (1);
	}
	return (0);
}

int			check_file_name(const char *str)
{
	int		len;
	char	*suff;

	len = 0;
	suff = ".cub";
	if ((len = (int)ft_strlen(str)) > 0)
		if ((ft_strncmp(&str[len - 4], suff, 4) == 0))
			return (1);
	return (0);
}
