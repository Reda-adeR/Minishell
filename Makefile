# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 21:54:49 by rel-mham          #+#    #+#              #
#    Updated: 2023/03/09 15:04:22 by rel-mham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC =	main.c \
		lexer.c \
		lexer_utils.c \
		stack_func.c \
		syntax_error.c \
		env_maker.c \
		fill_list.c

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	make -C ./libft
	cc $(CFLAGS) -lreadline -o  $(NAME) $(OBJS) ./libft/libft.a

clean:
	make clean -C ./libft
	rm -f $(OBJS)

fclean:clean
	make fclean -C ./libft
	rm -f $(NAME)

re:fclean all
