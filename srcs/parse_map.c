/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:10:22 by wchae             #+#    #+#             */
/*   Updated: 2022/07/21 02:11:02 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static
int	open_valid_map(char *argv)
{
	int	map_fd;

	if (ft_strlen(argv) < 5)
		ft_exit("file < 5");
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", -1))
		ft_exit("not .cub");
	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1)
		ft_exit("map_fd_error");
	return (map_fd);
}

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	ft_memset(texture, 0, sizeof(t_texture));
	if (!texture)
		exit(EXIT_FAILURE);
	return (texture);
}

/*
	map 구조체추가 필요
*/
void	parse_map(t_info *info, char **argv)
{
	int			map_fd;
	t_texture	*texture;

	map_fd = open_valid_map(argv[1]);
	texture = init_texture();
	get_texture(texture, map_fd);
	info->texture = texture;
	info->map = get_map(map_fd);
}
