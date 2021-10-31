# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 15:51:51 by dabel-co          #+#    #+#              #
#    Updated: 2021/10/11 13:24:30 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAGS = -Wall -Werror -Wextra -D BUFFER_SIZE=1000
CC = cc
LINK = -lmlx -framework OpenGL -framework AppKit
FILES =	fdf \
		count \
		utils \
		utils_2 \
		utils_3 \
		draw \

C = $(addprefix ./src/ft_, $(addsuffix .c, $(FILES)))
GNL = ./src/GNL/get_next_line.c ./src/GNL/get_next_line_utils.c

all: $(NAME)

$(NAME) :	check_libft
	@$(CC) $(FLAGS) $(LINK) $(C) $(GNL) ./src/libft/libft.a -o $(NAME)
check_libft :
	@make -C ./src/libft
clean:
	rm -f $(NAME)
fclean: clean
	make fclean -C ./src/libft
re: clean all

.PHONY : all clean fclean re check_libft
