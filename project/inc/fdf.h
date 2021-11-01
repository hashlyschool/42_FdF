#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include "../libft/includes/libft.h"
//# include "minilibx_macos/mlx.h"

typedef struct fdf
{
	int 	col;
	int		row;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	fdf;

void	read_map(fdf *data, char *file_name);

#endif //FDF_H
