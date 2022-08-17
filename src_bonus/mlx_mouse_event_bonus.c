/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_event_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:35:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/17 09:58:22 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "key_event.h"
#include "mlx.h"

int	check_mouse_move(int x, int y, t_info *info)
{
	int	gap;
	int	key;
	int	idx;

	mlx_mouse_get_pos(info->mlx.win, &x, &y);
	if ((0 <= x && x <= WIDTH) && (0 <= y && y <= HEIGHT))
	{
		if (x < info->bonus.mouse_x)
		{
			gap = info->bonus.mouse_x - x;
			key = KC_LEFT;
		}
		else
		{
			gap = x - info->bonus.mouse_x;
			key = KC_RIGHT;
		}
		idx = -1;
		while (++idx < 4)
			key_rotate_view(key, info, (MOUSE_SPEED * (gap)) / 4);
		info->bonus.mouse_x = x;
	}
	return (1);
}
