/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:34:04 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 17:18:25 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	else
	{
		while (i <= ft_strlen(s1) && s1[i] != '\0')
		{
			while (s1[i + j] == s2[j] && j < ft_strlen(s2))
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
