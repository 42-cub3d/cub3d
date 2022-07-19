/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:38:13 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 21:41:59 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

enum e_map_flag
{
	FIELD = 1 << 1,
	WALL = 1 << 2,
	SPACE = 1 << 3,
	POS_N = 1 << 4,
	POS_W = 1 << 5,
	POS_S = 1 << 6,
	POS_E = 1 << 7,
	END_LINE = 1 << 8,
	WRONG = 1 << 9,
	DOOR_OPEND = 1 << 10,
	DOOR_CLOSED = 1 << 11,
	SPRITE = 1 << 12,
	DOOR = DOOR_OPEND | DOOR_CLOSED,
	PLAYER = POS_N | POS_S | POS_E | POS_W
};

#endif
