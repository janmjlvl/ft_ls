/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:15:53 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 16:32:28 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*dest;

	dest = (char *)malloc(sizeof(s1) * (ft_strlen(s1) + 1));
	if (dest)
		return (ft_strcpy(dest, s1));
	else
		return (0);
}
