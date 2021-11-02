/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:44:27 by hashly            #+#    #+#             */
/*   Updated: 2021/11/02 21:44:28 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_error(char *str_error)
{
	ft_putstr_fd(str_error, 1);
	exit(0);
}

void	ft_error_malloc_str(char *str_error, fdf *data, int i)
{
	int	j;

	j = 0;
	ft_putstr_fd(str_error, 1);
	while (i < j)
	{
		free(data->z_matrix[i++]);
	}
	free(data->z_matrix);
	exit(0);
}
