# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweerts <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 15:35:02 by mweerts           #+#    #+#              #
#    Updated: 2020/01/13 17:06:07 by mweerts          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =	srcs/ft_printf.c\
		srcs/print_char.c\
		srcs/print_string.c\
		srcs/print_int.c\
		srcs/print_uint.c\
		srcs/print_percent.c\
		srcs/print_hex.c\
		srcs/get_pointer.c\
		srcs/utils.c\
		srcs/parser.c\
		srcs/number_utils.c
LIBFT_PATH = libft/
LIBFT = libft.a
OBJS= $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME):	
			@make -C $(LIBFT_PATH)
			@ar -x ./$(LIBFT_PATH)/$(LIBFT)
			@echo "\033[0;32mCompiling libftprintf"
			@gcc -c $(FLAGS) $(SRCS)
			@ar rc $(NAME) *.o 
			@ranlib $(NAME)

$(LIBFT):
		$(MAKE) -C $(LIBFT_PATH)

clean:	
		@echo "\033[0;31mCleaning printf binaries"
		@rm -rf *.o
		@make clean -C $(LIBFT_PATH)

fclean: 
		@echo "\033[0;31mCleaning libftprintf binaries"
		@rm -rf *.o
		@echo "\033[0;31mCleaning libftprintf.a"
		@rm -rf $(NAME)
		@make fclean -C $(LIBFT_PATH)

re: fclean all

bonus: all