/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:25:53 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/25 02:17:50 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "key_event.h"

static void	_key_rightward(t_info *info)
{
	size_t	x;
	size_t	y;

	x = (size_t)(info->ray.p_x + info->ray.plane_x * MOVE_SPEED);
	y = (size_t)(info->ray.p_y + info->ray.plane_y * MOVE_SPEED);
	if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
	{
		if ((info->map.map[y][x] != '1'))
		{
			info->ray.p_x += info->ray.plane_x * MOVE_SPEED;
			info->ray.p_y += info->ray.plane_y * MOVE_SPEED;
		}
	}
}

static void	_key_leftward(t_info *info)
{
	size_t	x;
	size_t	y;

	x = (size_t)(info->ray.p_x - info->ray.plane_x * MOVE_SPEED);
	y = (size_t)(info->ray.p_y - info->ray.plane_y * MOVE_SPEED);
	if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
	{
		if ((info->map.map[y][x] != '1'))
		{
			info->ray.p_x -= info->ray.plane_x * MOVE_SPEED;
			info->ray.p_y -= info->ray.plane_y * MOVE_SPEED;
		}
	}
}

static void	_key_forward(t_info *info)
{
	size_t	x;
	size_t	y;

	x = (size_t)(info->ray.p_x + info->ray.dir_x * MOVE_SPEED);
	y = (size_t)(info->ray.p_y + info->ray.dir_y * MOVE_SPEED);
	if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
	{
		if ((info->map.map[y][x] != '1'))
		{
			info->ray.p_x += info->ray.dir_x * MOVE_SPEED;
			info->ray.p_y += info->ray.dir_y * MOVE_SPEED;
		}
	}
}

static void	_key_backward(t_info *info)
{
	size_t	x;
	size_t	y;

	x = (size_t)(info->ray.p_x - info->ray.dir_x * MOVE_SPEED);
	y = (size_t)(info->ray.p_y - info->ray.dir_y * MOVE_SPEED);
	if (0 <= x && 0 <= y && x < info->map.width && y < info->map.height)
	{
		if ((info->map.map[y][x] != '1'))
		{
			info->ray.p_x -= info->ray.dir_x * MOVE_SPEED;
			info->ray.p_y -= info->ray.dir_y * MOVE_SPEED;
		}
	}
}

void	key_move(int key, t_info *info)
{
	if (key == KC_W)
		_key_forward(info);
	else if (key == KC_S)
		_key_backward(info);
	else if (key == KC_A)
		_key_leftward(info);
	else if (key == KC_D)
		_key_rightward(info);
	else
		return ;
	ft_ray_casting(info);
}
