/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:12:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/28 20:43:11 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_resize_map(t_map_parse *info)
{
	size_t	idx;

	info->map.map = (char **)malloc(sizeof(char *) * (info->cur + 1));
	if (!info->map.map)
		ft_exit("resize_map malloc error", 1);
	idx = 0;
	info->map.map[info->cur] = NULL;
	while (idx < info->cur)
	{
		info->map.map[idx] = (char *)malloc(sizeof(char) * (info->len + 1));
		if (!info->map.map[idx])
			ft_exit("resize_map malloc error", 1);
		info->map.map[idx][info->len] = '\0';
		ft_memset(info->map.map[idx], ' ', info->len);
		ft_memcpy(info->map.map[idx], info->temp_map[idx], \
												ft_strlen(info->temp_map[idx]));
		free(info->temp_map[idx]);
		idx++;
	}
	free(info->temp_map);
	info->map.width = info->len;
	info->map.height = idx;
}

static void	_init_info(t_map_parse *info)
{
	info->temp_map = ft_calloc(sizeof(char *), 2);
	if (!info->temp_map)
		ft_exit("map malloc error", 1);
	info->map.map = NULL;
	info->temp = NULL;
	info->str_vec_size = 2;
	info->cur = 0;
	info->gnl_check = -1;
	info->len = 0;
	info->temp_length = 0;
}

static void	_append_map(t_map_parse *info, size_t cur)
{
	char	**temp;

	if (cur < info->str_vec_size - 1)
	{
		info->temp_map[cur] = info->temp;
		return ;
	}
	info->str_vec_size <<= 1;
	temp = ft_calloc(info->str_vec_size, sizeof(char *));
	if (temp)
	{
		ft_memcpy(temp, info->temp_map, cur * (sizeof(char *)));
		free(info->temp_map);
		info->temp_map = temp;
		_append_map(info, info->cur);
		return ;
	}
	ft_exit("map append error", 1);
}

t_map	get_map(int fd)
{
	t_map_parse	info;

	_init_info(&info);
	info.gnl_check = get_next_line(fd, &info.temp);
	while (info.gnl_check > 0)
	{
		if (info.temp && !info.cur && !info.temp[0])
			free(info.temp);
		else if (info.temp)
		{
			_append_map(&info, info.cur);
			info.temp_length = ft_strlen(info.temp);
			if (info.temp_length > info.len)
				info.len = info.temp_length;
			info.cur++;
			info.temp = NULL;
		}
		else
			ft_exit("gnl error", 1);
		info.gnl_check = get_next_line(fd, &info.temp);
	}
	if (info.gnl_check)
		ft_exit("gnl error", 1);
	_resize_map(&info);
	return (check_map_error(info.map));
}
