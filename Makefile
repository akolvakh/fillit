# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolvakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/14 10:55:39 by akolvakh          #+#    #+#              #
#    Updated: 2019/04/22 15:43:33 by akolvakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

CC = clang

CFLAGS = -Wall -Werror -Wextra -I $(HEADERS) -o $(NAME)

SRC = 

LIBFT_DIR = libft
LIBS = libft/libft.a

OBJ = $(SRC:.c=.o)

HEADERS = .

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC) $(LIBS)
	$(CC) $(CFLAGS) $(SRC) $(LIBS)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
