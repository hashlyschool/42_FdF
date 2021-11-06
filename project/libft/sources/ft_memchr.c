/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:11:58 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 18:13:36 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)(arr) == (unsigned char)c)
			return ((char *)(arr));
		arr++;
	}
	return (NULL);
}
