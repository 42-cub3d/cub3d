/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:46:18 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/15 22:47:16 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	_set_draw_position(t_info *info, t_ray_beam *b)
{
	if (info->map.map[b->map_y][b->map_x] == '1')
		b->hit_type = TYPE_TEXT;
	else if (info->map.map[b->map_y][b->map_x] == '2')
		b->hit_type = TYPE_DOOR;
	b->line_height = (int)(HEIGHT / b->perp_wall_dist);
	b->draw_start = -b->line_height / 2 + HEIGHT / 2;
	if (b->draw_start < 0)
		b->draw_start = 0;
	b->draw_end = b->line_height / 2 + HEIGHT / 2;
	if (b->draw_end >= HEIGHT)
		b->draw_end = HEIGHT;
	if (b->hit_side == X_HIT)
		b->wallx = info->ray.p_y + b->perp_wall_dist * b->ray_dir_y;
	else
		b->wallx = info->ray.p_x + b->perp_wall_dist * b->ray_dir_x;
	b->wallx -= floor(b->wallx);
}

static void	_dda_working(t_info *info, t_ray_beam *b)
{
	while (!b->hit)
	{
		if (b->side_dist_x < b->side_dist_y)
		{
			b->side_dist_x += b->delta_dist_x;
			b->map_x += b->step_x;
			b->hit_side = X_HIT;
		}
		else
		{
			b->side_dist_y += b->delta_dist_y;
			b->map_y += b->step_y;
			b->hit_side = Y_HIT;
		}
		if (ft_strchr("12", info->map.map[b->map_y][b->map_x]))
			b->hit = 1;
		else if (info->map.map[b->map_y][b->map_x] == '3')
			sprite_add(info, b);
	}
	if (b->hit_side == X_HIT)
		b->perp_wall_dist = \
				(b->map_x - info->ray.p_x + (1 - b->step_x) / 2) / b->ray_dir_x;
	else
		b->perp_wall_dist = \
				(b->map_y - info->ray.p_y + (1 - b->step_y) / 2) / b->ray_dir_y;
}

static void	_set_dda_step(t_info *info, t_ray_beam *b)
{
	if (b->ray_dir_x < 0)
	{
		b->step_x = -1;
		b->side_dist_x = (info->ray.p_x - b->map_x) * b->delta_dist_x;
	}
	else
	{
		b->step_x = 1;
		b->side_dist_x = (b->map_x + 1.0 - info->ray.p_x) * b->delta_dist_x;
	}
	if (b->ray_dir_y < 0)
	{
		b->step_y = -1;
		b->side_dist_y = (info->ray.p_y - b->map_y) * b->delta_dist_y;
	}
	else
	{
		b->step_y = 1;
		b->side_dist_y = (b->map_y + 1.0 - info->ray.p_y) * b->delta_dist_y;
	}
}

static void	_set_ray_beam(t_info *info, t_ray_beam *b, int cur_x)
{
	b->cam = 2 * cur_x / (double)WIDTH - 1;
	b->ray_dir_x = info->ray.dir_x + info->ray.plane_x * b->cam;
	b->ray_dir_y = info->ray.dir_y + info->ray.plane_y * b->cam;
	b->map_x = (int)info->ray.p_x;
	b->map_y = (int)info->ray.p_y;
	b->delta_dist_x = fabs(1 / b->ray_dir_x);
	b->delta_dist_y = fabs(1 / b->ray_dir_y);
	b->hit = 0;
}

t_ray_beam	get_ray_beam_verline(t_info *info, int cur_x)
{
	t_ray_beam	b;

	_set_ray_beam(info, &b, cur_x);
	_set_dda_step(info, &b);
	_dda_working(info, &b);
	_set_draw_position(info, &b);
	return (b);
}
