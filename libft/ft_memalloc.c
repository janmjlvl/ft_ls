/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:10:25 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 17:16:33 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (size == 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (size));
	if (dest)
	{
		while (i < size)
		{
			dest[i] = 0;
			i++;
		}
		return (dest);
	}
	else
		return (0);
}
