/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:53:11 by wchae             #+#    #+#             */
/*   Updated: 2022/07/20 19:28:56 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*init_texture(void)
{
	t_texture	*texture;

	texture = malloc(sizeof(t_texture));
	ft_memset(texture, 0, sizeof(t_texture));
	if (!texture)
		exit(EXIT_FAILURE);
	return (texture);
}

size_t	count_comma(char *str)
{
	size_t	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == ',')
			cnt++;
		str++;
	}
	return (cnt);
}

static void	free_line(char **line, char ***splitted_line)
{
	size_t	i;

	free(*line);
	*line = NULL;
	i = 0;
	while ((*splitted_line))
	{
		free(&(*splitted_line)[i]);
		i++;
	}
	free(*splitted_line);
	*splitted_line = NULL;
}

static	void	get_texture_content(t_texture *t, char **line, size_t comma_cnt)
{
	if (ft_strncmp(line[0], NORTH, -1) == 0 && !line[2])
		t->north = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], SOUTH, -1) == 0 && !line[2])
		t->south = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], EAST, -1) == 0 && !line[2])
		t->east = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], WEST, -1) == 0 && !line[2])
		t->west = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], FLOOR, -1) && (comma_cnt == 2))
		t->floor = get_color(line);
	else if (ft_strncmp(line[0], CELLING, -1) && (comma_cnt == 2))
		t->ceiling = get_color(line[1]);
	else
		ft_exit();
}

void	get_texture(t_texture *texture, int map_fd)
{
	char	*line;
	char	*splited_line;
	size_t	comma_cnt;
	size_t	i;

	i = 0;
	while (i < 6)
	{
		if (get_next_line(map_fd, &line) < 0)
			ft_exit();
		comma_cnt = count_commna(line);
		splited_line = ft_split_delimiter(", \n");
		if (!*splited_line)
		{
			free_line(&line, &splited_line);
			return ;
		}
		if (!splited_line[1])
			ft_exit();
		get_texture_content(texture, comma_cnt, splited_line);
		free_line(&line, &splited_line);
		i++;
	}
}
