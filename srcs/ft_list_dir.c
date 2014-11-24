/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:35:05 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/24 16:23:03 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

char		**ft_list_dir(char *dirname)
{
	DIR		*dirp;
	struct dirent* dp;
	int		file_nbr;
	char	**result;
	/*char *ptr;*/
	int i;

	dirp = opendir(dirname);
	/*ft_putstr("opendir(\"");
	ft_putstr(dirname);
	ft_putstr("\") -> ");
	ft_putnbr((size_t)dirp);
	ft_putchar('\n');*/
	if (dirp == NULL)
	{
		/*ft_putstr_fd("ls: ", 2);
		if ((ptr = ft_strrchr(dirname, '/')) != NULL)
			ft_putstr_fd(ptr + 1, 2);
		else
			ft_putstr_fd(dirname, 2);
		ft_putendl_fd(": Not a directory", 2);*/
		perror(NULL);
		exit(-1);
	}
	file_nbr = 0;
	while((dp = readdir(dirp)) != NULL)
		file_nbr++;
	result = (char**)malloc(sizeof(char*) * (file_nbr + 1));
	if (!result)
		exit(-1);
	closedir(dirp);
	dirp = opendir(dirname);
	i = 0;
	while((dp = readdir(dirp)) != NULL)
	{
		result[i] = ft_strdup(dp->d_name);
		i++;
	}
	closedir(dirp);
	result[i] = NULL;
	return (result);
}

