/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:51:28 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 14:29:32 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

static void		display_stream(char **tab, t_ls_options *opts)
{
	(void)opts;
	while (*tab)
	{
		ft_putstr(*tab);
		tab++;
		if (*tab)
			ft_putstr(", ");
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

char			*ft_chooseprint(char *file, t_ls_options *opts)
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

void			ft_display_tab(char *d, char **t, t_ls_options *opts, int isdir)
{
	if (opts->a == 0)
	{
		if (opts->ma == 0)
		{
			if (!opts->d)
				t = ft_ls_stripdot(t);
			t = ft_ls_striphidden(t);
		}
		else
			t = ft_ls_stripdot(t);
	}
	if (opts->m)
		display_stream(t, opts);
	else if (opts->one == 1)
		display_one(t);
	else if (opts->l == 1)
		ft_optl(d, t, opts, isdir);
	else
		display_columns(t, opts->termwidth);
}
