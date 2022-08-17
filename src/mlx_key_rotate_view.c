/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_rotate_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:36:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/17 10:18:43 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "key_event.h"
#include "cub3d.h"

static void	_rotate_dir(t_info *info, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->ray.dir_x;
	info->ray.dir_x = info->ray.dir_x * cos(rot_speed) - \
										info->ray.dir_y * sin(rot_speed);
	info->ray.dir_y = old_dir_x * sin(rot_speed) + \
										info->ray.dir_y * cos(rot_speed);
	old_plane_x = info->ray.plane_x;
	info->ray.plane_x = info->ray.plane_x * cos(rot_speed) - \
										info->ray.plane_y * sin(rot_speed);
	info->ray.plane_y = old_plane_x * sin(rot_speed) + \
										info->ray.plane_y * cos(rot_speed);
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
		info->ray.plane_y = POV;
	}
	else if (key == KC_J)
	{
		info->ray.dir_x = -1;
		info->ray.plane_y = -POV;
	}
	else if (key == KC_K)
	{
		info->ray.dir_y = 1;
		info->ray.plane_x = -POV;
	}
	else if (key == KC_I)
	{
		info->ray.dir_y = -1;
		info->ray.plane_x = POV;
	}
}

void	key_rotate_view(int key, t_info *info, double rot_speed)
{
	if (key == KC_LEFT)
		_rotate_dir(info, -rot_speed);
	else if (key == KC_RIGHT)
		_rotate_dir(info, rot_speed);
	else
		_set_dir_vector(key, info);
}
