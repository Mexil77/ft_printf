/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readvar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 16:58:04 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/01 15:59:31 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_printstr(char *str)
{
	size_t	size;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	size = ft_strlen(str);
	write(1, str, size);
	return (size);
}

size_t	ft_printint(int d)
{
	size_t	size;
	char	*strdnum;

	strdnum = ft_itoa(d);
	size = ft_printstr(strdnum);
	free(strdnum);
	return (size);
}

size_t	ft_printunsg(unsigned int u)
{
	char	*strunum;
	size_t	size;

	strunum = ft_unsigned_itoa(u);
	size = ft_printstr(strunum);
	free(strunum);
	return (size);
}

size_t	ft_checkcharvar(int c, va_list ap)
{
	if (c == 'c')
		return (ft_printchar(va_arg(ap, int)));
	if (c == 's')
		return (ft_printstr(va_arg(ap, char *)));
	if (c == 'd')
		return (ft_printint(va_arg(ap, int)));
	if (c == 'p')
		return (ft_printptr(va_arg(ap, void *)));
	if (c == 'i')
		return (ft_printint(va_arg(ap, int)));
	if (c == 'u')
		return (ft_printunsg(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_printhex(va_arg(ap, unsigned int), c));
	if (c == 'X')
		return (ft_printhex(va_arg(ap, unsigned int), c));
	if (c == '%')
		return (ft_printchar(c));
	return (0);
}
