/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:13:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 17:13:18 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H

# define GET_MAP_H
# include <stddef.h>

enum e_return_code
{
	MAP_SUCCESS = 0,
	MAP_FAILURE = -1
};

enum e_player
{
	POS_E = 1,
	POS_W = 2,
	POS_S = 3,
	POS_N = 4
};

typedef struct s_player
{
	size_t	px;
	size_t	py;
	int		pdir;
}			t_player;

typedef struct s_map
{
	size_t		width;
	size_t		height;
	char		**map;
	t_player	p_info;
}				t_map;

typedef struct s_map_parse
{
	char	**temp_map;
	t_map	map;
	char	*temp;
	size_t	str_vec_size;
	size_t	cur;
	int		null_check;
	int		gnl_check;
	size_t	max_length;
	size_t	temp_length;
}			t_map_parse;

t_map	get_map(int fd);
t_map	check_map_error(t_map map);

#endif
