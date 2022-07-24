/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:30:11 by wchae             #+#    #+#             */
/*   Updated: 2022/07/24 22:30:37 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "get_map.h"
#include "mlx.h"

static char	*get_path(t_texture *texture, t_texture_dir dir)
{
	if (type == TEX_EAST)
		return (texture->east);
	else if (type == TEX_WEST)
		return (texture->west);
	else if (type == TEX_SOUTH)
		return (texture->south);
	else if (type == TEX_NORTH)
		return (texture->north);
	else
		ft_exit("TEXTURE FILE ERROR", 1);
	return (NULL);
}


t_img	*get_img(t_info *info, t_texture_dir dir, int *width, int *height)
{
	t_img	*img;
	void	*mlx;
	char	*path;

	img	= malloc(sizeof(t_img));
	mlx = info->mlx;
	path = get_path(info->texture, dir);
	img->img = mlx_xpm_file_to_image(mlx, path, width, height);
	if (!img->img || *width !=64 || *height != 64)
		ft_exit("TEXTURE PIXEL MUST BE 64", 0);
	return (img);
}

void	set_texture_buffer(int *texture_value, int width, int height, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			texture_value[width * y + x] = ((int *)(img->addr))[y * width + x];
			x++;
		}
		y++;
	}
}

int	*load_image(t_info *info, t_texture_dir dir)
{
	t_img	*img;
	int		width;
	int		height;
	int		*texture_value;

	img = get_img(info->texture, dir, &width, &height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
										&(img->line_length), &(img->endian));
	if ((img->bits_per_pixel != 32) || (img->endian != 0))
		ft_exit("MLX ERROR", 1);
	texture_value = malloc(sizeof(int) * width * height);
	set_texture_buffer(texture_value, width, height, img);
	mlx_destroy_image(info->mlx, img->img);
	free(img);
	img = NULL;
	return (texture_value);
}


void	set_texture(t_info *info)
{
	info->texture.textures[T_EAST] = load_image(info, T_EAST);
	info->texture.textures[T_WEST] = load_image(info, T_WEST);
	info->texture.textures[T_SOUTH] = load_image(info, T_SOUTH);
	info->texture.textures[T_NORTH] = load_image(info, T_NORTH);
}
