/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:02:51 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 19:37:07 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, float z)
{
	float	x_true;
	float	y_true;

	x_true = *x;
	y_true = *y;
	*x = (x_true - y_true) * cos(ISO_ANGLE);
	*y = (x_true + y_true) * sin(ISO_ANGLE) - z;
}

void	turn(float *x, float *y, float *z, t_fdf *data)
{
	float	true_x;
	float	true_y;
	float	true_z;

	true_y = *y;
	true_z = *z;
	*y = true_y * cos_deg(data->angle_x) + true_z * sin_deg(data->angle_x);
	*z = -true_y * sin_deg(data->angle_x) + true_z * cos_deg(data->angle_x);
	true_x = *x;
	true_z = *z;
	*x = true_x * cos_deg(data->angle_y) + true_z * sin_deg(data->angle_y);
	*z = -true_x * sin_deg(data->angle_y) + true_z * cos_deg(data->angle_y);
	true_x = *x;
	true_y = *y;
	*x = true_x * cos_deg(data->angle_z) - true_y * sin_deg(data->angle_z);
	*y = true_x * sin_deg(data->angle_z) + true_y * cos_deg(data->angle_z);
}

void	set_angle(t_fdf *data)
{
	if (data->type_view == 5)
	{
		data->angle_x = -90;
		data->angle_y = 0;
		data->angle_z = 0;
	}
	else if (data->type_view == 6)
	{
		data->angle_x = -90;
		data->angle_y = 90;
		data->angle_z = 0;
	}
	else if (data->type_view == 8)
	{
		data->angle_x = 0;
		data->angle_y = 0;
		data->angle_z = 0;
	}
}
