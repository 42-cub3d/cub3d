/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_texture_img.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:47:39 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/25 02:01:39 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

static void	_set_texture_buffer(int *texture_img, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < TEXTURE_HEIGHT)
	{
		x = 0;
		while (x < TEXTURE_WIDTH)
		{
			texture_img[(TEXTURE_WIDTH * y) + x] = \
								((int *)(img->addr))[(y * TEXTURE_WIDTH) + x];
			x++;
		}
		y++;
	}
}

static char	*_get_path(t_texture *texture, t_texture_dir dir)
{
	if (dir == T_EAST)
		return (texture->east);
	else if (dir == T_WEST)
		return (texture->west);
	else if (dir == T_SOUTH)
		return (texture->south);
	else if (dir == T_NORTH)
		return (texture->north);
	else
		ft_exit("texture dir error", 1);
	return (NULL);
}

static t_img	_get_img(t_info *info, t_texture_dir dir)
{
	t_img	img;
	int		width;
	int		height;

	img.img = mlx_xpm_file_to_image(\
				info->mlx.mlx, _get_path(&info->texture, dir), &width, &height);
	if (!img.img)
		ft_exit("texture_img : mlx_xpm_file_to_image error", 0);
	if (width != 64 || height != 64)
		ft_exit("texture pixel isn't 64 x 64 size", 0);
	return (img);
}

static int	*_load_image(t_info *info, t_texture_dir dir)
{
	t_img	img;
	int		*texture_img;

	img = _get_img(info, dir);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size, &img.endian);
	if (!img.addr || img.bpp != 32 || img.endian != 0)
		ft_exit("mlx image_data error", 1);
	texture_img = (int *)malloc(sizeof(int) * (TEXTURE_HEIGHT * TEXTURE_WIDTH));
	if (!texture_img)
		ft_exit("texture_img : malloc error", 1);
	_set_texture_buffer(texture_img, &img);
	mlx_destroy_image(info->mlx.mlx, img.img);
	return (texture_img);
}

void	set_texture_img(t_info *info)
{
	info->texture.textures[T_EAST] = _load_image(info, T_EAST);
	info->texture.textures[T_WEST] = _load_image(info, T_WEST);
	info->texture.textures[T_SOUTH] = _load_image(info, T_SOUTH);
	info->texture.textures[T_NORTH] = _load_image(info, T_NORTH);
}
