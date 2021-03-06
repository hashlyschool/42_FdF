/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:52 by hashly            #+#    #+#             */
/*   Updated: 2021/11/07 20:05:58 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
		ft_error("Неверное кол-во аргументов\nНужно: ./t_fdf map.t_fdf\n");
	read_map(&data, argv[1]);
	set_default_parametrs(&data);
	mlx_loop_hook(data.mlx_ptr, draw_map, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
