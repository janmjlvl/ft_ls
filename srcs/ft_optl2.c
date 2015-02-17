/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optl2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:48:44 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/17 13:08:00 by nmeier           ###   ########.fr       */
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
#include "optl.h"

int		display_name(char *dir, char *files)
{
	char			*test;
	int				k;
	int				status;
	struct stat		buf;

	test = (char *)malloc(sizeof(char) * 256);
	if (!test || (status = lstat(ft_make_path(dir, files), &buf)) == -1)
		return (-1);
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		k = readlink(ft_make_path(dir, files), test, 255);
		test[k] = '\0';
		if (k == -1)
		{
			ft_putstr("erreur readlink");
			return (-1);
		}
		ft_putstr(files);
		ft_putstr(" -> ");
		ft_putstr(test);
	}
	else
		ft_putstr(files);
	free(test);
	return (k);
}

int		display_acl(char *dir, char *files)
{
	acl_t		i;
	acl_entry_t	ent;

	i = acl_init(1);
	i = acl_get_link_np(ft_make_path(dir, files), ACL_TYPE_EXTENDED);
	if (acl_get_entry(i, ACL_FIRST_ENTRY, &ent) == -1)
	{
		acl_free(i);
		return (0);
	}
	return (1);
}

int		display_exattributes(char *dir, char *files)
{
	char		*test;
	char		*test2;
	ssize_t		k;
	int			status;
	struct stat	buf;

	test = (char *)malloc(sizeof(char) * 256);
	if (!test || (status = stat(ft_make_path(dir, files), &buf)) == -1)
		return (-1);
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		test2 = (char *)malloc(sizeof(char) * 256);
		k = readlink(ft_make_path(dir, files), test2, 255);
		if (k == -1)
			return (-1);
		k = listxattr(ft_make_path(dir, test2), test, 255, \
				XATTR_SHOWCOMPRESSION);
		free(test2);
	}
	else
		k = listxattr(ft_make_path(dir, files), test, 255, XATTR_NOFOLLOW);
	if (k == -1)
		return (0);
	free(test);
	return (k);
}

int		display_type(char *path)
{
	int				status;
	struct stat		buf;

	if ((status = lstat(path, &buf)) == -1)
		return (-1);
	if ((buf.st_mode & S_IFMT) == S_IFIFO)
		ft_putchar('p');
	else if ((buf.st_mode & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if ((buf.st_mode & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if ((buf.st_mode & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if ((buf.st_mode & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if ((buf.st_mode & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if ((buf.st_mode & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
	else
		return (-1);
	return (0);
}

int		displayrights(char *pathtmp, char *dir, char *file)
{
	if ((display_type(pathtmp)) == -1)
	{
		ft_putstr("error display_type");
		return (-1);
	}
	if ((display_chmod1(pathtmp)) == -1)
		ft_putstr("error chmod1");
	if ((display_chmod2(pathtmp)) == -1)
		ft_putstr("error chmod2");
	if ((display_chmod3(pathtmp)) == -1)
		ft_putstr("error chmod3");
	else if ((display_acl(dir, file))
			&& (!display_exattributes(dir, file)))
		ft_putchar('+');
	else
		ft_putchar(' ');
	return (0);
}
