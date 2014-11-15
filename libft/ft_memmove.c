/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:31:42 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 16:17:22 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*pdst;
	const char	*psrc;
	char		*tmp;
	size_t		i;

	pdst = dst;
	psrc = src;
	tmp = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	i = 0;
	while (i < len)
	{
		tmp[i] = psrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		pdst[i] = tmp[i];
		i++;
	}
	return (pdst);
}
