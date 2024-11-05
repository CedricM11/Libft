# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmarti <cedmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 07:59:24 by cedmarti          #+#    #+#              #
#    Updated: 2024/11/05 13:51:10 by cedmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB =	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c		\
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c	\
		ft_memcmp.c ft_memmove.c ft_memset.c ft_strchr.c	\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c	\
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c	\
		ft_calloc.c ft_strdup.c	\

ADD =	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c	\
		ft_itoa.c 

SRCS = $(LIB) $(ADD)

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I ./

NAME = libft.a

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
