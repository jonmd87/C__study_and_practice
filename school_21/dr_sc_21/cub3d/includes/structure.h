/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 09:35:32 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 22:26:08 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# include "cub3d.h"

typedef struct		s_plr {
	unsigned char	orient;
	int				x;
	int				y;
}					t_plr;

typedef struct		s_resol {
	int				height;
	int				width;
}					t_resol;

typedef struct		s_texture {
	char			*path;
}					t_texture;

typedef struct		s_fl_cell {
	int				col1;
	int				col2;
	int				col3;
}					t_fl_cell;

typedef struct		s_map {
	int				map_x;
	int				map_y;
	char			**map;
}					t_map;

typedef struct		s_win {
	void			*mlx;
	void			*win;
	int				scale;
}					t_win;

typedef struct		s_img {
	void			*img;
	int				*data;
	int				img_w;
	int				img_h;
	int				bpp;
	int				line_len;
	int				end;
}					t_img;

typedef struct		s_info {
	t_resol			*res;
	t_texture		*no;
	t_texture		*so;
	t_texture		*we;
	t_texture		*ea;
	t_texture		*s;
	t_fl_cell		*f;
	t_fl_cell		*c;
	t_map			*map;
	t_win			*win;
	t_img			*img;
	t_plr			*plr;
}					t_info;

#endif
