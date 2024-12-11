# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohaker <ohaker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 15:48:17 by ohaker            #+#    #+#              #
#    Updated: 2024/12/11 20:10:42 by ohaker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

franci:
	clear
	~/francinette/tester.sh
# Testing with francinette. Clears the terminal and starts tester.
# alias francinette="$HOME"/francinette/tester.sh
# alias paco="$HOME"/francinette/tester.sh

mygit:
	@bash -c ' \
	cp -ru ~/Projects/get_next_line ~/GitHub && \
	cd ../../GitHub/get_next_line && \
	git add . && \
	git status && \
	read -p "Commitment message: " input; \
	git commit -m "$$input" && \
	git push origin main'
# Command to copy all changed files into another directory
# so it can be pushed into my GitHub.
