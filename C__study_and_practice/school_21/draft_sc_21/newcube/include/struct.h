/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 20:09:25 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/01 17:49:22 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_img {
	void		*img;
	char		*data;

	int			size_l;
	int			bpp;
	int			end;
}				t_img;

typedef struct	s_texture {
	char		*path;
	t_img		*img;
	int			wid;
	int			hei;
}				t_texture;
	
typedef struct	s_win {
	void		*mlx;
	void		*win;
}				t_win;

typedef struct	s_map {
	char		**map;
	int			map_x;
	int			map_y;
}				t_map;

typedef struct	s_plr {
	int			x;
	int			y;
	double		pov;
}				t_plr;

typedef struct	s_color {
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_info {
	int			save;
	int			scale;
	int			step;
	int			wid;
	int			hei;
	int			col;
	int			dist;
	double		x;
	double		y;
	t_texture	*no;
	t_texture	*so;
	t_texture	*we;
	t_texture	*ea;
	t_texture	*spirit;
	t_color		*roof;
	t_color		*flor;
	t_map		*map;
	t_plr		*plr;
	t_win		*win;
	t_img 		*img;
}				t_info;
#endif
