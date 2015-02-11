/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_striphidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 13:52:17 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/11 15:01:11 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_ls_stripdot(char **tab)
{
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], ".") && ft_strcmp(tab[i], ".."))
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
		if (ft_strcmp(tab[i], ".") && ft_strcmp(tab[i], ".."))
		{
			result[j] = tab[i];
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);

}

char **ft_ls_striphidden(char **tab)
{
	int i;
	int j;
	char **result;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (tab[i][0] != '.' || tab[i][1] == '/')
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
		if (tab[i][0] != '.' || tab[i][1] == '/')
		{
			result[j] = tab[i];
			j++;
		}
		i++;
	}
	result[j] = NULL;
	return (result);
}
