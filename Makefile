# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 20:17:58 by mweerts           #+#    #+#              #
#    Updated: 2019/12/13 07:51:27 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	ft_printf.c\
		parser.c\
		ft_putchar.c\
		ft_strlen.c\
		ft_putnbr.c\
		ft_putunbr.c\
		ft_putstr.c

OBJS= $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

%.o: %.c
		gcc $(FLAGS) -c -o $@ $<

clean:
		rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
		rm -rf $(NAME)

re: fclean all