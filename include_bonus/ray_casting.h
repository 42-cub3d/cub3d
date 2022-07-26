/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:39:12 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/17 01:16:25 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# define X_HIT 0
# define Y_HIT 1
# define U_DIV 1
# define V_DIV 1
# define V_MOVE 0.0

typedef struct s_sprite
{
	int		x;
	int		y;
	double	dist;
}				t_sprite;

typedef struct s_ray
{
	double	p_x;
	double	p_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_ray;

typedef struct s_tex_pos
{
	int		t_x;
	int		t_y;
	double	t_step;
	double	t_pos;
	int		color;
}			t_tex_pos;

typedef struct s_sprite_tex_pos
{
	int		tex_pos;
	int		d;
	int		tex_y;
	int		color;
	double	gamma;
}			t_sprite_tex_pos;

typedef struct s_sprite_beam
{
	double		transform_x;
	double		transform_y;
	int			v_move_screen;
	int			s_screen_x;
	int			s_height;
	int			s_width;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_start_y;
	int			draw_end_y;
	int			tex_x;
	double		perp_wall_dist;
}				t_sprite_beam;

typedef struct s_ray_beam
{
	double	cam;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	double	side_dist_x;
	int		step_y;
	double	side_dist_y;
	int		hit;
	int		hit_type;
	int		hit_side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wallx;
}			t_ray_beam;

typedef struct s_info	t_info;

void	ft_ray_setting(t_info *info);
int		ft_ray_casting(t_info *info);
void	get_ray_beam_verline(t_info *info, int cur_x);
void	sprite_add(t_info *info, t_ray_beam *b);
void	ft_draw_sprite(t_info *info, double *z_buffer);
void	ft_print_sprite_pos(t_info *info);
int		ft_abs(int n);

#endif
