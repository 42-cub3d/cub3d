/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:26:13 by wchae             #+#    #+#             */
/*   Updated: 2022/02/24 02:21:50 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*gnl_strndup(const char *s1, size_t n)
{
	char	*ret;
	char	*ptr;

	ret = malloc(n + 1);
	if (!ret)
		return (NULL);
	ptr = ret;
	while (n--)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ret);
}

char	*gnl_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr && *ptr != (char)c)
		ptr++;
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	ret = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	while (s2[j])
		ret[i++] = s2[j++];
	ret[i] = '\0';
	return (ret);
}
