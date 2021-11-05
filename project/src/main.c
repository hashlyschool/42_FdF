/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:52 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 19:32:58 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	deal_key(int key, fdf *data)
{
	// if (data->type_draw == 1)
	// {
	// 	ft_putnbr_fd(key, 1);
	// 	ft_putstr_fd("\n", 1);
	// }
	//65307	Esc
	//65362	up
	//65364	down
	//65363	right
	//65361	left
	//105	i	isometric
	//53	5	view_main
	//54	6	view_right
	//56	8	view_top
	//44	,
	//46	.
	//45	-
	//61	=

	//Убрать бы перерисовку
	int	step;

	step = 20;
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
	else if (key == 45)
	{
		if (data->zoom > 10)
			data->zoom -= 5;
		else if (data->zoom > 1)
			data->zoom -= 1;
	}
	else if (key == 61)
	{
		if (data->zoom > 10)
			data->zoom += 5;
		else if (data->zoom > 0)
			data->zoom += 1;
	}
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
	return (0);
}

int	main(int argc, char **argv)
{
	fdf data;
	if (argc != 2)
		ft_error("Неправильное количество аргументов\nИспользуйте: ./fdf map.fdf\n");
	read_map(&data, argv[1]);

//test print
	// for (int i = 0; i < data.row; i++)
	// {
	// 	for (int j = 0; j < data.col; j++)
	// 	{
	// 		ft_putnbr_fd(data.map_z[i][j], 1);
	// 		ft_putstr_fd(" ", 1);
	// 	}
	// 	ft_putstr_fd("\n", 1);
	// }
//
	data.type_draw = 1;
	data.zoom = 20;
	data.angle_x = 0;
	data.angle_y = 0;
	data.angle_z = 0;
	data.shift_x = 200;
	data.shift_y = 200;
	data.color_max = 0xe80c0c;//0xE2062C;
	data.color_min = 0xffffff;//0x0000CD;
	data.type_view = 1;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FDF");

	draw_map(&data);

	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);

	return (0);
}
