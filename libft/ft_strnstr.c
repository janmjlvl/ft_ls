/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:46:34 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 17:46:22 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	else
	{
		while (i < n && s1[i] != '\0')
		{
			while (s1[i + j] == s2[j] && j < ft_strlen(s2) && i + j < n)
				j++;
			if (j == ft_strlen(s2))
				return ((char*)&s1[i]);
			else
				j = 0;
			i++;
		}
	}
	return (0);
}
