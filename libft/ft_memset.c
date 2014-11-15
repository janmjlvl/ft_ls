/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:11:39 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 16:25:08 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*pb;

	pb = b;
	i = 0;
	while (i < len)
	{
		pb[i] = (unsigned char)c;
		i++;
	}
	return (pb);
}
