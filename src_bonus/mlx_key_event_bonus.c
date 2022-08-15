/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_event_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 01:48:08 by yongmkim         ###   ########seoul.kr  */
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

static void	_toggle_mouse_view(t_info *info, int *toggle, int mode)
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
	if (mode == RIGHT_CLICK)
		ft_ray_casting(info);
}

static int	_key_press(int key, t_info *info)
{
	if (key == KC_ESC)
		_close_cube_three_d(info);
	else if (\
	key == KC_W || key == KC_A || key == KC_S || key == KC_D || key == KC_E)
		key_move(key, info);
	else if (key == KC_LEFT || key == KC_RIGHT \
	|| key == KC_I || key == KC_J || key == KC_K || key == KC_L)
		key_rotate_view(key, info, ROT_SPEED);
	else if (key == KC_F)
		_print_info(info);
	else if (key == KC_M)
		_toggle_mouse_view(info, &info->bonus.map_toggle, RIGHT_CLICK);
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
		_toggle_mouse_view(info, &info->bonus.mouse_toggle, LEFT_CLICK);
	else if (key == RIGHT_CLICK)
		_toggle_mouse_view(info, &info->bonus.map_toggle, RIGHT_CLICK);
	return (1);
}

void	ft_event_handler(t_info *info)
{
	mlx_mouse_hide();
	mlx_hook(info->mlx.win, KEY_PRESS, 0, _key_press, info);
	mlx_hook(info->mlx.win, DESTROY_NOTIFY, 0, _close_cube_three_d, info);
	mlx_hook(info->mlx.win, BUTTON_PRESS, 0, _mouse_press_handle, info);
	mlx_hook(info->mlx.win, MOTION_NITOFY, 0, check_mouse_move, info);
}

// mlx_loop_hook(info->mlx.mlx, check_mouse_move, info);
