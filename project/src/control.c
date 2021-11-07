/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 19:35:30 by hashly            #+#    #+#             */
/*   Updated: 2021/11/07 20:19:28 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	clear_window_and_draw(t_fdf *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img);
	data->img = mlx_new_image(data->mlx_ptr, WIDTH_DISP, HEIGHT_DISP);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
							&data->line_length, &data->endian);
	draw_map(data);
}

/*
	//65307		Esc				exit
	//65362		up				shift_up
	//65364		down			shift_down
	//65363		right			shift_right
	//65361		left			shift_left
	//53		5				view_main
	//54		6				view_left
	//55		7				view_isometric
	//56		8				view_top
	//103-108	9				view_custom
	//45		-				-zoom
	//61		=				+zoom
	//103-108	g,h,i,j,k,l		+-(x)(y)(z)
*/
int	deal_key(int key, t_fdf *data)
{
	if (key == 65307 || (key >= 65361 && key <= 65364) || key == 45
		|| key == 61 || (key >= 53 && key <= 56) || (key >= 103 && key <= 108))
	{
		if (key == 65307)
			ft_error_malloc_str("Good exit\n", data, data->row);
		else if (key == 65361)
			data->shift_x -= STEP_SHIFT;
		else if (key == 65362)
			data->shift_y -= STEP_SHIFT;
		else if (key == 65363)
			data->shift_x += STEP_SHIFT;
		else if (key == 65364)
			data->shift_y += STEP_SHIFT;
		else if (key == 45 && data->zoom > 1.2)
			data->zoom *= (1 - PERC_FOR_ZOOM / 100);
		else if (key == 61)
			data->zoom *= (1 + PERC_FOR_ZOOM / 100);
		else if (key >= 53 && key <= 56)
			find_param_view(data, key - 48);
		else if (key >= 103 && key <= 108)
			change_angle_view(data, key - 102);
		clear_window_and_draw(data);
	}
	return (0);
}

int	ft_close(t_fdf *data)
{
	ft_error_malloc_str("Good exit\n", data, data->row);
	return (0);
}
