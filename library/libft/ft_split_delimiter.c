/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_delimiter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:37:47 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 22:47:51 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**_append_sv(char **org, char *append, size_t *size, size_t cur)
{
	char	**temp;

	if (cur < 0)
	{
		temp = org;
		while (temp && *org)
			free(*(org++));
		free(temp);
		return (NULL);
	}
	if (cur < *size - 1)
	{
		org[cur] = append;
		return (org);
	}
	*size <<= 1;
	temp = ft_calloc(*size, sizeof(char *));
	if (temp)
	{
		ft_memcpy(temp, org, cur * (sizeof(char *)));
		free(org);
		return (_append_sv(temp, append, size, cur));
	}
	return (NULL);
}

static int	_is_delimiter(char c, char *delim)
{
	if (!delim)
		return (0);
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

static char	*_strchr_delimiter(char *s, char *delim)
{
	while (*s)
	{
		if (_is_delimiter(*s, delim))
			return (s);
		s++;
	}
	if (*delim == '\0')
	{
		if (s)
			return (s);
	}
	return (NULL);
}

char	**ft_split_delimiter(char const *s, char *delim)
{
	t_split_info	sp;

	if (!s)
		return (NULL);
	sp.size = 2;
	sp.cur = 0;
	sp.sv_temp = ft_calloc(sp.size, sizeof(char *));
	while (sp.sv_temp && *s)
	{
		if (!_is_delimiter(*s, delim))
		{
			sp.pos = _strchr_delimiter((char *)s, delim);
			if (!sp.pos)
				sp.pos = (char *)s + ft_strlen(s);
			sp.s_temp = ft_substr(s, 0, sp.pos - s);
			if (!sp.s_temp)
				return (_append_sv(sp.sv_temp, NULL, NULL, -1));
			sp.sv_temp = _append_sv(sp.sv_temp, sp.s_temp, &sp.size, sp.cur);
			sp.cur++;
			s = sp.pos;
		}
		if (*s)
			s++;
	}
	return (sp.sv_temp);
}
