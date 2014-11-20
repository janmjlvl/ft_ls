/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttime_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlevieil <jlevieil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:28:38 by jlevieil          #+#    #+#             */
/*   Updated: 2014/11/20 15:37:50 by jabadie          ###   ########.fr       */
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
	left = start;
	right = end + 1;
	if (start >= end)
		return ;
	while (1)
	{
		right--;
		while (tmp[right] < pivot)
			right--;
		left++;
		while (tmp[left] > pivot)
			left++;
		if (left < right)
			swap(tab, tmp, left, right);
		else
			break ;
	}
	quick_sort(tab, tmp, start, right);
	quick_sort(tab, tmp, right + 1, end);
}

void			sortlg_after(char **tab, char *tmp)
{
	int	i;
	int	start;
	int	len;
	int	first;

	i = 1
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
			quick_sort(tab, start, start + len, simul_log(len));
			i++;
		}
		if (tab[i] == NULL)
			break;
		i++;
	}
}

char			**sorttime_tab(char *dir, char **tab)
{
	struct stat		s_stat;
	int				i;
	int				*tmp;

	i = 0;
	while (tab[i] != NULL)
		i++;
	tmp = (int*)malloc(sizeof(int) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		stat(ft_make_path(dir, tab[i]), &s_stat);
		tmp[i] = s_stat.st_mtime;
		i++;
	}
	quick_sort(tab, tmp, 0, i - 1);
	sortlg_after(tab, tmp);
	return (tab);
}
