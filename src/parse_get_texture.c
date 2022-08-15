/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:53:11 by wchae             #+#    #+#             */
/*   Updated: 2022/07/25 16:19:28 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_get_color_content(char *str)
{
	char	*tmp;
	size_t	i;
	int		value;

	value = 0;
	if (!str)
		ft_exit("Color Invalid - Color is NULL", 0);
	i = 0;
	tmp = ft_strtrim(str, ", \n\t");
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
			ft_exit("Color Invalid - Allow Digit ONLY", 0);
		value *= 10;
		value += tmp[i] - '0';
		if (255 < value)
			ft_exit("Color Invalid - Allow range (0 ~ 255)", 0);
		i++;
	}
	free(tmp);
	return (value);
}

static int	_get_color(char **line)
{
	int	r;
	int	g;
	int	b;

	r = _get_color_content(line[1]);
	g = _get_color_content(line[2]);
	b = _get_color_content(line[3]);
	if (line[4])
		ft_exit("Color Invalid - RGB Value Error", 0);
	return ((r << 16) + (g << 8) + b);
}

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
			ft_exit("Texture - Direction Invalid (EA, WE, SO, NO)", 0);
	}
	else if (comma_nb == 2 && ft_strcmp(line[0], FLOOR) == 0)
		t->floor = _get_color(line);
	else if (comma_nb == 2 && ft_strcmp(line[0], CELLING) == 0)
		t->ceiling = _get_color(line);
	else
		ft_exit("Texture - Color Value Invalid (F, C)", 0);
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
			ft_exit("GNL Invalid", 1);
		if (!line)
			ft_exit("Map grid is Invalid", 0);
		splited_line = ft_split_delimiter(line, ", \n");
		if (!*splited_line)
		{
			free(line);
			ft_free_strv(splited_line);
			continue ;
		}
		if (!splited_line[1])
			ft_exit("Map File Contents Invalid - Check .cub file", 0);
		_get_texture_content(texture, splited_line, _count_comma(line));
		free(line);
		ft_free_strv(splited_line);
		i++;
	}
}
