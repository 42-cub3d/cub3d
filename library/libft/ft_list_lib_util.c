/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		(*lst)->next = NULL;
		ft_lstdelone(*lst, del);
		*lst = next;
	}
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	temp[3];
	void	*f_temp;

	if (!lst || !f)
		return (NULL);
	temp[0].next = NULL;
	while (lst)
	{
		f_temp = f(lst->content);
		temp[2].next = ft_lstnew(f_temp);
		if (!temp[2].next)
		{
			free(f_temp);
			ft_lstclear(&temp[0].next, del);
			return (NULL);
		}
		if (!temp[0].next)
			temp[0].next = temp[2].next;
		else
			temp[1].next->next = temp[2].next;
		temp[1].next = temp[2].next;
		lst = lst->next;
	}
	return (temp[0].next);
}
