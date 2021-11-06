/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:12:45 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 18:12:46 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (*s1 == *s2)
	{
		if (i == (n - 1))
			return (0);
		i++;
		++s1;
		++s2;
		if ((*s2 == *s1) && (*s1 == '\0'))
			return (0);
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
