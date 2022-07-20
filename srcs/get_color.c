/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:07 by wchae             #+#    #+#             */
/*   Updated: 2022/07/20 20:18:14 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color_content(char *str)
{
	char	*tmp;
	size_t	i;
	int		value;

	value = 0;
	if (!str)
		ft_exit();
	i = 0;
	tmp = ft_strtrim(str, ", \n\t");
	while (tmp[i])
	{
		if (!ft_isdigit(tmp[i]))
			ft_exit();
		value *= 10;
		value += tmp[i] - '0';
		if (255 < value)
			ft_exit();
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
		ft_exit();
	return ((r << 16) + (g << 8)+ b);
}
