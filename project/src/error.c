/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:44:27 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 17:04:16 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error(char *str_error)
{
	ft_putstr_fd(str_error, 1);
	exit(0);
}

void	ft_error_malloc_str(char *str_error, t_fdf *data, int i)
{
	int	j;

	j = 0;
	ft_putstr_fd(str_error, 1);
	while (j < i)
	{
		free(data->map_z[j++]);
	}
	free(data->map_z);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
