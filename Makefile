# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iwietzke <iwietzke@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 21:46:53 by iwietzke          #+#    #+#              #
#    Updated: 2024/06/13 17:08:58 by iwietzke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f
FILES = ft_printf.c \
	   	ft_print_char.c \
		ft_print_str.c \
		ft_strlen.c \
		ft_print_digit.c \
		ft_print_ptr.c
OBJS = $(FILES:.c=.o)
NAME = libftprintf.a
AR = ar rcs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re