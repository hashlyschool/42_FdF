/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:29:07 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 18:29:10 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	ft_abs(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

double	cos_deg(double x)
{
	return (cos(x * PI / 180.));
}

double	sin_deg(double x)
{
	return (sin(x * PI / 180.));
}
