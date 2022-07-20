/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/20 22:52:00 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
//TEST
void	ft_exit(char *err)
{
	if(err)
		printf("%s\n",err);
	printf("error exit\n");
	exit (EXIT_FAILURE);
}
//TEST
int	main(int argc, char **argv)
{
    if (argc != 2)
        printf("argc error\n");
	parse_map(argv);
	printf("SUCCESS\n");
    return (EXIT_SUCCESS);
}
