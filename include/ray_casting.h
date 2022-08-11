/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:39:12 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/11 09:49:23 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# define X_HIT 0
# define Y_HIT 1

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
	int		tex_x;
	int		tex_y;
	double	tex_step;
	double	tex_pos;
	int		color;
}			t_tex_pos;

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

void		ft_ray_setting(t_info *info);
void		ft_ray_casting(t_info *info);
t_ray_beam	get_ray_beam_per_verline(t_info *info, int cur_x);

#endif
