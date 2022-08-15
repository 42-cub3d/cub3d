/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:30:00 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/16 01:55:58 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	_ft_lst_add_des(t_list **lst, t_list *new)
{
	t_list	*temp;
	t_list	*pre;

	if (!lst || !new)
		return ;
	pre = NULL;
	temp = *lst;
	while (temp \
	&& ((t_sprite *)temp->content)->dist > ((t_sprite *)new->content)->dist)
	{
		pre = temp;
		temp = temp->next;
	}
	if (!pre)
	{
		new->next = *lst;
		*lst = new;
		return ;
	}
	pre->next = new;
	new->next = temp;
}

static int	_find_sprite(t_info *info, t_ray_beam *b)
{
	t_list		*temp;
	t_sprite	*sprite_temp;

	temp = info->sprite_list;
	while (temp)
	{
		sprite_temp = temp->content;
		if (sprite_temp->x == b->map_x && sprite_temp->y == b->map_y)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	sprite_add(t_info *info, t_ray_beam *b)
{
	t_sprite	*temp;
	t_list		*new;

	if (!_find_sprite(info, b))
	{
		temp = malloc(sizeof(t_sprite));
		if (!temp)
			ft_exit("t_sprite malloc error", 1);
		temp->x = b->map_x;
		temp->y = b->map_y;
		temp->dist = sqrt(pow(b->map_x - info->ray.p_x, 2) \
										+ pow(b->map_y - info->ray.p_y, 2));
		new = ft_lstnew(temp);
		if (!new)
			ft_exit("t_list malloc error", 1);
		_ft_lst_add_des(&info->sprite_list, new);
	}
}
