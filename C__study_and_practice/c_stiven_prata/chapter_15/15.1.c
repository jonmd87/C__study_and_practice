/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/01/24 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write a function that converts a string with a binary representation to 
** a numeric value. In other words, if there is
** char *pbin = "01001001";
** then the min variable can be passed to this function as an argument, 
** and the function must return the value 25 of the int type.
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define M 20
#define FAIL "!!!wrong input deta!!!"

static int		bintodig(char *str)
{
	int			val;
	int			len;
	int			count;

	val = 0;
	if (str)
	{
		len = (int)strlen(str);
		count = 1;
		while (--len > -1)
		{
			
			printf("str[%c] count[%i]  \n", str[len], count);
			val += count * (str[len] - '0');
			count *= 2;	
		}
	}
	return (val);
}

static int		check_str(char *str, const int len)
{
	int			ind;

	ind = 0;
	if (str)
	{
		while (ind < len)
		{
			if (str[ind] == '0' || str[ind] == '1')
				ind++;
			else
				return (0);
		}
		if (ind == len)
			return (1);
	}
	return (0);
}

static void		clean_mem(char *str)
{
	if (str)
	{
		bzero(str, strlen(str));
		free(str);
		str = NULL;
	}
}

static char		*ft_strjoin(const char *s1, const char *s2)
{
	char		*str;
	size_t		ind;
	size_t		len;
	
	str = NULL;
	ind = 0;
	if (!s1)
		return (NULL);
	if (!s2)
		return ((char*)s1);
	len = strlen(s1) + strlen(s2);
	if ((str = (char*)calloc(sizeof(char), len + 1)))
	{
		while (*s1 && ind != len)
			str[ind++] = *s1++;
		while (*s2 && ind != len)
			str[ind++] = *s2++;
		str[ind] = '\0';	
	}	
	return (str);
}

static void		del_endl(char *str)
{
	size_t		len;

	if (str)
	{
		len = strlen(str);
		if (str[len - 1] == '\n')
			str[len - 1] = '\0';
	}
}

static int		getstr(char **str)
{
	char		*buf;
	char		ch;
	int			fd;
	size_t		read_b;

	ch = 0;
	fd = 0;
	read_b = 0;
	if (!(buf = (char*)calloc(sizeof(char), M + 1)))
	{
		puts("Can not allocate memory for string\nGood Bye");
		exit(1);
	}
	*str = (char*)calloc(sizeof(char), 1);
	while ((!(strchr(buf, '\n'))) && (read_b = read(fd, buf, M)) > 0)
	{
		buf[read_b] = '\0';
		*str = ft_strjoin(*str, buf);
	}
	del_endl(*str);
	clean_mem(buf);
	if (*str && *str[0] != 'q' && *str[0] != 'e')
		return (1);
	return (0);
}

int				main(void)
{
	char		*str;
	ssize_t		val;

	str = NULL;
	val = 0;
	printf("\nEnter number in binary(For exit enter [q] or [e])\n");
	while (getstr(&str) != 0)
	{
		if (check_str(str, (int)strlen(str)) == 0)
		{
			puts(FAIL);
			clean_mem(str);
			continue ;
		}
		printf("[%s] in binary = [%i]\n", str, bintodig(str));
		clean_mem(str);
		printf("\nEnter number in binary(For exit enter [q] or [e])\n");
	}
	printf("Good bye!!!\n");
}
