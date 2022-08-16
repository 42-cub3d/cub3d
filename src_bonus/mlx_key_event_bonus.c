/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/17 00:44:34 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "key_event.h"
#include "mlx.h"

static int	_close_cube_three_d(t_info *info)
{
	ft_flush_info(info);
	exit(0);
	return (1);
}

static void	_toggle_value(int *toggle, int mode)
{
	if (*toggle == 0)
	{
		if (mode == LEFT_CLICK)
			mlx_mouse_show();
		*toggle = 1;
	}
	else
	{
		if (mode == LEFT_CLICK)
			mlx_mouse_hide();
		*toggle = 0;
	}
}

static int	_key_press(int key, t_info *info)
{
	if (key == KC_ESC)
		_close_cube_three_d(info);
	else if (is_move_or_rotate_key(key, 1))
		key_move(key, info);
	else if (is_move_or_rotate_key(key, 0))
		key_rotate_view(key, info, ROT_SPEED);
	else if (key == KC_F || key == KC_G)
		_print_info(info, key & 2);
	else if (key == KC_M)
		_toggle_value(&info->bonus.map_toggle, RIGHT_CLICK);
	else if (key == KC_Z)
		_toggle_value(&info->bonus.sprite_toggle, RIGHT_CLICK);
	else if (key == 257)
	{
		_toggle_value(&info->bonus.shift_toggle, RIGHT_CLICK);
		set_toggle_value(info->bonus.shift_toggle, &info->bonus.move_speed, \
												MOVE_SPEED * 1.66, MOVE_SPEED);
	}
	else if (key == KC_X)
	{
		_toggle_value(&info->bonus.x_toggle, RIGHT_CLICK);
		set_toggle_value(info->bonus.x_toggle, &info->bonus.move_speed, \
												MOVE_SPEED * 30, MOVE_SPEED);
	}
	return (1);
}

static int	_mouse_press_handle(int key, int x, int y, t_info *info)
{
	if ((info->bonus.mouse_init == 0) \
							&& (key == LEFT_CLICK || key == RIGHT_CLICK))
	{
		info->bonus.mouse_init |= 1;
		mlx_mouse_get_pos(info->mlx.win, &x, &y);
		info->bonus.mouse_x = x;
	}
	else if (key == LEFT_CLICK)
		_toggle_value(&info->bonus.mouse_toggle, LEFT_CLICK);
	else if (key == RIGHT_CLICK)
		_toggle_value(&info->bonus.map_toggle, RIGHT_CLICK);
	return (1);
}

int	ft_event_handler(t_info *info)
{
	mlx_hook(info->mlx.win, KEY_PRESS, 0, _key_press, info);
	mlx_hook(info->mlx.win, DESTROY_NOTIFY, 0, _close_cube_three_d, info);
	mlx_hook(info->mlx.win, BUTTON_PRESS, 0, _mouse_press_handle, info);
	mlx_hook(info->mlx.win, MOTION_NITOFY, 0, check_mouse_move, info);
	mlx_loop_hook(info->mlx.mlx, ft_ray_casting, info);
	return (0);
}
