/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:06:06 by emgarcia          #+#    #+#             */
/*   Updated: 2021/09/01 20:33:39 by emgarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

int			ft_printf(const char *str, ...);
size_t		ft_printstr(char *str);
size_t		ft_countcut(char *str);
void		ft_movestr(char *str, size_t move);
size_t		ft_printcut(char *str);
size_t		ft_checkcharvar(int c, va_list ap);
size_t		ft_checkconv(char *str, va_list ap);
size_t		ft_checkvar(size_t tipe, va_list ap);
char		*ft_unsigned_itoa(unsigned int n);
char		*ft_unsigned_chgbase(unsigned int nbr, char *base);
size_t		ft_printhex(unsigned int x, char conv);
char		*ft_ptr_chgbase(uintptr_t nbr, char *base);
size_t		ft_printptr(void *p);
uintptr_t	ft_pow(size_t base, int pow);

#endif
