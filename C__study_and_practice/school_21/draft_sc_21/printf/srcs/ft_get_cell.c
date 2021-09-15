/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 23:24:39 by lbardly           #+#    #+#             */
/*   Updated: 2020/08/06 08:00:07 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_cell(unsigned long int n, unsigned long int *d, char sp)
{
	int	i;

	i = 0;
	if (sp == 'X' || sp == 'x' || sp == 'p')
		*d = 16;
	else
		*d = 10;
	while (n != 0)
	{
		i++;
		n = n / *d;
	}
	return (i);
}
