/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	src_len;
	size_t	dst_len;

	if (!s)
		return (NULL);
	src_len = ft_strlen(s);
	if (start > src_len)
		start = src_len;
	dst_len = ft_strlen(s + start);
	if (dst_len > len)
		dst_len = len;
	temp = ft_calloc(dst_len + 1, sizeof(char));
	if (temp)
	{
		ft_memcpy(temp, s + start, dst_len);
		temp[dst_len] = '\0';
	}
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	t_len;
	char	*temp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	t_len = ft_strlen(s1) + ft_strlen(s2);
	temp = ft_calloc(t_len + 1, sizeof(char));
	if (temp)
	{
		ft_strlcat(temp, s1, t_len + 1);
		ft_strlcat(temp, s2, t_len + 1);
	}
	return (temp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_pos;
	size_t	rear_pos;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front_pos = 0;
	rear_pos = ft_strlen(s1);
	if (0 < rear_pos)
	{
		while (ft_strchr(set, s1[front_pos]))
			front_pos++;
		while (ft_strchr(set, s1[rear_pos - 1]))
			rear_pos--;
	}
	return (ft_substr(s1, front_pos, rear_pos - front_pos));
}

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

char	**ft_split(char const *s, char c)
{
	t_split_info	sp;

	if (!s)
		return (NULL);
	sp.size = 2;
	sp.cur = 0;
	sp.sv_temp = ft_calloc(sp.size, sizeof(char *));
	while (sp.sv_temp && *s)
	{
		if (*s != c)
		{
			sp.pos = ft_strchr(s, c);
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
