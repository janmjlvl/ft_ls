/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 15:53:04 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 16:13:02 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_delim(char c, char c2)
{
	if (c == c2)
		return (1);
	return (0);
}

static int		ft_find_nb_words(char *str, char c)
{
	int			result;

	result = 0;
	while (*str)
	{
		while (ft_delim(*str, c))
			str++;
		if (*str)
			result++;
		while (!ft_delim(*str, c) && *str)
			str++;
	}
	return (result);
}

static char		**ft_split_func(char *str, int nb_words, int *i, char c)
{
	int			i3;
	int			word_size;
	char		**result;

	if (!(result = malloc(sizeof(char*) * (nb_words + 1))))
		return (NULL);
	while (i[0] < nb_words)
	{
		while (ft_delim(str[i[1]], c))
			i[1]++;
		word_size = 0;
		while (!ft_delim(str[i[1] + word_size], c) && str[i[1] + word_size])
			word_size++;
		if (!(result[i[0]] = malloc(sizeof(char) * (word_size + 1))))
			return (NULL);
		i3 = -1;
		while (++i3 < word_size)
			result[i[0]][i3] = str[i[1] + i3];
		result[i[0]][i3] = '\0';
		i[1] += word_size;
		i[0]++;
	}
	result[i[0]] = (NULL);
	return (result);
}

char			**ft_strsplit(char const *s, char c)
{
	int			i[2];

	if ((s) && (c))
	{
		i[0] = 0;
		i[1] = 0;
		return (ft_split_func((char*)s, ft_find_nb_words((char*)s, c), i, c));
	}
	return (NULL);
}
