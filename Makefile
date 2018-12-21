# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 12:32:45 by jmoucach          #+#    #+#              #
#    Updated: 2018/12/14 14:07:04 by fgaribot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
CC= gcc
CFLAGS= -Wall -Werror -Wextra -g
SRC= ./main.c\
	 ./placement.c\
	 ./valid.c\
	 ./backtrack.c

OBJ= $(SRC:.c=.o)
LIB= ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(CFLAGS) $(OBJ) $(LIB)

%.o: %.c $(LIB)
	$(CC) -o $@ -c $< $(CFLAGS)

$(LIB):
	make -C ./libft
clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
re: fclean all
