/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 15:16:16 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 21:04:05 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_find_nl(char *s)
{
	int	pos;

	if (!s)
		return (0);
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == '\n')
			return (pos + 1);
		pos++;
	}
	return (0);
}

char	*ft_free(char **s1, char **s2, int keyword)
{
	char	*temp;

	if (keyword == FT_DEL)
	{
		if (*s1)
		{
			free(*s1);
			*s1 = NULL;
		}
	}
	else if (keyword == FT_ADD)
	{
		temp = ft_strjoin((char *)*s1, *s2);
		ft_free(s1, NULL, FT_DEL);
		*s1 = temp;
	}
	return (NULL);
}
