/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 01:13:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/24 21:44:59 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H

# define GET_MAP_H
# include <stddef.h>

# define NORTH "NO"
# define SOUTH "SO"
# define WEST "WE"
# define EAST "EA"
# define FLOOR "F"
# define CELLING "C"

typedef enum e_texture_dir		t_texture_dir;

enum e_return_code
{
	MAP_SUCCESS = 0,
	MAP_FAILURE = -1
};

enum e_player
{
	POS_E = 1 << 0,
	POS_W = 1 << 1,
	POS_S = 1 << 2,
	POS_N = 1 << 3
};

enum e_texture_dir
{
	T_EAST = 0,
	T_WEST,
	T_SOUTH,
	T_NORTH,
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
	int		gnl_check;
	size_t	len;
	size_t	temp_length;
}			t_map_parse;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor;
	int		ceiling;
	int		*textures[8];

}			t_texture;

typedef struct s_info	t_info;

void	get_texture(t_texture *texture, int map_fd);
int		get_color(char **line);
void	parse_map(t_info *info, char **argv);
t_map	get_map(int fd);
t_map	check_map_error(t_map map);

#endif
