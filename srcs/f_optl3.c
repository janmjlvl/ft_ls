/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_optl3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 13:01:04 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/17 13:13:45 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <stdio.h>

#include "optl.h"

int			display_spacingint(int n, int k)
{
	int			i;
	int			j;

	i = 0;
	j = find_intlength(n);
	while (i < k - j)
	{
		ft_putchar(' ');
		i++;
	}
	return (0);
}

int			display_spaceuid(char *name, int k)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(name);
	while (i < k - j)
	{
		ft_putchar(' ');
		i++;
	}
	return (0);
}

char		*display_modiftime(char *s, int flag)
{
	char	*dest;
	size_t	i;
	int		j;

	if (s)
	{
		if (flag == 0)
			return (ft_strjoin(ft_strsub(s, 4, 7), ft_strsub(s, 19, 5)));
		if (flag == 1)
		{
			i = 0;
			j = ft_strlen(s) - 1;
			while (s[i] != '\0' && s[i] != ' ')
				i++;
			if (i == ft_strlen(s))
				return (ft_strnew(0));
			while ((j > 0) && s[j] != ':')
				j--;
			dest = ft_strsub(s, i + 1, j - i - 1);
			return (dest);
		}
	}
	return (0);
}

int			display_total(char *dir, char **files)
{
	int			status;
	struct stat	buf;
	int			nb_blocks;
	int			i;

	if (*files == NULL)
		return (0);
	i = 0;
	nb_blocks = 0;
	while (files[i] != NULL)
	{
		if ((status = lstat(ft_make_path(dir, files[i]), &buf)) == -1)
			return (-1);
		nb_blocks = nb_blocks + buf.st_blocks;
		i++;
	}
	ft_putstr("total ");
	ft_putnbr(nb_blocks);
	ft_putchar('\n');
	return (0);
}

void		displaynames(struct stat buf, int *tab, t_ls_options *opts)
{
	struct passwd		*pwd;
	struct group		*grp;
	char				*result;

	ft_putchar(' ');
	if (opts->g == 0)
	{
		pwd = getpwuid(buf.st_uid);
		if (pwd)
			result = ft_strdup(pwd->pw_name);
		else
			result = ft_itoa(buf.st_uid);
		ft_putstr(result);
		display_spaceuid(result, tab[2]);
	}
	grp = getgrgid(buf.st_gid);
	if (grp)
		result = ft_strdup(grp->gr_name);
	else
		result = ft_itoa(buf.st_gid);
	ft_putstr(result);
	display_spaceuid(result, tab[3]);
}
