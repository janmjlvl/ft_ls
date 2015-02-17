/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findlenght.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:55:58 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/17 13:00:21 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <stdlib.h>
#include <sys/stat.h>

int		find_intlength(int n)
{
	int		i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		find_maxlength(char *dir, char **path, int flag)
{
	int			k;
	int			status;
	struct stat	buf;
	int			i;

	i = -1;
	k = 1;
	while (path[++i] != NULL)
	{
		if ((status = lstat(ft_make_path(dir, path[i]), &buf)) == -1)
			return (-1);
		if (flag == 0)
			k = max(k, find_intlength(buf.st_nlink));
		if (flag == 1)
			k = max(k, find_intlength(buf.st_size));
		if (flag == 2)
			k = max(k, find_intlength(major(buf.st_rdev)));
		if (flag == 3)
			k = max(k, find_intlength(minor(buf.st_rdev)));
	}
	if (flag == 0)
		k++;
	if (flag == 2)
		k = k + 1;
	return (k);
}

int		find_maxcharlength(char *dir, char **path, int flag)
{
	int				k;
	int				i;
	struct stat		buf;

	i = -1;
	k = 1;
	while (path[++i] != NULL)
	{
		stat(ft_make_path(dir, path[i]), &buf);
		if (flag == 0)
		{
			if (getpwuid(buf.st_uid))
				k = max(k, ft_strlen(getpwuid(buf.st_uid)->pw_name));
			else
				k = max(k, ft_strlen(ft_itoa(buf.st_uid)));
		}
		if (flag == 1)
		{
			if (getgrgid(buf.st_gid))
				k = max(k, ft_strlen(getgrgid(buf.st_gid)->gr_name));
			else
				k = max(k, ft_strlen(ft_itoa(buf.st_gid)));
		}
	}
	return (k + 2);
}
