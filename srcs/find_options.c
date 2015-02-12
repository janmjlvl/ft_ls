/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 15:07:49 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 15:46:23 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "stdlib.h"

int			find_options(t_ls_options *opt, char *s)
{
	if (*s == '\0')
		return (-1);
	if (*s == '-' && *(s + 1) == '\0')
		return (0);
	while (*s != '\0')
	{
		if (*s == 'a')
			opt->a = 1;
		else if (*s == 'd')
			opt->d = 1;
		else if (*s == 'f')
		{
			opt->f = 1;
			opt->a = 1;
		}
		else if (*s == 'g')
		{
			opt->g = 1;
			opt->l = 1;
			opt->one = 0;
		}
		else if (*s == 'r')
			opt->r = 1;
		else if (*s == 'R')
			opt->mr = 1;
		else if (*s == 'A')
			opt->ma = 1;
		else if (*s == 'l')
		{
			opt->l = 1;
			opt->one = 0;
			opt->mc = 0;
		}
		else if (*s == 't')
			opt->t = 1;
		else if (*s == 'C')
		{
			opt->mc = 1;
			opt->one = 0;
			opt->l = 0;
		}
		else if (*s == '1')
		{
			opt->one = 1;
			opt->mc = 0;
			opt->l = 0;
		}
		else if (*s == 'm')
		{
			opt->m = 1;
		}
		else if (*s == 'S')
		{
			opt->ms = 1;
		}
		else if (*s == 'u')
		{
			opt->u = 1;
		}
		else
		{
			ft_putstr_fd("ls: illegal option -- ", 2);
			ft_putchar_fd(*s, 2);
			ft_putchar_fd('\n', 2);
			ft_putendl_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] \
					[file ...]", 2);
			exit (-1);
		}
		s++;
	}
	return (1);
}
