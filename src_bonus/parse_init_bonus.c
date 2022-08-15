/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:22 by wchae             #+#    #+#             */
/*   Updated: 2022/08/15 16:22:21 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <fcntl.h>

static int	_open_valid_map(char *argv)
{
	int	map_fd;

	if (ft_strlen(argv) < 5)
		ft_exit("Format must be ./cub3D <filename.cub>", 0);
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", -1))
		ft_exit("Mapfile must be .cub", 0);
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_exit("Mapfile is Invalid", 0);
	return (map_fd);
}

void	parse_map(t_info *info, char **argv)
{
	int			map_fd;
	t_texture	texture;

	map_fd = _open_valid_map(argv[1]);
	get_texture(&texture, map_fd);
	info->texture = texture;
	info->map = get_map(map_fd);
	close(map_fd);
}
