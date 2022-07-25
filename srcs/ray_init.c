/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:11:39 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/25 17:31:46 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_vector_init(t_info *info)
{
	if (info->map.p_info.pdir & POS_E)
	{
		info->ray.dir_x = 1;
		info->ray.plane_y = 0.66;
	}
	else if (info->map.p_info.pdir & POS_W)
	{
		info->ray.dir_x = -1;
		info->ray.plane_y = -0.66;
	}
	else if (info->map.p_info.pdir & POS_S)
	{
		info->ray.dir_y = 1;
		info->ray.plane_x = -0.66;
	}
	else if (info->map.p_info.pdir & POS_N)
	{
		info->ray.dir_y = -1;
		info->ray.plane_x = 0.66;
	}
}

void	ft_ray_setting(t_info *info)
{
	info->ray.p_x = info->map.p_info.px + 0.01;
	info->ray.p_y = info->map.p_info.py + 0.01;
	info->ray.plane_x = 0;
	info->ray.plane_y = 0;
	info->ray.dir_x = 0;
	info->ray.dir_y = 0;
	_vector_init(info);
}
