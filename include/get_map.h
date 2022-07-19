/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:13:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 02:07:35 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H

# define GET_MAP_H
# include <stddef.h>

enum e_map_check
{
	SPACE = 1 << 0,
	WALL = 1 << 1,
	POS_N = 1 << 2,
	POS_S = 1 << 3,
	POS_E = 1 << 4,
	POS_W = 1 << 5,
	EMPTY = 1 << 8,
	PLAYER = POS_N | POS_S | POS_E | POS_W
};

typedef struct s_dot
{
	int		type;
	size_t	x;
	size_t	y;
}			t_dot;

typedef struct s_map_info
{
	t_dot	**map;
	char	**temp_map;
	char	*temp
	size_t	str_vec_size;
	size_t	cur;
	int		gnl_check;
	int		player_check;
	size_t	width;
	size_t	height;
}			t_map_info;

#endif
