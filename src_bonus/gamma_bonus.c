/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamma_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmkim <yongmkim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 00:56:54 by yongmkim          #+#    #+#             */
/*   Updated: 2022/08/17 02:18:57 by yongmkim         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	get_gamma_tex(double dist, double median)
{
	static double	d = -1;

	if (d < 0)
		d = median;
	if (dist > d)
		return (0);
	return (1.0 - dist / d);
}

double	get_gamma(double dist, double median)
{
	static double	d = -1;

	if (d < 0)
		d = median;
	if (dist > d)
		return (0);
	return (1.0 - dist / d);
}

static void	decode_color(int color, int *r, int *g, int *b)
{
	*r = (color & 0xFF0000) >> 16;
	*g = (color & 0xFF00) >> 8;
	*b = color & 0xFF;
}

static int	encode_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	fade_color(int color, double gamma)
{
	int	r;
	int	g;
	int	b;

	if (color == 0x0)
		return (color);
	if (gamma < 0)
		gamma = 0;
	else if (gamma > 1)
		gamma = 1;
	decode_color(color, &r, &g, &b);
	return (encode_color(r * gamma, g * gamma, b * gamma));
}
