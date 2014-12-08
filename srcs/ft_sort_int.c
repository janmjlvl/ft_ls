/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 19:06:16 by jabadie           #+#    #+#             */
/*   Updated: 2014/12/08 14:37:13 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include <stdio.h>

static int		split_sort(char **tab, long int *tmp, int start, int end)
{
	int pivot;
	int left;
	int right;

	pivot = end;
	left = start - 1;
	right = end;
	while (left <= right)
	{
		left++;
		right--;
		while (left < end && tmp[left] > tmp[pivot])
			left++;
		while (right >= start && tmp[right] < tmp[pivot])
			right--;
		if (left < right)
			swap(tab, tmp, left, right);
	}
	swap(tab, tmp, pivot, left);
	return (left);
}

void	int_quick_sort(char **tab, long int *tmp, int start, int end)
{
	int key;

	if (start < end)
	{
		key = split_sort(tab, tmp, start, end);
		int_quick_sort(tab, tmp, start, key - 1);
		int_quick_sort(tab, tmp, key + 1, end);
	}
}

void	sortlg_after(char **tab, long int *tmp)
{
	int	i;
	int	start;
	int	len;
	int	first;

	i = 1;
	while (tab[i] != NULL)
	{
		len = 0;
		first = 1;
		while (tmp[i] == tmp[i - 1] && tab[i] != NULL)
		{
			if (first == 1)
				start = i - 1;
			len++;
			first = 0;
			i++;
		}
		if (first == 0)
			all_quick_sort(tab, start, start + len, simul_log(len));
		if (tab[i] == NULL)
			break;
		i++;
	}
}
