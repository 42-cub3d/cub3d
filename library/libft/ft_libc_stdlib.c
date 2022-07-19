/* ************************************************************************** */
/**//**//*****//**//*   By: *//**//*   Created:   by *//*   Updated:   by *//**/
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
