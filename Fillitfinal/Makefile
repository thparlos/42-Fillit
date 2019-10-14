# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thparlos <thparlos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 10:16:32 by tpacaud           #+#    #+#              #
#    Updated: 2019/10/12 15:10:31 by thparlos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc

FLAGS = -Wall -Wextra -Werror

C = ft_readtotab.c ft_strsplit.c\
	ft_filltotab.c main.c ft_resolution.c ft_printtab.c\
	ft_maptocube.c ft_annex.c ft_free_cube.c norme.c

O = $(C:.c=.o)

I = fillit.h

all : $(NAME)

$(NAME): $(O)
	make -C libft/
	$(CC) $(FLAGS) -o $(NAME) $(O) -L libft/ -lft

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -rf $(O)
	make -C libft/ clean

fclean : clean
	make fclean -C libft/
	rm -rf $(NAME)

re : fclean all

.PHONY: all lib clean flean re
