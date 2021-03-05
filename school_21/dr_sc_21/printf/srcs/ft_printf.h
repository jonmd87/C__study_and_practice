/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 10:38:57 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 07:59:49 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

typedef	struct	s_arg
{
	int			sign;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			point;
	int			accur;
	char		spec;
	void		*raw;
	int			filler;
	int			ch;
	int			len;
	char		*str;
}				t_arg;

int				ft_printf(const char *string, ...);
int				distribution(t_arg *list);
void			initial(t_arg *list);
int				get_zero(const char str);
int				get_sign(t_arg *list, char ch);
int				get_width(const char *str, va_list ar, t_arg *list);
int				get_point(const char str);
int				get_spec(const char spec, t_arg *sp);
int				get_accur(char **str, va_list ar, t_arg *list);
int				putstring(const char *str, int lenth);
int				print_chars(const char ch, const int val);
int				show_integers(t_arg *list);
int				show_unsig(t_arg *list);
int				show_strings(t_arg *list);
int				show_chars(t_arg *list);
int				show_adres(t_arg *list);
char			*correction(char *str, char spec);
int				get_cell(unsigned long int n, unsigned long int *d, char sp);
int				output_un(t_arg *list);
void			make_ch(t_arg *list);
char			*correction(char *str, char spec);
int				check_res(t_arg *list);
void			setup_flags(t_arg *list);
void			clear_memory(char **str);

#endif
