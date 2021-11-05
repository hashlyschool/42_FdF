/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:58:37 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 16:01:09 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	isometric(float *x, float *y, float z)
{
	float	x_true;
	float	y_true;
	double	angle;

	x_true = *x;
	y_true = *y;
	angle = 0.523599;
	*x = (x_true - y_true) * cos(angle);
	*y = (x_true + y_true) * sin(angle) - z;
}

void	turn(float *x, float *y, float *z, fdf *data)
{
	float	true_x;
	float	true_y;
	float	true_z;

	true_y = *y;
	true_z = *z;
	// turn_x
	*y = true_y * COS_DEG(data->angle_x) + true_z * SIN_DEG(data->angle_x);
	*z = -true_y * SIN_DEG(data->angle_x) + true_z * COS_DEG(data->angle_x);
	// turn_y
	true_x = *x;
	true_z = *z;
	*x = true_x * COS_DEG(data->angle_y) + true_z * SIN_DEG(data->angle_y);
	*z = -true_x * SIN_DEG(data->angle_y) + true_z * COS_DEG(data->angle_y);
	// turn_z
	true_x = *x;
	true_y = *y;
	*x = true_x * COS_DEG(data->angle_z) - true_y * SIN_DEG(data->angle_z);
	*y = true_x * SIN_DEG(data->angle_z) + true_y * COS_DEG(data->angle_z);
}

/*
Функция соединяет две точки по прямой
*/
void	draw_straight_line(float x1, float y1, float x2, float y2, fdf *data)
{
	float	x_step;
	float	y_step;
	float	z_step;
	int		max;
	float	z1;
	float	z2;
	float	z1_color;

	z1 = data->map_z[(int)y1][(int)x1];
	z2 = data->map_z[(int)y2][(int)x2];

	x1 *= data->zoom;
	x2 *= data->zoom;
	y1 *= data->zoom;
	y2 *= data->zoom;
	z1 *= data->zoom / 2;
	z2 *= data->zoom / 2;
	z1_color = z1;

	if (data->type_view == 1)
	{
		isometric(&x1, &y1, z1);
		isometric(&x2, &y2, z2);
	}
	else
	{
		if (data->type_view == 8) //вид сверху
		{
			data->angle_x = 0;
			data->angle_y = 0;
			data->angle_z = 0;
		}
		else if (data->type_view == 5) //главный вид
		{
			data->angle_x = -90;
			data->angle_y = 0;
			data->angle_z = 0;
		}
		else if (data->type_view == 6) //вид справа
		{
			data->angle_x = -90;
			data->angle_y = 90;
			data->angle_z = 0;
		}
		turn(&x1, &y1, &z1, data);
		turn(&x2, &y2, &z2, data);
	}



	x1 += data->shift_x;
	y1 += data->shift_y;
	x2 += data->shift_x;
	y2 += data->shift_y;

	x_step = x2 - x1;
	y_step = y2 - y1;
	z_step = z2 - z1;

	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	z_step /= max;
	while((int)(x1 - x2) || (int)(y1 - y2))
	{
		if (x1 > 0 && x1 <= WIDTH && y1 > 0 && y1 <= HEIGHT)
		{
			data->color = get_color(data, z1_color / data->zoom * 2);
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x1, y1, data->color);
		}
		x1 += x_step;
		y1 += y_step;
		z1 += z_step;
	}
}

/*
Функция в зависимости от параметра data->type_draw
запускает функцию рисования по двум точкам.
Либо соединяет две точки по прямой (type_draw == 1) или выступами (type_draw == 2)
*/
void	draw_by_two_points(float x1, float y1, float x2, float y2, fdf *data)
{
	if (data->type_draw == 1)
		draw_straight_line(x1, y1, x2, y2, data);
	/* нарисовать выступами
	else if (data->type_draw == 2)
		draw with protrusions()
	*/
}


void	draw_map(fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while(y < data->row)
	{
		x = 0;
		while(x < data->col)
		{
			if (x < data->col - 1)
				draw_by_two_points(x, y, x + 1, y, data);
			if (y < data->row - 1)
				draw_by_two_points(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}
