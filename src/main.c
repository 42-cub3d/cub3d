/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:07:21 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 23:48:00 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	ft_exit(char *err_msg, int errno_mode)
{
	ft_putstr_fd("Error\n", 2);
	if (errno_mode)
		perror(err_msg);
	else
		ft_putendl_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

void	ft_flush_info(t_info *info)
{
	size_t	i;

	i = 0;
	while (info->map.map[i])
	{
		free(info->map.map[i]);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		free(info->texture.textures[i]);
		i++;
	}
	free(info->map.map);
	free(info->texture.east);
	free(info->texture.west);
	free(info->texture.south);
	free(info->texture.north);
	mlx_destroy_window(info->mlx.mlx, info->mlx.win);
	mlx_destroy_image(info->mlx.mlx, info->mlx.img);
	free(info->mlx.mlx);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		ft_exit("./cub3D <map_file>", 0);
	parse_map(&info, argv);
	ft_mlx_init(&info.mlx);
	set_texture_img(&info);
	ft_ray_setting(&info);
	ft_ray_casting(&info);
	ft_event_handler(&info);
	mlx_loop(info.mlx.mlx);
	ft_flush_info(&info);
	return (EXIT_SUCCESS);
}
