/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbardly <lbradly@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 09:38:12 by lbardly           #+#    #+#             */
/*   Updated: 2020/10/29 11:50:50 by lbardly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# define BUFFER_SIZE 40
# define NAME_WIN "my_window"
# define PLAYER "NSWE"
# define FINISH "GOOD BUY"

/*
** KEY PRESS
*/

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_RIGHT 124
# define KEY_LEFT 123

/*
** EVENTS
*/

# define EVENT_PRESS 2
# define EVENT_RELEASE 3 
# define EVENT_EXIT 17

/*
**ERROR ALARMS
*/

# define EXIT EXIT_FAILURE
# define WRONG_ARG "------ not enoudght arguments"
# define NOT_CUB_FILE "----- not a [*.cub] file"
# define WRONG_FILE_NAME "Wrong file name"
# define BAD_CUB "----- bad *.cub file"
# define ALLOC_RES "----- can not allocate mem for resolution struct"
# define ALLOC_TEXT "----- can not allocate mem for texture struct"
# define ALLOC_MAP "can not allocate memory for struct map"
# define ALLOC_MAP_MAP "can not allocate memory for array"
# define ALLOC_IMG "can not allocate memory for image struct"
# define ALLOC_WIN "can not allocate memory for win struct"
# define ALLOC_PLR "can not allocate memory for player struct"
# define MORE_PLR "unknown character or many players on the map"
# define NO_PLR "No player in map"
# define CAN_NOT_ADD_IMG_DATA "ca not add image data"
# define BAD_RES "bad resolution"
# define BAD_MAP "wrong charachters in map, check your map"

# define BYE "Good bye, see you again"
#endif
