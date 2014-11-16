#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 10:03:13 by vle-guen          #+#    #+#              #
#    Updated: 2014/11/16 11:49:08 by nmeier           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
SRCS = $(wildcard *.c)
CFLAGS = -Wall -Wextra -Werror
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	gcc -o $@ $(CFLAGS) $^

$(LIBFT) :
	$(MAKE) -C libft

%.o : %.c
	gcc -c $^ $(CFLAGS) -I ./libft -I .

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS)

re : fclean all

.PHONY: fclean clean
