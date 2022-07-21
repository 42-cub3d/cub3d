/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 21:43:42 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(char *err_msg)
{
	write(2, "error\n", 6);
	perror(err_msg);
	exit(EXIT_FAILURE);
}

void	ft_flush_info(t_info *info)
{
	free(info->texture->east);
	free(info->texture->west);
	free(info->texture->south);
	free(info->texture->north);
	free(info->texture);
	mlx_destory_window(info->mlx->mlx, info->mlx->win);
	mlx_destroy_image(info->mlx->mlx, info->mlx->img);
	free(info->mlx->mlx);
	free(info->mlx);
	free(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = ft_calloc(1, sizeof(t_info));
	if (argc != 2)
		ft_exit("Need .cub map file");
	parse_map(info, argv);
	ft_mlx_init(info->mlx);
	ft_event_handler(info);



	//
	//mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img, 0, 0);
	mlx_loop(info->mlx->mlx);
	ft_flush_info(info);
	return (EXIT_SUCCESS);
}
