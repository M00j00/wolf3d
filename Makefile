# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/28 23:00:04 by amanchon          #+#    #+#              #
#    Updated: 2016/11/21 17:39:57 by amanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d
FLAGS	=	-Wall -Wextra
LINK	=	-L./includes -lft -lmlx -framework OpenGL -framework AppKit
CC		=	gcc
SRC		=	main.c image.c texture.c raycaster.c hooks.c map.c free.c
OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):
	$(MAKE) -C libft
	@mkdir includes
	@cp libft/libft.a ./includes/
	@cp libft/libft.h ./includes/
	@cp /usr/local/lib/libmlx.a ./includes/
	@cp /usr/local/include/mlx.h ./includes/
	$(CC) $(FLAGS) $(LIB) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	$(MAKE) -C libft clean
	@rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	@rm -rf ./includes/
	rm -f $(NAME)

re: fclean all
