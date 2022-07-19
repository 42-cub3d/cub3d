/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc_ctype_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 22:25:21 by yongmkim          #+#    #+#             */
/*   Updated: 2022/07/19 22:25:23 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

int	ft_isascii(int c)
{
	return (0 <= c && c <= 0177);
}

int	ft_isprint(int c)
{
	return (040 <= c && c <= 0176);
}
