/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:29:07 by hashly            #+#    #+#             */
/*   Updated: 2021/11/04 11:31:41 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}

float	ft_abs(float a)
{
	if (a < 0)
		return -a;
	else
		return a;
}
