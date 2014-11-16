/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:49:58 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/16 12:46:29 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

void	ft_redirec(t_ls_options *opts)
{
	char	**files;
	char	**dir;
	char	**ret;
	int		i;

	if (splitnames(opts->names, &files, &dir) == -1)
		return ;
	if (*files)
	{
		sortlg_tab(files);
		ft_display_tab(files, opts);
		if (*dir)
			ft_putchar('\n');
	}
	if (*dir)
	{
		i = 0;
		if (opts->r)
			revsortlg_tab(dir);
		else
			sortlg_tab(dir);
		while (dir[i] != NULL)
		{
			if (*files || dir[1] != NULL)
			{
				ft_putstr(dir[i]);
				ft_putendl(":");
			}
			ret = ft_list_dir(dir[i]);
			sortlg_tab(ret);
			ft_display_tab(ret, opts);
			if (dir[i+1] != NULL)
				ft_putchar('\n');
			i++;
		}
	}
}
