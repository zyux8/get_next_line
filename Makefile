# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:48:17 by ohaker            #+#    #+#              #
#    Updated: 2024/12/04 16:27:28 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libget_next_line.a
CFLAGS = -Wall -Wextra -Werror
SRC = \	

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(NAME)

re: fclean all

franci:
	clear
	~/francinette/tester.sh
# Testing with francinette. Clears the terminal and starts tester.
# alias francinette="$HOME"/francinette/tester.sh
# alias paco="$HOME"/francinette/tester.sh

mygit:
	@bash -c ' \
	cd ../../GitHub && \
	cp -ru ~/Projects/get_next_line ~/GitHub && \
	git add get_next_line && \
	git status && \
	read -p "Commitment message: " input; \
	git commit -m "$$input" && \
	git push origin main'
# Command to copy all changed files into another directory
# so it can be pushed into my GitHub.

.PHONY: all clean fclean re