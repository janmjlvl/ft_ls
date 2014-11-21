/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:05:35 by jabadie           #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

char	*ft_make_path(char *dir, char *ret)
{
	char	*new;

	if (ret[0] != '/')
	{
		new = ft_strjoin(dir, "/");
		new = ft_strjoin(new, ret);
	}
	else
		return ft_strdup(ret);
	return (new);
}

void	ft_bigr(t_ls_options *opts, char *dir, int i, int first)
{
	char	**ret;
	int		len;
	struct stat	st_buf;

	if (!*dir)
		return ;
	if (lstat(dir, &st_buf) == -1)
		return ;
	if ((st_buf.st_mode & S_IFMT) != S_IFDIR)
		return ;
	if (first == 0)
	{
		ft_putchar('\n');
		ft_putstr(dir);
		ft_putendl(":");
	}
	ret = ft_list_dir(dir);
	opt_sort(opts, dir, ret);
	ft_display_tab(dir, ret, opts);
	len = ft_ptrlen(ret);
	while (i < len)
	{
		if (!(ret[i][0] == '.' && ((ret[i][1] == '.' && ret[i][2] == '\0')
														|| ret[i][1] == '\0')))
			ft_bigr(opts, ft_make_path(dir, ret[i]), 0, 0);
		i++;
	}
}
