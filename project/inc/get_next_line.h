/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:44:11 by hashly            #+#    #+#             */
/*   Updated: 2021/11/05 19:50:19 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 500

# include <stdlib.h>
# include <unistd.h>

int		ft_sheck_rtn(char *surplus);
size_t	ft_strlen(const char *str);
char	*ft_strjoin_free(char *surplus, char *buf);
int		get_next_line(int fd, char **line);

#endif
