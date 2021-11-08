/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:44 by hashly            #+#    #+#             */
/*   Updated: 2021/11/08 10:55:00 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include "./get_next_line.h"
# include "../minilibx-linux/mlx.h"

# define ISO_ANGLE			0.523599
# define PI					3.14159265359

# define WIDTH_DISP			1800
# define HEIGHT_DISP		1000

# define ZOOM_FACTOR_Z		10.
# define STEP_SHIFT			20
# define STEP_ANGLE			5
# define PERC_FOR_ZOOM		15.

# define COLOR_ZERO			0xffffffff
# define COLOR_MAX			0xffe80c0c
# define COLOR_MIN			0xff0000CD

typedef struct s_fdf
{
	int		col;
	int		row;
	int		max;
	int		min;
	int		color_max;
	int		color_min;
	int		color;
	int		**map_z;
	float	zoom;
	int		shift_x;
	int		shift_y;
	int		angle_x;
	int		angle_y;
	int		angle_z;
	int		type_view;

	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

//read_map.c
void	read_map(t_fdf *data, char *file_name);
//error.c
void	ft_error(char *str_error);
void	ft_error_malloc_str(char *str_error, t_fdf *data, int i);
//helper_func.c
float	ft_max(float a, float b);
float	ft_abs(float a);
float	ft_min(float a, float b);
double	sin_deg(double x);
double	cos_deg(double x);
//draw.c
int		draw_map(t_fdf *data);
//draw_turn.c
void	set_angle(t_fdf *data);
void	isometric(float *x, float *y, float z);
void	turn(float *x, float *y, float *z, t_fdf *data);
//color.c
int		get_color(t_fdf *data, float current);
//param_view.c
void	set_default_parametrs(t_fdf *data);
void	find_param_view(t_fdf *data, int type_view);
void	change_angle_view(t_fdf *data, int key);
//control.c
int		deal_key(int key, t_fdf *data);
int		ft_close(t_fdf *data);
//draw2.c
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);

#endif
