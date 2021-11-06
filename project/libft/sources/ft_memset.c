/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:12:08 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 18:12:09 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (count--)
		*(unsigned char *)ptr++ = (unsigned char)ch;
	return (buf);
}
