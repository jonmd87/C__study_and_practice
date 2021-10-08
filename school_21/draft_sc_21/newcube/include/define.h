/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:15:36 by lbardly           #+#    #+#             */
/*   Updated: 2020/12/06 15:39:09 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# define BUF_SIZE 40
# define HEAD_SIZE 54
# define FOV 1.0471976
# define FOV_STEP 0.052 
# define WIN_NM "cub3d"
# define FAIL EXIT_FAILURE
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define SAVE "--save"
# define SAVE_NAME "screenshot.bmp"
# define BAD_ARG2 "Bad second argument"
# define BAD_FLAGS "Bad flags, check flags for open file( [r] [w] or [rw])"
# define BAD_ARG "Bad arguments"
# define BAD_FILE "Bad file name or file no exist"
# define BAD_GNL "Wrong data in get_next_line, check buf or fd or line!"
# define BAD_CLOSE "Can not close file"
# define BAD_RES "Bad resolution, check *.cub file"
# define BAD_MAP "Bad map, check charachters in map"
# define BAD_PLR "no player or players more than one"
# define BAD_HOLES "Holes in map"
# define BAD_IMG "Can not upload data in imgage texture"
# define DOUBLE_TEX "Double texture check config"
# define NO_TEX_NO "No path to NO texture"
# define NO_TEX_SO "No path to SO texture"
# define NO_TEX_WE "No path to WE texture"
# define NO_TEX_EA "No path to EA texture"
# define NO_TEX_SPIRIT "No path to spirit texture"
# define ALLOC_MAIN_STRUCT "Can not allocate memory for main struct"
# define ALLOC_TEXT "Can not allocate memory for texture struct"
# define ALLOC_MAP "Can not allocate mem for map struct"
# define ALLOC_PLR "Can not allocate mem for player struct"
# define ALLOC_MASK "Can not allocate mem for mask"
# define ALLOC_MAP_MAP "Can not allocate mem for map->map"
# define ALLOC_COLOR "Can not allocate memory for color struct"
# define ALLOC_WIN "Can not allocate mem for window struct"
# define ALLOC_IMG "Can not allocate mem for img struct"
# define ALLOC_VIEW "Can not allocate mem for view struct"

#endif
