/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:07:49 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/17 12:07:41 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "stdlib.h"

static int	charcomp1(t_ls_options *opt, char c)
{
	if (c == 'a')
		opt->a = 1;
	else if (c == 'd')
		opt->d = 1;
	else if (c == 'f')
	{
		opt->f = 1;
		opt->a = 1;
	}
	else if (c == 'g')
	{
		opt->g = 1;
		opt->l = 1;
		opt->one = 0;
	}
	else if (c == 'r')
		opt->r = 1;
	else if (c == 'R')
		opt->mr = 1;
	else if (c == 'A')
		opt->ma = 1;
	else
		return (0);
	return (1);
}

static int	charcomp2(t_ls_options *opt, char c)
{
	if (c == 'l')
	{
		opt->l = 1;
		opt->one = 0;
		opt->mc = 0;
	}
	else if (c == 't')
		opt->t = 1;
	else if (c == 'C')
	{
		opt->mc = 1;
		opt->one = 0;
		opt->l = 0;
	}
	else if (c == '1')
	{
		opt->one = 1;
		opt->mc = 0;
		opt->l = 0;
	}
	else if (c == 'm')
		opt->m = 1;
	else
		return (0);
	return (1);
}

int			find_options(t_ls_options *opt, char *s)
{
	if (*s == '\0')
		return (-1);
	if (*s == '-' && *(s + 1) == '\0')
		return (0);
	while (*s != '\0')
	{
		if (charcomp1(opt, *s))
			;
		else if (charcomp2(opt, *s))
			;
		else if (*s == 'S')
			opt->ms = 1;
		else if (*s == 'u')
			opt->u = 1;
		else
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(*s, 2);
			ft_putendl_fd("\nusage: ls [-ACRSadfglrt1] \
					[file ...]", 2);
			exit (-1);
		}
		s++;
	}
	return (1);
}
