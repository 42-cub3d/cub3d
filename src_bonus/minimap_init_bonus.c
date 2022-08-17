/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:44:06 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/17 14:43:29 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mini_map_init(t_info *info)
{
	if ((WIDTH / 2 / info->map.width) < (HEIGHT / 2 / info->map.height))
		info->mini_map.m_ratio = (double)(WIDTH / 2) / info->map.width;
	else
		info->mini_map.m_ratio = (double)(HEIGHT / 2) / info->map.height;
	info->mini_map.m_x = ((info->map.width) * info->mini_map.m_ratio);
	info->mini_map.m_y = ((info->map.height) * info->mini_map.m_ratio);
	info->mini_map.m_median = (info->map.width + info->map.height) / 2.0;
	if (info->mini_map.m_ratio < 6)
		info->mini_map.scalar = 10 / info->mini_map.m_ratio;
	else
		info->mini_map.scalar = 1;
	if (info->mini_map.m_median > 100)
		info->mini_map.m_median = 100;
}

int	is_in_mini_map(t_info *info, int x, int y)
{
	return (x < info->mini_map.m_x && y < info->mini_map.m_y);
}

static int	_set_color(char monad)
{
	int	color;

	if (monad == '1')
		color = 0x4C3A51;
	else if (monad == ' ')
		color = 0x000000;
	else if (monad == '2')
		color = 0x53F3EB;
	else if (monad == '4')
		color = 0x23837B;
	else if (monad == '3')
		color = 0xFA2FB5;
	else
		color = 0xE7AB79;
	return (color);
}

static void	_draw_player(t_info *info)
{
	int		s_x;
	int		s_y;
	int		e_x;
	int		e_y;
	double	scalar;

	scalar = 0.3 * info->mini_map.scalar;
	e_x = (info->ray.p_x + scalar) * info->mini_map.m_ratio;
	e_y = (info->ray.p_y + scalar) * info->mini_map.m_ratio;
	s_y = (info->ray.p_y - scalar) * info->mini_map.m_ratio;
	while (s_y < e_y)
	{
		s_x = (info->ray.p_x - scalar) * info->mini_map.m_ratio;
		while (s_x < e_x)
		{
			if (is_in_mini_map(info, s_x, s_y))
				ft_put_pixel(&info->mlx, s_x, s_y, 0xD61C4E);
			s_x++;
		}
		s_y++;
	}
}

void	mini_map_draw(t_info *info)
{
	int	x;
	int	y;
	int	color;
	int	prev_map_x;

	y = 0;
	while (y < info->mini_map.m_y)
	{
		x = 0;
		prev_map_x = -1;
		while (x < info->mini_map.m_x)
		{
			if ((int)(x / info->mini_map.m_ratio) != prev_map_x)
			{
				prev_map_x = (int)(x / info->mini_map.m_ratio);
				color = _set_color(\
				info->map.map[(int)(y / info->mini_map.m_ratio)][prev_map_x]);
			}
			ft_put_pixel(&info->mlx, x, y, color);
			x++;
		}
		y++;
	}
	_draw_player(info);
}
