/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:24:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/26 20:02:01 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_set_hit_tex(t_info *info, t_ray_beam *b)
{
	if (b->side == X_HIT)
	{
		if (info->ray.p_x < b->map_x)
			info->cur_tex = info->texture.textures[T_EAST];
		else
			info->cur_tex = info->texture.textures[T_WEST];
	}
	else if (b->side == Y_HIT)
	{
		if (info->ray.p_y < b->map_y)
			info->cur_tex = info->texture.textures[T_SOUTH];
		else
			info->cur_tex = info->texture.textures[T_NORTH];
	}
}

static void	_set_tex_step_and_position(t_info *info, t_ray_beam *b)
{
	t_tex_pos	t;

	t.tex_x = (int)(b->wallx * (double)TEXTURE_WIDTH);
	if ((b->side == X_HIT && b->ray_dir_x > 0) \
	|| (b->side == Y_HIT && b->ray_dir_y < 0))
		t.tex_x = TEXTURE_WIDTH - b->tex_x - 1;
	t.tex_step = 1.0 * TEXTURE_HEIGHT / b->line_height;
	t.tex_pos = (b->draw_start - HEIGHT / 2 + b->line_height / 2) * t.tex_step;
}

static void	_draw_texture_verline(t_info *info, t_ray_beam b)
{
	_set_hit_tex(info, &b);
	_set_tex_step_and_position(info, &b);
	// while (draw.draw_start < draw.draw_end)
	// {
	// 	draw.tex_y = (int)draw.tex_pos & (TEXTURE_HEIGHT - 1);
	// 	draw.tex_pos += draw.tex_step;
	// 	draw.color = info->cur_tex[draw.tex_x + draw.tex_y * TEXTURE_WIDTH];
	// 	if (draw.side == Y_HIT)
	// 		draw.color = (draw.color >> 1) & 0x7F7F7F;
	// 	ft_put_color(info, x, draw.draw_start, draw.color);
	// 	draw.draw_start++;
	// }

}

void	ft_ray_casting(t_info *info)
{
	int			x;
	t_draw	draw;

	x = 0;
	// ft_img_clear(info);
	while (x < WIDTH)
	{
		_draw_texture_verline(info, get_ray_beam_per_verline(info));
		x++;
	}
	ft_re_render(info);
}
