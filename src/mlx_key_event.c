/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/15 16:49:10 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_event.h"
#include "mlx.h"

static int	_close_cube_three_d(t_info *info)
{
	ft_flush_info(info);
	exit(0);
	return (1);
}

static int	_key_press(int key, t_info *info)
{
	if (key == KC_ESC)
		_close_cube_three_d(info);
	else if (key == KC_W || key == KC_A || key == KC_S || key == KC_D)
		key_move(key, info);
	else if (key == KC_LEFT || key == KC_RIGHT \
	|| key == KC_I || key == KC_J || key == KC_K || key == KC_L)
		key_rotate_view(key, info, ROT_SPEED);
	else if (key == KC_F)
		_print_info(info);
	return (1);
}

void	ft_event_handler(t_info *info)
{
	mlx_mouse_hide();
	mlx_hook(info->mlx.win, KEY_PRESS, 0, _key_press, info);
	mlx_hook(info->mlx.win, DESTROY_NOTIFY, 0, _close_cube_three_d, info);
}
