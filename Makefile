# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 15:41:57 by dabel-co          #+#    #+#              #
#    Updated: 2022/05/03 15:43:19 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Werror -Wextra
CC = cc
FILES =	philo \

C = $(addprefix ./philo/, $(addsuffix .c, $(FILES)))

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(C) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./Libft
re: clean all

.PHONY : all clean fclean re
