/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displaychmod.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/17 12:52:58 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/17 12:55:17 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

int		display_chmod1(char *path)
{
	struct stat		buf;

	if (lstat(path, &buf) == -1)
		return (-1);
	ft_putchar(buf.st_mode & S_IRUSR ? 'r' : '-');
	ft_putchar(buf.st_mode & S_IWUSR ? 'w' : '-');
	if ((buf.st_mode & S_IXUSR))
	{
		if ((buf.st_mode & S_ISUID))
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else
	{
		if ((buf.st_mode & S_ISUID))
			ft_putchar('S');
		else
			ft_putchar('-');
	}
	return (0);
}

int		display_chmod2(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) == -1)
		return (-1);
	ft_putchar(buf.st_mode & S_IRGRP ? 'r' : '-');
	ft_putchar(buf.st_mode & S_IWGRP ? 'w' : '-');
	if ((buf.st_mode & S_IXGRP))
	{
		if ((buf.st_mode & S_ISGID))
			ft_putchar('s');
		else
			ft_putchar('x');
	}
	else
	{
		if ((buf.st_mode & S_ISGID))
			ft_putchar('S');
		else
			ft_putchar('-');
	}
	return (0);
}

int		display_chmod3(char *path)
{
	int				status;
	struct stat		buf;

	if ((status = lstat(path, &buf)) == -1)
		return (-1);
	if ((buf.st_mode & S_IROTH))
		ft_putchar('r');
	else
		ft_putchar('-');
	if ((buf.st_mode & S_IWOTH))
		ft_putchar('w');
	else
		ft_putchar('-');
	if (buf.st_mode & S_ISVTX)
	{
		if (buf.st_mode & S_IXOTH)
			ft_putchar('t');
		else
			ft_putchar('T');
	}
	else if ((buf.st_mode & S_IXOTH))
		ft_putchar('x');
	else
		ft_putchar('-');
	return (0);
}
