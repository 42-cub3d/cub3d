/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:12:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 18:18:01 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdlib.h>

static void	_init_info(t_map_parse *info)
{
	info->temp_map = ft_calloc(sizeof(char *), 2);
	if (!info->temp_map)
		ft_exit("map malloc error");
	info->map.map = NULL;
	info->temp = NULL;
	info->str_vec_size = 2;
	info->cur = 0;
	info->gnl_check = -1;
	info->max_length = 0;
	info->temp_length = 0;
}

static int	_append_map(t_map_parse *info, size_t cur)
{
	char	**temp;

	if (cur < info->str_vec_size - 1)
	{
		info->temp_map[cur] = info->temp;
		return (MAP_SUCCESS);
	}
	info->str_vec_size <<= 1;
	temp = ft_calloc(info->str_vec_size, sizeof(char *));
	if (temp)
	{
		ft_memcpy(temp, info->temp_map, cur * (sizeof(char *)));
		free(info->temp_map);
		info->temp_map = temp;
		return (_append_map(info, info->cur));
	}
	return (MAP_FAILURE);
}

static int	_resize_map(t_map_parse *info)
{
	size_t	idx;

	info->map.map = (char **)malloc(sizeof(char *) * (info->cur + 2 + 1));
	if (info->map.map)
	{
		idx = 0;
		info->map.map[info->cur + 2] = NULL;
		while (idx < info->cur + 2)
		{
			info->map.map[idx] = (char *)malloc(sizeof(char) \
													* (info->max_length + 1));
			if (!info->map.map[idx])
				return (MAP_FAILURE);
			info->map.map[idx][info->max_length] = '\0';
			ft_memset(info->map.map[idx], ' ', info->max_length);
			if (idx != 0 && idx != (info->cur + 1))
				ft_memcpy(info->map.map[idx], info->temp_map[idx - 1], \
											ft_strlen(info->temp_map[idx - 1]));
			idx++;
		}
		info->map.width = info->max_length;
		info->map.height = idx;
		return (MAP_SUCCESS);
	}
	return (MAP_FAILURE);
}

void	print_map(t_map map)
{
	size_t	idx;

	idx = 0;
	while (map.map[idx])
	{
		printf("%s\n", map.map[idx]);
		idx++;
	}
}

t_map	get_map(int fd)
{
	t_map_parse	info;

	_init_info(&info);
	info.gnl_check = get_next_line(fd, &info.temp);
	while (info.gnl_check > 0)
	{
		if (info.temp)
		{
			if (_append_map(&info, info.cur))
				ft_exit("map append error");
			info.temp_length = ft_strlen(info.temp);
			if (info.temp_length > info.max_length)
				info.max_length = info.temp_length;
			info.cur++;
			info.temp = NULL;
		}
		info.gnl_check = get_next_line(fd, &info.temp);
	}
	if (info.gnl_check || _resize_map(&info))
		ft_exit("map alloc error");
	return (check_map_error(info.map));
}
