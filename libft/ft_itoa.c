/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:45:22 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/08 12:52:55 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

static int	ft_find_length(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strcpy(ft_strnew(11), "-2147483648"));
	i = ft_find_length(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str)
	{
		str[i + 1] = '\0';
		if (n < 0)
		{
			n = -n;
			str[0] = '-';
		}
		while (n > 9)
		{
			str[i--] = (n % 10) + 48;
			n = n / 10;
		}
		str[i] = n + 48;
		return (str);
	}
	else
		return (0);
}
