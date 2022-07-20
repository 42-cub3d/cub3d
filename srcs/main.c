/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 01:49:49 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	ft_exit(char *err_msg)
{
	if(err_msg)
	{
		ft_putendl_fd(err_msg, 2);
	}
	else 
		ft_putendl_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
    if (argc != 2)
        ft_exit("Need .cub map file");
	parse_map(argv);
    return (EXIT_SUCCESS);
}
