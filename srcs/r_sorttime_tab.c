/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_sorttime_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlevieil <jlevieil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/18 14:55:22 by jlevieil          #+#    #+#             */
/*   Updated: 2014/11/20 14:18:48 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

static void		swap(char **tab, int *tmp, int i, int j)
{
	int		i_tmp;
	char	*tab_tmp;

	i_tmp = tmp[i];
	tab_tmp = tab[i];
	tmp[i] = tmp[j];
	tab[i] = tab[j];
	tmp[j] = i_tmp;
	tab[j] = tab_tmp;
}

static void		quick_sort(char **tab, int *tmp, int start, int end)
{
	int pivot;
	int left;
	int right;

	pivot = tmp[start];
	left = start - 1;
	right = end + 1;
	if (start >= end)
		return ;
	while (1)
	{
		right--;
		while (tmp[right] > pivot)
			right--;
		left++;
		while (tmp[left] < pivot)
			left++;
		if (left < right)
			swap(tab, tmp, left, right);
		else
			break ;
	}
	quick_sort(tab, tmp, start, right);
	quick_sort(tab, tmp, right + 1, end);
}

char			**r_sorttime_tab(char *dir, char **tab)
{
	struct stat		s_stat;
	int				i;
	int				*tmp;

	i = 0;
	while (tab[i] != '\0')
		i++;
	tmp = (int*)malloc(sizeof(int) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tab[i] != '\0')
	{
		stat(ft_make_path(dir, tab[i]), &s_stat);
		tmp[i] = s_stat.st_mtime;
		i++;
	}
	quick_sort(tab, tmp, 0, i - 1);
	return (tab);
}
