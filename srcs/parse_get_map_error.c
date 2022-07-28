/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:58:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/28 20:36:07 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_check_wall(size_t x, size_t y, t_map map)
{
	if ((0 < x && !ft_strchr("1 ", map.map[y][x - 1]))
	|| (0 < y && !ft_strchr("1 ", map.map[y - 1][x]))
	|| (x + 1 < map.width && !ft_strchr("1 ", map.map[y][x + 1]))
	|| (y + 1 < map.height && !ft_strchr("1 ", map.map[y + 1][x]))
	|| ((0 < x && 0 < y)
		&& !ft_strchr("1 ", map.map[y - 1][x - 1]))
	|| ((x + 1 < map.width && 0 < y)
		&& !ft_strchr("1 ", map.map[y - 1][x + 1]))
	|| ((0 < x && y + 1 < map.height)
		&& !ft_strchr("1 ", map.map[y + 1][x - 1]))
	|| ((x + 1 < map.width && y + 1 < map.height)
		&& !ft_strchr("1 ", map.map[y + 1][x + 1])))
		return (MAP_FAILURE);
	return (MAP_SUCCESS);
}

static int	_check_player(t_player *p, t_map *map, char dir)
{
	if (p->pdir)
		return (MAP_FAILURE);
	p->pdir = dir;
	map->p_info.px = p->px;
	map->p_info.py = p->py;
	if (dir == 'E')
		map->p_info.pdir = POS_E;
	else if (dir == 'W')
		map->p_info.pdir = POS_W;
	else if (dir == 'S')
		map->p_info.pdir = POS_S;
	else if (dir == 'N')
		map->p_info.pdir = POS_N;
	return (MAP_SUCCESS);
}

static void	_check_error_case(t_map *map, t_player *p)
{
	char	monad;

	monad = map->map[p->py][p->px];
	if (monad == '0' || monad == '2' || monad == '3')
	{
		if ((!p->px || !p->py \
			|| p->px == map->width - 1 || p->py == map->height - 1))
			ft_exit("map field unclosed error", 0);
	}
	else if (monad == ' ')
	{
		if (_check_wall(p->px, p->py, *map))
			ft_exit("map wall unclosed error", 0);
	}
	else if (ft_strchr("EWSN", monad))
	{
		if ((!p->px || !p->py \
			|| p->px == map->width - 1 || p->py == map->height - 1))
			ft_exit("map player unclosed error", 0);
		if (_check_player(p, map, monad))
			ft_exit("map player error", 0);
	}
	else if (!ft_strchr("123", monad))
		ft_exit("map invalid character", 0);
}

t_map	check_map_error(t_map map)
{
	t_player	p;

	p.py = 0;
	p.pdir = 0;
	while (p.py < map.height)
	{
		p.px = 0;
		while (p.px < map.width)
		{
			_check_error_case(&map, &p);
			p.px++;
		}
		p.py++;
	}
	if (!p.pdir)
		ft_exit("map player direction error", 0);
	return (map);
}
