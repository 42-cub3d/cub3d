/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 12:45:07 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include "mlx.h"

void	ft_re_render(t_info *info)
{
	mlx_clear_window(info->mlx.mlx, info->mlx.win);
	mlx_put_image_to_window(info->mlx.mlx, info->mlx.win, info->mlx.img, 0, 0);
	mlx_do_sync(info->mlx.mlx);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	char	*temp;
	int		idx;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	idx = (y * mlx->size) + (x * (mlx->bpp / 8));
	temp = mlx->img_data + idx;
	*(unsigned int *)temp = color;
}

void	ft_fill_floor_ceiling(t_info *info, t_ray_beam *b, int cur_x)
{
	int	i;
	int	*canvas;

	i = 0;
	canvas = (int *)(info->mlx.img_data);
	while (i < HEIGHT)
	{
		if ((!info->bonus.map_toggle) \
				|| (info->bonus.map_toggle && !is_in_mini_map(info, cur_x, i)))
		{
			if (i < b->draw_start && i < HEIGHT / 2)
				canvas[i * WIDTH + cur_x] = info->texture.ceiling;
			else if (b->draw_end <= i && (HEIGHT / 2) <= i)
				canvas[i * WIDTH + cur_x] = info->texture.floor;
		}
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
	mlx.img_data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size, &mlx.endian);
	if (!mlx.img_data || mlx.bpp != 32 || mlx.endian != 0)
		ft_exit("mlx image_data error", 1);
	*org = mlx;
}
