/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	t_itoa_info	it;

	it.len = !n;
	it.n_backup = n;
	while (it.n_backup)
	{
		it.len++;
		it.n_backup /= 10;
	}
	it.len += (n < 0);
	it.temp = ft_calloc(it.len + 1, sizeof(char));
	if (it.temp)
	{
		if (n < 0)
			it.temp[0] = '-';
		else if (!n)
			it.temp[--it.len] = '0';
		while (n)
		{
			it.temp[--it.len] = '0' + ((1 - ((n < 0) << 1)) * (n % 10));
			n /= 10;
		}
	}
	return (it.temp);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*temp;

	if (!s || !f)
		return (NULL);
	temp = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (temp)
	{
		i = 0;
		while (s[i])
		{
			temp[i] = f(i, s[i]);
			i++;
		}
	}
	return (temp);
}

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
