/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_specificators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 11:54:05 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 10:54:06 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	initial(t_arg *list)
{
	list->sign = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->width = 0;
	list->point = 0;
	list->accur = 0;
	list->filler = ' ';
	list->spec = 0;
	list->raw = NULL;
	list->filler = 0;
	list->ch = 0;
	list->len = 0;
	list->str = NULL;
}

int		get_width(const char *str, va_list ar, t_arg *list)
{
	list->width = -1;
	if (*str == '*')
	{
		list->width = (int)va_arg(ar, int);
		if (list->width < 0)
		{
			list->width *= -1;
			list->sign = 1;
		}
	}
	else if ((ft_isdigit(*str)))
	{
		list->width = ft_atoi(str);
		if (list->width < 0)
		{
			list->width *= -1;
			list->sign = 1;
		}
	}
	return (list->width);
}

int		get_point(const char ch)
{
	int		point;

	point = -1;
	if (ch == '.')
		point = 1;
	return (point);
}

int		get_accur(char **str, va_list ar, t_arg *list)
{
	if (list->point == 1)
	{
		list->accur = 0;
		if (**str == '*')
		{
			list->accur = (int)va_arg(ar, int);
			(*str)++;
		}
		else if ((ft_isdigit(**str)))
			list->accur = ft_atoi(*str);
	}
	else
		list->accur = -1;
	return (list->accur);
}

int		get_spec(const char c, t_arg *list)
{
	char	ch;
	char	*pnt;

	ch = -1;
	pnt = ft_strchr("csidupxX", c);
	if (pnt != NULL)
	{
		ch = *pnt;
		if (ft_strchr("csp", ch))
			list->zero = ' ';
	}
	if (c == '%')
		ch = c;
	return (ch);
}
