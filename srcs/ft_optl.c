/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 12:41:34 by vle-guen          #+#    #+#             */
/*   Updated: 2015/02/17 13:18:27 by nmeier           ###   ########.fr       */
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

int			findblkchr(char *dir, char **tab)
{
	struct stat buf;

	while (*tab)
	{
		if (lstat(ft_make_path(dir, *tab), &buf) == -1)
			return (-1);
		else if ((buf.st_mode & S_IFMT) == S_IFCHR || \
				(buf.st_mode & S_IFMT) == S_IFBLK)
			return (1);
		tab++;
	}
	return (0);
}

void		displayversion(struct stat buf, int *tab, int hasblkorchr)
{
	if ((buf.st_mode & S_IFMT) == S_IFCHR || (buf.st_mode & S_IFMT) == S_IFBLK)
	{
		display_spacingint(major(buf.st_rdev), tab[4]);
		ft_putnbr(major(buf.st_rdev));
		ft_putstr(", ");
		display_spacingint(minor(buf.st_rdev), tab[5]);
		ft_putnbr(minor(buf.st_rdev));
	}
	else
	{
		if (hasblkorchr)
			display_spacingint(0, tab[4] + tab[5] + 2);
		display_spacingint(buf.st_size, tab[1]);
		ft_putnbr(buf.st_size);
	}
	ft_putchar(' ');
}

static void	filltab(int *tab, char *dir, char **files)
{
	tab[0] = find_maxlength(dir, files, 0);
	tab[1] = find_maxlength(dir, files, 1);
	tab[2] = find_maxcharlength(dir, files, 0);
	tab[3] = find_maxcharlength(dir, files, 1);
	tab[4] = find_maxlength(dir, files, 2);
	tab[5] = find_maxlength(dir, files, 3);
	tab[6] = findblkchr(dir, files);
}

static int	iteration(char *dir, char *file, int *tab, t_ls_options *opts)
{
	char			*pathtmp;
	struct stat		buf;
	int				status;
	int				flag;

	pathtmp = ft_make_path(dir, file);
	if ((status = lstat(pathtmp, &buf)) == -1)
	{
		perror(ft_strjoin("ls: ", ft_strrchr(pathtmp, '/') + 1));
		return (-1);
	}
	if (displayrights(pathtmp, dir, file))
		return (-1);
	display_spacingint(buf.st_nlink, tab[0]);
	ft_putnbr(buf.st_nlink);
	displaynames(buf, tab, opts);
	displayversion(buf, tab, tab[6]);
	flag = buf.st_mtime < (time(NULL) - 15778800) || \
			buf.st_mtime > (time(NULL) + 3600);
	ft_putstr(display_modiftime(ctime(&(buf.st_mtime)), !flag));
	ft_putchar(' ');
	display_name(dir, file);
	ft_putchar('\n');
	free(pathtmp);
	return (0);
}

int			ft_optl(char *dir, char **files, t_ls_options *opts, int isdir)
{
	int				i;
	int				tab[7];

	if (opts->d == 0 && isdir)
		display_total(dir, files);
	filltab(tab, dir, files);
	i = 0;
	while (files[i] != NULL)
	{
		if (iteration(dir, files[i], tab, opts))
			return (-1);
		i++;
	}
	return (0);
}
