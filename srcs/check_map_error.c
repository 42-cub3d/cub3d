/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:58:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 22:22:00 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "libft.h"

static int	_check_wall(size_t x, size_t y, t_map map)
{
	int	flag;

	flag = 0;
	if ((0 < x && !ft_strchr("1 ", map.map[y][x - 1]))
		|| (0 < y && !ft_strchr("1 ", map.map[y - 1][x]))
		|| (x + 1 < map.width && !ft_strchr("1 ", map.map[y][x + 1]))
		|| (y + 1 < map.height && !ft_strchr("1 ", map.map[y + 1][x])))
		return (-1);
	return (0);
}

static int	_check_player(t_player *p, t_map *map, char dir)
{
	if (p->pdir)
		return (-1);
	p->pdir = dir;
	map->px = p->px;
	map->py = p->py;
	if (dir == 'E')
		map->pdir = 1;
	else if (dir == 'W')
		map->pdir = 2;
	else if (dir == 'S')
		map->pdir = 3;
	else if (dir == 'N')
		map->pdir = 4;
	return (0);
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
			if (map.map[p.py][p.px] == ' ' && (_check_wall(p.px, p.py, map)))
				ft_exit();
			else if (ft_strchr("EWSN", map.map[p.py][p.px]))
			{
				if (_check_player(&p, &map, map.map[p.py][p.px]))
					ft_exit();
			}
			else if (!ft_strchr("01", map.map[p.py][p.px]))
				ft_exit();
			p.px++;
		}
		p.py++;
	}
	if (!p.pdir)
		ft_exit();
	return (map);
}
