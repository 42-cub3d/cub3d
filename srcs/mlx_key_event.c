/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 22:24:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "key_event.h"
#include "cub3d.h"
#include "mlx.h"

static void	_key_move(int key, t_info *info)
{
	(void)key;
	(void)info;


	//ft_render
}

static void	_key_view(int key, t_info *info)
{

	(void)key;
	(void)info;

	//ft_render
}

static int	_key_press(int key, t_info *info)
{
	if (key == KC_ESC)
	{
		ft_flush_info(info);
		exit(0);
	}
	else if (key == KC_W || key == KC_A || key == KC_S || key == KC_D)
		_key_move(key, info);
	else if (key == KC_LEFT || key == KC_RIGHT)
		_key_view(key, info);
	return (1);
}

static int	_close_cube_three_d(t_info *info)
{
	ft_flush_info(info);
	exit(0);
}

void	ft_event_handler(t_info *info)
{
	mlx_hook(info->mlx->win, KEY_PRESS, 0, _key_press, info);
	mlx_hook(info->mlx->win, DESTROY_NOTIFY, 0, _close_cube_three_d, info);
}
