/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:25:40 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 16:13:56 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*dest;
	int		i;

	i = 0;
	if ((s) && (f))
	{
		dest = (char *)malloc(sizeof(s) * ft_strlen((s) + 1));
		if (dest)
		{
			while (s[i] != '\0')
			{
				dest[i] = f(s[i]);
				i++;
			}
			dest[i] = '\0';
			return (dest);
		}
	}
	return (0);
}
