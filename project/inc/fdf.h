/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:44 by hashly            #+#    #+#             */
/*   Updated: 2021/11/02 20:05:03 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/includes/libft.h"
//# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include "./get_next_line.h"


typedef struct fdf
{
	int 	col;
	int		row;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	read_map(fdf *data, char *file_name);
void	ft_error(char *str_error);
void	ft_error_malloc_str(char *str_error, fdf *data, int i);

#endif //FDF_H
