/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_sort_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 16:36:38 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/12 16:04:07 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "../libft/includes/libft.h"

void	rev_insertion_sort(char **tab, int first, int last)
{
	int		i;
	int		i2;
	char	*tmp;

	i = first + 1;
	while (i <= last)
	{
		i2 = i;
		tmp = tab[i];
		while (i2 - 1 >= first && ft_strcmp(tmp, tab[i2 - 1]) > 0)
		{
			tab[i2] = tab[i2 - 1];
			i2--;
		}
		tab[i2] = tmp;
		i++;
	}
}

void	rev_create_stack(char **tab, int noeud, int size)
{
	char	*tmp;
	int		j;

	j = (noeud * 2) + 1;
	while (j < size)
	{
		if (j + 1 < size && ft_strcmp(tab[j], tab[j + 1]) > 0)
			j++;
		if (ft_strcmp(tab[noeud], tab[j]) > 0)
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

void	rev_heap_sort(char **tab, int first, int size)
{
	int		i;
	char	*tmp;

	i = (size / 2) - 1;
	while (i >= first)
	{
		rev_create_stack(tab, i, size);
		i--;
	}
	i = size - 1;
	while (i > first)
	{
		if (ft_strcmp(tab[i], tab[first]) < 0)
		{
			tmp = tab[i];
			tab[i] = tab[first];
			tab[first] = tmp;
		}
		rev_create_stack(tab, first, i);
		i--;
	}
}

int		rev_split_sort(char **tab, int first, int last)
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
		while (i < last && ft_strcmp(tab[i], tab[key]) > 0)
			i++;
		while (j >= first && ft_strcmp(tab[j], tab[key]) < 0)
			j--;
		if (i < j)
			ft_tabswap(tab + i, tab + j);
	}
	ft_tabswap(tab + key, tab + i);
	return (i);
}

void	rev_quick_sort(char **tab, int first, int last, int depth)
{
	int	key;

	if (first < last)
	{
		if (last - first <= 15)
			rev_insertion_sort(tab, first, last);
		else
		{
			key = rev_split_sort(tab, first, last);
			rev_quick_sort(tab, first, key - 1, depth - 1);
			rev_quick_sort(tab, key + 1, last, depth - 1);
		}
	}
}
