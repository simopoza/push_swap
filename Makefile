# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:48:24 by mannahri          #+#    #+#              #
#    Updated: 2022/05/13 18:31:31 by mannahri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
CC=gcc
# SANITIZE= -g -fsanitize=address
CFLAGS= -Wall -Wextra -Werror $(SANITIZE)
RM= rm -f
SRC = linked_list.c main.c push_swap.c linked_list1.c swap.c rotate.c r_rotate.c push.c lis.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a
all: $(NAME)
$(LIBFT):
		make -C libft
$(NAME): $(LIBFT) $(OBJ) 
	gcc $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
clean:
	$(RM) $(OBJ)
	make clean -C libft
fclean: clean
	$(RM) $(NAME)
	make fclean -C libft
re: fclean all