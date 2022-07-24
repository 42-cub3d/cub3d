/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/24 19:57:48 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void _print_player_info(t_info *info)
{
	printf("\n---\n");
	printf("field value     : ( %c )\n", info->map.map[(int)info->ray.p_y][(int)info->ray.p_x]);
	printf("Player  position: (x: %f, y: %f)\n", info->ray.p_x, info->ray.p_y);
	printf("Player direction: (x_d:%f, y_d:%f)\n", info->ray.dir_x, info->ray.dir_y);
}

void	ft_re_render(t_info *info)
{
	_print_player_info(info);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.win, info->mlx.img, 0, 0);
}

static void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*temp;
	int		idx;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	idx = (y * mlx->size) + (x * (mlx->bpp / 8));
	temp = mlx->img_data + idx;
	*(unsigned int *)temp = color;
}

void	ft_img_clear(t_info *info)
{
	int	i;
	int	size;
	int	*temp;

	i = 0;
	size = WIDTH * HEIGHT;
	temp = (int *)(info->mlx.img_data);
	while (i < size)
	{
		if (i < size / 2)
			temp[i] = info->texture.ceiling;
		else
			temp[i] = info->texture.floor;
		i++;
	}
}

void	ft_draw_vertical(t_info *info, int x, int y1, int y2)
{
	int		color;
	int		i;

	i = y1;
	while (i <= y2)
	{
		// color  set texture file
		color = 0xFFFFFF;
		ft_put_pixel(&info->mlx, x, i, color);
		i++;
	}
}

void	ft_mlx_init(t_mlx *org)
{
	t_mlx	mlx;

	mlx.mlx = mlx_init();
	if (!mlx.mlx)
		ft_exit("mlx init error", 1);
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!mlx.win)
		ft_exit("mlx window error", 1);
	mlx.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	if (!mlx.img)
		ft_exit("mlx image error", 1);
	mlx.img_data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size, \
															&mlx.endian);
	if (!mlx.img_data)
		ft_exit("mlx image_data error", 1);
	*org = mlx;
}
