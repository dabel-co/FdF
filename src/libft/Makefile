# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 10:36:13 by dabel-co          #+#    #+#              #
#    Updated: 2021/09/03 11:53:10 by dabel-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra 
AR = ar rc

FILES = bzero \
		memcpy \
		memset \
		memccpy \
		memchr \
		memmove \
		memcmp \
		strlen \
		isalpha \
		isalnum \
		isdigit \
		isascii \
		isprint \
		toupper \
		tolower \
		strchr \
		strrchr \
		strncmp \
		strlcpy \
		strlcat \
		strnstr \
		atoi \
		calloc \
		strdup \
		substr \
		strjoin \
		strtrim \
		split \
		itoa \
		strmapi \
		putchar_fd \
		putstr_fd \
		putendl_fd \
		putnbr_fd \

BONUS = lstnew \
		lstadd_front \
		lstsize \
		lstlast \
		lstadd_back \
		lstdelone \
		lstclear \
		lstiter \
		lstmap \


C = $(addprefix ./ft_, $(addsuffix .c, $(FILES)))
O = $(addprefix ./ft_, $(addsuffix .o, $(FILES)))
Cbonus = $(addprefix ./ft_, $(addsuffix .c, $(BONUS)))
Obonus = $(addprefix ./ft_, $(addsuffix .o, $(BONUS)))

$(NAME) : $(O)
	@gcc $(FLAGS) -c $(C) && $(AR) $(NAME) $(O)
bonus : $(Obonus)
	@gcc $(FLAGS) -c $(C) $(Cbonus) && $(AR) $(NAME) $(O) $(Obonus)
clean:
	rm -f $(O) $(Obonus)
fclean: clean
	rm -f $(NAME)
all: $(NAME)

re: fclean all
