/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_work_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:24:55 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/18 16:01:10 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	_set_hit_tex(t_info *info, t_ray_beam *b)
{
	if (b->hit_type == TYPE_TEXT)
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
	else
		info->cur_tex = info->texture.textures[T_DOOR];
}

static void	_set_tex_step_and_pos(t_tex_pos *t, t_ray_beam *b)
{
	t->t_x = (int)(b->wallx * (double)TEXTURE_WIDTH);
	if ((b->hit_side == X_HIT && b->ray_dir_x > 0) \
	|| (b->hit_side == Y_HIT && b->ray_dir_y < 0))
		t->t_x = TEXTURE_WIDTH - t->t_x - 1;
	t->t_step = (double)TEXTURE_HEIGHT / b->line_height;
	t->t_pos = (b->draw_start - H_HEIGHT + b->line_height / 2) * t->t_step;
}

static void	_draw_texture_workhorse(\
						t_info *info, t_tex_pos *t, t_ray_beam *b, int cur_x)
{
	int		tex_pos;
	int		y;
	double	gamma;

	ft_fill_floor_ceiling(info, b, cur_x);
	y = b->draw_start;
	while (y < b->draw_end)
	{
		t->t_y = (int)t->t_pos & (TEXTURE_HEIGHT - 1);
		t->t_pos += t->t_step;
		tex_pos = t->t_x * TEXTURE_WIDTH + t->t_y;
		set_overflow(&tex_pos, 0, TEXTURE_WIDTH * TEXTURE_HEIGHT);
		t->color = info->cur_tex[tex_pos];
		gamma = get_gamma_tex(b->perp_wall_dist, info->mini_map.m_median);
		if (b->hit_type == TYPE_TEXT && b->hit_side == Y_HIT)
			t->color = (t->color >> 1) & 0x7F7F7F;
		if ((!info->bonus.map_toggle) || (info->bonus.map_toggle \
											&& !is_in_mini_map(info, cur_x, y)))
			ft_put_pixel(&info->mlx, cur_x, y, fade_color(t->color, gamma));
		y++;
	}
}

static void	_draw_texture_verline(t_info *info, int cur_x, double *z_buffer)
{
	z_buffer[cur_x] = info->b.perp_wall_dist;
	_set_hit_tex(info, &info->b);
	_set_tex_step_and_pos(&info->t, &info->b);
	_draw_texture_workhorse(info, &info->t, &info->b, cur_x);
}

int	ft_ray_casting(t_info *info)
{
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		get_ray_beam_verline(info, x);
		_draw_texture_verline(info, x, info->bonus.z_buffer);
		x++;
	}
	if (info->sprite_list)
		ft_draw_sprite(info, info->bonus.z_buffer);
	if (info->bonus.map_toggle)
		mini_map_draw(info);
	ft_re_render(info);
	info->fps++;
	if (info->fps >= FPS_MAX)
		info->fps = 0;
	return (0);
}
