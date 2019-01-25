# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabou-h <maabou-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 20:41:23 by maabou-h          #+#    #+#              #
#    Updated: 2019/01/24 13:34:35 by maabou-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = ft_csp_case.c ft_di_case.c ft_di_helper.c ft_flags.c ft_o_case.c	\
	  ft_o_helper.c ft_p_helper.c ft_printf.c ft_tools.c ft_u_case.c	\
	  ft_u_helper.c ft_x_case.c ft_x_helper.c ft_xu_case.c 				\
	  ft_xu_helper.c ft_tools2.c

OBJ = $(SRC:.c=.o)

.PHONY: norm, re, fclean, clean, all

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

norm:
	norminette $(SRC)
