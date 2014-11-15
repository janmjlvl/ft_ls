/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:03:27 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 13:43:23 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void			*ft_memchr(const void *s, int c, size_t n)
{
	char		*ps;
	size_t		i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char*)s)[i])
		{
			ps = &((char*)s)[i];
			return ((void*)ps);
		}
		i++;
	}
	return (0);
}
