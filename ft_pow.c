/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:40:01 by emgarcia          #+#    #+#             */
/*   Updated: 2021/08/31 17:53:05 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintptr_t	ft_pow(size_t base, int pow)
{
	int			i;
	uintptr_t	res;

	if (pow == 0)
		return (1);
	i = 1;
	res = (uintptr_t)base;
	while (i < pow)
	{
		res *= base;
		i++;
	}
	return (res);
}
