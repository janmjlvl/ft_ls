/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:38:21 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 14:27:25 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dest;
	int		i;

	i = 0;
	if ((s) && (f))
	{
		dest = (char *)malloc(sizeof(*s) * ft_strlen((s) + 1));
		if (dest)
		{
			while (s[i] != '\0')
			{
				dest[i] = f(i, s[i]);
				i++;
			}
			dest[i] = '\0';
			return (dest);
		}
	}
	return (0);
}
