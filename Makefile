# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 15:41:57 by dabel-co          #+#    #+#              #
#    Updated: 2022/09/06 18:35:45 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Wextra -pthread -fsanitize=address -g3
CC = cc
FILES =	philo \
		philo_utils \

C = $(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(C) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./Libft
re: clean all

.PHONY : all clean fclean re
