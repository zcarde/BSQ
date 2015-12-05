# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/04 17:07:13 by zcarde            #+#    #+#              #
#    Updated: 2015/11/06 12:34:09 by zcarde           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= bsq


SRC			= bsq.c\
error.c\
ft_atoi.c\
ft_putchar.c\
ft_putnbr.c\
ft_putstr.c\
ft_strjoin.c\
ft_strlen.c\
ft_strsub.c\
map.c\
map_chars.c\
nb_lines.c\
print.c\
read.c\
square.c

OBJ			= $(SRC:.c=.o)

CC			= clang
CFLAGS		= -Wall -Werror -Wextra

INCLUDES	= -I includes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all