# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asubrama <asubrama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 15:48:07 by asubrama          #+#    #+#              #
#    Updated: 2019/09/07 20:37:46 by asubrama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
# name of library when run 

CFLAGS = -Wall -Wextra -Werror -c 
# flags to compile with header in local directory 

SRC	=	ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_strcpy.c \
		ft_strdup.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_isspace.c \
		ft_atoi.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlcat.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_ispos.c \
		ft_isneg.c \
		ft_wordcount.c \
		ft_strndup.c


		
# source files 

OBJ = $(SRC:.c=.o)
# .c becomes .o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
# ar updates and rc replaces library file if any changes have been made

clean:
	rm -f $(OBJ)
# cleans object files in directory

fclean: clean
	rm -f $(NAME)
#empties library as well
re: fclean all

.PHONY: clean fclean all re		