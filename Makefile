# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 16:14:51 by lsemlali          #+#    #+#              #
#    Updated: 2021/12/02 16:14:52 by lsemlali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = put_nbr.c put_nbr_base.c put_add.c put_char.c put_str.c ft_printf.c
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)
all : $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
