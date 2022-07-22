/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:24:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/22 22:09:33 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_dda_loop(t_info *info, t_cast_info *beam)
{
	while (!beam->hit)
	{
		if (beam->side_dist_x < beam->side_dist_y)
		{
			beam->side_dist_x += beam->delta_dist_x;
			beam->map_x += beam->step_x;
			beam->side = 0;
		}
		else
		{
			beam->side_dist_y += beam->delta_dist_y;
			beam->map_y += beam->step_y;
			beam->side = 1;
		}
		if (info->map.map[beam->map_y][beam->map_x] == '1')
			beam->hit = 1;
	}
	if (!beam->side)
		beam->perp_wall_dist = (beam->map_x - info->ray.p_x + \
									(1 - beam->step_x) / 2) / beam->ray_dir_x;
	else
		beam->perp_wall_dist = (beam->map_y - info->ray.p_y + \
									(1 - beam->step_y) / 2) / beam->ray_dir_y;
}

static void	_set_dda_step(t_info *info, t_cast_info *beam)
{
	if (beam->ray_dir_x < 0)
	{
		beam->step_x = -1;
		beam->side_dist_x = (info->ray.p_x - beam->map_x) * beam->delta_dist_x;
	}
	else
	{
		beam->step_x = 1;
		beam->side_dist_x = (beam->map_x + 1.0 - info->ray.p_x) * \
															beam->delta_dist_x;
	}
	if (beam->ray_dir_y < 0)
	{
		beam->step_y = -1;
		beam->side_dist_y = (info->ray.p_y - beam->map_y) * beam->delta_dist_y;
	}
	else
	{
		beam->step_y = 1;
		beam->side_dist_y = (beam->map_y + 1.0 - info->ray.p_y) * \
															beam->delta_dist_y;
	}
}

static float	get_perp_wall_dist(t_info *info, int x)
{
	t_cast_info	beam;

	beam.cam = 2 * x / (double)WIDTH - 1;
	beam.ray_dir_x = info->ray.dir_x + info->ray.plane_x * beam.cam;
	beam.ray_dir_y = info->ray.dir_y + info->ray.plane_y * beam.cam;
	beam.map_x = (int)info->ray.p_x;
	beam.map_y = (int)info->ray.p_y;
	beam.delta_dist_x = fabs(1 / beam.ray_dir_x);
	beam.delta_dist_y = fabs(1 / beam.ray_dir_y);
	beam.hit = 0;
	_set_dda_step(info, &beam);
	_dda_loop(info, &beam);
	return (beam.perp_wall_dist);
}

void	ft_ray_casting(t_info *info)
{
	int		x;
	t_draw	draw;

	x = 0;
	while (x < WIDTH)
	{
		draw.line_height = (int)(HEIGHT / get_perp_wall_dist(info, x));
		draw.draw_start = -draw.line_height / 2 + HEIGHT / 2;
		if (draw.draw_start < 0)
			draw.draw_start = 0;
		draw.draw_end = draw.line_height / 2 + HEIGHT / 2;
		if (draw.draw_end >= HEIGHT)
			draw.draw_end = HEIGHT - 1;
		printf("%d %d %d %d\n", x, draw.draw_start, draw.draw_end, draw.line_height);
		x++;
	}
}
