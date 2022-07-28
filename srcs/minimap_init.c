/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:44:06 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/28 17:16:49 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mini_map_init(t_info *info)
{
	info->mini_map.m_x = info->map.width * MAP_RATIO;
	info->mini_map.m_y = info->map.height * MAP_RATIO;
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
	else
		color = 0xE7AB79;
	return (color);
}

static void	_draw_player(t_info *info)
{
	int	s_x;
	int	s_y;
	int	e_x;
	int	e_y;

	e_x = (info->ray.p_x + 0.3) * MAP_RATIO;
	e_y = (info->ray.p_y + 0.3) * MAP_RATIO;
	s_y = (info->ray.p_y - 0.3) * MAP_RATIO;
	while (s_y < e_y)
	{
		s_x = (info->ray.p_x - 0.3) * MAP_RATIO;
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
	int		x;
	int		y;
	int		color;

	y = 0;
	while (y < info->mini_map.m_y)
	{
		x = 0;
		while (x < info->mini_map.m_x)
		{
			if (x % MAP_RATIO == 0)
				color = _set_color(info->map.map[y / MAP_RATIO][x / MAP_RATIO]);
			ft_put_pixel(&info->mlx, x, y, color);
			x++;
		}
		y++;
	}
	_draw_player(info);
}
