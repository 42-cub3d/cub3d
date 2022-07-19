#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_charjoin(char *str)
{
	return (ft_strjoin(str, "\n"));
}

int main(void)
{
	t_list	*head = NULL;
	char	*c = "0123456789";
	for (int i = 0; i < 10; i++)
	{
		ft_lstadd_back(&head, ft_lstnew(ft_itoa(i)));
		printf("%d, %s : %d\n", i, head->content, ft_lstsize(head));
		printf(":%s\n\n", ft_lstlast(head)->content);
	}

	printf("clear!\n");
	t_list	*cpy = ft_lstmap(head, ft_charjoin, free);
	int i = 0;
	while (cpy)
	{
		printf("%d: %s\n", i++, cpy->content);
		cpy = cpy->next;
	}
}
