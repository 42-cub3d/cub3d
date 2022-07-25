/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc_stdlib.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:25:32 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/25 11:12:13 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_isspace(char c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	number;

	while (_isspace(*str))
		str++;
	sign = 0;
	if (*str == '+' || *str == '-')
		sign = *(str++) == '-';
	number = 0;
	while (*str && ft_isdigit(*str))
		number = (number * 10) + ((*(str++) - '0') * (1 - (sign << 1)));
	return (number);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*temp;

	temp = malloc(count * size);
	if (temp)
		ft_bzero(temp, count * size);
	return (temp);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*s2 - *s1);
}

void	ft_free_strv(char **strv)
{
	size_t	i;

	i = 0;
	while (strv[i])
	{
		free(strv[i]);
		i++;
	}
	free(strv);
}
