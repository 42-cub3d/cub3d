/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/24 21:10:55 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "key_event.h"
#include "cub3d.h"
#include "mlx.h"

static void	_key_move(int key, t_info *info)
{
	size_t	x;
	size_t	y;

	if (key == KC_W)
	{
		x = (size_t)(info->ray.p_x + info->ray.dir_x * MOVE_SPEED);
		y = (size_t)(info->ray.p_y + info->ray.dir_y * MOVE_SPEED);
		if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
		{
			if ((info->map.map[y][x] != '1'))
			{
				info->ray.p_y += info->ray.dir_y * MOVE_SPEED;
				info->ray.p_x += info->ray.dir_x * MOVE_SPEED;
			}
		}
	}
	else if (key == KC_S)
	{
		x = (size_t)(info->ray.p_x - info->ray.dir_x * MOVE_SPEED);
		y = (size_t)(info->ray.p_y - info->ray.dir_y * MOVE_SPEED);
		if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
		{
			if ((info->map.map[y][x] != '1'))
			{
				info->ray.p_y -= info->ray.dir_y * MOVE_SPEED;
				info->ray.p_x -= info->ray.dir_x * MOVE_SPEED;
			}
		}
	}
	ft_ray_casting(info, RENDER);
}

static void	_key_view(int key, t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->ray.dir_x;
	if (key == KC_LEFT)
	{
		info->ray.dir_x = info->ray.dir_x * cos(-ROT_SPEED) - \
											info->ray.dir_y * sin(-ROT_SPEED);
		info->ray.dir_y = old_dir_x * sin(-ROT_SPEED) + \
											info->ray.dir_y * cos(-ROT_SPEED);
		old_plane_x = info->ray.plane_x;
		info->ray.plane_x = info->ray.plane_x * cos(-ROT_SPEED) - \
											info->ray.plane_y * sin(-ROT_SPEED);
		info->ray.plane_y = old_plane_x * sin(-ROT_SPEED) + \
											info->ray.plane_y * cos(-ROT_SPEED);
	}
	else if (key == KC_RIGHT)
	{
		info->ray.dir_x = info->ray.dir_x * cos(ROT_SPEED) - \
											info->ray.dir_y * sin(ROT_SPEED);
		info->ray.dir_y = old_dir_x * sin(ROT_SPEED) + \
											info->ray.dir_y * cos(ROT_SPEED);
		old_plane_x = info->ray.plane_x;
		info->ray.plane_x = info->ray.plane_x * cos(ROT_SPEED) - \
											info->ray.plane_y * sin(ROT_SPEED);
		info->ray.plane_y = old_plane_x * sin(ROT_SPEED) + \
											info->ray.plane_y * cos(ROT_SPEED);
	}
	ft_ray_casting(info, RENDER);
}

static int	_close_cube_three_d(t_info *info)
{
	ft_flush_info(info);
	exit(0);
}

static int	_key_press(int key, t_info *info)
{
	if (key == KC_ESC)
		_close_cube_three_d(info);
	else if (key == KC_W || key == KC_A || key == KC_S || key == KC_D)
		_key_move(key, info);
	else if (key == KC_LEFT || key == KC_RIGHT)
		_key_view(key, info);
	else if (key == KC_M)
		_print_info(info);
	return (1);
}

void	ft_event_handler(t_info *info)
{
	mlx_hook(info->mlx.win, KEY_PRESS, 0, _key_press, info);
	mlx_hook(info->mlx.win, DESTROY_NOTIFY, 0, _close_cube_three_d, info);
}
