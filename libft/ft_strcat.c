/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:18:47 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/07 16:33:26 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;

	i = ft_strlen(s1);
	while (*s2)
	{
		s1[i] = *s2;
		++s2;
		++i;
	}
	s1[i] = '\0';
	return (s1);
}
