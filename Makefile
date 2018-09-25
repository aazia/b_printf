# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azkeever <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/02 10:36:43 by azkeever          #+#    #+#              #
#    Updated: 2018/09/24 14:09:09 by azkeever         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCE = *.c
OBJECTS = *.o
HEADER = libftprintf.h

all: $(NAME)

$(NAME):
	gcc $(HEADER) -c $(SOURCE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean: 
	rm -f *.o *.swp *~ *.gch

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

