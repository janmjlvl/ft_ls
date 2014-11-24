/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 18:43:05 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/24 15:14:41 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_ls.h"

char		**sort_last_acces(char *dir, char **tab)
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
		lstat(ft_make_path(dir, tab[i]), &s_stat);
		tmp[i] = s_stat.st_atime;
		i++;
	}
	int_quick_sort(tab, tmp, 0, i - 1);
	sortlg_after(tab, tmp);
	return (tab);
}

char			**sortsize_tab(char *dir, char **tab)
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
		lstat(ft_make_path(dir, tab[i]), &s_stat);
		tmp[i] = s_stat.st_size;
		i++;
	}
	int_quick_sort(tab, tmp, 0, i - 1);
	sortlg_after(tab, tmp);
	return (tab);
}

char			**sorttime_tab(char *dir, char **tab)
{
	struct stat		s_stat;
	int				i;
	int				*tmp;

	i = 0;
	while (tab[i] != NULL)
		i++;
	tmp = (int*)malloc(sizeof(int) * i);
	if (!tmp)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		lstat(ft_make_path(dir, tab[i]), &s_stat);
		tmp[i] = s_stat.st_mtime;
		i++;
	}
	int_quick_sort(tab, tmp, 0, i - 1);
	sortlg_after(tab, tmp);
	return (tab);
}
