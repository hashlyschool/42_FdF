/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:47:25 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 18:17:40 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	get_percent(int start, int end, float current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	else
		return (placement / distance);
}

/*
int	get_light(int start, int end, double percentage)
*/
int	g_l(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_fdf *d, float current)
{
	int		red;
	int		green;
	int		blue;
	double	per;

	if (current >= 0)
	{
		d->color_max = COLOR_MAX;
		d->color_min = COLOR_ZERO;
	}
	else
	{
		d->color_max = COLOR_ZERO;
		d->color_min = COLOR_MIN;
	}
	if (current >= d->max * 0.99)
		return (d->color_max);
	else if (current <= d->min * 0.99)
		return (d->color_min);
	per = get_percent(d->max, d->min, current);
	red = g_l((d->color_max >> 16) & 0xFF, (d->color_min >> 16) & 0xFF, per);
	green = g_l((d->color_max >> 8) & 0xFF, (d->color_min >> 8) & 0xFF, per);
	blue = g_l(d->color_max & 0xFF, d->color_min & 0xFF, per);
	return ((red << 16) | (green << 8) | blue);
}
