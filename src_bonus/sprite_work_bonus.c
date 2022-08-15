/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_work_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:53:41 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 01:57:19 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	_set_sprite_transform(t_info *info, t_sprite *vec, t_sprite_beam *b)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = vec->x - info->ray.p_x;
	sprite_y = vec->y - info->ray.p_y;
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
	if (b->draw_start_y < 0)
		b->draw_start_y = 0;
	b->draw_end_y = b->s_height / 2 + HEIGHT / 2 + b->v_move_screen;
	if (b->draw_end_y > HEIGHT)
		b->draw_end_y = HEIGHT;
	b->s_width = ft_abs((int)(HEIGHT / b->transform_y)) / U_DIV;
	b->draw_start_x = -b->s_width / 2 + b->s_screen_x;
	if (b->draw_start_x < 0)
		b->draw_start_x = 0;
	b->draw_end_x = b->s_width / 2 + b->s_screen_x;
	if (b->draw_end_x > WIDTH)
		b->draw_end_x = WIDTH;
}

static void	_draw_sprite_verline2(\
					t_info *info, t_sprite_beam *b, double *z_buffer, int x)
{
	const size_t	arr_tex_x = x * TEXTURE_WIDTH;
	int				y;
	int				d;
	int				tex_y;
	int				color;

	if (b->transform_y > 0 && b->transform_y < z_buffer[x])
	{
		y = b->draw_start_y;
		while (y < b->draw_end_y)
		{
			d = (y - b->v_move_screen) * 256 - HEIGHT * 128 + b->s_height * 128;
			tex_y = ((d * TEXTURE_HEIGHT) / b->s_height) / 256;
			info->cur_tex = info->texture.textures[5 + (info->fps / FPS_CNT)];
			color = info->cur_tex[arr_tex_x + tex_y];
			if ((0x000000 <= color && color <= 0xffffff) \
			&& ((!info->bonus.map_toggle) \
				|| (info->bonus.map_toggle \
				&& !is_in_mini_map(info, b->draw_start_x, b->draw_start_y))))
				ft_put_pixel(&info->mlx, b->draw_start_x, y, color);
			y++;
		}
	}
}

static void	_draw_sprite_verline(\
						t_info *info, t_sprite_beam *b, double *z_buffer)
{
	int	x;

	while (b->draw_start_x < b->draw_end_x)
	{
		x = (int)(256 * (b->draw_start_x - (-b->s_width / 2 + b->s_screen_x)) \
											* TEXTURE_WIDTH / b->s_width) / 256;
		_draw_sprite_verline2(info, b, z_buffer, x);
		b->draw_start_x++;
	}
}

void	ft_draw_sprite(t_info *info, double *z_buffer)
{
	t_list			*temp;
	t_sprite_beam	b;

	temp = info->sprite_list;
	while (temp)
	{
		_set_sprite_transform(info, temp->content, &b);
		_set_sprite_beam(&b);
		_draw_sprite_verline(info, &b, z_buffer);
		ft_lstdelone(temp, free);
		temp = temp->next;
	}
	info->fps++;
	if (info->fps >= FPS_MAX)
		info->fps = 0;
}
