/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:22 by wchae             #+#    #+#             */
/*   Updated: 2022/07/20 20:19:12 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	open_valid_map(char *argv)
{
	int	map_fd;

	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", -1))
		ft_exit();
	map_fd = open(argv, O_RDONLY);
	if (ret == -1)
		ft_exit();
	return (map_fd);
}

/*
	map 구조체추가 필요
*/
void	parse_map(char *argv)
{
	int			map_fd;
	t_texture	*texture;

	map_fd = open_valid_map(argv[1]);
	texture = init_texture();
	get_texture(texture, map_fd);
	//map parse & valid
}
