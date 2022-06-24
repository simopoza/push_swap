# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannahri <mannahri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/10 12:48:24 by mannahri          #+#    #+#              #
#    Updated: 2022/05/30 23:42:31 by mannahri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

src = ./Mandatory/*.c 
push_swap = push_swap
FLAGS = -Wall -Wextra -Werror
CC = cc

all : push_swap
	
$(push_swap): $(src)	
	@$(CC) $(FLAGS) $(src) -o push_swap
	@tput setaf 2; echo "PUSH_SWAP IS READY"

clean :
	@rm -f push_swap
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all

src_bonus = ./Bonus/*.c ./Mandatory/ft_atoi.c ./Mandatory/ft_isdigit.c ./Mandatory/linked_list.c ./Mandatory/linked_list1.c ./Mandatory/linked_list2.c ./Mandatory/push_swap.c
checker = checker
FLAGS = -Wall -Wextra -Werror
CC = cc

bonus : checker

$(checker) : $(src_bonus)
	@$(CC) $(FLAGS) $(src_bonus) -o checker
	@tput setaf 2; echo "BONUS IS READY"

clean_bonus :
	@rm -f checker
	@tput setaf 1; echo "CLEAN COMPLET"

fclean : clean

re: fclean all