# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 19:37:00 by egomez-g          #+#    #+#              #
#    Updated: 2023/11/29 17:13:32 by egomez-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SOURCES =	so_long.c get_next_line.c get_next_line_utils.c so_long_utils.c \
			create_map.c check_map.c print_sprites.c move_char.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS := -Wall -Wextra -Werror -Imlx
REMOVE = rm -f
CC := cc

all: $(NAME)

$(NAME): $(OBJECTS) mlx/libmlx.a
	$(CC) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

mlx/libmlx.a:
	make -C mlx/

run:
	./so_long map1.ber

clean:
	$(REMOVE) $(OBJECTS)
	$(REMOVE) $(OBJECTS_BONUS)
	make -C mlx/ clean

fclean: clean
	$(REMOVE) $(NAME)
	$(REMOVE) $(NAME_BONUS)

re: fclean all
