/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:05:34 by emgarcia          #+#    #+#             */
/*   Updated: 2021/08/30 19:55:16 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_cpy_len(unsigned int n_cpy, size_t *len, unsigned int n)
{
	if (n == 0)
		*len += 1;
	return (n_cpy);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	size_t			len;
	char			*str_num;
	unsigned int	n_cpy;

	len = 1;
	n_cpy = n;
	n_cpy = ft_cpy_len(n_cpy, &len, n);
	len += ft_intlen(n_cpy);
	str_num = (char *)malloc(sizeof(char) * len);
	if (str_num == NULL)
		return (NULL);
	str_num[--len] = '\0';
	while (--len > 0)
	{
		str_num[len] = (n_cpy % 10) + '0';
		n_cpy /= 10;
	}
	str_num[len] = (n_cpy % 10) + '0';
	return (str_num);
}
