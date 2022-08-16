/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:25:48 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 14:44:11 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

size_t	set_sprite_texture(int *cur_fps, size_t min, size_t max)
{
	size_t	arr_pos;
	size_t	ret_value;

	arr_pos = (*cur_fps / FPS_CNT);
	ret_value = 0;
	if (min <= arr_pos && arr_pos < max)
		ret_value = arr_pos;
	else if (arr_pos < min)
	{
		*cur_fps = 0;
		ret_value = min;
	}
	else if (max <= arr_pos)
	{
		*cur_fps = 0;
		ret_value = max - 1;
	}
	return (ret_value);
}

void	set_overflow_min(int *org, int cmp_low)
{
	if (*org < cmp_low)
		*org = cmp_low;
}

void	set_overflow_max(int *org, int cmp_high)
{
	if (*org >= cmp_high)
		*org = cmp_high - 1;
}

void	set_overflow(int *org, int cmp_low, int cmp_high)
{
	set_overflow_min(org, cmp_low);
	set_overflow_max(org, cmp_high);
}
