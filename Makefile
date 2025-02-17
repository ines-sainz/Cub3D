# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isainz-r <isainz-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 10:06:01 by isainz-r          #+#    #+#              #
#    Updated: 2025/02/12 10:06:03 by isainz-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3D

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3

PARSE_DIR		=	src/parse
SRC				=	src/main.c \
					$(PARSE_DIR)/parse.c \
					$(PARSE_DIR)/cub_line_break.c \
					$(PARSE_DIR)/colors_textures.c \
					$(PARSE_DIR)/check_map.c

OBJ				=	$(SRC:.c=.o)

LIBFT_DIR	=	include/libft
LIBFT		=	$(LIBFT_DIR)/libft.a

GNL_DIR		=	include/get_next_line
GNL			=	$(GNL_DIR)/gnl.a

all: $(NAME)

r: fclean all
	./$(NAME) maps/valid/map.cub

run: ./cub3D

$(LIBFT):
	$(MAKE) -s -C $(LIBFT_DIR)

$(GNL):
	$(MAKE) -s -C $(GNL_DIR)

$(NAME): $(LIBFT) $(GNL) $(OBJ)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(GNL_DIR) $(OBJ) $(LIBFT) $(GNL) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -s -C $(LIBFT_DIR) clean
	$(MAKE) -s -C $(GNL_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -s -C $(LIBFT_DIR) fclean
	$(MAKE) -s -C $(GNL_DIR) fclean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re
