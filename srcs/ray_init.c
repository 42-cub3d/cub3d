/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:24:47 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/22 22:58:33 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void	_set_start_vector_unit(t_info *info)
{
	// if (info->map.p_info.pdir == POS_E)
	// {
	// 	info->ray.dir_x = 1;
	// 	info->ray.dir_y = 0;
	// }
	// else if (info->map.p_info.pdir == POS_W)
	// {
	// 	info->ray.dir_x = -1;
	// 	info->ray.dir_y = 0;
	// }
	// else if (info->map.p_info.pdir == POS_S)
	// {
	// 	info->ray.dir_x = 0;
	// 	info->ray.dir_y = -1;
	// }
	// else if (info->map.p_info.pdir == POS_N)
	// {
	// 	info->ray.dir_x = 0;
	// 	info->ray.dir_y = 1;
	// }
	info->ray.dir_x = -1;
	info->ray.dir_y = 0;
}

void	ft_ray_init(t_info *info)
{
	_set_start_vector_unit(info);
	info->ray.p_x = info->map.p_info.px;
	info->ray.p_y = info->map.p_info.py;
	info->ray.plane_x = 0;
	info->ray.plane_y = 0.66;
}
