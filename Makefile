#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 10:03:13 by vle-guen          #+#    #+#              #
#    Updated: 2014/11/14 11:02:13 by vle-guen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_ls
SRCS = main.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(patsubst %.c, %.o, $(SRCS))
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	gcc -o $@ $(CFLAGS) $^

$(LIBFT) :
	$(MAKE) -C libft

%.o : %.c
	gcc -c $^ $(CFLAGS) -I ./libft/includes

fclean :
	rm -rf $(NAME)

clean :
	rm -rf $(OBJS)

re :
	fclean all