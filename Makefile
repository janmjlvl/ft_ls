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
SRCS = $(wildcard srcs/*.c)
CFLAGS = -Wall -Wextra -Werror
OBJS = $(patsubst srcs/%.c, objs/%.o, $(SRCS))
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT)
	gcc -o $@ $(CFLAGS) $(OBJS) $^

$(LIBFT) : $(OBJS)
	$(MAKE) -C libft

objs/%.o : srcs/%.c
	gcc -c $^ -o $@ $(CFLAGS) -I./libft/includes -I./includes

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)


re : fclean all

.PHONY: fclean clean
