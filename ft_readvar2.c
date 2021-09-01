/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readvar2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:03:43 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/01 19:16:01 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printhex(unsigned int x, char conv)
{
	char	*strxnum;
	size_t	size;
	char	*base;

	if (conv == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	strxnum = ft_unsigned_chgbase(x, base);
	size = ft_printstr(strxnum);
	free(strxnum);
	return (size);
}

size_t	ft_printptr(void *p)
{
	uintptr_t	ptrval;
	char		*strpnum;
	size_t		size;

	ptrval = (uintptr_t)p;
	strpnum = ft_ptr_chgbase(ptrval, "0123456789abcdef");
	size = ft_printstr(strpnum);
	free(strpnum);
	return (size);
}
