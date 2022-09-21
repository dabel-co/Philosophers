# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <dabel-co@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 15:41:57 by dabel-co          #+#    #+#              #
#    Updated: 2022/09/21 13:00:54 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
FLAGS = -Wall -Werror  -Wextra -pthread
CC = cc
FILES =	main \
		philo_utils \
		philo \

C = $(addsuffix .c, $(FILES))

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) $(C) -o $(NAME)
clean:
	rm -f $(NAME)
fclean: clean
re: clean all

.PHONY : all clean fclean re
