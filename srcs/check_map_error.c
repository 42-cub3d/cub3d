/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <codeyoma@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:58:34 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 20:25:50 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"


				if (!check_player)
				{
					check_player |= 1;
					map.player_info.px = p.px;
					map.player_info.py = p.py;
					map.player_info.pdir = map.map[p.py][p.px];
				}
				else
					ft_exit();


static int	_check_wall(size_t x, size_t y, )
{
}

t_map	check_map_error(t_map map)
{
	t_player	p;
	
	p.px = 0;
	p.py = 0;
	p.check_player = 0;
	while (p.py < map.height)
	{
		while (p.px < map.width)
		{
			if (map.map[p.py][p.px] == ' ')
			{
				if (_check_wall(p.px, p.py, map.map))
					ft_exit();
				// check x + 1 || y + 1 is "1" or " "
			}
			else if (ft_strchr("EWSN", map.map[p.py][p.px])) 
			{
				// init player info
			}
			else if (!ft_strchr("01", map.map[p.py][p.px]))
				ft_exit();
			p.px++;
		}
		p.py++;
	}
}
