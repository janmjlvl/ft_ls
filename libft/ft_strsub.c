/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:49:51 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 14:31:30 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (s)
	{
		dest = (char *)malloc(sizeof(s) * (len + 1));
		if (dest)
		{
			while (i < len)
			{
				dest[i] = s[start];
				i++;
				start++;
			}
			dest[i] = '\0';
			return (dest);
		}
	}
	return (0);
}
