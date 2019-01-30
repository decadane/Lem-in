/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:22:01 by ffahey            #+#    #+#             */
/*   Updated: 2018/11/26 21:52:24 by ffahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long int	num;
	size_t		size;
	char		*res;

	num = n < 0 ? -(long)n : n;
	size = n <= 0 ? 1 : 0;
	while (num && ++size)
		num /= 10;
	if (!(res = ft_strnew(size)))
		return (NULL);
	num = n < 0 ? -(long)n : n;
	if (!num)
		*res = '0';
	else
	{
		while (size-- && num)
		{
			res[size] = num % 10 + '0';
			num /= 10;
		}
		res[size] = size ? res[size] : '-';
	}
	return (res);
}
