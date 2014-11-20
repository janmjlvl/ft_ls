/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitnames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:19:24 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/20 15:59:45 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include <sys/stat.h>
#include <stdlib.h>

int		*def_items(char **tab, int *dex)
{
	int			status;
	struct stat	st_buf;
	int			i;

	i = 0;
	dex[0] = 0;
	dex[1] = 0;
	while (i < ft_ptrlen(tab))
	{
		status = stat(tab[i], &st_buf);
		if (status)
		{
			ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(tab[i], 2);
			ft_putendl_fd(": No such file or directory", 2);
		}
		if (S_ISDIR(st_buf.st_mode))
			dex[0]++;
		else
			dex[1]++;
		i++;
	}
	return (dex);
}

int		alloc_ptr(char ***files, char ***dir, int *dex)
{
	*dir = (char **)malloc(sizeof(char*) * (dex[0] + 1));
	if (!(*dir))
		return (-1);
	*files = (char **)malloc(sizeof(char*) * (dex[1] + 1));
	if (!(*files))
		return (-1);
	return (0);
}

int		splitnames(char **tab, char ***files, char ***dir)
{
	int			dex[4];
	struct stat	st_buf;

	dex[2] = 0;
	def_items(tab, dex);
	if (dex[0] == -1)
		return (-1);
	if ((dex[3] = alloc_ptr(files, dir, dex)) == -1)
		return (-1);
	dex[0] = 0;
	dex[1] = 0;
	while (dex[2] < ft_ptrlen(tab))
	{
		dex[3] = stat(tab[dex[2]], &st_buf);
		if (dex[3])
		{
			/*ft_putstr_fd("ls: ", 2);
			ft_putstr_fd(tab[dex[2]], 2);
			ft_putendl_fd(": No such file or directory", 2);
			return(-1);*/
		}
		else if (S_ISDIR(st_buf.st_mode))
		{
			(*dir)[dex[0]] = tab[dex[2]];
			dex[0] = dex[0] + 1;
		}
		else
		{
			(*files)[dex[1]] = tab[dex[2]];
			dex[1] = dex[1] + 1;
		}
		dex[2]++;
	}
	(*dir)[dex[0]] = NULL;
	(*files)[dex[1]] = NULL;
	return (0);
}
