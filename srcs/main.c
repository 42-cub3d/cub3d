/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/21 19:10:38 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit(char *err_msg)
{
	perror(err_msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_info *info;
	info = ft_calloc(1, sizeof(t_info));
	if (argc != 2)
		ft_exit("Need .cub map file");
	parse_map(info, argv);
	free(info);
	return (EXIT_SUCCESS);
}
