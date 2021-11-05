/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:44 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 18:08:00 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
//# include "minilibx_macos/mlx.h"
# include "../../../minilibx-linux/mlx.h"
# include "../../../minilibx-linux/mlx_int.h"

# define PI atan(1) * 4
# define DEG_TO_RAD(deg) (deg * PI / 180)
# define COS_DEG(deg) (cos(DEG_TO_RAD(deg)))
# define SIN_DEG(deg) (sin(DEG_TO_RAD(deg)))
# define WIDTH 1600
# define HEIGHT 800

typedef struct fdf
{
	int 	col;
	int		row;
	int		max;
	int		min;
	int		color_max;
	int		color_min;
	int		color;
	int		**map_z;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		type_draw;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	int		type_view;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

//read_map.c
void	read_map(fdf *data, char *file_name);
//error.c
void	ft_error(char *str_error);
void	ft_error_malloc_str(char *str_error, fdf *data, int i);
//helper_func.c
float	ft_max(float a, float b);
float	ft_abs(float a);
//draw.c
void	draw_map(fdf *data);
//color.c
int get_color(fdf *data, int current);

#endif //FDF_H
