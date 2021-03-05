/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:35:56 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 10:58:11 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static t_arg	*create(void)
{
	t_arg		*list;

	list = NULL;
	list = (t_arg*)malloc(sizeof(t_arg));
	initial(list);
	return (list);
}

static int		fill_flags(t_arg *list, char ch)
{
	if (ch == '-')
	{
		list->sign = 1;
		return (1);
	}
	if (ch == '+')
	{
		list->plus = 1;
		return (1);
	}
	if (ch == '0')
	{
		list->zero = '0';
		return (1);
	}
	if (ch == ' ')
	{
		list->space = ' ';
		return (1);
	}
	return (0);
}

static char		*get_scale(t_arg *list, char **string, va_list ar)
{
	char		*str;

	str = *string;
	if ((get_width(str, ar, list)) > -1)
		while (ft_isdigit(*str) || *str == '*')
			str++;
	if ((list->point = get_point(*str)) > -1)
		str++;
	if ((get_accur(&str, ar, list)) > -1)
		while (ft_isdigit(*str) || *str == '*')
			str++;
	if ((list->spec = get_spec(*str, list)) > -1)
		str++;
	list->raw = (void*)va_arg(ar, void*);
	*string += (str - (*string) - 1);
	return (str);
}

static int		conversion(char **string, va_list ar)
{
	t_arg		*list;
	char		*str;
	int			val;

	str = *string;
	list = NULL;
	val = 0;
	if (*str == '%')
		str++;
	list = create();
	if (list == NULL)
		return (-1);
	while (*str && (ft_strchr("- + 0", *str)))
	{
		fill_flags(list, *str);
		str++;
	}
	str = get_scale(list, &str, ar);
	val = distribution(list);
	*string += (str - (*string) - 1);
	return (val);
}

int				ft_printf(const char *string, ...)
{
	va_list		ar;
	int			val;
	int			control;

	val = 0;
	control = 0;
	va_start(ar, string);
	while (*string != '\0')
	{
		control = val;
		if (*string == '%' && *(string + 1) != '%' && *(string + 1))
			val += conversion((char**)&string, ar);
		else
		{
			ft_putchar_fd(*string, 1);
			if (*string == '%' && *(string + 1) == '%')
				string++;
			val++;
		}
		if (control > val)
			break ;
		string++;
	}
	va_end(ar);
	return ((control > val) ? -1 : val);
}
