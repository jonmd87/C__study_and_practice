/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15.2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EvGeN <jonmd87@yandex.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 by EvGeN                      #+#    #+#             */
/*   Updated: 2021/02/21 by EvGeN                     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Write a program that reads two strings with a binary representation
** as command-line arguments and outputs the results of applying 
** the - to operation to each number, as well as the results of applying the
** [&], [|], and ^ operations to a pair of numbers.
** Display the results in the form of binary strings.
** (If the command-line environment is not available,
** provide interactive line input in the program).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define M 20
#define FAIL EXIT_FAILURE
#define SUCC EXIT_SUCCESS
#define ER_MEM "Can not allocate memory!!!()"
#define BYE "!!!GOOD BYE!!!"

static int			get_data(char **s1, char **s2);
static int			check_str(char *str);
static char			*get_str(void);
static char			*ft_strjoin(const char *s1, const char *s2);
static void			make_operations(char *s1, char *s2);
static int			convert(const char *str);
static char			*itobin(const int num);
static void			clean_mem(char *str);
static void			ft_quit(int val, const char *message);

int					main(void)
{
	char			*s1;
	char			*s2;
	int				res;

	s1 = NULL;
	s2 = NULL;
	res = 0;
	while ((res = get_data(&s1, &s2)) > 0)
	{
		make_operations(s1, s2);
		clean_mem(s1);
		clean_mem(s2);
	}
	puts(BYE);
	return (0);
}

static int			get_data(char **s1, char **s2)
{
	puts("Enter first string");
	*s1 = get_str();
	if ((!check_str(*s1)))
	{
		clean_mem(*s1);
		return (0);
	}
	puts("Enter second string");
	*s2 = get_str();
	if (!(check_str(*s2)))
	{
		clean_mem(*s1);
		clean_mem(*s2);
		return (0);
	}
	return (1);
}

static int			check_str(char *str)
{
	int				ind;
	int				len;

	if (!str)
		return (0);
	if (tolower(*str) == 'q')
		return (0);
	len = (int)strlen(str);
	ind = 0;
	if (str[len - 1] == '\n')
		str[--len] = '\0';
	while (str[ind])
	{
		if (str[ind] != '0' && str[ind] != '1')
		{
			puts("wrong data");
			return (0);
		}
		ind++;
	}
	return (1);
} 

static char			*get_str(void)
{
	char			*str;
	char			*temp;
	char			*buf;
	ssize_t			read_b;

	read_b = 0;
	str = (char*)calloc(sizeof(char), 1);
	buf = (char*)calloc(sizeof(char), M + 1);
	if (!buf || !str)
		ft_quit(FAIL, ER_MEM);
	while ((!(strchr(str, '\n')) && (read_b = read(0, buf, M)) > 0))
	{
		buf[read_b] = '\0';
		temp = ft_strjoin(str, buf);
		clean_mem(str);
		str = temp;
	}
	temp = NULL;
	clean_mem(buf);
	return (str);
}

static char			*ft_strjoin(const char *s1, const char *s2)
{
	size_t			ind;
	size_t			len;
	char			*str;
	if (!s1)
		return (NULL);
	if (!s2)
		return ((char*)s1);
	len = strlen(s1) + strlen(s2);
	ind = 0;
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

static void			make_operations(char *s1, char *s2)
{
	int				res;
	int				num1;
	int				num2;
	int				len;

	res = 0;
	num1 = convert(s1);
	num2 = convert(s2);
	if (strlen(s1) > strlen(s2))
		len = strlen(s1);
	else
		len = strlen(s2);
	printf("[%*s](%-10i)\n", len, s1, num1);
	printf("[%*s](%-10i)\n", len, s2, num2);
	printf("-------------------------------------AND[ & ]\n");
	res = num1 & num2;
  	printf("[%*s] <---RESULT\n\n", len, itobin(res));
	printf("[%*s](%-10i)\n", len, s1, num1);
	printf("[%*s](%-10i)\n", len, s2, num2);
	printf("-------------------------------------OR[ | ]\n");
	res = num1 | num2;
  	printf("[%*s] <---RESULT\n\n", len, itobin(res));
	printf("[%*s](%-10i)\n", len, s1, num1);
	printf("[%*s](%-10i)\n", len, s2, num2);
	printf("-------------------------------------XOR[ ^ ]\n");
	res = num1 ^ num2;
  	printf("[%*s] <---RESULT\n\n", len, itobin(res));
	printf("[%*s](%-10i)\n", len, s1, num1);
	printf("[%*s](%-10i)\n", len, s2, num2);
	printf("-------------------------------------NO[ ~ ]\n");
	res = num1 & num2;
  	printf("[%*s] <---RESULT\n", len, itobin(res));
	
}

static char			*itobin(const int num)
{
	char			*str;
	unsigned int	cell;
	int				val;

	str = NULL;
	cell = 0;
	val = num;
	if (num < 1)
		cell++;
	while (val > 0)
	{
		cell++;
		val /= 2;
	}
	val = num;
	if ((str = (char*)calloc(sizeof(char), cell + 1)))
	{
		memset(str, '0', cell);
		while (val != 0)
		{
			cell--;
			str[cell] = val % 2 + '0';
			val /= 2;
		}
	}
	return (str);
}

static int			convert(const char *str)
{
	int				val;
	int				cnt;
	int				len;

	if (!str)
		ft_quit(FAIL, "Wrong input data{funct.[convert]");
	cnt = 1;
	val = 0;
	len = (int)strlen(str);
	while (--len > -1)
	{
		val += cnt * (str[len] - '0');
		cnt *= 2;
	}
	return (val);
}

static void			clean_mem(char *str)
{
	if (str)
	{
		memset(str, '\0', strlen(str));
		free(str);
	}
}

static void			ft_quit(int val, const char *message)
{
	printf("ERROR:-->!!![%s]!!!\n", message);
	exit(val);
}
