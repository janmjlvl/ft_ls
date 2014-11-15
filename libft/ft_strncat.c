/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:04:58 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 16:33:44 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (*s2 && j < n)
	{
		s1[i] = *s2;
		++s2;
		++i;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
