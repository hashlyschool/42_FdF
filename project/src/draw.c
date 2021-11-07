/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:58:37 by hashly            #+#    #+#             */
/*   Updated: 2021/11/07 20:11:16 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
/*
a[i]:
	i
	0:	x1
	1:	y1
	2:	x2
	3:	y2
*/
void	zoom_turn_shift(t_fdf *data, float *a, float z1, float z2)
{
	a[0] *= data->zoom;
	a[2] *= data->zoom;
	a[1] *= data->zoom;
	a[3] *= data->zoom;
	z1 *= data->zoom / ZOOM_FACTOR_Z;
	z2 *= data->zoom / ZOOM_FACTOR_Z;
	if (data->type_view == 7)
	{
		isometric(&(a[0]), &(a[1]), z1);
		isometric(&(a[2]), &(a[3]), z2);
	}
	else
	{
		turn(&a[0], &a[1], &z1, data);
		turn(&a[2], &a[3], &z2, data);
	}
	a[0] += data->shift_x;
	a[1] += data->shift_y;
	a[2] += data->shift_x;
	a[3] += data->shift_y;
}

void	draw_line(float *steps, float *a, t_fdf *d, float z1_true)
{
	int		max;

	steps[0] = a[2] - a[0];
	steps[1] = a[3] - a[1];
	max = ft_max(ft_abs(steps[0]), ft_abs(steps[1]));
	steps[0] /= max;
	steps[1] /= max;
	steps[2] /= max;
	while ((int)(a[0] - a[2]) || (int)(a[1] - a[3]))
	{
		if (a[0] >= 0 && a[0] <= WIDTH_DISP && a[1] >= 0 && a[1] <= HEIGHT_DISP)
		{
			d->color = get_color(d, z1_true);
			my_mlx_pixel_put(d, a[0], a[1], d->color);
		}
		a[0] += steps[0];
		a[1] += steps[1];
		z1_true += steps[2];
	}
}

/*
Функция соединяет две точки по прямой.
arr[i]:
	i
	0:	x1
	1:	y1
	2:	x2
	3:	y2

steps[i]:
i
0:	x_step
1:	y_step
2:	z_step
*/
void	draw_by_two_points(float *a, t_fdf *data)
{
	float	*steps;
	float	z1_true;

	steps = (float *)malloc(sizeof(float) * 3);
	z1_true = data->map_z[(int)a[1]][(int)a[0]];
	steps[2] = data->map_z[(int)a[3]][(int)a[2]] \
							- data->map_z[(int)a[1]][(int)a[0]];
	zoom_turn_shift(data, a, data->map_z[(int)a[1]][(int)a[0]], \
					data->map_z[(int)a[3]][(int)a[2]]);
	draw_line(steps, a, data, z1_true);
	free(steps);
}

/*
type = 1 - horiz
type = 2 - vertic
*/
void	fiil_arr(float *arr, int x, int y, int type)
{
	arr[0] = x;
	arr[1] = y;
	if (type == 1)
	{
		arr[2] = arr[0] + 1;
		arr[3] = arr[1];
	}
	else if (type == 2)
	{
		arr[2] = arr[0];
		arr[3] = arr[1] + 1;
	}
}

/*
arr:
0	x1
1	y1
2	x2
3	y2
*/
int	draw_map(t_fdf *data)
{
	int		x;
	int		y;
	float	*arr;

	arr = (float *)malloc(sizeof(float) * 4);
	y = 0;
	while (y < data->row)
	{
		x = 0;
		while (x < data->col)
		{
			fiil_arr(arr, x, y, 1);
			if (x < data->col - 1)
				draw_by_two_points(arr, data);
			fiil_arr(arr, x, y, 2);
			if (y < data->row - 1)
				draw_by_two_points(arr, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
	free(arr);
	return (0);
}
