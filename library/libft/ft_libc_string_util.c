/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc_string_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:26:14 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 22:26:17 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	while (len--)
		((unsigned char *)b)[len] = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_len;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	if (len < haystack_len)
		haystack_len = len;
	while (*haystack && len >= needle_len)
	{
		if (!ft_strncmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(s1) + 1;
	temp = ft_calloc(len, sizeof(char));
	if (temp)
		ft_memcpy(temp, s1, len);
	return (temp);
}
