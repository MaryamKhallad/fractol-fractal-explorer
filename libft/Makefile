# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkhallad <mkhallad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/04 15:55:47 by mkhallad          #+#    #+#              #
#    Updated: 2025/09/01 12:31:16 by mkhallad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
       ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	   ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
	   ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	   ft_strrchr.c ft_strnstr.c ft_atoi.c \
	   ft_substr.c ft_split.c ft_strtrim.c ft_strmapi.c \
	   ft_striteri.c ft_strjoin.c ft_itoa.c ft_putchar_fd.c \
	   ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

BONUS_SRC = ft_lstnew_bonus.c \
			ft_lstadd_back_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_front_bonus.c ft_lstsize_bonus.c \

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	ar -rcs $(NAME) $(OBJ)

bonus: ${OBJ} ${BONUS_OBJ}
	ar -rcs ${NAME} ${OBJ} ${BONUS_OBJ}

clean:
	rm -f ${OBJ} ${BONUS_OBJ}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
