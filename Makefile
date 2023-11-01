# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seblin <seblin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/10/31 22:39:03 by seblin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)
LIBFTDIR = ./libft
#LIBFTOPATH = $(wildcard libft/*.o)
.PHONY : all libft clean fclean re

all : libft test $(NAME)
	
libft : 
	$(MAKE) -C $(LIBFTDIR) onlyo
	
	
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

test :
	$(eval LIBFTOPATH = $(wildcard libft/*.o))

$(NAME) :: $(OBJECTS) $(LIBFTOPATH)
	ar rcs $@ $(LIBFTOPATH)

$(NAME) :: $(OBJECTS) $(LIBFTOPATH)
	ar rcs $@  $?
	
clean :
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	
re : fclean all