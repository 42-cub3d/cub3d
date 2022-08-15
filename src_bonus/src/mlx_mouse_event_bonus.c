/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_event.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 01:35:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/15 16:22:17 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "key_event.h"
#include "mlx.h"

int	check_mouse_move(t_info *info)
{
	int	x;
	int	y;
	int	gap;

	mlx_mouse_get_pos(info->mlx.win, &x, &y);
	if ((0 <= x && x <= WIDTH) && (0 <= y && y <= HEIGHT))
	{
		if (x < info->bonus.mouse_x)
		{
			gap = info->bonus.mouse_x - x;
			key_rotate_view(KC_LEFT, info, MOUSE_SPEED * (gap / 2));
		}
		else
		{
			gap = x - info->bonus.mouse_x;
			key_rotate_view(KC_RIGHT, info, MOUSE_SPEED * (gap / 2));
		}
		info->bonus.mouse_x = x;
		mlx_do_sync(info->mlx.mlx);
	}
	return (1);
}
