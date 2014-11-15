/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:32:29 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 16:14:55 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((s1) && (s2))
	{
		dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (dest)
		{
			while (i < ft_strlen(s1))
			{
				dest[i] = s1[i];
				i++;
			}
			while (i < ft_strlen(s1) + ft_strlen(s2))
				dest[i++] = s2[j++];
			dest[i] = '\0';
			return (dest);
		}
	}
	return (0);
}
