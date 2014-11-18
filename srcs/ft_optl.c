/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 12:41:34 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/18 15:03:44 by vle-guen         ###   ########.fr       */
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

int	display_type(char *path)
{
	int status;
	struct stat buf;

	if((status = stat(path, &buf)) == -1)
	   return (-1);
	if ((buf.st_mode & S_IFIFO))
		ft_putchar('p');
	else if ((buf.st_mode & S_IFCHR))
		ft_putchar('c');
	else if ((buf.st_mode & S_IFDIR))
		ft_putchar('d');
	else if ((buf.st_mode & S_IFBLK))
		ft_putchar('b');
	else if ((buf.st_mode & S_IFREG))
		ft_putchar('-');
	else if ((buf.st_mode & S_IFLNK))
		ft_putchar('l');
	else if ((buf.st_mode & S_IFSOCK))
		ft_putchar('s');
	else
		return (-1);
	return (0);
}

int	display_chmod1(char *path)
{
	int status;
	struct stat buf;

	if((status = stat(path, &buf)) == -1)
	   return (-1);
	if(!(buf.st_mode & S_IRWXU))
		ft_putstr("rwx");
	else 
	{
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
	}
	return (0);
}

int	display_chmod2(char *path)
{
	int status;
	struct stat buf;

	if((status = stat(path, &buf)) == -1)
	   return (-1);
	if(!(buf.st_mode & S_IRWXG))
		ft_putstr("rwx");
	else 
	{
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
	}
	return (0);
}

int	display_chmod3(char *path)
{
	int status;
	struct stat buf;

	if((status = stat(path, &buf)) == -1)
	   return (-1);
	if(!(buf.st_mode & S_IRWXO))
		ft_putstr("rwx");
	else 
	{
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
	}
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

int		find_maxlength(char **path, int flag)
{
	int			k;
	int			status;
	struct stat buf;
	int i;

	i = 0;
	k = 1;
	while (path[i] != NULL)
	{
		if ((status = stat(path[i], &buf)) == -1)
			return (-1);
		if (flag == 0)
			k = max(k, find_intlength(buf.st_nlink));
		if (flag == 1)
			k = max(k, find_intlength(buf.st_size));
//		if (flag == 2)
//		k = max(k, find_intlength(buf.remplir));
		i++;
	}
	k = k + 2;
	return (k);
}

int		find_maxcharlength(char **path)
{
	int	k;
	int i;
	struct passwd	*pwd;
	struct stat	buf;

	i = 0;
	k = 1;
	while (path[i] != NULL)
	{
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

char	*display_modiftime(char *s)
{
	char	*dest;
	size_t	i;
	int		j;

	if (s)
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
	return (0);
}

int		ft_optl(char **path)
{
	int			status;
	struct stat	buf;
	struct passwd	*pwd;
	char		*result;
	int i;
	int tab[4];

	i = 0;
	tab[0] = find_maxlength(path, 0);
	tab[1] = find_maxlength(path, 1);
	tab[2] = find_maxcharlength(path);
	while (path[i] != NULL)
	{
		if ((status = stat(path[i], &buf)) == -1)
			return (-1);
		display_type(path[i]);
		display_chmod1(path[i]);
		display_chmod2(path[i]);
		display_chmod3(path[i]);
		display_spacingint(buf.st_nlink, tab[0]);
		ft_putnbr(buf.st_nlink);
		ft_putchar(' ');
		pwd = getpwuid(buf.st_uid);
		result = ft_strdup(pwd->pw_name);
		ft_putstr(result);
		display_spaceuid(result, tab[2]);
//		pwd = getgrgid(buf.st_gid);
//		result = ft_strdup(pwd->pw_name);
//		ft_putstr(result);
		ft_putnbr(buf.st_gid);
		display_spacingint(buf.st_size, tab[1]);
		ft_putnbr(buf.st_size);
		ft_putchar(' ');
		ft_putstr(display_modiftime(ctime(&(buf.st_mtime))));
		ft_putchar(' ');
		ft_putstr(path[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

int		main(void)
{
	int		status;
	char **path = ft_list_dir(".");

	if ((status = ft_optl(path)) == -1)
		return (-1);
	return (0);
}
