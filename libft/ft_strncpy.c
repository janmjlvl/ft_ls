/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:00:58 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 16:33:04 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (ft_strlen(src) >= n)
	{
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (i <= n)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((char*)dst);
}
