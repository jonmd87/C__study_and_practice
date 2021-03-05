/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:27:25 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/02 18:00:22 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "define.h"
# include "struct.h"
# include "../source/libft/libft.h"
# include "../mlx/mlx.h"

/*
**MAIN FUNCTIONS
*/
void		parser(t_info *f, const char *name);
void		distrib(const char *str, t_info *f);
void		make_picture(t_info *f);
void		hit_rays(t_info *f, double step);
int			my_key_hook(int key, t_info *f);
int         my_close(int key, t_info *f);

/*
**MAKE_PICTURE.C
*/
int			my_pxl_put(t_info *f, int sc, int xx, int yy, int col);
void        make_picture(t_info *f);

/*
**GET_COLOR.C
*/
void		get_color_from_txt(t_info *f, int ind, int size);

/*
**INIT.C
*/
t_img		*init_img(t_info *f);
t_win		*init_win(t_info *f);
t_plr		*init_plr(t_info *f, int x, int y, int view);
t_map		*init_map(size_t size);

/*
**INIT2.C
*/
void		init_texture_img(t_info *f, t_texture *tex);

/*
**SHOW_FUNCTIONS.C
*/
void		show_map(t_map *map);
void		show_list(const void *data);
void		show_texture(const char *name, t_texture *text);
void		show_all(t_info *f);
void		show_color(const t_color *color);
void		show_plr(t_plr *plr);
/*
**CHECK_DATA_FROM_INPUT_FILE.C
*/
void		check_resolution(t_info *f);
int			check_allowed_char(const char *patt, const char *str);
int			check_empty_line(const char *str);
void		check_cup(t_info *f);

/*
**CHECK_MAP.C
*/
void		del_tails(char **str, size_t *size);
void		check_map(t_map *map);

/*
**EXIT_FREE.c
*/
void		clean_arr(char **str);
void		clean_str(char *str);
void		ft_quit(int code, const char *message);

/*
**OPEN_FILE_CLOSE.C
*/
int			ft_openfile(const char *name, const char *flag);
void		close_fd(int fd);

/*
**SAVE_IMAGE
*/

void		check_save(int  *save, const char *arg);
void		save_image(t_info *f);

#endif
