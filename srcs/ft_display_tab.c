/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/18 10:28:54 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		display_columns(char **tab, int termwidth)
{
	int i;
	int j;
	int k;
	int tmp;
	int maxlen;
	int colnbr;
	int linenbr;
	int tablen;
	i = 0;
	if (!*tab)
		return ;
	maxlen = ft_strlen(tab[0]);
	while (tab[i] != NULL)
	{
		if ((tmp = ft_strlen(tab[i])) > maxlen)
		{
			maxlen = tmp;
		}
		i++;
	}
	maxlen = maxlen + 8 - (maxlen % 8);
	tablen = ft_ptrlen(tab);
	colnbr = termwidth / maxlen;
	linenbr = tablen / colnbr;
	if (tablen % colnbr != 0)
	{
		linenbr++;
	}
	j = 0;
	while (j < linenbr && j * colnbr < tablen)
	{
		i = 0;
		while (i < colnbr && (i * linenbr) + j < tablen)
		{
			ft_putstr(tab[(i * linenbr) + j]);
			tmp = ft_strlen(tab[(i * linenbr) + j]);
			k = 0;
			while (k < maxlen - tmp)
			{
				ft_putchar(' ');
				k++;
			}
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

static void		display_one(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

void		ft_display_tab(char **tab, t_ls_options* opts)
{
	if (opts->a == 0)
		tab = ft_ls_striphidden(tab);
	if (opts->one == 1)
		display_one(tab);
	else
		display_columns(tab, opts->termwidth);
}
