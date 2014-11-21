/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2014/11/21 16:11:47 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		display_stream(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab);
		if (*(tab + 1))
			ft_putstr(", ");
		tab++;
	}
	ft_putchar('\n');
}


static void		display_one(char **tab)
{
	while (*tab)
	{
		ft_putendl(*tab);
		tab++;
	}
}

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
	if (colnbr <= 1)
	{
		display_one(tab);
		return ;
	}
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
			if (i + 1 < colnbr && ((i + 1) * linenbr) + j < tablen)
				//ft_putchar('\t');
			{
				k = 0;
				while (k < maxlen - tmp)
				{
					ft_putchar('\t');
					k = k + 8 - (k % 8);
				}
			}
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

char	*ft_chooseprint(char *file, t_ls_options *opts)
{
	if (opts->a == 1)
		return (file);
	else if (opts->ma == 1)
	{
		if (file[0] == '.' &&
					((file[1] == '.' && file[2] == '\0') || file[1] == '\0'))
			return (NULL);
		else
			return (file);
	}
	else
	{
		if (file[0] == '.')
			return (NULL);
		else
			return (file);
	}
}

void		ft_display_tab(char *dir, char **tab, t_ls_options* opts)
{
	if (opts->a == 0)
	{
		if (opts->ma == 0)
			tab = ft_ls_striphidden(tab);
		else
			tab = ft_ls_stripdot(tab);
	}
	if (opts->m)
		display_stream(tab);
	else if (opts->one == 1)
		display_one(tab);
	else if (opts->l == 1)
		ft_optl(dir, tab, opts);
	else
		display_columns(tab, opts->termwidth);
}
