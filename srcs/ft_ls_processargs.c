/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_processargs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmeier <nmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 10:35:02 by nmeier            #+#    #+#             */
/*   Updated: 2015/02/12 13:43:30 by nmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "ft_ls.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

int		find_options(t_ls_options *opt, char *s)
{
	/*ft_putstr("Processing options: ");
	ft_putendl(s);*/
	if (*s == '\0') /* si l'argument est '-', ls va chercher le fichier intitulé '-'*/
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
			ft_putendl_fd("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", 2);
			exit (-1);
		}
		s++;
	}
	return (1);
}

int		getcolwidth()
{
	char	*str;
	struct winsize window;
	if ((str = getenv("COLUMNS")) != NULL)
		return ft_atoi(str);
	else if (ioctl(1, TIOCGWINSZ, &window) == 0 && window.ws_col > 0)
		return window.ws_col;
	return (80);
}

int		find_optoffset(t_ls_options *opt, int argc, char **argv)
{
	int				i;
	int				stop_opt;
	int				opt_offset;

	ft_bzero(opt, sizeof(t_ls_options));
	opt->termwidth = getcolwidth();
	i = 1;
	stop_opt = 1; /*indicateur de la fin des options (0 ou 1)*/
	opt_offset = 1; /*index des argv indiquant le début des filenames*/
	while (i < argc)
	{
		if (argv[i][0] == '-' && stop_opt == 1)
		{
			if ((stop_opt = find_options(opt, &(argv[i][1]))) != 1)
			{
				if (stop_opt == -1)
				{
					opt_offset = i;
					opt->files_nbr++;
				}
				else
					opt_offset = i + 1;
			}
		}
		else if (stop_opt == 1)
		{
			opt->files_nbr++; /*on a notre files_nbr complété*/
			stop_opt = 0;
			opt_offset = i;
		}
		else
			opt->files_nbr++;
		i++;
	}
	return (opt_offset);
}

void	find_filenames(t_ls_options *opt, char **argv, int opt_offset)
{
	int	i;

	i = 0;
	if (opt->files_nbr != 0)
	{
		opt->names = (char **)malloc(sizeof(char*) * (opt->files_nbr + 1));
		while (i < opt->files_nbr)
		{
			opt->names[i] = argv[opt_offset + i];
			i++;
		}
		opt->names[i] = NULL;
	}
	else
	{
		opt->names = (char **)malloc(sizeof(char*) * 2);
		opt->files_nbr = 1;
		opt->names[0] = ft_strdup(".");
		opt->names[1] = NULL;
	}
}

void		ft_ls_processargs(int argc, char **argv, t_ls_options *opts)
{
	int opt_offset;

	opt_offset = find_optoffset(opts, argc, argv);
	if (!isatty(fileno(stdout)) && opts->l == 0)
		opts->one = 1;
	find_filenames(opts, argv, opt_offset);
}
