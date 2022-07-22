/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:07:21 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/22 11:08:18 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	ft_exit(char *err_msg, int errno_mode)
{
	write(2, "error\n", 6);
	if (errno_mode)
		perror(err_msg);
	else
	{
		write(2, err_msg, ft_strlen(err_msg));
		write(2, "\n", 1);
	}
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
	free(info->map.map);
	free(info->texture.east);
	free(info->texture.west);
	free(info->texture.south);
	free(info->texture.north);
	mlx_destroy_window(info->mlx.mlx, info->mlx.win);
	mlx_destroy_image(info->mlx.mlx, info->mlx.img);
	free(info->mlx.mlx);
}

static void	_print_info(t_info *info)
{
	size_t	idx;

	printf("[texture]\nE: %s\nW: %s\nS: %s\nN: %s\n", \
													info->texture.east, \
													info->texture.west, \
													info->texture.south, \
													info->texture.north);
	printf("\n[player]\ndir: %d\nx: %zu\ny: %zu\n", \
													info->map.p_info.pdir, \
													info->map.p_info.px, \
													info->map.p_info.py);
	idx = 0;
	printf("\n[map]\nwidth: %zu\nheight: %zu\n", \
													info->map.width, \
													info->map.height);
	while (info->map.map[idx])
	{
		printf("%s<\n", info->map.map[idx]);
		idx++;
	}
}

void	handler(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	t_info	info;

	atexit(handler);
	if (argc != 2)
		ft_exit("./cub3D <map_file>", 0);
	parse_map(&info, argv);
	_print_info(&info);
	ft_mlx_init(&info.mlx);
	ft_event_handler(&info);
	// add ray casting part
	mlx_loop(info.mlx.mlx);
	ft_flush_info(&info);
	return (EXIT_SUCCESS);
}
