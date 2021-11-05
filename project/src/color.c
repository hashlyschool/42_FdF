/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:47:25 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 15:29:34 by hashly           ###   ########.fr       */
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
	// if (delta.x > delta.y)
	// 	percentage = percent(start.x, end.x, current.x);
	// else
	// 	percentage = percent(start.y, end.y, current.y);
	red = get_light((data->color_max >> 16) & 0xFF, (data->color_min >> 16) & 0xFF, percent);
	green = get_light((data->color_max >> 8) & 0xFF, (data->color_min >> 8) & 0xFF, percent);
	blue = get_light(data->color_max & 0xFF, data->color_min & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

// int get_color(t_point current, t_point start, t_point end, t_point delta)
// {
//     int     red;
//     int     green;
//     int     blue;
//     double  percentage;

//     if (current.color == end.color)
//         return (current.color);
//     if (delta.x > delta.y)
//         percentage = percent(start.x, end.x, current.x);
//     else
//         percentage = percent(start.y, end.y, current.y);
//     red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
//     green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
//     blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
//     return ((red << 16) | (green << 8) | blue);
// }

