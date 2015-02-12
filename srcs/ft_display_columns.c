/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_columns.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:26:26 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 14:31:05 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "stdlib.h"

static int		get_maxlen(char **tab)
{
	int maxlen;
	int tmp;
	int i;

	maxlen = ft_strlen(tab[0]);
	i = 0;
	while (tab[i] != NULL)
	{
		if ((tmp = ft_strlen(tab[i])) > maxlen)
			maxlen = tmp;
		i++;
	}
	return (maxlen + 8 - (maxlen % 8));
}

static void		print_columns(char **tab, t_colparms *p)
{
	int i;
	int j;
	int k;
	int tmp;

	j = -1;
	while ((j += 1) < p->linenbr && j * p->colnbr < p->tablen)
	{
		i = -1;
		while ((i += 1) < p->colnbr && (i * p->linenbr) + j < p->tablen)
		{
			ft_putstr(tab[(i * p->linenbr) + j]);
			tmp = ft_strlen(tab[(i * p->linenbr) + j]);
			if (i + 1 < p->colnbr && ((i + 1) * p->linenbr) + j < p->tablen)
			{
				k = 0;
				while (k < p->maxlen - tmp)
				{
					ft_putchar('\t');
					k = k + 8 - (k % 8);
				}
			}
		}
		ft_putchar('\n');
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

void			display_columns(char **tab, int termwidth)
{
	t_colparms colparms;

	if (!*tab)
		return ;
	colparms.maxlen = get_maxlen(tab);
	colparms.tablen = ft_ptrlen(tab);
	colparms.colnbr = termwidth / colparms.maxlen;
	if (colparms.colnbr <= 1)
	{
		display_one(tab);
		return ;
	}
	colparms.linenbr = colparms.tablen / colparms.colnbr;
	if (colparms.tablen % colparms.colnbr != 0)
		colparms.linenbr++;
	print_columns(tab, &colparms);
}
