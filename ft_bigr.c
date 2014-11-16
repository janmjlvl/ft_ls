/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 13:05:35 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/16 13:07:06 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <sys/stat.h>

void	ft_bigr(t_ls_options *opts, char *dir, int multip, int i)
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
	if (multip == 1)
	{
		ft_putstr(dir);
		ft_putendl(":");
	}
	ret = ft_list_dir(dir);
	sortlg_tab(ret);
	ft_display_tab(ret, opts);
	len = ft_ptrlen(ret);
	while (i < len)
	{
		ft_bigr(opts, ret[i], multip, 0);
		i++;
	}
}
