/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_chgbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 17:26:58 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/01 20:13:45 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_imp_ptr_nums(uintptr_t nbr, int max_pow, char *base, char *str)
{
	int		imp;
	size_t	i;
	size_t	basesize;

	imp = 0;
	i = 2;
	basesize = ft_strlen(base);
	max_pow--;
	if (!nbr)
		str[i] = '0';
	while (nbr > 0 || max_pow >= 0)
	{
		imp = nbr / ft_pow(basesize, max_pow);
		str[i++] = base[imp];
		nbr = nbr - (imp * ft_pow(basesize, max_pow));
		max_pow--;
	}
}

char	*ft_ptr_chgbase(uintptr_t nbr, char *base)
{
	uintptr_t	count;
	int			max_pow;
	char		*strbase;

	max_pow = 0;
	if (!ft_strlen(base))
		return (NULL);
	count = nbr;
	while (count > 0 && ++max_pow)
		count /= ft_strlen(base);
	strbase = malloc(sizeof(char) * (max_pow + 3));
	if (!strbase)
		return (NULL);
	strbase[0] = '0';
	strbase[1] = 'x';
	if (nbr)
		strbase[max_pow + 3] = '\0';
	else
		strbase[3] = '\0';
	ft_imp_ptr_nums(nbr, max_pow, base, strbase);
	return (strbase);
}
