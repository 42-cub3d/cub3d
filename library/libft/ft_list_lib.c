/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_lib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:26:31 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 22:26:33 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (temp)
	{
		temp->content = content;
		temp->next = NULL;
	}
	return (temp);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst)
	{
		cnt++;
		lst = lst->next;
	}
	return (cnt);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}
