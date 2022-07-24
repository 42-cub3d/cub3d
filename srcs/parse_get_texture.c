/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:53:11 by wchae             #+#    #+#             */
/*   Updated: 2022/07/25 02:01:09 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	_count_comma(char *str)
{
	size_t	cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (*str)
	{
		if (*str == ',')
			cnt++;
		str++;
	}
	return (cnt);
}

static void	_free_line(char *line, char **splited_line)
{
	size_t	i;

	free(line);
	i = 0;
	while ((splited_line)[i])
	{
		free((splited_line)[i]);
		i++;
	}
	free(splited_line);
}

static	void	_get_texture_content(t_texture *t, char **line, size_t comma_nb)
{
	if (!line[2])
	{
		if (ft_strcmp(line[0], NORTH) == 0)
			t->north = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], SOUTH) == 0)
			t->south = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], EAST) == 0)
			t->east = ft_strdup(line[1]);
		else if (ft_strcmp(line[0], WEST) == 0)
			t->west = ft_strdup(line[1]);
		else
			ft_exit("from_get_texture_content", 0);
	}
	else if (comma_nb == 2 && ft_strcmp(line[0], FLOOR) == 0)
		t->floor = get_color(line);
	else if (comma_nb == 2 && ft_strcmp(line[0], CELLING) == 0)
		t->ceiling = get_color(line);
	else
		ft_exit("from_get_texture_content", 0);
}

void	get_texture(t_texture *texture, int map_fd)
{
	char	*line;
	char	**splited_line;
	size_t	i;

	i = 0;
	while (i < 6)
	{
		if (get_next_line(map_fd, &line) < 0)
			ft_exit("get_next_line_error", 1);
		if (!line)
			ft_exit("get texture line error", 0);
		splited_line = ft_split_delimiter(line, ", \n");
		if (!*splited_line)
		{
			_free_line(line, splited_line);
			continue ;
		}
		if (!splited_line[1])
			ft_exit("splited_line_error", 0);
		_get_texture_content(texture, splited_line, _count_comma(line));
		_free_line(line, splited_line);
		i++;
	}
}
