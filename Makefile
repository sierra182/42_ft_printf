# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seblin <seblin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/10/29 09:26:28 by seblin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -WaLL -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
SOURCES = 

.PHONY : all clean fclean re

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $@ $^
	
clean :
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(NAME)

re : fclean all