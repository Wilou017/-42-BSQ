# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/24 00:34:42 by amaitre           #+#    #+#              #
#    Updated: 2015/09/24 16:30:47 by jtranchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCF = ./src/

DOTC = $(SRCF)main.c $(SRCF)algo.c $(SRCF)functions.c

DOTO = 	$(addprefix obj/,$(notdir $(DOTC:.c=.o)))

DOTH = ./inc/

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(DOTO)
	gcc $(FLAG) -o $(NAME) $(DOTO)

obj/%.o: src/%.c
	gcc -c $(FLAG) -o $@ $< -I $(DOTH)

clean:
	/bin/rm $(DOTO)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
