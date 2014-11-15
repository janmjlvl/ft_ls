/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:49:58 by jabadie           #+#    #+#             */
/*   Updated: 2014/11/15 16:09:15 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
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
	}
	if (*dir)
	{
		i = 0;
		sortlg_tab(dir);
		while (dir[i] != NULL)
		{
			ret = ft_list_dir(dir[i]);
			sortlg_tab(ret);
			ft_display_tab(ret, opts);
			i++;
		}
	}
}
