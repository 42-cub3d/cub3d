/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:16:38 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 21:43:16 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

static t_mlx	*_mlx_set_value(void)
{
	t_mlx	*temp;

	temp = (t_mlx *)malloc(sizeof(t_mlx));
	if (temp)
	{
		temp->mlx = NULL;
		temp->win = NULL;
		temp->img = NULL;
		temp->img_data = NULL;
	}
	return (temp);
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

void	*ft_mlx_init(t_mlx *mlx)
{
	mlx = _mlx_set_value();
	if (mlx)
	{
		mlx->mlx = mlx_init();
		if (!mlx->mlx)
			ft_exit("mlx init error");
		mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, "cub3d");
		if (mlx->win)
			ft_exit("mlx window error");
		mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
		if (mlx->img)
			ft_exit("mlx image error");
		mlx->img_data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size, \
																&mlx->endian);
		if (mlx->img_data)
			ft_exit("mlx image_data error");
	}
	ft_exit("mlx malloc error");
}
