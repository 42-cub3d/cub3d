/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:24:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/28 14:57:54 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_set_hit_tex(t_info *info, t_ray_beam *b)
{
	if (b->hit_side == X_HIT)
	{
		if (info->ray.p_x < b->map_x)
			info->cur_tex = info->texture.textures[T_EAST];
		else
			info->cur_tex = info->texture.textures[T_WEST];
	}
	else
	{
		if (info->ray.p_y < b->map_y)
			info->cur_tex = info->texture.textures[T_SOUTH];
		else
			info->cur_tex = info->texture.textures[T_NORTH];
	}
}

static void	_set_tex_step_and_pos(t_tex_pos *t, t_ray_beam *b)
{
	t->tex_x = (int)(b->wallx * (double)TEXTURE_WIDTH);
	if ((b->hit_side == X_HIT && b->ray_dir_x > 0) \
	|| (b->hit_side == Y_HIT && b->ray_dir_y < 0))
		t->tex_x = TEXTURE_WIDTH - t->tex_x - 1;
	t->tex_step = 1.0 * TEXTURE_HEIGHT / b->line_height;
	t->tex_pos = \
				(b->draw_start - HEIGHT / 2 + b->line_height / 2) * t->tex_step;
}

static void	_draw_texture_workhorse(\
						t_info *info, t_tex_pos *t, t_ray_beam *b, int cur_x)
{
	ft_fill_floor_ceiling(info, b, cur_x);
	while (b->draw_start < b->draw_end)
	{
		t->tex_y = (int)t->tex_pos & (TEXTURE_HEIGHT - 1);
		t->tex_pos += t->tex_step;
		t->color = info->cur_tex[t->tex_x + t->tex_y * TEXTURE_WIDTH];
		if (b->hit_side == Y_HIT)
			t->color = (t->color >> 1) & 0x7F7F7F;
		ft_put_pixel(&info->mlx, cur_x, b->draw_start, t->color);
		b->draw_start++;
	}
}

static void	_draw_texture_verline(t_info *info, t_ray_beam b, int cur_x)
{
	t_tex_pos	t;

	_set_hit_tex(info, &b);
	_set_tex_step_and_pos(&t, &b);
	_draw_texture_workhorse(info, &t, &b, cur_x);
}

void	ft_ray_casting(t_info *info)
{
	int		x;

	x = 0;
	while (x < WIDTH)
	{
		_draw_texture_verline(info, get_ray_beam_per_verline(info, x), x);
		x++;
	}
	test_map_draw(info);
	ft_re_render(info);
}
