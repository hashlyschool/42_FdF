/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_view.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 12:50:25 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 22:30:58 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_zoom_shift(t_fdf *d, float x_pixel, float y_pixel)
{
	d->zoom = ft_min(WIDTH_DISP / x_pixel, HEIGHT_DISP / y_pixel);
	x_pixel = (d->zoom * (x_pixel - 1)) + 1;
	y_pixel = (d->zoom * (y_pixel - 1)) + 1;
	d->shift_x = (WIDTH_DISP - x_pixel) / 2;
	d->shift_y = (HEIGHT_DISP - y_pixel) / 2;
}

/*
d->shift_x -= x_min_iso * d->zoom;
d->shift_y -= y_min_iso * d->zoom;
*/
void	set_size_for_iso(t_fdf *d, float *x_pixel, float *y_pixel)
{
	float	x_min_iso;
	float	x_max_iso;
	float	y_min_iso;
	float	y_max_iso;

	x_min_iso = d->row * cos(ISO_ANGLE);
	x_max_iso = d->col * cos(ISO_ANGLE);
	y_min_iso = sin(ISO_ANGLE) - (d->map_z[0][0] / ZOOM_FACTOR_Z);
	y_max_iso = (d->col + d->row) * sin(ISO_ANGLE) - \
				(d->map_z[d->row - 1][d->col - 1] / ZOOM_FACTOR_Z);
	*x_pixel = ft_abs(x_max_iso) + ft_abs(x_min_iso);
	*y_pixel = ft_abs(y_max_iso) + ft_abs(y_min_iso);
	set_zoom_shift(d, *x_pixel, *y_pixel);
	d->shift_x += x_min_iso * d->zoom;
	d->shift_y += y_min_iso * d->zoom;
}

void	find_param_view(t_fdf *d, int type_view)
{
	float	x_pixel;
	float	y_pixel;

	d->type_view = type_view;
	set_angle(d);
	if (type_view == 5 || type_view == 6 || type_view == 8)
	{
		x_pixel = d->col;
		if (type_view == 5)
			y_pixel = (d->max - d->min) / ZOOM_FACTOR_Z;
		else if (type_view == 8)
			y_pixel = d->row;
		else
		{
			x_pixel = d->row;
			y_pixel = (d->max - d->min) / ZOOM_FACTOR_Z;
		}
		set_zoom_shift(d, x_pixel, y_pixel);
	}
	else if (type_view == 7)
		set_size_for_iso(d, &x_pixel, &y_pixel);
}

/*
1:	+x
2:	-x
3:	+y
4:	-y
5:	+z
6:	-z
*/
void	change_angle_view(t_fdf *data, int key)
{
	data->type_view = 0;
	if (key == 1)
		data->angle_x += STEP_ANGLE;
	else if (key == 2)
		data->angle_x -= STEP_ANGLE;
	else if (key == 3)
		data->angle_y += STEP_ANGLE;
	else if (key == 4)
		data->angle_y -= STEP_ANGLE;
	else if (key == 5)
		data->angle_z += STEP_ANGLE;
	else if (key == 6)
		data->angle_z -= STEP_ANGLE;
}

void	set_default_parametrs(t_fdf *data)
{
	int	width;
	int	height;

	width = WIDTH_DISP;
	height = HEIGHT_DISP;
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	find_param_view(data, 7);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "t_fdf");
}
