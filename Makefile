# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seblin <seblin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 08:16:28 by seblin            #+#    #+#              #
#    Updated: 2023/10/29 11:36:10 by seblin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -WaLL -Wextra -Werror
HEADER = ft_printf.h
NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)
LIBFTDIR = ./libft
LIBFTPATH = ./libft/libft.a

.PHONY : all clean fclean re

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) $< -c -o $@

libft : 
	$(MAKE) -C $(LIBFTDIR)

all : libft $(NAME)

$(NAME) : $(OBJECTS) $(LIBFTPATH)
	ar rcs $@ $^
	
clean :
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	
re : fclean all