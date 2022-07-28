/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:07:21 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/28 16:35:52 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

void	_print_info(t_info *info)
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
	printf("\n[map]\nwidth: %zu\nheight: %zu\n", \
													info->map.width, \
													info->map.height);
	idx = 0;
	while (info->map.map[idx])
	{
		printf("%3zu: %s<\n", idx, info->map.map[idx]);
		idx++;
	}
	printf("\nfield value     : ( %c )\n", info->map.map[(int)info->ray.p_y] \
														[(int)info->ray.p_x]);
	printf("P_pos: (x  :%10f, y  :%10f)\n", info->ray.p_x, info->ray.p_y);
	printf("P_dir: (x_d:%10f, y_d:%10f)\n", info->ray.dir_x, info->ray.dir_y);
}

void	ft_exit(char *err_msg, int errno_mode)
{
	ft_putstr_fd("Error: ", 2);
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
	free(info->map.map);
	free(info->texture.east);
	free(info->texture.west);
	free(info->texture.south);
	free(info->texture.north);
	mlx_destroy_window(info->mlx.mlx, info->mlx.win);
	mlx_destroy_image(info->mlx.mlx, info->mlx.img);
	free(info->mlx.mlx);
}

static void	_set_mouse_info(t_bonus *org)
{
	org->mouse_x = 0;
	org->mouse_init = 0;
	org->mouse_toggle = 0;
	org->map_toggle = 1;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2)
		ft_exit("./cub3D <map_file>", 0);
	parse_map(&info, argv);
	ft_mlx_init(&info.mlx);
	_set_mouse_info(&info.bonus);
	mini_map_init(&info);
	set_texture_img(&info);
	ft_event_handler(&info);
	ft_ray_setting(&info);
	ft_ray_casting(&info);
	_print_info(&info);
	mlx_loop(info.mlx.mlx);
	ft_flush_info(&info);
	return (EXIT_SUCCESS);
}
