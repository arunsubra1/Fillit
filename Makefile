# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/29 00:07:17 by asubrama          #+#    #+#              #
#    Updated: 2019/11/08 18:02:22 by asubrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Wextra -Werror

SRC =		parse.c \
			shift.c \
			valid.c \
			solve.c \
			map.c \
			main.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/

all: $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(SRC) -I $(HEAD) -L. libft/libft.a

clean:
		rm -rf $(OBJ)
		make -C $(LIBFT) clean

fclean:
		rm -rf $(NAME)
		make -C $(LIBFT) fclean
		
re: fclean all