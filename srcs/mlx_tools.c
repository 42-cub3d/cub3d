/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/24 22:32:51 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub3d.h"

void	ft_re_render(t_info *info)
{
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

void	ft_draw_vertical(t_info *info, int x, int start, int end)
{
	int		color;

	while (start <= end)
	{
		set_texture(info);
		// color  set texture file
		color = 0xFFFFFF;
		ft_put_pixel(&info->mlx, x, start, color);
		start++;
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
