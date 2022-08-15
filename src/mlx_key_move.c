/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:25:53 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/15 16:47:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_event.h"

static void	_key_move(t_info *info, double dir_x, double dir_y)
{
	size_t	x;
	size_t	y;

	x = (size_t)(info->ray.p_x + dir_x * MOVE_SPEED);
	y = (size_t)(info->ray.p_y + dir_y * MOVE_SPEED);
	if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
	{
		if (!ft_strchr("12", info->map.map[y][x]))
		{
			info->ray.p_x += dir_x * MOVE_SPEED;
			info->ray.p_y += dir_y * MOVE_SPEED;
		}
	}
}

void	key_move(int key, t_info *info)
{
	if (key == KC_W)
		_key_move(info, info->ray.dir_x, info->ray.dir_y);
	else if (key == KC_S)
		_key_move(info, -info->ray.dir_x, -info->ray.dir_y);
	else if (key == KC_A)
		_key_move(info, -info->ray.plane_x, -info->ray.plane_y);
	else if (key == KC_D)
		_key_move(info, info->ray.plane_x, info->ray.plane_y);
	ft_ray_casting(info);
}
