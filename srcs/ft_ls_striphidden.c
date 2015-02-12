/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_striphidden.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 13:52:17 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 15:14:57 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_ls_stripdot(char **tab)
{
	int		i;
	int		j;
	char	**result;

	i = -1;
	j = 0;
	while (tab[++i])
		if (ft_strcmp(tab[i], ".") && ft_strcmp(tab[i], ".."))
			j++;
	result = (char**)malloc(sizeof(char*) * (j + 1));
	if (!result)
		exit(-1);
	i = -1;
	j = 0;
	while (tab[++i])
		if (ft_strcmp(tab[i], ".") && ft_strcmp(tab[i], ".."))
			result[j++] = tab[i];
	result[j] = NULL;
	return (result);
}

char		**ft_ls_striphidden(char **tab)
{
	int		i;
	int		j;
	char	**result;

	i = -1;
	j = 0;
	while (tab[++i])
		if (tab[i][0] != '.' || tab[i][1] == '/' || tab[i][1] == '\0')
			j++;
	result = (char**)malloc(sizeof(char*) * (j + 1));
	if (!result)
	{
		exit(-1);
	}
	i = -1;
	j = 0;
	while (tab[++i])
		if (tab[i][0] != '.' || tab[i][1] == '/' || tab[i][1] == '\0')
			result[j++] = tab[i];
	result[j] = NULL;
	return (result);
}
