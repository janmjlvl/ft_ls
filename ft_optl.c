/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 12:41:34 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/18 15:34:24 by jlevieil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
//#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>
#include <stdlib.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int n)
{
	if (n >= 10)
    {
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
    }
	else
		ft_putchar(48 + n);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

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
	else
		return (b);
	return (0);
}

int		find_maxlength(char **path)
{
	int			k;
	int			status;
	struct stat buf;
	int i;

	i = 0;
	k = 0;
	while (path[i] != NULL)
	{
		if ((status = stat(path[i], &buf)) == -1)
			return (-1);
		k = max(k, find_intlength(buf.st_nlink));
		i++;
	}
	while (k % 4 != 0)
		k++;
	return (k);

}

int		display_spacing(int n, int k)
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

int		ft_optl(char **path)
{
	int			status;
	struct stat	buf;
	int i;
	int k;

	i = 0;
	k = find_maxlength(path);
	while (path[i] != NULL)
	{
		if ((status = stat(path[i], &buf)) == -1)
			return (-1);
		display_type(path[i]);
		display_chmod1(path[i]);
		display_chmod2(path[i]);
		display_chmod3(path[i]);
		display_spacing(buf.st_nlink, k);
		ft_putnbr(buf.st_nlink);
		ft_putchar('\n');
		ft_putnbr(buf.st_uid);
		ft_putchar('\n');
		ft_putnbr(buf.st_gid);
		ft_putchar('\n');
		ft_putnbr(buf.st_size);
		ft_putchar('\n');
		ft_putstr(ctime(&(buf.st_mtime)));
		ft_putstr(path[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}

/*int		main(void)
{
	int		status;
	char **path;

	path = (char **)malloc(sizeof(char *) * 4);
	path[0] = (char *)malloc(sizeof(char) * 50);
	path[1] = (char *)malloc(sizeof(char) * 50);
	path[2] = (char *)malloc(sizeof(char) * 50);
	path[3] = (char *)malloc(sizeof(char) * 50);
	path[0] = "libft";
	path[1]= "b";
	path[2] = "c";
	path[3] = NULL;
	if ((status = ft_optl(path)) == -1)
		return (-1);
	return (0);
}*/
