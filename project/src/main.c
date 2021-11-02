/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:52 by hashly            #+#    #+#             */
/*   Updated: 2021/11/02 20:29:59 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	fdf data;
	if (argc != 2)
		ft_error("Неправильное количество аргументов\nИспользуйте: ./fdf map.fdf\n");
	read_map(&data, argv[1]);

	for (int i = 0; i < data.row; i++)
	{
		for (int j = 0; j < data.col; j++)
		{
			ft_putnbr_fd(data.z_matrix[i][j], 1);
			ft_putstr_fd(" ", 1);
		}
		ft_putstr_fd("\n", 1);
	}

	// set_default(&PRM);
	// draw(matrix);
	// mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	// mlx_loop(PRM.mlx_ptr);


	return (0);
}
