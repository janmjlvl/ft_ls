/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/16 15:22:01 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void		ft_display_tab(char **tab, t_ls_options* opts)
{
	int i;
	int tmp;
	int maxlen;
	int colnbr;

	i = 0;
	maxlen = ft_strlen(tab[0]);
	while (tab[i] != NULL)
	{
		if ((tmp = ft_strlen(tab[i])) > maxlen)
			maxlen = tmp;
		i++;
	}
	colnbr = opts->termwidth / (maxlen + ((maxlen) % 6));
	(void)colnbr;
	/*ft_putstr("Col nbr: ");
	ft_putnbr(colnbr);
	ft_putchar('\n');*/

	if (opts->r == 0)
	{
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
		i = ft_ptrlen(tab) - 1;
		while (i >= 0)
		{
			if (opts->a == 1 || tab[i][0] != '.')
				ft_putendl(tab[i]);
			i--;
		}
	}
}
