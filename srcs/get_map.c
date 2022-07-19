/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:41:30 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 22:03:27 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_map.h"
#include "libft.h"

//	1. using gnl
//	2. append to string vector
//	3. check valid
static char	**_strvec_resize(char **map, size_t	&size)
{
	*size <<= 1;
}

char	**get_map(int fd)
{
	char	*temp;
	char	*return_map;
	size_t	str_vec_size;

	str_vec_size = 2;
	return_map = NULL;
	temp = get_next_line(fd);
	if (!temp)
		// exit error - perror
	while (temp)
	{
		temp = get_next_line(fd);
	}
	return (return_map);
}
