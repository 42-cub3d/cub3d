/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:47:40 by wchae             #+#    #+#             */
/*   Updated: 2022/08/16 13:27:30 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

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
# define MAP_RATIO 15
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define ROT_SPEED 0.15
# define MOUSE_SPEED 0.02
# define MOVE_SPEED 0.25
# define POV 0.88
# define INIT 1
# define RENDER 2
# define FPS_MAX 50
# define FPS_CNT 10
# define DOOR_SRC "./img/carved_pumpkin.xpm"
# define SPRITE_1 "./img/sprite/sprite1.xpm"
# define SPRITE_2 "./img/sprite/sprite3.xpm"
# define SPRITE_3 "./img/sprite/sprite5.xpm"
# define SPRITE_4 "./img/sprite/sprite7.xpm"
# define SPRITE_5 "./img/sprite/sprite9.xpm"

enum e_texture_type
{
	TYPE_TEXT	= 1,
	TYPE_DOOR,
	TYPE_SPRITE
};

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

typedef struct s_bonus
{
	int		mouse_x;
	int		mouse_init;
	int		mouse_toggle;
	int		map_toggle;
	int		sprite_toggle;
}			t_bonus;

typedef struct s_mini_map
{
	int		m_x;
	int		m_y;
	int		m_ratio;
}			t_mini_map;

typedef struct s_info
{
	t_texture	texture;
	t_map		map;
	t_mlx		mlx;
	t_ray		ray;
	t_bonus		bonus;
	t_mini_map	mini_map;
	t_list		*sprite_list;
	int			*cur_tex;
	int			fps;
}				t_info;

/*
**		util
*/
void	_print_info(t_info *info, int mode);
void	ft_exit(char *err_msg, int errno_mode);
void	ft_flush_info(t_info *info);

/*
**      mlx part
*/
void	ft_mlx_init(t_mlx *org);
void	ft_put_pixel(t_mlx *mlx, int x, int y, int color);
void	ft_re_render(t_info *info);
void	ft_fill_floor_ceiling(t_info *info, t_ray_beam *b, int cur_x);

/*
**      mlx event_part
*/
int		ft_event_handler(t_info *info);
void	key_move(int key, t_info *info);
void	key_rotate_view(int key, t_info *info, double rot_speed);
int		check_mouse_move(int x, int y, t_info *info);

/*
**		mini_map
*/
void	mini_map_init(t_info *info);
void	mini_map_draw(t_info *info);
int		is_in_mini_map(t_info *info, int x, int y);

#endif
