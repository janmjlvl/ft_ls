/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 15:49:58 by jabadie           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2014/11/20 15:13:44 by jabadie          ###   ########.fr       */
=======
/*   Updated: 2014/11/20 13:56:22 by nmeier           ###   ########.fr       */
>>>>>>> 29377fe9a437ee4b9ee34826ab4637b9403329ad
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <stdlib.h>

void	opt_sort(t_ls_options *opts, char *path, char **tab)
{
	if (opts->r == 0)
	{
		if (opts->ms == 1)
			sortsize_tab(path, tab);
		else if (opts->t == 1)
			sorttime_tab(path, tab);
		else if (opts->u == 1)
			sort_last_acces(path, tab);
		else
			sortlg_tab(tab);
	}
	else if (opts-> r == 1)
	{
		if (opts->ms == 1)
			r_sortsize_tab(path, tab);
		else if (opts->t == 1)
			r_sorttime_tab(path, tab);
		else if (opts->u == 1)
			r_sort_last_acces(path, tab);
		else
			revsortlg_tab(tab);
	}
}

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
		opt_sort(opts, ".", files);
		ft_display_tab(".", files, opts);
		if (*dir)
			ft_putchar('\n');
	}
	if (*dir)
	{
		i = 0;
		opt_sort(opts, ".", dir);
		while (dir[i] != NULL && opts->mr == 1)
		{
			ft_bigr(opts, dir[i], 0, 1);
			i++;
		}
		while (dir[i] != NULL)
		{
			if (*files || dir[1] != NULL)
			{
				ft_putstr(dir[i]);
				ft_putendl(":");
			}
			ret = ft_list_dir(dir[i]);
			opt_sort(opts, dir[i], ret);
			ft_display_tab(dir[i], ret, opts);
			if (dir[i+1] != NULL)
				ft_putchar('\n');
			i++;
		}
	}
}
