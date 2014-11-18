/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/18 10:16:04 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void		ft_display_tab(char **tab, t_ls_options* opts)
{
	int i;
	int j;
	int k;
	int tmp;
	int maxlen;
	int colnbr;
	int linenbr;
	int tablen;
	if (opts->a == 0)
		tab = ft_ls_striphidden(tab);
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
	colnbr = opts->termwidth / maxlen;
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
