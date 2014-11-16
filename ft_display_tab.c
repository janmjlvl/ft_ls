/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/16 12:23:26 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void		ft_display_tab(char **tab, t_ls_options* opts)
{
	int i;

	//ft_putendl("DISPLAY_TAB");
	if (opts->r == 0)
	{
		//ft_putendl("no r");
		i = 0;
		while (tab[i] != NULL)
		{
			if (opts->a == 1 || tab[i][0] != '.')
				ft_putendl(tab[i]);
			i++;
		}
	}
	else
	{
		//J'ai corriger le probleme du -r n'afficher rien, yavait (*tab)[0]
		//alors k'il fallait tab[i][0]
		//ft_putendl("r");
		i = ft_ptrlen(tab) - 1;
		while (i >= 0)
		{
			if (opts->a == 1 || tab[i][0] != '.')
				ft_putendl(tab[i]);
			i--;
		}
	}
}
