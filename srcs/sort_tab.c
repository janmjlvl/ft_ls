/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:18:42 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/23 14:47:25 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	insertion_sort(char **tab, int first, int last)
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

static void	create_stack(char **tab, int noeud, int size)
{
	char	*tmp;
	int		j;

	j = (noeud * 2) + 1;
	while (j < size)
	{
		if (j + 1 < size && ft_strcmp(tab[j], tab[j + 1]) < 0)
			j++;
		if (ft_strcmp(tab[noeud], tab[j]) < 0)
		{
			tmp = tab[noeud];
			tab[noeud] = tab[j];
			tab[j] = tmp;
			noeud = j;
			j = (noeud * 2) + 1;
		}
		else
			break ;
	}
}

static void	heap_sort(char **tab, int first, int size)
{
	int		i;
	char	*tmp;

	i = (size / 2) - 1;
	while (i >= first)
	{
		create_stack(tab, i, size);
		i--;
	}
	i = size - 1;
	while (i > first)
	{
		tmp = tab[i];
		tab[i] = tab[first];
		tab[first] = tmp;
		create_stack(tab, first, i);
		i--;
	}
}

static int		split_sort(char **tab, int first, int last)
{
	int		i;
	int		j;
	int		key;
	char	*tmp;

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
		{
			tmp = tab[i];
			tab[i] = tab[j];
			tab[j] = tmp;
		}
	}
	tmp = tab[key];
	tab[key] = tab[i];
	tab[i] = tmp;
	return (i);
}

void	all_quick_sort(char **tab, int first, int last, int depth)
{
	int	key;

	if (first < last)
	{
		if (depth == 0)
			heap_sort(tab, first, last + 1);
		else if (last - first <= 15)
			insertion_sort(tab, first, last);
		else
		{
			key = split_sort(tab, first, last);
			all_quick_sort(tab, first, key - 1, depth - 1);
			all_quick_sort(tab, key + 1, last, depth - 1);
		}
	}
}

void	sortlg_tab(char **tab)
{
	int len;

	len = ft_ptrlen(tab);
	insertion_sort(tab, 0, len - 1);
	/*all_quick_sort(tab, 0, len - 1, simul_log(len));*/
}

void	revsortlg_tab(char **tab)
{
	int len;

	len = ft_ptrlen(tab);
	rev_insertion_sort(tab, 0, len - 1);
	/*rev_quick_sort(tab, 0, len - 1, simul_log(len));*/
}

