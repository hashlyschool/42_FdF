/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hashly <hashly@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 18:11:29 by hashly            #+#    #+#             */
/*   Updated: 2021/11/06 18:11:30 by hashly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_find_len(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ptr;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648\0"));
	i = 0;
	len = ft_find_len(n);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[i++] = '-';
		n *= -1;
	}
	ptr[len] = 0;
	while (len > i)
	{
		ptr[--len] = n % 10 + 48;
		n = n / 10;
	}
	return (ptr);
}
