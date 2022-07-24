/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_rotate_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:36:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/25 02:26:19 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "key_event.h"
#include "cub3d.h"

static void	_rotate_right(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->ray.dir_x;
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

static void	_rotate_left(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->ray.dir_x;
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

static void	_set_dir_vector(int key, t_info *info)
{
	info->ray.plane_x = 0;
	info->ray.plane_y = 0;
	info->ray.dir_x = 0;
	info->ray.dir_y = 0;
	if (key == KC_L)
	{
		info->ray.dir_x = 1;
		info->ray.plane_y = 0.66;
	}
	else if (key == KC_J)
	{
		info->ray.dir_x = -1;
		info->ray.plane_y = -0.66;
	}
	else if (key == KC_K)
	{
		info->ray.dir_y = 1;
		info->ray.plane_x = -0.66;
	}
	else if (key == KC_I)
	{
		info->ray.dir_y = -1;
		info->ray.plane_x = 0.66;
	}
}

void	key_rotate_view(int key, t_info *info)
{
	if (key == KC_LEFT)
		_rotate_left(info);
	else if (key == KC_RIGHT)
		_rotate_right(info);
	else
		_set_dir_vector(key, info);
	ft_ray_casting(info);
}
