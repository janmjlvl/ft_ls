/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:18:42 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/16 12:44:30 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	sortlg_tab(char	**tab)
{
	int		min;
	int		i;
	int		i2;
	int		len;
	char	*tmp;

	len = ft_ptrlen(tab);
	i = 0;
	min = 0;
	while (i < len)
	{
		i2 = i;
		while (i2 < len)
		{
			if (ft_strcmp(tab[i2], tab[min]) < 0)
					min = i2;
			i2++;
		}
		tmp = tab[i];
		tab[i] = tab[min];
		tab[min] = tmp;
		i++;
		min = i;
	}
}

void	revsortlg_tab(char **tab)
{
	int		max;
	int		i;
	int		i2;
	int		len;
	char	*tmp;

	len = ft_ptrlen(tab);
	i = 0;
	max = 0;
	while (i < len)
	{
		i2 = i;
		while (i2 < len)
		{
			if (ft_strcmp(tab[i2], tab[max]) > 0)
					max = i2;
			i2++;
		}
		tmp = tab[i];
		tab[i] = tab[max];
		tab[max] = tmp;
		i++;
		max = i;
	}
}