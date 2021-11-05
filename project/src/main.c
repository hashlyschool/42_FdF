/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:52 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 23:22:13 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
	//65307	Esc		exit
	//65362	up		shift_up
	//65364	down	shift_down
	//65363	right	shift_right
	//65361	left	shift_left
	//105	i		isometric
	//53	5		view_main
	//54	6		view_right
	//56	8		view_top
	//44	,
	//46	.
	//45	-		-zoom
	//61	=		+zoom
*/
int	deal_key(int key, fdf *data)
{
	// if (data->type_draw == 1)
	// {
	// 	ft_putnbr_fd(key, 1);
	// 	ft_putstr_fd("\n", 1);
	// }

	int		step;
	float	perc_for_zoom;

	step = 20;
	perc_for_zoom = 15;
	if (key == 65307 || key == 65362 || key == 65364 || key == 65363 ||
		key == 65361 || key == 45 || key == 61 || key == 53 || key == 54 ||
		key == 56 || key == 105)
	{
		if (key == 65307)
			ft_error_malloc_str("Штатное завершение работы программы\n", data, data->row);
		else if (key == 65362)
			data->shift_y -= step;
		else if (key == 65364)
			data->shift_y += step;
		else if (key == 65363)
			data->shift_x += step;
		else if (key == 65361)
			data->shift_x -= step;
		else if (key == 45 && data->zoom > 1.2)
			data->zoom *= (1 - perc_for_zoom / 100);
		else if (key == 61)
			data->zoom *= (1 + perc_for_zoom / 100);
		else if (key == 53)
			data->type_view = 5;
		else if (key == 54)
			data->type_view = 6;
		else if (key == 56)
			data->type_view = 8;
		else if (key == 105)
			data->type_view = 1;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_map(data);
	}
	return (0);
}

void	find_param_view(fdf *data)
{
	float	x_pixel;
	float	y_pixel;
	int		y_max;
	int		x_max;

	x_max = WIDTH_DISP;
	y_max = HEIGHT_DISP;
	//min_size_display
	x_pixel = data->col;//((data->col - 1) * 2) + 1;
	y_pixel = data->row;//((data->row - 1) * 2) + 1;
	//find zoom
	data->zoom = ft_min(x_max / x_pixel, y_max / y_pixel);
	//real size_map
	x_pixel = (data->zoom * (data->col - 1)) + 1;
	y_pixel = (data->zoom * (data->row - 1)) + 1;
	//set shift
	data->shift_x = (x_max - x_pixel) / 2;
	data->shift_y = (y_max - y_pixel) / 2;
}

void	set_default_parametrs(fdf *data)
{
	data->type_draw = 1;

	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;

	find_param_view(data);
	// data->zoom = 10.9;
	// data->shift_x = 200;
	// data->shift_y = 200;
	data->type_view = 8;

	data->color_max = 0xe80c0c;//0xE2062C;
	data->color_min = 0xffffff;//0x0000CD;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH_DISP, HEIGHT_DISP, "FDF");
}

int	main(int argc, char **argv)
{
	fdf data;
	if (argc != 2)
		ft_error("Неправильное количество аргументов\nИспользуйте: ./fdf map.fdf\n");
	read_map(&data, argv[1]);
	set_default_parametrs(&data);
	draw_map(&data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
