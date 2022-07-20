/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:47:40 by wchae             #+#    #+#             */
/*   Updated: 2022/07/20 20:18:21 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_texture
{
	char	**north;
	char	**south;
	char	**east;
	char	**west;
	int		floor;
	int		ceiling;
}	t_texture;

typedef struct s_info
{
	t_texture	texture;
}	t_info;

#define NORTH "NO"
#define SOUTH "SO"
#define WEST "WE"
#define EAST "EA"
#define FLOOR "F"
#define CELLING "C"

/* PARSE MAP */
void	get_texture(t_texture *texture, int map_fd);
int		get_color(char **line);

#endif
