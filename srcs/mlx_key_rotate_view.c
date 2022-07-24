/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_rotate_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:36:17 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/24 21:39:50 by yongmkim         ###   ########seoul.kr  */
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

void	key_rotate_view(int key, t_info *info)
{
	if (key == KC_LEFT)
		_rotate_left(info);
	else if (key == KC_RIGHT)
		_rotate_right(info);
	ft_ray_casting(info, RENDER);
}
