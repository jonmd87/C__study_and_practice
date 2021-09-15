/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 21:20:57 by lbardly           #+#    #+#             */
/*   Updated: 2020/05/29 00:35:44 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_separators(char const *s, char c)
{
	size_t	len;
	size_t	last;
	size_t	num;

	len = 0;
	last = 0;
	num = 0;
	while (s[len])
	{
		while (s[len] == c && s[len])
			len++;
		last = len;
		while (s[len] != c && s[len])
			len++;
		if (last < len)
			num++;
	}
	return (num);
}

static void	*free_all(char **ar, size_t num)
{
	size_t	ind;

	ind = 0;
	while (ind < num)
	{
		free(ar[ind]);
		ind++;
	}
	free(ar);
	return (NULL);
}

static char	**make_arr(const char *s, const char c, size_t max, char **pnt)
{
	size_t	len;
	size_t	last;
	size_t	ind;

	len = 0;
	last = 0;
	ind = 0;
	while (s[len])
	{
		while (s[len] == c && s[len])
			len++;
		last = len;
		while (s[len] != c && s[len])
			len++;
		if (last < len)
			if (ind < max && !(pnt[ind++] = ft_substr(s, last, len - last)))
				return (free_all(pnt, ind));
	}
	pnt[ind] = NULL;
	return (pnt);
}

char		**ft_split(char const *s, char c)
{
	char	**pnt;
	size_t	num;

	pnt = NULL;
	if (s)
	{
		num = get_separators(s, c);
		pnt = (char**)malloc(sizeof(char*) * (num + 1));
		if (pnt)
			make_arr(s, c, num, pnt);
	}
	return (pnt);
}
