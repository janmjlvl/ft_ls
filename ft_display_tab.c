/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/15 14:30:42 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void		ft_display_tab(char **tab, t_ls_options* opts)
{
	int i;

	if (opts->r == 0)
	{
		while (*tab != NULL)
		{
			ft_putendl(*tab);
			tab++;
		}
	}
	else
	{
		i = ft_ptrlen(tab) - 1;
		while (i > 0)
		{
			ft_putendl(tab[i]);
			i--;
		}
	}
}
