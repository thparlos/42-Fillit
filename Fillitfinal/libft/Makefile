# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpacaud <tpacaud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 10:16:32 by tpacaud           #+#    #+#              #
#    Updated: 2019/02/01 11:27:07 by tpacaud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

C = ft_putendl.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strcmp.c  \
	ft_strlen.c ft_strjoin.c  ft_strchr.c ft_bzero.c ft_strcpy.c\
	ft_isascii.c ft_bzero.c

O = $(C:.c=.o)

I = libft.h

all : $(NAME)

$(NAME): $(O)
	ar rc $(NAME) $(O)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(O)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
