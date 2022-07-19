/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 16:47:40 by wchae             #+#    #+#             */
/*   Updated: 2022/07/19 21:09:21 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_texture
{
    int *north;
    int *south;
    int *east;
    int *west;
}   t_texture;

typedef struct s_info
{
    t_texture   texture;

}   t_info;

#endif
