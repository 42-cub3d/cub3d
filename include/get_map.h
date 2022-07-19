/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:13:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 01:40:31 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H

# define GET_MAP_H
# include <stddef.h>

enum e_map_check
{
	EMPTY = 1 << 0,
	SPACE = 1 << 1,
	WALL = 1 << 2,
	POS_N = 1 << 3,
	POS_S = 1 << 4,
	POS_E = 1 << 5,
	POS_W = 1 << 6,
	PLAYER = POS_N | POS_S | POS_E | POS_W
};

typedef struct s_dot
{
	size_t	x;
	size_t	y;
	int		type;
}			t_dot;

#endif
