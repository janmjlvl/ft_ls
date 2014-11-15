/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:35:05 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/15 16:09:59 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <dirent.h>

char		**ft_list_dir(char *dirname)
{
	DIR		*dirp;
	struct dirent* dp;
	int		file_nbr;
	char	**result;

	dirp = opendir(dirname);
	if (dirp == NULL)
	{
		ft_putstr("ERROR: failed to open dir: ");
		ft_putendl(dirname);
		exit(-1);
	}
	file_nbr = 0;
	while((dp = readdir(dirp)) != NULL)
		file_nbr++;
	result = (char**)malloc(sizeof(char*) * (file_nbr + 1));
	if (!result)
		exit(-1);
	rewinddir(dirp);
	while((dp = readdir(dirp)) != NULL)
	{
		*result = dp->d_name;
		result++;
	}
	*result = NULL;
	return (result - file_nbr);
}

