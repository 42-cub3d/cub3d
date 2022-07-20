/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:12:28 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 17:58:30 by yongmkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "libft.h"
#include <stdlib.h>






#include <stdio.h>
#include <fcntl.h>
void	ft_exit(void)
{
	printf("ft_exit\n");
	exit(-1);
}

static void	_init_info(t_map_info *info)
{
	info->temp_map = ft_calloc(sizeof(char *), 2);
	info->map.width = 0;
	info->map.height = 0;
	info->map.map = NULL;
	info->temp = NULL;
	info->str_vec_size = 2;
	info->cur = 0;
	info->gnl_check = -1;
	info->max_length = 0;
	info->temp_length = 0;
}

static int	_append_map(t_map_info *info, size_t cur)
{
	char	**temp;

	if (cur < 0)
	{
		temp = info->temp_map;
		while (info->temp_map && *temp)
			free(*(temp++));
		free(info->temp_map);
		return (-1);
	}
	if (cur < info->str_vec_size - 1)
	{
		info->temp_map[cur] = info->temp;
		return (0);
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
	return (-1);
}

static int	_resize_map(t_map_info *info)
{
	size_t	idx;

	info->map.map = (char **)malloc(sizeof(char *) * (info->cur + 1));
	if (info->map.map)
	{
		idx = 0;
		info->map.map[info->cur] = NULL;
		while (idx < info->cur)
		{
			info->map.map[idx] = (char *)malloc(sizeof(char) \
													* (info->max_length + 1));
			if (!info->map.map[idx])
				return (-1);
			info->map.map[idx][info->max_length] = '\0';
			ft_memset(info->map.map[idx], ' ', info->max_length);
			ft_memcpy(info->map.map[idx], info->temp_map[idx], \
												ft_strlen(info->temp_map[idx]));
			idx++;
		}
		info->map.width = info->max_length;
		info->map.height = idx;
		return (0);
	}
	return (-1);
}

t_map	get_map(int fd)
{
	t_map_info	info;

	_init_info(&info);
	info.gnl_check = get_next_line(fd, &info.temp);
	while (info.gnl_check > 0)
	{
		if (_append_map(&info, info.cur))
			ft_exit();
		info.temp_length = ft_strlen(info.temp);
		if (info.temp_length > info.max_length)
			info.max_length = info.temp_length;
		info.cur++;
		info.temp = NULL;
		info.gnl_check = get_next_line(fd, &info.temp);
	}
	if (info.gnl_check || _resize_map(&info))
		ft_exit();
	return (info.map);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd = open(argv[1], O_RDONLY);

		if (fd > 0)
		{
			t_map temp = get_map(fd);
			if (temp.map)
			{
				printf("is it, %zu %zu\n", temp.width, temp.height);
			}

			size_t	idx = 0;
			while (temp.map[idx])
			{
				printf("%s$\n", temp.map[idx]);
				idx++;
			}
			close(fd);
		}
	}
}
