/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_chgbase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 20:39:10 by emgarcia          #+#    #+#             */
/*   Updated: 2021/08/31 17:40:26 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_imp_nums(unsigned int nbr, int max_pow, char *base, char *str)
{
	int		imp;
	size_t	i;
	size_t	basesize;

	imp = 0;
	i = 0;
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

char	*ft_unsigned_chgbase(unsigned int nbr, char *base)
{
	unsigned int	count;
	int				max_pow;
	char			*strbase;

	max_pow = 0;
	if (!ft_strlen(base))
		return (NULL);
	count = nbr;
	while (count > 0 && ++max_pow)
		count /= ft_strlen(base);
	strbase = malloc(sizeof(char) * (max_pow + 1));
	if (!strbase)
		return (NULL);
	strbase[max_pow] = '\0';
	ft_imp_nums(nbr, max_pow, base, strbase);
	return (strbase);
}
