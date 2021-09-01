/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:57:08 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/01 19:37:24 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_countcut(char *str)
{
	size_t	i;
	size_t	before;

	if (!str || str[0] == '%')
		return (0);
	i = -1;
	before = 1;
	while (str[++i] && before)
	{
		if (str[i + 1] == '%')
			before--;
	}
	return (i);
}

void	ft_movestr(char *str, size_t move)
{
	size_t	i;

	i = 0;
	if (str)
	{	
		while (str[move + i])
		{
			str[i] = str[move + i];
			i++;
		}
		while (str[i])
			str[i++] = '\0';
	}
}

size_t	ft_printcut(char *str)
{
	char	*cut;
	size_t	sizecut;
	size_t	i;

	sizecut = ft_countcut(str);
	if (!sizecut)
		return (0);
	cut = malloc(sizeof(char) * (sizecut + 1));
	if (!cut)
		return (0);
	i = -1;
	while (str[++i])
		if (i < sizecut)
			cut[i] = str[i];
	cut[sizecut] = '\0';
	ft_printstr(cut);
	ft_movestr(str, sizecut);
	free(cut);
	return (sizecut);
}

size_t	ft_checkconv(char *str, va_list ap)
{
	size_t	size;

	size = 0;
	if (str[1])
	{
		size = ft_checkcharvar(str[1], ap);
		ft_movestr(str, 2);
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	total;
	char	*strman;

	va_start(ap, str);
	total = 0;
	strman = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!strman)
		return (0);
	ft_strlcpy(strman, str, ft_strlen(str) + 1);
	total += ft_printcut(strman);
	while (ft_strlen(strman))
	{
		total += ft_checkconv(strman, ap);
		total += ft_printcut(strman);
	}
	free(strman);
	va_end(ap);
	return (total);
}
