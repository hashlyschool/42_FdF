/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:45:55 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 19:54:08 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

/*
Функция проверяет валидность карты.

Карта должна быть:
- прямоугольной;
- содержать только числа, пробелы и символ переноса строки.
*/
void	check_map(fdf *data, char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY | __O_DIRECTORY);
	if (fd != -1)
		ft_error("Указана директория. Укажите файл с расширением .fdf\n");
	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		data->col = 0;
		/*
			Здесь я, возможно, напишу проверки карты
		*/
		close(fd);
	}
	else
		ft_error("Ошибка открытия файла\n");
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

	char	**arr_nbr;
	fd = open(file_name, O_RDONLY);
	if (fd != -1)
	{
		data->col = 0;
		data->row = 0;
		i = get_next_line(fd, &line);
		arr_nbr = ft_split(line, ' ');
		while (arr_nbr[data->col])
		{
			free(arr_nbr[data->col]);
			data->col++;
		}
		free(arr_nbr);
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
		return (ft_error("Ошибка открытия файла\n"));
}

void	split_str_and_write_to_array(fdf *data, char *str, int num_str)
{
	char	**arr_nbr;
	int		nbr;
	int		i;

	i = 0;
	arr_nbr = ft_split(str, ' ');
	while(arr_nbr[i])
	{
		nbr = ft_atoi(arr_nbr[i]);
		free(arr_nbr[i]);
		data->map_z[num_str][i] = nbr;
		if (nbr > data->max)
			data->max = nbr;
		if (nbr < data->min)
			data->min = nbr;
		i++;
	}
	free(arr_nbr);
}

void	fill_map(fdf *data, char *file_name)
{
	int		fd;
	char	*line;
	int		i;
	int		num_str;

	num_str = 0;
	fd = open(file_name, O_RDONLY);
	if (fd > 0)
	{
		data->max = -2147483648;
		data->min = 2147483647;
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
		return (ft_error("Ошибка открытия файла\n"));
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
	data->map_z = (int **)malloc(sizeof(int *) * data->row);
	if (!data->map_z)
		ft_error("Ошибка выделения памяти\n");
	i = data->row;
	while (i--)
	{
		data->map_z[i] = (int *)malloc(sizeof(int) * data->col);
		if (!data->map_z[i])
			ft_error_malloc_str("Ошибка выделения памяти\n", data, i); //очистить память в i-1 строках
	}
	fill_map(data, file_name);
	// ft_putstr_fd("\n", 1);
	// ft_putnbr_fd(data->max, 1);
	// ft_putstr_fd("\n", 1);
	// ft_putnbr_fd(data->min, 1);
	// ft_putstr_fd("\n", 1);
	return ;
}
