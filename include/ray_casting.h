/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:39:12 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/22 21:59:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

typedef struct s_ray
{
	double	p_x;
	double	p_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_ray;

typedef struct s_cast_info
{
	double	cam;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
}			t_cast_info;

typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
}			t_draw;

void	ft_ray_init(t_info *info);
void	ft_ray_casting(t_info *info);

#endif
