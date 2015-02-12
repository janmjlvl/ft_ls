/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:35:05 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 14:51:17 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

static int		check_dirp(DIR *dirp, char *dirname)
{
	char			*ptr;

	if (dirp != NULL)
		return (1);
	ft_putstr_fd("ls: ", 2);
	if ((ptr = ft_strrchr(dirname, '/')) != NULL)
		ft_putstr_fd(ptr + 1, 2);
	else
		ft_putstr_fd(dirname, 2);
	ft_putstr(": ");
	perror(NULL);
	return (0);
}

char			**ft_list_dir(char *dirname)
{
	DIR				*dirp;
	struct dirent	*dp;
	int				file_nbr;
	char			**result;
	int				i;

	dirp = opendir(dirname);
	if (!check_dirp(dirp, dirname))
		return (NULL);
	file_nbr = 0;
	while ((dp = readdir(dirp)) != NULL)
		file_nbr++;
	if (!(result = (char**)malloc(sizeof(char*) * (file_nbr + 1))))
		exit(-1);
	closedir(dirp);
	dirp = opendir(dirname);
	i = 0;
	while ((dp = readdir(dirp)) != NULL)
		result[i++] = ft_strdup(dp->d_name);
	closedir(dirp);
	result[i] = NULL;
	return (result);
}
