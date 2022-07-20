/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:12:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 11:52:37 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "libft.h"
#include <stdlib.h>

static void	_init_info(t_map_info *info)
{
	info->map = NULL;
	info->temp_map = NULL;
	info->temp = NULL;
	info->str_vec_size = 2;
	info->cur = 0;
	info->gnl_check = -1;
	info->player_check = 0;
	info->height = 0;
	info->width = 0;
}

static int	_append_map(t_map_info *info)
{
	char	**temp;

	if (info->cur < 0)
	{
		temp = info->temp_map;
		while (info->temp_map && *temp)
			free(*(temp++));
		free(info->temp_map);
		return (-1);
	}
	if (info->cur < info->str_vec_size - 1)
	{
		info->temp_map[info->cur] = info->temp;
		return (0);
	}
	info->str_vec_size <<= 1;
	temp = ft_calloc(info->str_vec_size, sizeof(char *));
	if (temp)
	{
		ft_memcpy(temp, info->temp_map, info->cur * (sizeof(char *)));
		free(info->temp_map);
		info->temp_map = temp;
		return (_append_map(info));
	}
	return (-1);
}

t_dot	**get_map(int fd)
{
	t_map_info	info;

	info.gnl_check = get_next_line(fd, &info.temp);
	while (info.gnl_check > 0)
	{
		if (_append_map(&info))
			return (NULL);
		info.temp = NULL;
		info.gnl_check = get_next_line(fd, &info.temp);
	}
	if (info.gnl_check == -1)
		return (NULL);
	return (info.map);
}

// str to s_dot
// check valid map
