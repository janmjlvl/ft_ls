/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorttime_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlevieil <jlevieil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:28:38 by jlevieil          #+#    #+#             */
/*   Updated: 2014/11/15 15:59:25 by jlevieil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

void		swap(int *tab, int p1, int p2)
{
	int		tmp;

	tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
}

void		swap_char(char **tab, int p1, int p2)
{
	char	*tmp;

	tmp = tab[p1];
	tab[p1] = tab[p2];
	tab[p2] = tmp;
}

char		**sorttime_tab(char **tab)
{
	struct stat		s_stat;
	int				i;
	int				*tmp;
	int				sort;

	sort = 0;
	i = 0;
	while (tab[i] != '\0')
		i++;
	tmp = (int*)malloc(sizeof(int) * i + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tab[i] != '\0')
	{
		stat(tab[i], &s_stat);
		tmp[i] = s_stat.st_mtime;
		i++;
	}
	tmp[i] = -2;
	while (sort != 1)
	{
		sort = 1;
		i = 0;
		while (tmp[i + 1] != -2)
		{
			if (tmp[i] < tmp[i + 1])
			{
				swap(tmp, i, i + 1);
				swap_char(tab, i, i + 1);
				sort = 0;
			}
			i++;
		}
	}
	return (tab);
}
