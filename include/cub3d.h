/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:47:40 by wchae             #+#    #+#             */
/*   Updated: 2022/07/27 02:27:06 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>

# include "libft.h"
# include "get_map.h"
# include "ray_casting.h"

# define WIDTH 1600
# define HEIGHT 900
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define ROT_SPEED 0.15
# define MOVE_SPEED 0.25
# define INIT 1
# define RENDER 2

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

typedef struct s_mouse
{
	int		mouse_x;
	int		mouse_y;
	int		mouse_init;
	int		mouse_toggle;
}			t_mouse;

typedef struct s_info
{
	t_texture	texture;
	t_map		map;
	t_mlx		mlx;
	t_ray		ray;
	t_mouse		mouse;
	int			*cur_tex;
}				t_info;

/*
**		util
*/
void	_print_info(t_info *info);
void	ft_exit(char *err_msg, int errno_mode);
void	ft_flush_info(t_info *info);

/*
**      mlx part
*/
void	ft_mlx_init(t_mlx *org);
void	ft_put_color(t_info *info, int x, int y, int color);
void	ft_re_render(t_info *info);
void	ft_fill_floor_ceiling(t_info *info, t_ray_beam *b, int cur_x);
void	ft_event_handler(t_info *info);
void	key_move(int key, t_info *info);
void	key_rotate_view(int key, t_info *info);

#endif
