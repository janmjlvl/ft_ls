/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:18:42 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/12 16:04:11 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void			insertion_sort(char **tab, int first, int last)
{
	int		i;
	int		i2;
	char	*tmp;

	i = first + 1;
	while (i <= last)
	{
		i2 = i;
		tmp = tab[i];
		while (i2 - 1 >= first && ft_strcmp(tmp, tab[i2 - 1]) < 0)
		{
			tab[i2] = tab[i2 - 1];
			i2--;
		}
		tab[i2] = tmp;
		i++;
	}
}

static int		split_sort(char **tab, int first, int last)
{
	int		i;
	int		j;
	int		key;

	key = last;
	i = first - 1;
	j = last;
	while (i <= j)
	{
		i++;
		j--;
		while (i < last && ft_strcmp(tab[i], tab[key]) < 0)
			i++;
		while (j >= first && ft_strcmp(tab[j], tab[key]) > 0)
			j--;
		if (i < j)
			ft_tabswap(tab + i, tab + j);
	}
	ft_tabswap(tab + key, tab + i);
	return (i);
}

void			all_quick_sort(char **tab, int first, int last, int depth)
{
	int	key;

	if (first < last)
	{
		if (last - first <= 15)
			insertion_sort(tab, first, last);
		else
		{
			key = split_sort(tab, first, last);
			all_quick_sort(tab, first, key - 1, depth - 1);
			all_quick_sort(tab, key + 1, last, depth - 1);
		}
	}
}

void			sortlg_tab(char **tab)
{
	int len;

	len = ft_ptrlen(tab);
	all_quick_sort(tab, 0, len - 1, simul_log(len));
}

void			revsortlg_tab(char **tab)
{
	int len;

	len = ft_ptrlen(tab);
	rev_quick_sort(tab, 0, len - 1, simul_log(len));
}
