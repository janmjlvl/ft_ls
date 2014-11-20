/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_sort_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 18:34:15 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/20 19:14:18 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

char		**r_sort_last_acces(char *dir, char **tab)
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
		tmp[i] = s_stat.st_atime;
		i++;
	}
	r_int_quick_sort(tab, tmp, 0, i - 1);
	//r_sortlg_after(tab, tmp);
	return (tab);
}

char			**r_sortsize_tab(char *dir, char **tab)
{
	struct stat		s_stat;
	int				i;
	int				*tmp;

	i = 0;
	while (tab[i] != '\0')
		i++;
	tmp = (int*)malloc(sizeof(int) * i);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tab[i] != '\0')
	{
		stat(ft_make_path(dir, tab[i]), &s_stat);
		tmp[i] = s_stat.st_size;
		i++;
	}
	r_int_quick_sort(tab, tmp, 0, i - 1);
	r_sortlg_after(tab, tmp);
	return (tab);
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
	r_int_quick_sort(tab, tmp, 0, i - 1);
	r_sortlg_after(tab, tmp);
	return (tab);
}
