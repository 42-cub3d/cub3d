/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:47:40 by wchae             #+#    #+#             */
/*   Updated: 2022/07/21 22:18:38 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

# include "libft.h"
# include "get_map.h"

# define WIDTH 1600
# define HEIGHT 900

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size;
	int		endian;
}			t_mlx;

typedef struct s_info
{
	t_texture	*texture;
	t_map		map;
	t_mlx		*mlx;
}				t_info;

void	ft_exit(char *err_msg);

void	ft_flush_info(t_info *info);

/*
**      mlx part
*/
void	ft_mlx_init(t_mlx *mlx);
void	ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void	ft_re_render(t_info *info);

void	ft_event_handler(t_info *info);

#endif
