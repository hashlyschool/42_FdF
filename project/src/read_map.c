#include "fdf.h"

/*
Функция проверяет валидность карты.

Карта должна быть:
- прямоугольной;
- содержать только числа, пробелы и символ переноса строки.
*/
void	check_map(fdf *data, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);

	if (fd)
	{
		/*
			Здесь я, возможно, напишу проверки карты
		*/
		close(fd);
	}
	else
		return (fd_error("Ошибка открытия файла"));
}

/*
Функция определяет количество строк и чисел в строке.
Затем записывает эти значения в соответствующие переменные data
*/
void	get_weight_height(fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	if (fd)
	{
		data->col = 0;
		data->row = 1;
		i = get_next_line(fd, &line);
		while (*line)
		{
			if (*line++ == ' ')
				data->col++;
		}
		while (i)
		{
			data->row++;
			free(line);
			i = get_next_line(fd, &line);
		}
		free(line);
		close(fd);
	}
	else
		return (fd_error("Ошибка открытия файла"));
}

void	split_str_and_write_to_array(fdf *data, char *str, int num_str)
{
	char	**arr_nbr;
	int		i;

	i = 0;
	arr_nbr = ft_split(str, ' ');
	while(arr_nbr[i])
	{
		data->z_matrix[num_str][i] = ft_atoi(arr_nbr[i]);
		i++;
	}
}

void	fill_map(fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;
	int		num_str;

	num_str = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd)
	{
		i = get_next_line(fd, &line);
		while (i)
		{
			split_str_and_write_to_array(data, line, num_str);
			num_str++;
			free(line);
			i = get_next_line(fd, &line);
		}
		free(line);
		close(fd);
	}
	else
		return (fd_error("Ошибка открытия файла"));
}

/*
Функция записывает в структуру data содержимое карты с именем file_name

Карта должна быть:
- прямоугольной;
- содержать только числа, пробелы и символ переноса строки.
*/
void	read_map(fdf *data, char *file_name)
{
	int	i;

	check_map(data, file_name);
	get_weight_height(data, file_name);
	data->z_matrix = (char **)malloc(sizeof(char *) * data->row);
	if (!data->z_matrix)
		ft_error("Ошибка выделения памяти\n");
	i = data->col;
	while (i--)
	{
		data->z_matrix[i] = (char *)malloc(sizeof(char) * data->col);
		if (!data->z_matrix[i])
			ft_error_malloc_str("Ошибка выделения памяти\n", i); //очистить память в i-1 строках
	}
	fill_map(data, file_name);
	return ;
}
