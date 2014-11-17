/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/17 10:00:52 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void		ft_display_tab(char **tab, t_ls_options* opts)
{
	int i;
	int j;
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
	colnbr = opts->termwidth / (maxlen + 2 + ((maxlen + 2) % 6));
	if (opts->r == 0)
	{
		i = 0;
		j = 0;
		while (tab[i + j] != NULL)
		{
			j = 0;
			while (j < colnbr && tab[i + j] != NULL)
			{
				if (opts->a == 1 || tab[i + j][0] != '.')
				{
					ft_putstr(tab[i + j]);
					ft_putchar('\t');
				}
				j++;
			}
			ft_putchar('\n');
			if (tab[i + j] == NULL)
				break ;
			i+=colnbr;
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
