/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_work_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:53:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 14:57:30 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	_set_sprite_transform(t_info *info, t_sprite *vec, t_sprite_beam *b)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = vec->x - info->ray.p_x + 0.5;
	sprite_y = vec->y - info->ray.p_y + 0.5;
	inv_det = 1.0 / (info->ray.plane_x * info->ray.dir_y \
										- info->ray.dir_x * info->ray.plane_y);
	b->transform_x = inv_det * (info->ray.dir_y * sprite_x \
												- info->ray.dir_x * sprite_y);
	b->transform_y = inv_det * (-info->ray.plane_y * sprite_x \
												+ info->ray.plane_x * sprite_y);
}

static void	_set_sprite_beam(t_sprite_beam *b)
{
	b->s_screen_x = (int)((WIDTH / 2) * (1 + b->transform_x / b->transform_y));
	b->v_move_screen = (int)(V_MOVE / b->transform_y);
	b->s_height = ft_abs((int)(HEIGHT / b->transform_y)) / V_DIV;
	b->draw_start_y = -b->s_height / 2 + HEIGHT / 2 + b->v_move_screen;
	b->draw_end_y = b->s_height / 2 + HEIGHT / 2 + b->v_move_screen;
	b->s_width = ft_abs((int)(HEIGHT / b->transform_y)) / U_DIV;
	b->draw_start_x = -b->s_width / 2 + b->s_screen_x;
	b->draw_end_x = b->s_width / 2 + b->s_screen_x;
	set_overflow_min(&b->draw_start_y, 0);
	set_overflow_min(&b->draw_start_x, 0);
	set_overflow_max(&b->draw_end_y, HEIGHT);
	set_overflow_max(&b->draw_end_x, WIDTH);
}

static void	_draw_sprite_verline_y(\
					t_info *info, t_sprite_beam *b, double *z_buffer, int x)
{
	int	tex_pos;
	int	y;
	int	d;
	int	tex_y;
	int	color;

	if ((b->transform_y > 0) && ((0 <= x && x < WIDTH) \
											&& (b->transform_y < z_buffer[x])))
	{
		y = b->draw_start_y;
		while (y < b->draw_end_y)
		{
			d = (y - b->v_move_screen) * 256 - HEIGHT * 128 + b->s_height * 128;
			tex_y = ((d * TEXTURE_HEIGHT) / b->s_height) / 256;
			tex_pos = b->tex_x * TEXTURE_WIDTH + tex_y;
			set_overflow(&tex_pos, 0, TEXTURE_WIDTH * TEXTURE_HEIGHT);
			color = info->cur_tex[tex_pos];
			if ((0 <= color) \
			&& ((!info->bonus.map_toggle) \
					|| (info->bonus.map_toggle && !is_in_mini_map(info, x, y))))
				ft_put_pixel(&info->mlx, x, y, color);
			y++;
		}
	}
}

static void	_draw_sprite_verline(\
							t_info *info, t_sprite_beam *b, double *z_buffer)
{
	int	x;

	x = b->draw_start_x;
	while (x < b->draw_end_x)
	{
		b->tex_x = (int)(256 \
					* (x - (-b->s_width / 2 + b->s_screen_x)) \
					* TEXTURE_WIDTH / b->s_width) / 256;
		_draw_sprite_verline_y(info, b, z_buffer, x);
		x++;
	}
}

void	ft_draw_sprite(t_info *info, double *z_buffer)
{
	t_list			*temp;
	t_list			*prev;
	t_sprite_beam	b;

	temp = info->sprite_list;
	prev = NULL;
	if (info->bonus.sprite_toggle)
		ft_print_sprite_pos(info);
	info->cur_tex = info->texture.textures[5 + \
						set_sprite_texture(&info->fps, 0, FPS_MAX / FPS_CNT)];
	while (temp)
	{
		_set_sprite_transform(info, temp->content, &b);
		_set_sprite_beam(&b);
		_draw_sprite_verline(info, &b, z_buffer);
		prev = temp;
		temp = temp->next;
		ft_lstdelone(prev, free);
	}
	info->sprite_list = NULL;
	if (info->bonus.sprite_toggle)
		info->bonus.sprite_toggle = 0;
}
