/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 12:41:34 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/21 16:27:46 by nmeier           ###   ########.fr       */
/*   Updated: 2014/11/21 12:57:26 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <stdlib.h>
#include <grp.h>
#include <sys/xattr.h>

int	display_name(char *dir, char *files)
{
	char	*test;
	int	k;
	int status;
	struct stat buf;

	test = (char *)malloc(sizeof(char) * 256);
	if (!test)
		return (-1);
	if((status = lstat(ft_make_path(dir, files), &buf)) == -1)
	   return (-1);
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		k = readlink(ft_make_path(dir, files), test, 255);
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

int	display_exattributes(char *dir, char *files)
{
	char *test;
	char *test2;
	ssize_t	k;
	int	status;
	struct stat	buf;

	test = (char *)malloc(sizeof(char) * 256);
	if (!test)
		return (-1);
	if((status = stat(ft_make_path(dir, files), &buf)) == -1)
	   return (-1);
	if ((buf.st_mode & S_IFMT) == S_IFLNK)
	{
		test2 = (char *)malloc(sizeof(char) * 256);
		k = readlink(ft_make_path(dir, files), test2, 255);
		if (k == -1)
		{
			ft_putstr("erreur readlink");
			return (-1);
		}
		k = listxattr(ft_make_path(dir, test2), test, 255, XATTR_SHOWCOMPRESSION);
		free(test2);
	}
	else
		k = listxattr(ft_make_path(dir, files),test, 255, XATTR_NOFOLLOW);
	if (k == -1)
	{
		ft_putstr("erreur attributes");
		return (-1);
	}
	free(test);
	return (k);
}

int	display_type(char *path)
{
	int status;
	struct stat buf;

	if((status = lstat(path, &buf)) == -1)
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

int	display_chmod1(char *path)
{
	int status;
	struct stat buf;

	if((status = lstat(path, &buf)) == -1)
	   return (-1);
	if ((buf.st_mode & S_IRUSR))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IWUSR))
		ft_putchar('w');	
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IXUSR))
		ft_putchar('x');
	else
		ft_putchar('-');
	return (0);
}

int	display_chmod2(char *path)
{
	int status;
	struct stat buf;

	if((status = lstat(path, &buf)) == -1)
	   return (-1);
	if ((buf.st_mode & S_IRGRP))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IWGRP))
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IXGRP))
		ft_putchar('x');
	else
		ft_putchar('-');
	return (0);
}

int	display_chmod3(char *path)
{
	int status;
	struct stat buf;

	if((status = lstat(path, &buf)) == -1)
	   return (-1);
	if ((buf.st_mode & S_IROTH))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IWOTH))
		ft_putchar('w');
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IXOTH))
		ft_putchar('x');
	else
		ft_putchar('-');
	return (0);
}

int		find_intlength(int n)
{
	int i;

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
	struct stat buf;
	int i;

	i = 0;
	k = 1;
	while (path[i] != NULL)
	{
		if ((status = stat(ft_make_path(dir, path[i]), &buf)) == -1)
			return (-1);
		if (flag == 0)
			k = max(k, find_intlength(buf.st_nlink));
		if (flag == 1)
			k = max(k, find_intlength(buf.st_size));
		i++;
	}
	if (flag == 0)
		k++;
	if (flag == 1)
		k = k + 2;
	return (k);
}

int		find_maxcharlength(char *dir, char **path)
{
	int	k;
	int i;
	struct passwd	*pwd;
	struct stat	buf;

	i = 0;
	k = 1;
	while (path[i] != NULL)
	{
		stat(ft_make_path(dir, path[i]), &buf);
		pwd = getpwuid(buf.st_uid);
		k = max(k, ft_strlen(ft_strdup(pwd->pw_name)));
		i++;
	}
	k = k + 2;
	return (k);
}

int		display_spacingint(int n, int k)
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

int		display_spaceuid(char *name, int k)
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

char	*display_modiftime(char *s, int flag)
{
	char	*dest;
	size_t	i;
	int		j;

	if (s)
	{
		if (flag == 0)
		{
			dest = ft_strjoin(ft_strsub(s, 4, 7), ft_strsub(s, 19, 5));
			return (dest);
		}
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

int		display_total(char *dir, char **files)
{
	if (*files == NULL)
		return (0);
	int	status;
	struct stat	buf;
	int	nb_blocks;
	int	i;

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

int		ft_optl(char *dir, char **files, t_ls_options *opts)
{
	int			status;
	struct stat	buf;
	struct passwd	*pwd;
	struct group	*grp;
	char		*result;
	int i;
	int tab[4];
	char *pathtmp;

	i = 0;
	if (opts->d == 0)
		display_total(dir, files);
	tab[0] = find_maxlength(dir, files, 0);
	tab[1] = find_maxlength(dir, files, 1);
	tab[2] = find_maxcharlength(dir, files);
	while (files[i] != NULL)
	{
		pathtmp = ft_make_path(dir, files[i]);
		if ((status = lstat(pathtmp, &buf)) == -1)
		{
			ft_putstr("error stat: ");
			ft_putendl(pathtmp);
			return (-1);
		}
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
		if ((display_exattributes(dir, files[i])))
			ft_putchar('@');
		else
			ft_putchar(' ');
		display_spacingint(buf.st_nlink, tab[0]);
		ft_putnbr(buf.st_nlink);
		ft_putchar(' ');
		if (opts->g == 0)
		{
			pwd = getpwuid(buf.st_uid);
			result = ft_strdup(pwd->pw_name);
			ft_putstr(result);
			display_spaceuid(result, tab[2]);
		}
		grp = getgrgid(buf.st_gid);
		result = ft_strdup(grp->gr_name);
		ft_putstr(result);
		display_spacingint(buf.st_size, tab[1]);
		ft_putnbr(buf.st_size);
		ft_putchar(' ');
		if (buf.st_mtime < (time(NULL) - 15778800) || buf.st_mtime > (time(NULL) + 3600))
			ft_putstr(display_modiftime(ctime(&(buf.st_mtime)), 0));
		else 
			ft_putstr(display_modiftime(ctime(&(buf.st_mtime)), 1));
		ft_putchar(' ');
		display_name(dir, files[i]);
		ft_putchar('\n');
		free(pathtmp);
		i++;
	}
	return (0);
}
