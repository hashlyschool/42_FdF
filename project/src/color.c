/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:47:25 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 19:35:31 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double get_percent(int start, int end, int current)
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

int get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int get_color(fdf *data, int current)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (current == data->max)
		return (data->color_max);
	else if (current == data->min)
		return (data->color_min);
	percent = get_percent(data->max, data->min, current);
	red = get_light((data->color_max >> 16) & 0xFF, (data->color_min >> 16) & 0xFF, percent);
	green = get_light((data->color_max >> 8) & 0xFF, (data->color_min >> 8) & 0xFF, percent);
	blue = get_light(data->color_max & 0xFF, data->color_min & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}
