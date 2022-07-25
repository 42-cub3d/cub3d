/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:24:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/25 16:26:30 by yongmkim         ###   ########seoul.kr  */
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
			beam->draw.map_x += beam->step_x;
			beam->draw.side = X_HIT;
		}
		else
		{
			beam->side_dist_y += beam->delta_dist_y;
			beam->draw.map_y += beam->step_y;
			beam->draw.side = Y_HIT;
		}
		if (info->map.map[beam->draw.map_y][beam->draw.map_x] == '1')
			beam->hit = 1;
	}
	if (beam->draw.side == X_HIT)
		beam->perp_walld = (beam->draw.map_x - info->ray.p_x + \
								(1 - beam->step_x) / 2) / beam->draw.ray_dir_x;
	else if (beam->draw.side == Y_HIT)
		beam->perp_walld = (beam->draw.map_y - info->ray.p_y + \
								(1 - beam->step_y) / 2) / beam->draw.ray_dir_y;
}

static void	_set_dda_step(t_info *info, t_cast_info *beam)
{
	if (beam->draw.ray_dir_x < 0)
	{
		beam->step_x = -1;
		beam->side_dist_x = (info->ray.p_x - beam->draw.map_x) * \
															beam->delta_dist_x;
	}
	else
	{
		beam->step_x = 1;
		beam->side_dist_x = (beam->draw.map_x + 1.0 - info->ray.p_x) * \
															beam->delta_dist_x;
	}
	if (beam->draw.ray_dir_y < 0)
	{
		beam->step_y = -1;
		beam->side_dist_y = (info->ray.p_y - beam->draw.map_y) * \
															beam->delta_dist_y;
	}
	else
	{
		beam->step_y = 1;
		beam->side_dist_y = (beam->draw.map_y + 1.0 - info->ray.p_y) * \
															beam->delta_dist_y;
	}
}

static t_draw	_get_wallx(t_info *info, int x)
{
	t_cast_info	beam;

	beam.cam = 2 * x / (double)WIDTH - 1;
	beam.draw.ray_dir_x = info->ray.dir_x + info->ray.plane_x * beam.cam;
	beam.draw.ray_dir_y = info->ray.dir_y + info->ray.plane_y * beam.cam;
	beam.draw.map_x = (int)info->ray.p_x;
	beam.draw.map_y = (int)info->ray.p_y;
	beam.delta_dist_x = fabs(1 / beam.draw.ray_dir_x);
	beam.delta_dist_y = fabs(1 / beam.draw.ray_dir_y);
	beam.hit = 0;
	_set_dda_step(info, &beam);
	_dda_loop(info, &beam);
	beam.draw.line_height = (int)(HEIGHT / beam.perp_walld);
	beam.draw.draw_start = -beam.draw.line_height / 2 + HEIGHT / 2;
	if (beam.draw.draw_start < 0)
		beam.draw.draw_start = 0;
	beam.draw.draw_end = beam.draw.line_height / 2 + HEIGHT / 2;
	if (beam.draw.draw_end >= HEIGHT)
		beam.draw.draw_end = HEIGHT - 1;
	if (beam.draw.side == X_HIT)
		beam.draw.wallx = info->ray.p_y + beam.perp_walld * beam.draw.ray_dir_y;
	else if (beam.draw.side == Y_HIT)
		beam.draw.wallx = info->ray.p_x + beam.perp_walld * beam.draw.ray_dir_x;
	beam.draw.wallx -= floor(beam.draw.wallx);
	return (beam.draw);
}

static t_draw	_get_tex_pos(t_info *info, t_draw draw)
{
	draw.tex_x = (int)(draw.wallx * (double)TEXTURE_WIDTH);
	if ((draw.side == X_HIT && draw.ray_dir_x > 0) \
	|| (draw.side == Y_HIT && draw.ray_dir_y < 0))
		draw.tex_x = TEXTURE_WIDTH - draw.tex_x - 1;
	draw.tex_step = 1.0 * TEXTURE_HEIGHT / draw.line_height;
	draw.tex_pos = (draw.draw_start - HEIGHT / 2 + draw.line_height / 2) * \
																draw.tex_step;
	if (draw.side == X_HIT)
	{
		if (info->ray.p_x < draw.map_x)
			info->cur_tex = info->texture.textures[T_EAST];
		else
			info->cur_tex = info->texture.textures[T_WEST];
	}
	else if (draw.side == Y_HIT)
	{
		if (info->ray.p_y < draw.map_y)
			info->cur_tex = info->texture.textures[T_SOUTH];
		else
			info->cur_tex = info->texture.textures[T_NORTH];
	}
	return (draw);
}

void	ft_ray_casting(t_info *info)
{
	int		x;
	t_draw	draw;

	x = 0;
	ft_img_clear(info);
	while (x < WIDTH)
	{
		draw = _get_tex_pos(info, _get_wallx(info, x));
		while (draw.draw_start < draw.draw_end)
		{
			draw.tex_y = (int)draw.tex_pos & (TEXTURE_HEIGHT - 1);
			draw.tex_pos += draw.tex_step;
			draw.color = info->cur_tex[draw.tex_x + draw.tex_y * TEXTURE_WIDTH];
			if (draw.side == Y_HIT)
				draw.color = (draw.color >> 1) & 0x7F7F7F;
			ft_put_color(info, x, draw.draw_start, draw.color);
			draw.draw_start++;
		}
		x++;
	}
	ft_re_render(info);
}
