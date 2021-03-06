/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:05:35 by jabadie           #+#    #+#             */
/*   Updated: 2015/02/12 14:02:15 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

char		*ft_make_path(char *dir, char *ret)
{
	char	*new;

	if (ret[0] != '/')
	{
		new = ft_strjoin(dir, "/");
		new = ft_strjoin(new, ret);
	}
	else
		return (ft_strdup(ret));
	return (new);
}

int			is_hidden_dir(char *path)
{
	char *ptr;

	if (ft_strcmp(path, ".") == 0 || ft_strcmp(path, "..") == 0)
		return (0);
	if ((ptr = ft_strrchr(path, '/')) != NULL)
	{
		ptr++;
		if (*ptr == '.')
			return (1);
	}
	else if (path[0] == '.')
		return (1);
	return (0);
}

int			is_empty_dir(char **tab, t_ls_options *opts)
{
	while (*tab)
	{
		if (ft_chooseprint(*tab, opts))
			return (0);
		tab++;
	}
	return (1);
}

static void	print_dirname(t_ls_options *opts, char *dir, int first)
{
	if ((!is_hidden_dir(dir) || opts->a == 1 || opts->ma == 1))
	{
		if (first == 0)
			ft_putchar('\n');
		if (ft_strcmp(dir, ".") != 0)
		{
			ft_putstr(dir);
			ft_putendl(":");
		}
	}
}

void		ft_bigr(t_ls_options *opts, char *dir, int i, int *first)
{
	char			**ret;
	int				len;
	struct stat		st_buf;

	if (!*dir || lstat(dir, &st_buf) == -1 || \
			(st_buf.st_mode & S_IFMT) != S_IFDIR)
		return ;
	print_dirname(opts, dir, *first);
	if (!(ret = ft_list_dir(dir)))
		return ;
	opt_sort(opts, dir, ret);
	if ((!is_hidden_dir(dir)) || opts->a == 1 || opts->ma == 1)
	{
		if (!is_empty_dir(ret, opts))
			*first = 0;
		ft_display_tab(dir, ret, opts, 1);
	}
	len = ft_ptrlen(ret);
	while (i < len)
	{
		if (!(ret[i][0] == '.' && ((ret[i][1] == '.' && ret[i][2] == '\0') \
														|| ret[i][1] == '\0')))
			ft_bigr(opts, ft_make_path(dir, ret[i]), 0, first);
		i++;
	}
}
