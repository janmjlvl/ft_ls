/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-guen <vle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 12:41:34 by vle-guen          #+#    #+#             */
/*   Updated: 2014/11/16 14:37:11 by vle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_ls.h"
//#include "libft.h"
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <pwd.h>
#include <uuid/uuid.h>

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

int		ft_optl(char *path)
{
	int			status;
	struct stat	buf;

	if ((status = stat(path, &buf)) == -1)
		return (-1);
	ft_putnbr(buf.st_mode);
	ft_putchar('\n');
	ft_putnbr(buf.st_nlink);
	ft_putchar('\n');
	ft_putnbr(buf.st_uid);
	ft_putchar('\n');
	ft_putnbr(buf.st_gid);
	ft_putchar('\n');
	ft_putnbr(buf.st_size);
	ft_putchar('\n');
	ft_putstr(ctime(&(buf.st_mtime)));
	ft_putchar('\n');
	ft_putstr(path);
	ft_putchar('\n');
	return (0);
}

int		main(void)
{
	char	*path = "./ft_optl.c";
	int		test;

	if ((test = ft_optl(path)) == -1)
		return (-1);
	return (0);
}
