# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emgarcia <emgarcia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/29 17:12:03 by emgarcia          #+#    #+#              #
#    Updated: 2021/09/03 14:36:24 by emgarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_ptr_chgbase.c ft_readvar.c ft_readvar2.c ft_unsigned_itoa.c ft_unsigned_chgbase.c ft_pow.c
LIBFT	= libft/libft.a
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS}
	cd libft ; make
	cp ${LIBFT} ${NAME}
	ar -crs ${NAME} ${OBJS} ${LIBFT}

clean:
	cd libft ; make clean
	${RM} ${OBJS}

fclean: clean
	cd libft ; make fclean
	${RM} ${NAME}

re: fclean all
