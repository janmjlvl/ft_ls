/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:56:33 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 17:12:39 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char				*ft_strtrim(char const *s)
{
	char			*dest;
	size_t			i;
	int				j;

	if (s)
	{
		i = 0;
		j = ft_strlen(s) - 1;
		while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		if (i == ft_strlen(s))
			return (ft_strnew(0));
		while ((j > 0) && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
			j--;
		dest = ft_strsub(s, i, j - i + 1);
		return (dest);
	}
	return (0);
}
