/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:07 by wchae             #+#    #+#             */
/*   Updated: 2022/07/22 09:22:14 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_color_content(char *str)
{
	char	*tmp;
	size_t	i;
	int		value;

	value = 0;
	if (!str)
		ft_exit("get_color_error_NULL", 0);
	i = 0;
	tmp = ft_strtrim(str, ", \n\t");
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
			ft_exit("get_color not digit", 0);
		value *= 10;
		value += tmp[i] - '0';
		if (255 < value)
			ft_exit("get_color out of range", 0);
		i++;
	}
	free(tmp);
	return (value);
}

int	get_color(char **line)
{
	int	r;
	int	g;
	int	b;

	r = get_color_content(line[1]);
	g = get_color_content(line[2]);
	b = get_color_content(line[3]);
	if (line[4])
		ft_exit("get color error", 0);
	return ((r << 16) + (g << 8) + b);
}
