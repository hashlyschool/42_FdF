#include "fdf.h"

int main(int argc, char **argv)
{
	fdf data;
	if (argc != 2)
		ft_error("Неправильное количество аргументов\nИспользуйте: ./fdf map.fdf\n");
	read_map(&data, argv[1]);


	// set_default(&PRM);
	// draw(matrix);
	// mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	// mlx_loop(PRM.mlx_ptr);


	return (0);
}
