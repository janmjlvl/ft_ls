/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:18:42 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/18 15:54:38 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	insertion_sort(char **tab, int first, int last)
{
	int		i;
	int		i2;
	char	*tmp;

	i = first;
	while (i <= last)
	{
		i2 = i;
		tmp = tab[i];
		while (i2 - 1 >= 0 && ft_strcmp(tmp, tab[i2 - 1]) < 0)
		{
			tab[i2] = tab[i2 - 1];
			i2--;
		}
		tab[i2] = tmp;
		i++;
	}
}

void	revinsertion_sort(char **tab, int first, int last)
{
	int		i;
	int		i2;
	char	*tmp;

	i = first;
	while (i <= last)
	{
		i2 = i;
		tmp = tab[i];
		while (i2 - 1 >= 0 && ft_strcmp(tmp, tab[i2 - 1]) > 0)
		{
			tab[i2] = tab[i2 - 1];
			i2--;
		}
		tab[i2] = tmp;
		i++;
	}
}

void	create_tas(char **tab, int noeud, int size)
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

void	heap_sort(char **tab, int first, int size)
{
	int		i;
	char	*tmp;

	i = (size / 2) - 1;
	while (i >= first)
	{
		create_tas(tab, i, size);
		i--;
	}
	i = size - 1;
	while (i > 0)
	{
		tmp = tab[i];
		tab[i] = tab[0];
		tab[0] = tmp;
		create_tas(tab, 0, i);
		i--;
	}
}

int		partition(char **tab, int first, int last)
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
	return (key);
}

void	quick_sort(char **tab, int first, int last)
{
	int	key;

	if (first < last)
	{
		if (last - first <= 15)
			insertion_sort(tab, first, last);
		else
		{
			key = partition(tab, first, last);
			quick_sort(tab, first, key - 1);
			quick_sort(tab, key + 1, last);
		}
	}
}

void	sortlg_tab(char **tab)
{
	int len;

	len = ft_ptrlen(tab);
	quick_sort(tab, 0, len - 1);
}

void	revsortlg_tab(char **tab)
{
	int len;

	len = ft_ptrlen(tab);
	revinsertion_sort(tab, 0, len - 1);
}

