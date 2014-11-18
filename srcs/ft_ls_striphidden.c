/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_striphidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 13:52:17 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/18 10:17:36 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char **ft_ls_striphidden(char **tab)
{
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i][0] != '.')
		{
			j++;
		}
		i++;
	}
	result = (char**)malloc(sizeof(char*) * (j + 1));
	if (!result)
	{
		exit(-1);
	}
	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i][0] != '.')
		{
			result[j] = tab[i];
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
