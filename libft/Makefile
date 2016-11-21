# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/27 16:29:55 by amanchon          #+#    #+#              #
#    Updated: 2016/11/06 22:36:57 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
FLAGS	=	-Wall -Wextra -Werror
CC		=	gcc
SRC		=	ft_bzero.c		\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memalloc.c	\
			ft_memccpy.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memdel.c		\
			ft_memmove.c	\
			ft_memset.c		\
			ft_strcat.c		\
			ft_strchr.c		\
			ft_strclr.c		\
			ft_strcmp.c		\
			ft_strcpy.c		\
			ft_strdel.c		\
			ft_strdup.c		\
			ft_strequ.c		\
			ft_striter.c	\
			ft_striteri.c	\
			ft_strjoin.c	\
			ft_strlcat.c	\
			ft_strlen.c		\
			ft_strmap.c		\
			ft_strmapi.c	\
			ft_strncmp.c	\
			ft_strncat.c	\
			ft_strnequ.c	\
			ft_strncpy.c	\
			ft_strnstr.c	\
			ft_strnew.c		\
			ft_strrchr.c	\
			ft_strstr.c		\
			ft_strsub.c		\
			ft_strtrim.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_isspace.c	\
			ft_strsplit.c	\
			ft_itoa.c		\
			ft_atoi.c		\
			ft_abs.c		\
			ft_putchar.c	\
			ft_putchar_fd.c	\
			ft_putendl.c	\
			ft_putendl_fd.c	\
			ft_putnbr.c		\
			ft_putnbr_fd.c	\
			ft_putstr.c		\
			ft_putstr_fd.c	\
			ft_lstnew.c		\
			ft_lstdelone.c	\
			ft_lstdel.c		\
			ft_lstadd.c		\
			ft_lstiter.c	\
			ft_lstmap.c		

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $^ -o $@

clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
