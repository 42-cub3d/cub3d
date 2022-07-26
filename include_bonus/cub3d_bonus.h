/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:47:40 by wchae             #+#    #+#             */
/*   Updated: 2022/08/18 16:00:31 by yongmkim         ###   ########seoul.kr  */
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
# define H_HEIGHT 450
# define MAP_RATIO 10
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define ROT_SPEED 0.15
# define MOUSE_SPEED 0.01
# define MOVE_SPEED 0.25
# define POV 0.88
# define INIT 1
# define RENDER 2
# define FPS_MAX 75
# define FPS_CNT 15
# define DOOR_SRC "./img/carved_pumpkin.xpm"
# define SPRITE_1 "./img/sprite/sprite3.xpm"
# define SPRITE_2 "./img/sprite/sprite5.xpm"
# define SPRITE_3 "./img/sprite/sprite7.xpm"
# define SPRITE_4 "./img/sprite/sprite6.xpm"
# define SPRITE_5 "./img/sprite/sprite4.xpm"

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
	int		bpp_shift;
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
	int		shift_toggle;
	int		x_toggle;
	double	move_speed;
	double	z_buffer[WIDTH];
}			t_bonus;

typedef struct s_mini_map
{
	int		m_x;
	int		m_y;
	double	m_ratio;
	double	m_median;
	double	scalar;
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
	t_ray_beam	b;
	t_tex_pos	t;
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
int		is_move_or_rotate_key(int key, int mode);
void	set_toggle_value(\
			int toggle, double *toggle_value, double scalar1, double scalar2);

/*
**		mini_map
*/
void	mini_map_init(t_info *info);
void	mini_map_draw(t_info *info);
int		is_in_mini_map(t_info *info, int x, int y);

/*
**		util
*/
size_t	set_sprite_texture(int *cur_fps, size_t min, size_t max);
void	set_overflow_min(int *org, int cmp_low);
void	set_overflow_max(int *org, int cmp_high);
void	set_overflow(int *org, int cmp_low, int cmp_high);
int		fade_color(int color, double gamma);
double	get_gamma(double dist, double median);
double	get_gamma_tex(double dist, double median);

#endif
