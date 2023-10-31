# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svidot <svidot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/10/31 12:11:28 by svidot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)
LIBFTDIR = ./libft
LIBFTOPATH1 = $(wildcard libft/*.o)
LIBFTOPATH = libft/*.o

.PHONY : all libft clean fclean re

all : libft $(NAME)

libft : 
	$(MAKE) -C $(LIBFTDIR) onlyo
	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

$(NAME) : $(OBJECTS) $(LIBFTOPATH1)
	ar rcs $@ $? 
	
clean :
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	
re : fclean all