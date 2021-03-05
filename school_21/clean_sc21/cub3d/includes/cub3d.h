/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:48:29 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 21:32:57 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "define.h"
# include "structure.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

void		show_file(t_info *file);
void		show_map(t_map *map);
void		show_img(t_img *img);
void		show_lst(t_list *head);

/*
**General functions
*/

char		*marker(char *str, char ***line, const ssize_t *read_b);
int			get_next_line(int fd, char **line);
void		parser(char *name, t_info *file);
t_list		*get_data(t_list *head, t_info *file);
void		distribut(char *str, t_info *file);
t_resol		*get_resolution(char *str);
t_texture	*get_path(char *str);
t_fl_cell	*get_color(char *str);
t_map		*make_map(t_list **head, size_t size);
int			start_mlx(t_info *f);

/*
**functions for creat and init struct
*/

t_info		*create(void);
void		init_struct(t_info *file);
t_map		*init_map(size_t size);
t_win		*init_win(t_info *f);
t_plr		*init2_plr(t_info *f, const int y, const int x);
t_img		*init_img(t_info *f);

int			get_scale(t_info *f);

/*
**functions for check data
*/

int			check_is_map(const char *str);
int			check_file_name(const char *str);
int			check_line(const char *str);
void		check_max_resol(t_info *file);
void		check_map_and_init_plr_pos(t_info *f);

/*
**function for draw image
*/

/*
**function for hooks
*/

/*
**functions for clear and exit
*/

void		ft_quit(int flag, char *mess);
void		clean_arr(char **str);
void		clean_struct(t_info *file);

#endif
