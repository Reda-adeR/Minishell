# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-mham <rel-mham@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 17:55:26 by rel-mham          #+#    #+#              #
#    Updated: 2023/03/03 15:25:17 by rel-mham         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalnum.c \
		ft_isalpha.c \
			ft_isdigit.c \
				ft_isprint.c \
					ft_memchr.c \
						ft_memcmp.c \
							ft_strlen.c \
								ft_memset.c \
									ft_isascii.c \
										ft_bzero.c \
											free_me.c \
											ft_memcpy.c \
												ft_toupper.c \
													ft_tolower.c \
														ft_strchr.c \
															ft_strrchr.c \
																ft_strncmp.c \
																ft_strcmp.c \
															ft_strlcpy.c \
														ft_strnstr.c \
														ft_atoi.c \
													ft_calloc.c \
												ft_strdup.c \
											ft_strlcat.c \
										ft_substr.c \
									ft_strjoin.c \
								ft_itoa.c \
							ft_strmapi.c \
						ft_striteri.c \
					ft_putchar_fd.c \
				ft_putstr_fd.c \
			ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_split.c \
	ft_strtrim.c \
ft_memmove.c \
ft_split_qk.c


.SILENT:

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o:%.c
	gcc $(FLAGS) -c $<

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

re:fclean all
